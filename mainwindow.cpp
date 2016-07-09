#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include <QDebug>
#include <QJsonObject>
#include <champion.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    net=new NetworkRequest(this);
    QStringList regions;
    regions<<"BR"<<"EUNE"<<"EUW"<<"JP"<<"KR"<<"LAN"<<"LAS"<<"NA"<<"OCE"<<"RU"<<"TR";
    foreach (QString region, regions) {
        ui->comboBoxServer->addItem(region);
    }
    connect(ui->comboBoxServer,SIGNAL(currentIndexChanged(QString)),this,SLOT(getLoLStaticData()));
    ui->comboBoxServer->setCurrentIndex(6);
    ui->lineEditIdCampeon->setValidator(new QIntValidator(0,200));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    net->Realm=ui->comboBoxServer->currentText().toLower();
    QVector<Champion> Campeones=net->getChampionList(false);
    QString texto;

    ui->comboBoxCampeones->clear();
    foreach (Champion campeon, Campeones){
        texto.append("Id:"+QString::number(campeon.id)+" Active: "+QString::number(campeon.active)+"\n");
        ui->comboBoxCampeones->addItem(QString::number(campeon.id));
    }
    ui->textEditResult->setText(texto);
}

void MainWindow::on_pushButtonGetCampeonByID_clicked()
{
    net->Realm=ui->comboBoxServer->currentText().toLower();
    Champion ca=net->getChampionById(ui->lineEditIdCampeon->text());
    QString texto= "Id:"+QString::number(ca.id)+" Active: "+QString::number(ca.active);
    ui->textEditResult->setText(texto);
}

void MainWindow::on_pushButtonSearchSummoner_clicked()
{
    net->Realm=ui->comboBoxServer->currentText().toLower();
    const QString summonerName=ui->lineEditSummonerName->text().toLower().remove(" ");
    Summoner invocador=net->getSummonerByName(summonerName);
    QString texto="ID invocador: "+QString::number(invocador.id)+" Nombre: "+invocador.name+" Nivel: "+QString::number(invocador.summonerLevel);
    ui->textEditResult->setText(texto);
    QImage imagen=net->getSummonerProfileIconByID(invocador.profileIconId);
    //ui->textEditResult->textCursor().insertImage(imagen);
    ui->labelSumonerImage->setPixmap(QPixmap::fromImage(imagen));
    net->getMatchList(invocador.id);

}

void MainWindow::getLoLStaticData()
{
    net->Realm=ui->comboBoxServer->currentText().toLower();
    LolStaticData staticData=net->getLoLStaticData();
    net->staticData=staticData;
    QString texto="Version: "+staticData.v;
    ui->textEditResult->setText(texto);
}


