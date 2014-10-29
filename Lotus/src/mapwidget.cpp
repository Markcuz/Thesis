#include "mapwidget.h"

uint qHash(const QPoint& p)
{
    return p.x() * 17 ^ p.y();
}

SlippyMap::SlippyMap(QObject *parent, int _width, int _height)
    : QObject(parent)
{
    objName = "SlippyMap";
    width   = _width;
    height  = _height;

    latitude = defaultLatitude;
    longitude = defaultLongitude;
    zoom = defaultZoom;

    m_emptyTile = QPixmap(tdim, tdim);
    m_emptyTile.fill(Qt::lightGray);

    QNetworkDiskCache *cache = new QNetworkDiskCache;
    cache->setCacheDirectory(QDesktopServices::storageLocation
                             (QDesktopServices::CacheLocation));
    m_manager.setCache(cache);
    connect(&m_manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(handleNetworkData(QNetworkReply*)));
}

SlippyMap::~SlippyMap()
{
    saveSettings();
}


void SlippyMap::loadSettings()
{
    settings.beginGroup("map");
    latitude   = settings.value("latitude",defaultLatitude).toReal();
    longitude   = settings.value("longitude",defaultLongitude).toReal();
    zoom        = settings.value("zoom",defaultZoom).toInt();
    settings.endGroup();

    emit debugMsg(QtDebugMsg, objName, "last settings loaded ");
}

void SlippyMap::saveSettings()
{
    settings.beginGroup("map");
    settings.setValue("latitude",latitude);
    settings.setValue("longitude",longitude);
    settings.setValue("zoom",zoom);
    settings.endGroup();

    emit debugMsg(QtDebugMsg, objName, "settings saved ");
}

void SlippyMap::setDefaultSettings()
{
    settings.beginGroup("map");
    settings.remove("");    //removes all previous settings in "map"
    settings.setValue("tilesStoredLocally",defaultTilesStoredLocally);
    settings.setValue("tilesStorageDirectory",defaultTilesStorageDirectory);
    settings.setValue("baseURL",defaultBaseURL);
    settings.setValue("minZoom",defaultMinZoom);
    settings.setValue("maxZoom",defaultMaxZoom);
    settings.setValue("maxWidth",defaultMaxWidth);
    settings.setValue("maxHeight",defaultMaxHeight);
    settings.endGroup();

    // UWA coordinates
    latitude = defaultLatitude;
    longitude = defaultLongitude;
    zoom = defaultZoom;

    emit debugMsg(QtDebugMsg, objName, "default settings applied ");

    saveSettings();
}


void SlippyMap::setCenter(qreal lat, qreal lng)
{
    latitude = lat;
    longitude = lng;
    invalidate();
}

void SlippyMap::zoomIn() {
    if (zoom < settings.value("map/maxZoom",defaultMaxZoom).toInt()){
        zoom++;
        invalidate();
    }
}

void SlippyMap::zoomOut() {
    if (zoom > settings.value("map/minZoom",defaultMinZoom).toInt()){
        zoom--;
        invalidate();
    }
}

void SlippyMap::setZoom(int _zoom) {
    if (_zoom >= settings.value("map/minZoom",defaultMinZoom).toInt()
        && _zoom <= settings.value("map/maxZoom",defaultMaxZoom).toInt()){
        zoom = _zoom;
        invalidate();
    }
}

void SlippyMap::invalidate() {
    if (width <= 0 || height <= 0)
        return;

    //what is the center tile? -> transform coordinates to tiles
    QPointF ct = tileForCoordinate(latitude, longitude, zoom);
    int tCenterX = static_cast<int>(ct.x());
    int tCenterY = static_cast<int>(ct.y());

    // top-left corner of the center tile (in pixels from top left corner of the object)
    int pCtX = width / 2 - (ct.x() - tCenterX) * tdim;
    int pCtY = height / 2 - (ct.y() - tCenterY) * tdim;

    //number of tiles left from center tile / above center tile
    int tx = (pCtX + tdim - 1) / tdim;
    int ty = (pCtY + tdim - 1) / tdim;

    // first tile vertical and horizontal
    int tFirstX = tCenterX - tx;
    int tFirstY = tCenterY - ty;

    // number of tiles vertical and horizontal
    int ntx = tx + (width - pCtX - 1) / tdim + 1;
    int nty = ty + (height - pCtY - 1) / tdim + 1;

    // build a rect
    m_tilesRect = QRect(tFirstX, tFirstY, ntx, nty);

    // offset for top-left tile (in pixels from top left corner of the object)
    m_offset = QPoint(pCtX - tx * tdim, pCtY - ty * tdim);

    //load the tiles to m_tilePixmaps (if neccessary)
    getTiles();

    emit updated(QRect(0, 0, width, height));

    // purge unused spaces
    QRect bound = m_tilesRect.adjusted(-2, -2, 2, 2);   //keep 2 more tiles than visible in every direction
    foreach(QPoint tp, m_tilePixmaps.keys())
        if (!bound.contains(tp))
            m_tilePixmaps.remove(tp);

}

