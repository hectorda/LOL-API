#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <networkrequest.h>
#include <lolstaticdata.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void getLoLStaticData();
    void on_pushButton_clicked();
    void on_pushButtonGetCampeonByID_clicked();

    void on_pushButtonSearchSummoner_clicked();

private:
    Ui::MainWindow *ui;
    NetworkRequest *net;

};

#endif // MAINWINDOW_H
