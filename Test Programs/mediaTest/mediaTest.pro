#-------------------------------------------------
#
# Project created by QtCreator 2014-09-24T21:14:05
#
#-------------------------------------------------

QT       += core gui\
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

target.path = /home/pi/
TARGET = mediaTest
INSTALLS += target
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        media.cpp

HEADERS  += mainwindow.h \
            media.h

FORMS    += mainwindow.ui
