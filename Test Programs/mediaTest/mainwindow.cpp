#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //init_ui();
}

/*
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init_ui() {
    media.init();
    qDebug() << "initialising";

    connect(ui->play,SIGNAL(clicked()), this, SLOT(play()));
    connect(ui->pause,SIGNAL(clicked()), this, SLOT(pause()));
    connect(ui->stop,SIGNAL(clicked()), this, SLOT(stop()));
    connect(ui->next,SIGNAL(clicked()), this, SLOT(next()));
    connect(ui->prev,SIGNAL(clicked()), this, SLOT(prev()));
    connect(ui->add,SIGNAL(clicked()),this, SLOT(add()));
    connect(ui->shuffle, SIGNAL(clicked()),this, SLOT(shuffle()));
    connect(ui->remove, SIGNAL(clicked()), this, SLOT(remove()));

    qDebug() << "completed init";
}


void MainWindow::play() {
    media.play();
    qDebug() << "played";
}

void MainWindow::pause() {
    media.pause();
}
void MainWindow::stop() {
    media.stop();
}

void MainWindow::next() {
    media.next();
}
void MainWindow::prev() {
    media.prev();
}

void MainWindow::add() {
    QString songPath;
    songPath = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "",
                tr("MP3 (*.mp3);; WAV (*.wav)" )
                );
    media.add(songPath);
}

void MainWindow::remove() {
    media.remove();
}

void MainWindow::shuffle() {
    media.shuffle();
}
*/
/*
void MainWindow::setupTable() {
    QMediaPlaylist playlist= media.mediaList();

    ui->tableWidget->setRowCount(playlist.mediaCount());
    ui->tableWidget->setColumnCount(3);

    for(int i=0; i<playlist.mediaCount(); i++) {
        //setup Song

    }
}
*/


