/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *play;
    QPushButton *pause;
    QPushButton *next;
    QPushButton *prev;
    QPushButton *stop;
    QPushButton *add;
    QPushButton *remove;
    QSlider *trackLength;
    QPushButton *shuffle;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(754, 500);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        play = new QPushButton(centralWidget);
        play->setObjectName(QStringLiteral("play"));
        play->setGeometry(QRect(70, 290, 71, 21));
        pause = new QPushButton(centralWidget);
        pause->setObjectName(QStringLiteral("pause"));
        pause->setGeometry(QRect(150, 290, 71, 21));
        next = new QPushButton(centralWidget);
        next->setObjectName(QStringLiteral("next"));
        next->setGeometry(QRect(350, 290, 71, 31));
        prev = new QPushButton(centralWidget);
        prev->setObjectName(QStringLiteral("prev"));
        prev->setGeometry(QRect(420, 290, 114, 32));
        stop = new QPushButton(centralWidget);
        stop->setObjectName(QStringLiteral("stop"));
        stop->setGeometry(QRect(230, 290, 114, 32));
        add = new QPushButton(centralWidget);
        add->setObjectName(QStringLiteral("add"));
        add->setGeometry(QRect(150, 230, 114, 32));
        remove = new QPushButton(centralWidget);
        remove->setObjectName(QStringLiteral("remove"));
        remove->setGeometry(QRect(340, 230, 114, 32));
        trackLength = new QSlider(centralWidget);
        trackLength->setObjectName(QStringLiteral("trackLength"));
        trackLength->setGeometry(QRect(150, 360, 331, 22));
        trackLength->setOrientation(Qt::Horizontal);
        shuffle = new QPushButton(centralWidget);
        shuffle->setObjectName(QStringLiteral("shuffle"));
        shuffle->setGeometry(QRect(530, 290, 114, 32));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 754, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        play->setText(QApplication::translate("MainWindow", "play", 0));
        pause->setText(QApplication::translate("MainWindow", "pause", 0));
        next->setText(QApplication::translate("MainWindow", "next", 0));
        prev->setText(QApplication::translate("MainWindow", "prev", 0));
        stop->setText(QApplication::translate("MainWindow", "stop", 0));
        add->setText(QApplication::translate("MainWindow", "add", 0));
        remove->setText(QApplication::translate("MainWindow", "remove", 0));
        shuffle->setText(QApplication::translate("MainWindow", "shuffle", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
