#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QJsonObject>
#include <QJsonArray>
#include <QVector>
#include <lolstaticdata.h>
#include <champion.h>
#include <summoner.h>
#include <matchlist.h>

class RIOTParser
{
public:
    RIOTParser();
    LolStaticData getLoLStaticData(QJsonObject jsonObject);
    Champion getChampion(QJsonObject jsonObject);
    QVector<Champion> getChampionList(QJsonObject jsonObject);
    Summoner getSummoner(QJsonObject jsonObject);


    QVector<MatchList::MatchReference> getMatchList(QJsonObject jsonOBject);
};

#endif // JSONPARSER_H
