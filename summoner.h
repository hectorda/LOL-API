#ifndef SUMMONER_H
#define SUMMONER_H

#include <QString>

class Summoner
{
public:
    Summoner();
    long id; //Summoner ID.
    QString name; //Summoner name.
    long profileIconId; //ID of the summoner icon associated with the summoner.
    long revisionDate;   //Date summoner was last modified specified as epoch milliseconds. The following events will update this timestamp: profile icon change, playing the tutorial or advanced tutorial, finishing a game, summoner name change
    long summonerLevel;  //long	Summoner level associated with the summoner.
};

#endif // SUMMONER_H