//delivers position and size of the tile containing this point
QRect SlippyMap::tileRect(const QPoint &tp) {
    QPoint t = tp - m_tilesRect.topLeft();
    int x = t.x() * tdim + m_offset.x();
    int y = t.y() * tdim + m_offset.y();
    return QRect(x, y, tdim, tdim);
}

//render a map of the tiles
void SlippyMap::render(QPainter *p, const QRect &rect) {
    for (int x = 0; x <= m_tilesRect.width(); ++x)
        for (int y = 0; y <= m_tilesRect.height(); ++y) {
        QPoint tp(x + m_tilesRect.left(), y + m_tilesRect.top()); //get "name" of the tile
        QRect box = tileRect(tp);               //get position of the tile relative to our widget
        if (rect.intersects(box)) {             //check if the tile is visible
            if (m_tilePixmaps.contains(tp))     //check if tile is loaded
                p->drawPixmap(box, m_tilePixmaps.value(tp));    //draw the tile
            else
                p->drawPixmap(box, m_emptyTile);
        }
    }
}

void SlippyMap::resize(int _width, int _height)
{
    if (_width>0 && _width<settings.value("map/maxWidth",defaultMaxWidth).toInt() &&
        _height>0 && _height<settings.value("map/maxHeight",defaultMaxHeight).toInt())
    {
        width = _width;
        height = _height;
        invalidate();
    }
}

void SlippyMap::getTiles() {

    QString userAgent = QCoreApplication::organizationName() + " - " + QCoreApplication::applicationName();
    QString path = settings.value("map/baseURL",defaultBaseURL).toString();
    path += "/%1/%2/%3.png";

    //get all tiles that are needed for the current map
    for (int x = 0; x <= m_tilesRect.width(); ++x){
        for (int y = 0; y <= m_tilesRect.height(); ++y) {
            QPoint tp = m_tilesRect.topLeft() + QPoint(x, y);
            if (!m_tilePixmaps.contains(tp)) {  // check if tile is already loaded
                if (!loadTile(tp)) {            // check if tile is already on hdd
                    //check if there is another request processed at the moment
                    if (!m_url.isEmpty())
                        return;
                    m_url = QUrl(path.arg(zoom).arg(tp.x()).arg(tp.y()));
                    QNetworkRequest request;
                    request.setUrl(m_url);
                    request.setRawHeader("User-Agent",userAgent.toAscii());
                    request.setAttribute(QNetworkRequest::User, QVariant(tp));
                    m_manager.get(request);
                    return;
                }
            }
        }
    }
}

//load tile from local file - return false if not available
bool SlippyMap::loadTile(QPoint tp)
{
    if(!settings.value("map/tilesStoredLocally",defaultTilesStoredLocally).toBool())
        return false;

    QString tilesDirName = settings.value("map/tilesStorageDirectory", defaultTilesStorageDirectory).toString();
    QDir tilePath(QDir::homePath()+"/"+tilesDirName+"/"+QString::number(zoom)+"/"+QString::number(tp.x()));
    QFile thisTile(tilePath.absolutePath()+"/"+QString::number(tp.y())+".png");

    if (!thisTile.exists())
        return false;

    QImage img(thisTile.fileName());
    m_tilePixmaps[tp] = QPixmap::fromImage(img);
    return true;
}

//save tile on hdd
void SlippyMap::saveTile(QPoint tp, QImage img)
{
    if(!settings.value("map/tilesStoredLocally",defaultTilesStoredLocally).toBool())
        return;

    QString tilesDirName = settings.value("map/tilesStorageDirectory", defaultTilesStorageDirectory).toString();
    QDir tilePath(QDir::homePath()+"/"+tilesDirName+"/"+QString::number(zoom)+"/"+QString::number(tp.x()));

    if (!tilePath.exists())
        tilePath.mkpath(tilePath.absolutePath());

    img.save(tilePath.absolutePath()+"/"+QString::number(tp.y())+".png");

}


