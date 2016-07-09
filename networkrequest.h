#ifndef NETWORKREQUEST_H
#define NETWORKREQUEST_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <riotparser.h>
#include <lolstaticdata.h>
#include <champion.h>
#include <summoner.h>


class NetworkRequest : public QObject
{
    Q_OBJECT
public:
    QString Realm;
    LolStaticData staticData;

    explicit NetworkRequest(QObject *parent = 0);
    void getRequest(const QString &urlString);
    QJsonObject jsonObject;
    QVector<Champion> getChampionList(bool freeToPlay);
    Champion getChampionById(const QString id);
    Summoner getSummonerByName(const QString name);
    Summoner getSummonerByID(const int id);
    LolStaticData getLoLStaticData();
    QImage getSummonerProfileIconByID(long profileIconId);
    QImage getDownloadImage(const QString &urlString);
    void getMatchList(const int id);
private:

signals:

};

#endif // NETWORKREQUEST_H
