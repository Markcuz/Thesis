#include <QApplication>
#include "rev_hmi.h"
#include <QStyleFactory>
#include <QStyle>
#include <QStyleFactory>

#if QT_VERSION < 0x0040500
#error You need Qt 4.5 or newer
#endif


int main(int argc, char *argv[])
{
    QApplication::setStyle("fusion");
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("The REV Project");
    QCoreApplication::setOrganizationDomain("therevproject.com");
    QCoreApplication::setApplicationName("REV HMI");

    QSettings settings;
    settings.setDefaultFormat(QSettings::IniFormat);
//
//    QTranslator translator;
//    translator.load("rev_hmi_de");
//    a.installTranslator(&translator);



    REV_HMI w;

        w.showFullScreen();


    return a.exec();
}

