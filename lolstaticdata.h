#ifndef LOLSTATICDATA_H
#define LOLSTATICDATA_H

#include <QString>

class LolStaticData
{
public:
    LolStaticData();

    QString cdn; //The base CDN url.
    QString css;  //string	Latest changed version of Dragon Magic's css file.
    QString	dd; //Latest changed version of Dragon Magic.
    QString	l;  //Default language for this realm.
    QString lg; //Legacy script mode for IE6 or older.
    QString n;  //		Latest changed version for each data type listed.
    int profileiconmax; //Special behavior number identifying the largest profileicon id that can be used under 500. Any profileicon that is requested between this number and 500 should be mapped to 0.
    QString store;	//	Additional api data drawn from other sources that may be related to data dragon functionality.
    QString v;	//	Current version of this file for this realm.
};

#endif // LOLSTATICDATA_H
