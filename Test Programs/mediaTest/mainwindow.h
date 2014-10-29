#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QProcess>
#include <QShortcut>
#include <QString>
#include <QFileDialog>
#include "media.h"

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

private slots:
    void init_ui();
    void play();
    void pause();
    void stop();
    void next();
    void prev();
    void add();
    void remove();
    void shuffle();
};

#endif // MAINWINDOW_H
