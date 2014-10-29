#-------------------------------------------------
#
# Project created by QtCreator 2014-10-06T09:59:37
#
#-------------------------------------------------

QT       += core gui\
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = musictest
target.path = /home/pi
INSTALLS += target

TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        media.cpp

HEADERS  += mainwindow.h \
            media.h

FORMS    += mainwindow.ui
