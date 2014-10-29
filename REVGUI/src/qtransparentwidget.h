#ifndef QTRANSPARENTWIDGET_H
#define QTRANSPARENTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QRegion>

class QTransparentWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QTransparentWidget(QWidget *parent = 0);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *pnt);

};

#endif // QTRANSPARENTWIDGET_H
