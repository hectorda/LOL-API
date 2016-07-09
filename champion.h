#ifndef CHAMPION_H
#define CHAMPION_H

class Champion
{
public:
    Champion();
    Champion(int id,bool botMmEnabled,bool rankedPlayEnabled,bool botEnabled,bool active,bool freeToPlay);
    int id;
    bool botMmEnabled;
    bool rankedPlayEnabled;
    bool botEnabled;
    bool active;
    bool freeToPlay;
};

#endif // CHAMPION_H
