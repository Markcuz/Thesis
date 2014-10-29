#include "camera.h"
#include <QMediaService>
#include <QMediaRecorder>

Camera::Camera() : QObject()
{
    QByteArray cameraDevice;

    QList<QByteArray> list = QCamera::availableDevices();
    if(list.isEmpty()) printf("No Cameras\n");
        foreach(const QByteArray &deviceName, QCamera::availableDevices()) {
            QString description = camera->deviceDescription(deviceName);
            printf("Camera: %s\n",description.toLatin1().constData());
            if (cameraDevice.isEmpty()) {
                cameraDevice = deviceName;
            }
        }
        camera = new QCamera;
        imageCapture = new QCameraImageCapture(camera);
        camera->setCaptureMode(QCamera::CaptureStillImage);
        imageCapture->capture();
}

Camera::~Camera()
{
    delete mediaRecorder;
    delete imageCapture;
    delete camera;
}