void SlippyMap::handleNetworkData(QNetworkReply *reply) {
    QImage img;
    QPoint tp = reply->request().attribute(QNetworkRequest::User).toPoint();

    //get tile from network reply
    if (!reply->error())
        if (img.load(reply, 0)){
            m_tilePixmaps[tp] = QPixmap::fromImage(img);
            saveTile(tp, img);
            emit updated(tileRect(tp));
        }

    reply->deleteLater();

    m_url = QUrl(); //clear url to show that network request is processed
    getTiles();     //download other tiles if neccessary
}

//move map by delta pixels
void SlippyMap::pan(const QPoint &delta) {
    QPointF dx = QPointF(delta) / qreal(tdim);
    QPointF center = tileForCoordinate(latitude, longitude, zoom) - dx;
    latitude = latitudeFromTile(center.y(), zoom);
    longitude = longitudeFromTile(center.x(), zoom);
    invalidate();
}

//returns the distance in pixels from the map center
QPointF SlippyMap::pixelForCoordinate(qreal myLat, qreal myLng)
{
    QPointF centerPoint = tileForCoordinate(latitude, longitude, zoom);
    QPointF myPoint = tileForCoordinate(myLat, myLng, zoom);
    qreal x = (myPoint.x() - centerPoint.x()) * tdim + width/2;
    qreal y = (myPoint.y() - centerPoint.y()) * tdim + height/2;

    return QPointF(x, y);
}


QPointF SlippyMap::tileForCoordinate(qreal lat, qreal lng, int zoom)
{
    qreal zn = static_cast<qreal>(1 << zoom);
    qreal tx = (lng + 180.0) / 360.0; //0.821851483*32768 = 26930.429
    qreal ty = (1.0 - log(tan(lat * M_PI / 180.0) +
                          1.0 / cos(lat * M_PI / 180.0)) / M_PI) / 2.0;//0.501549264*32768 = 16434.76
    return QPointF(tx * zn, ty * zn);
}

qreal SlippyMap::longitudeFromTile(qreal tx, int zoom)
{
    qreal zn = static_cast<qreal>(1 << zoom);
    qreal lat = tx / zn * 360.0 - 180.0;
    return lat;
}

qreal SlippyMap::latitudeFromTile(qreal ty, int zoom)
{
    qreal zn = static_cast<qreal>(1 << zoom);
    qreal n = M_PI - 2 * M_PI * ty / zn;
    qreal lng = 180.0 / M_PI * atan(0.5 * (exp(n) - exp(-n)));
    return lng;
}


// ================================================================================= //


MapWidget::MapWidget(QWidget *parent) : QWidget(parent)
{
    objName = "MapWidget";

    m_slippyMap = new SlippyMap(this, width(), height());

    myPosLat = defaultLatitude;
    myPosLng = defaultLongitude;
    myDir = defaultDirection;

    centered = defaultCentered;
    invert = defaultInvert;
    myTrackVisible = defaultMyTrackVisible;
    testTrackVisible = defaultTestTrackVisible;
    testTrackCmtsVisible = defaultTestTrackCmtsVisible;

    trackFile = defaultTrackFile;

    connect(m_slippyMap, SIGNAL(updated(QRect)), this, SLOT(updateMap(QRect)));
    connect(m_slippyMap, SIGNAL(debugMsg(QtMsgType,QString,QString)),
            this, SLOT(forwardDebugMsg(QtMsgType,QString,QString)));
}

MapWidget::~MapWidget()
{
    saveSettings();
}

void MapWidget::loadSettings()
{
    m_slippyMap->loadSettings();

    settings.beginGroup("map");
    myPosLat    = settings.value("myPosLat",defaultLatitude).toReal();
    myPosLng    = settings.value("myPosLng",defaultLongitude).toReal();
    myDir       = settings.value("myDir",defaultDirection).toReal();
    centered    = settings.value("centered",defaultCentered).toBool();
    invert      = settings.value("invert",defaultInvert).toBool();
    myTrackVisible = settings.value("myTrackVisible",defaultMyTrackVisible).toBool();
    testTrackVisible = settings.value("testTrackVisible",defaultTestTrackVisible).toBool();
    testTrackCmtsVisible = settings.value("testTrackCmtsVisible",defaultTestTrackCmtsVisible).toBool();
    trackFile=settings.value("trackFile",defaultTrackFile).toString();
    settings.endGroup();

    loadTrack(trackFile);

    emit debugMsg(QtDebugMsg, objName, "last settings loaded ");
}

