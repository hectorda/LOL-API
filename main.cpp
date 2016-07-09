#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //QString API_KEY("api_key=RGAPI-021E0305-80DE-4238-AD1C-E4473F06A4CA");
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
