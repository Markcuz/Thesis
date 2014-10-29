#
#  QCustomPlot Plot Examples
#

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

target.path = /home/pi/

TARGET = plot-examples

INSTALLS += target

TEMPLATE = app

INCLUDEPATH += ~/Qt/rasp-pi-rootfs/usr/include
DEPENDPATH += ~/Qt/rasp-pi-rootfs/usr/include

SOURCES += main.cpp\
           mainwindow.cpp \
         ../../qcustomplot.cpp

HEADERS  += mainwindow.h \
         ../../qcustomplot.h

FORMS    += mainwindow.ui

