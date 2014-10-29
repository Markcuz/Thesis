#include "qtransparentwidget.h"

QTransparentWidget::QTransparentWidget(QWidget *parent) : QWidget(parent)
{
    {
        setAttribute(Qt::WA_TranslucentBackground);
    }
}

void QTransparentWidget::paintEvent(QPaintEvent *pnt)
{
    int roundness = 10;
    QRect widget_rect = this->rect();
    QColor current_color = QColor("white");
    QPainter painter(this);

    QLinearGradient linearGrad(QPointF(100, 100), QPointF(200, 200));
    //ANGRY!
    //linearGrad.setColorAt(0, Qt::black);
    //linearGrad.setColorAt(1, Qt::white);


    QPen pen = QPen("grey");
    QBrush brush = QBrush(linearGrad);

//clip region

    QPainterPath rounded_rect;
    rounded_rect.addRoundRect(1, 1, widget_rect.width() - 2, widget_rect.height() - 2, roundness, roundness);
    painter.setClipPath(rounded_rect);

// mask widget
    QRegion maskregion = painter.clipRegion();
    setMask(maskregion);

    pen.setWidth(7);
    pen.setStyle(Qt::SolidLine);
    pen.setJoinStyle(Qt::RoundJoin);
    pen.setCapStyle(Qt::SquareCap);

    pen.setBrush(brush);


    current_color.setAlpha(100);

    painter.fillPath(rounded_rect, current_color);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(pen);
    painter.drawRoundRect(rect(),roundness,roundness);

    //painter.restore();
}
