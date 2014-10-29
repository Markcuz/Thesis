#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()),
                this, SLOT(onPushButtonClicked()));

    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(onPushButton2Clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onPushButton2Clicked() {
    imagePath = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "",
                tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" )
                );

    ui->textEdit->setText(imagePath);
}

void MainWindow::onPushButtonClicked() {
    //QString imagePath = ui->plainTextEdit->toPlainText();
    imageObject = new QImage();
    imageObject->load(imagePath);

    image = QPixmap::fromImage(*imageObject);

    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    ui->graphicsView->setScene(scene);

}
