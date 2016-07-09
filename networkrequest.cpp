#include "networkrequest.h"

#include <QEventLoop>
#include <QImage>

const QString BASE_URL = "https://las.api.pvp.net/api/lol/";
const QString BASE_STATIC_URL = "https://global.api.pvp.net/api/lol/static-data/";
const QString CHAMPION_API_VERSION = "/v1.2/";
const QString GAME_API_VERSION = "/v1.3/";
const QString LEAGUE_API_VERSION = "/v2.3/";
const QString STATIC_API_VERSION = "/v1.2/";
const QString STATS_API_VERSION = "/v1.2/";
const QString SUMMONER_API_VERSION = "/v1.4/";
const QString TEAM_API_VERSION = "/v2.2/";
const QString MATCHLIST_API_VERSION = "/v2.2/";

const QString API_KEY = "RGAPI-021E0305-80DE-4238-AD1C-E4473F06A4CA";

NetworkRequest::NetworkRequest(QObject *parent): QObject(parent)
{

}

void NetworkRequest::getRequest(const QString &urlString)
{
    QUrl url (urlString);
    QNetworkAccessManager NAManager;
    QNetworkRequest request(url);
    QNetworkReply *reply = NAManager.get(request);
    QEventLoop eventLoop;

    QObject::connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));

    eventLoop.exec();
    QObject::disconnect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    if (reply->error() == QNetworkReply::NoError) {

        QString strReply = (QString)reply->readAll();

        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
        jsonObject = jsonResponse.object();
        qDebug()<<jsonObject;
        delete reply;
    }
    else {
        //failure
        qDebug() << "Failure" <<reply->errorString();
        delete reply;
    }
}

QImage NetworkRequest::getDownloadImage(const QString &urlString)
{
    QUrl url (urlString);
    QNetworkAccessManager NAManager;
    QNetworkRequest request(url);
    QNetworkReply *reply = NAManager.get(request);
    QEventLoop eventLoop;

    QObject::connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));

    eventLoop.exec();
    QImage img2;
    QObject::disconnect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    if (reply->error() == QNetworkReply::NoError) {

        img2.loadFromData(reply->readAll());
        delete reply;
    }
    else {
        //failure
        qDebug() << "Failure" <<reply->errorString();
        delete reply;
    }
    return img2;
}







//------------------------------Champion API-----------------//
QVector<Champion> NetworkRequest::getChampionList(bool freeToPlay)
{
    QString url = BASE_URL
                    + Realm
                    + CHAMPION_API_VERSION
                    + "champion"
                    + "?freeToPlay=" + (freeToPlay ? "true" : "false")
                    + "&api_key=" + API_KEY;

    this->getRequest(url);
    RIOTParser parser;


    return parser.getChampionList(this->jsonObject);
}

Champion NetworkRequest::getChampionById(const QString id)
{
    QString url = BASE_URL
                + Realm
                + CHAMPION_API_VERSION
                + "champion"
                + "/"+id+
                + "?api_key=" + API_KEY;
    qDebug()<<url;
    this->getRequest(url);

    RIOTParser parser;

    return parser.getChampion(this->jsonObject);
}

/*-------------------Summoner API----------------------------*/
Summoner NetworkRequest::getSummonerByName(const QString name)
{
    QString url = BASE_URL
                + Realm
                + SUMMONER_API_VERSION
                + "summoner/by-name/"
                + name
                + "?api_key=" + API_KEY;
    qDebug()<<url;
    this->getRequest(url);
    RIOTParser parser;
    const QJsonObject sumonerJson=this->jsonObject[name].toObject();
    return parser.getSummoner(sumonerJson);
}

Summoner NetworkRequest::getSummonerByID(const int id)
{
    QString url = BASE_URL
                + Realm
                + SUMMONER_API_VERSION
                + "summoner/"
                + QString::number(id)
                + "?api_key=" + API_KEY;
    qDebug()<<url;
    this->getRequest(url);
    RIOTParser parser;
    return parser.getSummoner(this->jsonObject);
}

/*------------------------------------------------------*/
LolStaticData NetworkRequest::getLoLStaticData()
{
    QString url = BASE_STATIC_URL
            + Realm
            + STATIC_API_VERSION
            + "realm"
            + "?api_key=" + API_KEY;
    this->getRequest(url);
    RIOTParser parser;
    return parser.getLoLStaticData(this->jsonObject);
}

QImage NetworkRequest::getSummonerProfileIconByID(long profileIconId)
{
    QString url = staticData.cdn
            + "/"
            + staticData.dd
            + "/img/profileicon/"
            + QString::number(profileIconId)
            + ".png";
    return this->getDownloadImage(url);
}

/*----MatchList-----*/
void NetworkRequest::getMatchList(const int id)
{
    QString season="";
    QString url = BASE_URL
            + Realm
            + MATCHLIST_API_VERSION
            + "matchlist/by-summoner/"
            + QString::number(id)
            +"?seasons="
            + season
            + "&api_key="
            + API_KEY;

    this->getRequest(url);
    RIOTParser parser;
    QVector<MatchList::MatchReference> matches=parser.getMatchList(this->jsonObject);
    foreach (MatchList::MatchReference m,matches) {
        qDebug()<<m.matchId;
    }

    ///api/lol/{region}/v2.2/matchlist/by-summoner/{summonerId}
}


