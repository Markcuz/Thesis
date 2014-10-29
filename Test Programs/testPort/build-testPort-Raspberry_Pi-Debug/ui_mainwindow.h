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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QCheckBox *check1;
    QCheckBox *check2;
    QCheckBox *check3;
    QCheckBox *check4;
    QLabel *label;
    QLabel *outList;
    QPushButton *pressLights;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(630, 501);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(350, 30, 114, 32));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 80, 114, 32));
        check1 = new QCheckBox(centralWidget);
        check1->setObjectName(QStringLiteral("check1"));
        check1->setGeometry(QRect(40, 60, 87, 20));
        check2 = new QCheckBox(centralWidget);
        check2->setObjectName(QStringLiteral("check2"));
        check2->setGeometry(QRect(40, 100, 87, 20));
        check3 = new QCheckBox(centralWidget);
        check3->setObjectName(QStringLiteral("check3"));
        check3->setGeometry(QRect(40, 140, 87, 20));
        check4 = new QCheckBox(centralWidget);
        check4->setObjectName(QStringLiteral("check4"));
        check4->setGeometry(QRect(40, 180, 87, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 150, 81, 21));
        outList = new QLabel(centralWidget);
        outList->setObjectName(QStringLiteral("outList"));
        outList->setGeometry(QRect(320, 180, 141, 151));
        pressLights = new QPushButton(centralWidget);
        pressLights->setObjectName(QStringLiteral("pressLights"));
        pressLights->setGeometry(QRect(50, 260, 114, 32));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 310, 62, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 310, 62, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 630, 22));
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
        pushButton->setText(QApplication::translate("MainWindow", "Start Test", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Display", 0));
        check1->setText(QApplication::translate("MainWindow", "Input 1", 0));
        check2->setText(QApplication::translate("MainWindow", "input2", 0));
        check3->setText(QApplication::translate("MainWindow", "input3", 0));
        check4->setText(QApplication::translate("MainWindow", "input4", 0));
        label->setText(QApplication::translate("MainWindow", "Raw Array", 0));
        outList->setText(QApplication::translate("MainWindow", "--", 0));
        pressLights->setText(QApplication::translate("MainWindow", "Press Lights", 0));
        label_2->setText(QApplication::translate("MainWindow", "--", 0));
        label_3->setText(QApplication::translate("MainWindow", "--", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
