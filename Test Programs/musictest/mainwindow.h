#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "media.h"
#include <QFileDialog>
#include <QStringList>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Media media;
    int tableIndex;

private slots:
    void addMedia();
    void setupTable();
    void removeAll();
    void removeMedia();
    void songName();

};

#endif // MAINWINDOW_H
