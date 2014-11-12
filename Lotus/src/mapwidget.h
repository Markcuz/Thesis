#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QtCore>
#include <QtGui>
#include <QtNetwork>
#include <QtWidgets>
#include <QPainter>
#include <QPen>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


static const bool defaultTilesStoredLocally = true;
static const QString defaultTilesStorageDirectory = "maps";
static const QString defaultBaseURL = "http://tile.openstreetmap.org";
static const int defaultMinZoom = 11;
static const int defaultMaxZoom = 18;
static const int defaultMaxWidth = 1920;
static const int defaultMaxHeight = 1200;

// UWA coordinates
static const qreal defaultLatitude =-31.979283;
static const qreal defaultLongitude = 115.815852;
static const qreal defaultDirection = 0.0;
static const int defaultZoom = 15;

static const bool defaultCentered = true;
static const bool defaultInvert = false;
static const bool defaultMyTrackVisible = true;
static const bool defaultTestTrackVisible = false;
static const bool defaultTestTrackCmtsVisible = false;
static const QString defaultTrackFile = "testtrack.gpx";


class SlippyMap: public QObject
{
    Q_OBJECT

    // tile size in pixels
    const static int tdim = 256;

public:
    SlippyMap(QObject *parent = 0,int width=400, int height=300);
    ~SlippyMap();

public slots:
    void loadSettings();
    void saveSettings();
    void setDefaultSettings();

    void zoomIn();
    void zoomOut();
    void setZoom(int zoom);
    void setCenter(qreal lat, qreal lng);
    void pan(const QPoint &delta);
    void render(QPainter *p, const QRect &rect);
    void resize(int width, int height);

    QPointF pixelForCoordinate(qreal myLat, qreal myLng);

signals:
    void updated(const QRect &rect);
    void debugMsg(QtMsgType, QString, QString);

private slots:
    void handleNetworkData(QNetworkReply *reply);

private:
    QString objName;
    int width;
    int height;

    int zoom;
    qreal latitude;
    qreal longitude;

    QSettings settings;
    QDir tilesDir;
    QPoint m_offset;
    QRect m_tilesRect;
    QPixmap m_emptyTile;
    QPixmap m_errorTile;
    QHash<QPoint, QPixmap> m_tilePixmaps;
    QNetworkAccessManager m_manager;
    QUrl m_url;

    void getTiles();
    bool loadTile(QPoint tp);
    void saveTile(QPoint tp, QImage img);
    void invalidate();
    QRect tileRect(const QPoint &tp);
    QPointF tileForCoordinate(qreal lat, qreal lng, int zoom);
    qreal longitudeFromTile(qreal tx, int zoom);
    qreal latitudeFromTile(qreal ty, int zoom);
};


class MapWidget: public QWidget
{
    Q_OBJECT

public:
    MapWidget(QWidget *parent = 0);
    virtual ~MapWidget();


public slots:
    void loadSettings();
    void saveSettings();
    void setDefaultSettings();

    void zoomIn();
    void zoomOut();
    void setCenter(qreal lat, qreal lng);
    void setMyPos(qreal lat, qreal lng, qreal dir);

    void setCentered(bool centered);
    void toggleNightMode();
    void showMyTrack(bool myTrackVisible);
    void showTestTrack(bool testTrackVisible);
    void showTestTrackComments(bool testTrackCmtsVisible);

    bool isCentered();
    bool isNightmode();
    bool isVisibleMyTrack();
    bool isVisibleTestTrack();
    bool isVisibleTestTrackComments();

    void loadTrack(QString trackFile);
    QString getTrackFile();

signals:
    void debugMsg(QtMsgType, QString, QString);

private slots:
    void updateMap(const QRect &r);
    bool isVisible(QPointF point);
    void forwardDebugMsg(QtMsgType warnLevel, QString source, QString msg);

protected:

    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *);

private:
    QString objName;
    QSettings settings;
    SlippyMap *m_slippyMap;

    QPoint pressPos;
    bool invert;
    bool centered;
    bool myTrackVisible;
    bool testTrackVisible;
    bool testTrackCmtsVisible;

    int zoom;
    qreal centerLat;
    qreal centerLng;

    qreal myPosLat;
    qreal myPosLng;
    qreal myDir;

    QString trackFile;
    QList<QPointF> loadedTrackPoints;
    QStringList loadedTrackComments;
    QList<QPointF> myTrackPoints;

    void drawCarPosition();
    void drawTrack(QList<QPointF> trackPoints,
                   QColor normalColor = Qt::black,
                   QColor invertColor = Qt::lightGray);
};

#endif // MAPWIDGET_H
