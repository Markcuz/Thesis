#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <string>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    shell = new QProcess(this);

    connect(shell, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

    connect(ui->pushButton, SIGNAL(clicked()),
                this, SLOT(onPushButtonClicked()));
    count=0;
}

MainWindow::~MainWindow()
{
    shell->write("exit()");
    shell->close();
    shell->terminate();
    delete ui;
}


void MainWindow::display(QString input) {

    QStringList list = input.split("\n");

    if(list.at(0).toInt() == 1) {
        ui->check1->setChecked(true);
    }
    else {
        ui->check1->setChecked(false);
    }

    if(list.at(1).toInt() == 1) {
        ui->check2->setChecked(true);
    }
    else {
        ui->check2->setChecked(false);
    }

    if(list.at(2).toInt() == 1) {
        ui->check3->setChecked(true);
    }
    else {
        ui->check3->setChecked(false);
    }

    if(list.at(3).toInt() == 1) {
        ui->check4->setChecked(true);
    }
    else {
        ui->check4->setChecked(false);
    }

    ui->outList->setText(input);

}

void MainWindow::onPushButtonClicked()
{

    QString program = "python3";

    QStringList arguments;
    arguments << "test.py";

    shell->start(program,arguments);

    if (!shell->waitForStarted())
        exit(1);

    qDebug() << "Shell error code:" << shell->error();
}

QString MainWindow::onReadyRead()
{
    QString text = shell->readAll();
    qDebug() << count;
    qDebug() << text;
    count++;
    display(text);
    return text;
}