void MapWidget::saveSettings()
{
    settings.beginGroup("map");

    if (!(myPosLat==0&&myPosLng==0)){   //only save when myPos was set
        settings.setValue("myPosLat",myPosLat);
        settings.setValue("myPosLng",myPosLng);
        settings.setValue("myDir",myDir);
    }

    settings.setValue("centered", centered);
    settings.setValue("invert", invert);
    settings.setValue("myTrackVisible", myTrackVisible);
    settings.setValue("testTrackVisible", testTrackVisible);
    settings.setValue("testTrackCmtsVisible", testTrackCmtsVisible);

    settings.setValue("trackFile",trackFile);

    settings.endGroup();

    emit debugMsg(QtDebugMsg, objName, "settings saved ");
}

void MapWidget::setDefaultSettings()
{
    //delete current settings and set SlippyMap default settings
    m_slippyMap->setDefaultSettings();

    myPosLat = defaultLatitude;
    myPosLng = defaultLongitude;
    myDir = defaultDirection;

    centered = defaultCentered;
    invert = defaultInvert;
    myTrackVisible = defaultMyTrackVisible;
    testTrackVisible = defaultTestTrackVisible;
    testTrackCmtsVisible = defaultTestTrackCmtsVisible;

    trackFile = defaultTrackFile;

    emit debugMsg(QtDebugMsg, objName, "default settings applied ");

    saveSettings();
}



void MapWidget::setMyPos(qreal lat, qreal lng, qreal dir)
{
    myPosLat = lat;
    myPosLng = lng;
    myDir = dir;

    myTrackPoints.append(QPointF(myPosLat,myPosLng));

    if (centered)
        m_slippyMap->setCenter(myPosLat, myPosLng);

    update();
}

void MapWidget::zoomIn() {
    m_slippyMap->zoomIn();
    update();
}

void MapWidget::zoomOut() {
    m_slippyMap->zoomOut();
    update();
}

void MapWidget::setCenter(qreal lat, qreal lng){
    m_slippyMap->setCenter(lat, lng);
}

void MapWidget::setCentered(bool c){
    centered = c;
    if (centered)
        m_slippyMap->setCenter(myPosLat, myPosLng);
}

void MapWidget::toggleNightMode() {
    invert = !invert;
    update();
}


void MapWidget::showMyTrack(bool _myTrackVisible){
    myTrackVisible = _myTrackVisible;
    update();
}

void MapWidget::showTestTrack(bool _testTrackVisible){
    testTrackVisible = _testTrackVisible;
    update();
}

void MapWidget::showTestTrackComments(bool _testTrackCmtsVisible)
{
    testTrackCmtsVisible = _testTrackCmtsVisible;
    update();
}


bool MapWidget::isCentered()
{
    return centered;
}

bool MapWidget::isNightmode()
{
    return invert;
}

bool MapWidget::isVisibleMyTrack(){
    return myTrackVisible;
}

bool MapWidget::isVisibleTestTrack(){
    return testTrackVisible;
}

bool MapWidget::isVisibleTestTrackComments(){
    return testTrackCmtsVisible;
}


void MapWidget::mousePressEvent(QMouseEvent *event) {
    if (event->buttons() == Qt::LeftButton)
        pressPos = event->pos();
}

void MapWidget::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() == Qt::LeftButton && !centered) {
        QPoint delta = event->pos() - pressPos;
        pressPos = event->pos();
        m_slippyMap->pan(delta);
        return;
    }
}

void MapWidget::mouseReleaseEvent(QMouseEvent *) {
    update();
}

void MapWidget::resizeEvent(QResizeEvent *) {
    //check max size because sometimes during loading it has very large values for a moment
    if (width()<settings.value("map/maxWidth",defaultMaxWidth).toInt()
        && height()<settings.value("map/maxHeight",defaultMaxHeight).toInt()){
        m_slippyMap->resize(width(), height());
    }
}

void MapWidget::paintEvent(QPaintEvent *event) {
    QPainter p;
    p.begin(this);

    if (invert){
        p.setCompositionMode(QPainter::RasterOp_NotSource);
        p.setPen(Qt::white);
    }

    m_slippyMap->render(&p, event->rect());
    p.drawText(rect(),  Qt::AlignBottom | Qt::TextWordWrap,
               "Map data CCBYSA 2009 OpenStreetMap.org contributors");
    p.end();

    if (testTrackVisible)
        drawTrack(loadedTrackPoints);

    if(myTrackVisible)
        drawTrack(myTrackPoints, Qt::blue, Qt::red);

    drawCarPosition();
}



