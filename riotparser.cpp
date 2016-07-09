#include "riotparser.h"
#include <QDebug>

RIOTParser::RIOTParser()
{

}

LolStaticData RIOTParser::getLoLStaticData(QJsonObject jsonObject)
{
    LolStaticData staticData;
    staticData.cdn=jsonObject["cdn"].toString();
    staticData.css=jsonObject["css"].toString();
    staticData.dd=jsonObject["dd"].toString();
    staticData.l=jsonObject["l"].toString();
    staticData.lg=jsonObject["lg"].toString();
    staticData.n=jsonObject["n"].toString();
    staticData.profileiconmax=jsonObject["profileiconmax"].toInt();
    staticData.store=jsonObject["store"].toString();
    staticData.v=jsonObject["v"].toString();
    return staticData;

}

Champion RIOTParser::getChampion(QJsonObject jsonObject){

    Champion campeon;
    campeon.id=jsonObject["id"].toInt();
    campeon.active=jsonObject["active"].toBool();
    campeon.botMmEnabled=jsonObject["botMmEnabled"].toBool();
    campeon.rankedPlayEnabled=jsonObject["rankedPlayEnabled"].toBool();
    campeon.botEnabled=jsonObject["botEnabled"].toBool();
    campeon.freeToPlay=jsonObject["freeToPlay"].toBool();
    return campeon;
}


QVector<Champion> RIOTParser::getChampionList(QJsonObject jsonObject){
    QVector<Champion> Campeones;
    QJsonArray jsonArray = jsonObject["champions"].toArray();
    foreach (const QJsonValue & value, jsonArray) {
        QJsonObject obj = value.toObject();
        Campeones.append(this->getChampion(obj));
    }
    return Campeones;
}

Summoner RIOTParser::getSummoner(QJsonObject jsonObject)
{
    Summoner invocador;
    invocador.id=jsonObject["id"].toDouble();
    invocador.name=jsonObject["name"].toString();
    invocador.profileIconId=jsonObject["profileIconId"].toDouble();
    invocador.revisionDate=jsonObject["revisionDate"].toDouble();
    invocador.summonerLevel=jsonObject["summonerLevel"].toDouble();
    return invocador;
}

QVector<MatchList::MatchReference> RIOTParser::getMatchList(QJsonObject jsonOBject)
{
    QVector<MatchList::MatchReference> matchList;
    QJsonArray jsonArray = jsonOBject["matches"].toArray();
    foreach (const QJsonValue & value, jsonArray) {
        QJsonObject obj = value.toObject();
        MatchList::MatchReference matchReference;
        matchReference.champion=obj["champion"].toInt();
        matchReference.lane=obj["lane"].toString();
        matchReference.matchId=obj["matchId"].toVariant().toLongLong();
        matchReference.platformId=obj["platformId"].toString();
        matchReference.queue=obj["queue"].toString();
        matchReference.region=obj["region"].toString();
        matchReference.role=obj["role"].toString();
        matchReference.season=obj["season"].toString();
        matchReference.timestamp=obj["timestamp"].toDouble();
        matchList.append(matchReference);
    }
    return matchList;
}





