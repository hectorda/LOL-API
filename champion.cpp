#include "champion.h"
Champion::Champion()
{

}

Champion::Champion(int id, bool botMmEnabled, bool rankedPlayEnabled, bool botEnabled, bool active, bool freeToPlay)
{
    this->id=id;
    this->botMmEnabled=botMmEnabled;
    this->rankedPlayEnabled=rankedPlayEnabled;
    this->botEnabled=botEnabled;
    this->active=active;
    this->freeToPlay=freeToPlay;
}




