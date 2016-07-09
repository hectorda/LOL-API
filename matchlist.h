#ifndef MATCHLIST_H
#define MATCHLIST_H

#include <QString>

class MatchList
{
public:
    struct MatchReference{
        long champion;
        QString lane;//Legal values: MID, MIDDLE, TOP, JUNGLE, BOT, BOTTOM
        long matchId;
        QString platformId;
        QString queue;	//Legal values: TEAM_BUILDER_DRAFT_RANKED_5x5, RANKED_SOLO_5x5, RANKED_TEAM_3x3, RANKED_TEAM_5x5
        QString region;
        QString role; //	Legal values: DUO, NONE, SOLO, DUO_CARRY, DUO_SUPPORT
        QString season; //	Legal values: PRESEASON3, SEASON3, PRESEASON2014, SEASON2014, PRESEASON2015, SEASON2015, PRESEASON2016, SEASON2016
        long timestamp;
    };
    MatchList();
    int endIndex;
    /*List*/ int matches	;//[MatchReference]
    int startIndex;
    int totalGames;

};

#endif // MATCHLIST_H