void MapWidget::drawCarPosition()
{
    QPointF position = m_slippyMap->pixelForCoordinate(myPosLat, myPosLng);

    qreal carX = 10;
    qreal carY = 20;

    QPainter p;
    p.begin(this);

    p.translate(position.x(),position.y());

    p.rotate(this->myDir);

    QPainterPath path;
    path.lineTo(carX/2, carY/3);
    path.lineTo(0, -carY*2/3);
    path.lineTo(-carX/2, carY/3);
    path.lineTo(0,0);

    p.setRenderHint(QPainter::Antialiasing);
    QBrush brush(Qt::SolidPattern);
    brush.setColor(Qt::black);
    if (invert)
       brush.setColor(Qt::lightGray);


    QPen pen(brush, 1.5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    p.fillPath(path, brush);
    p.setPen(pen);
    p.drawPath(path);

    p.end();
}

void MapWidget::loadTrack(QString _trackFile)
{
    loadedTrackPoints.clear();
    loadedTrackComments.clear();

    trackFile = _trackFile;
    settings.setValue("map/trackFile",trackFile);
    QFile* xmlFile = new QFile(trackFile);

    if (!xmlFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open " << xmlFile->fileName();
        return;
    }
    QXmlStreamReader xmlReader(xmlFile);

    while (!xmlReader.atEnd()){
        xmlReader.readNextStartElement();
        if (xmlReader.name()=="trkpt" && xmlReader.isStartElement()){
            QPointF trackPoint;
            trackPoint.setX(xmlReader.attributes().value("lat").toString().toDouble());
            trackPoint.setY(xmlReader.attributes().value("lon").toString().toDouble());
            loadedTrackPoints.append(trackPoint);
            xmlReader.readNextStartElement();
            if (xmlReader.name()=="cmt" && xmlReader.isStartElement())
                loadedTrackComments.append(xmlReader.readElementText());
            else
                loadedTrackComments.append("");
        }
    }

    update();
}

QString MapWidget::getTrackFile() {
    return settings.value("map/trackFile").toString();
}

void MapWidget::drawTrack(QList<QPointF> trackPoints, QColor normalColor, QColor invertColor)
{
    if(trackPoints.isEmpty())
        return;

    QPointF pixelPoint;
    QPointF prevPoint;
    QPointF nextPoint = m_slippyMap->pixelForCoordinate(
            trackPoints.at(0).x(), trackPoints.at(0).y());

    QPainter p;
    p.begin(this);
    p.setRenderHint(QPainter::Antialiasing);

    QPen pen;
    if (invert)
        pen.setColor(invertColor);
    else
        pen.setColor(normalColor);

    pen.setWidthF(3.0);
    p.setPen(pen);


    QPainterPath path;
    for (int i=0; i<trackPoints.length(); i++){
        prevPoint = pixelPoint;
        pixelPoint = nextPoint;
        if ((i+1)<trackPoints.length()){
            nextPoint = m_slippyMap->pixelForCoordinate(
                    trackPoints.at(i+1).x(), trackPoints.at(i+1).y());
        }

        //don't draw points that are too far away
        if (trackPoints.length()<1000 || isVisible(prevPoint)
            || isVisible(pixelPoint) || isVisible(nextPoint)){
            if (path.currentPosition() == QPointF())
                path.moveTo(pixelPoint); //first point
            path.lineTo(pixelPoint);
        }
    }
    p.drawPath(path);


    if (testTrackCmtsVisible)
    {
        QBrush brush(Qt::SolidPattern);
        brush.setColor(invertColor);
        if (invert)
            brush.setColor(normalColor);

        pen.setWidthF(1.0);
        p.setPen(pen);

        for (int i=0; i<trackPoints.length(); i++)
        {
            if (loadedTrackComments.at(i)!=""){
                pixelPoint = m_slippyMap->pixelForCoordinate(
                        trackPoints.at(i).x(), trackPoints.at(i).y());
                int rectWidth = loadedTrackComments.at(i).length()*7;
                QRectF rect(pixelPoint.x()-rectWidth/2, pixelPoint.y()-10, rectWidth, 20);
                p.fillRect(rect,brush);
                p.drawRect(rect);
                p.drawText(rect, Qt::AlignHCenter|Qt::AlignVCenter,
                           loadedTrackComments.at(i));
            }
        }
    }

    p.end();

}

bool MapWidget::isVisible(QPointF point)
{
    return point.x()>0 && point.x()<width()
                && point.y()>0 && point.y()<height();
}


void MapWidget::updateMap(const QRect &r)
{
    update(r);
}

void MapWidget::forwardDebugMsg(QtMsgType warnLevel, QString source, QString msg)
{
    emit debugMsg(warnLevel, source, msg);
}

