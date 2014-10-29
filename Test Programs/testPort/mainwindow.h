#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>

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
    QProcess *shell;
    QString outputs;
    int count;

private slots:
    QString onReadyRead();
    void onPushButtonClicked();
    void display(QString input);

};
#endif // MAINWINDOW_H
