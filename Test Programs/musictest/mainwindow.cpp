#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    media.init();
    setupTable();

    connect(ui->add, SIGNAL(clicked()), this, SLOT(addMedia()));
    connect(ui->play, SIGNAL(clicked()), &media, SLOT(play()));
    connect(ui->pause, SIGNAL(clicked()), &media, SLOT(pause()));
    connect(ui->stop, SIGNAL(clicked()), &media, SLOT(stop()));
    connect(ui->next, SIGNAL(clicked()), &media, SLOT(next()));
    connect(ui->prev, SIGNAL(clicked()), &media, SLOT(prev()));
    connect(ui->remove, SIGNAL(clicked()), this, SLOT(removeMedia()));
    connect(ui->removeAll, SIGNAL(clicked()), this, SLOT(removeAll()));
    connect(&media, SIGNAL(songChanged()), this, SLOT(songName()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::songName() {
    ui->textBrowser->setText(media.songName);
}

void MainWindow::setupTable() {
    QStringList list = media.mediaList();

    while(ui->tableWidget->rowCount() != 0) {
        ui->tableWidget->removeRow(0);
    }

    qDebug() << list.size();

    tableIndex = 0;
    while(tableIndex<list.size()) {
        ui->tableWidget->insertRow(tableIndex);
        qDebug() <<list.at(tableIndex);
        ui->tableWidget->setItem(tableIndex,0,new QTableWidgetItem(list.at(tableIndex)));
        tableIndex++;
    }
}

void MainWindow::removeAll() {
    media.removeAll();
    tableIndex = 0;
    setupTable();
}

void MainWindow::addMedia() {
    QString songPath;
    songPath = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "",
                tr("MP3 (*.mp3);; WAV (*.wav)" )
                );
    media.add(songPath);

    setupTable();
}

void MainWindow::removeMedia() {
    media.remove(ui->tableWidget->currentRow());
    setupTable();
}
