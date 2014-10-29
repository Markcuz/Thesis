#ifndef CAMERA_H
#define CAMERA_H

#include <QCamera>
#include <QCameraImageCapture>
#include <QMediaRecorder>

class Camera : public QObject
{
  Q_OBJECT

public:
    Camera();
    virtual ~Camera();

private:
    QCamera *camera;
    QCameraImageCapture *imageCapture;
    QMediaRecorder* mediaRecorder;
};

#endif // CAMERA_H
