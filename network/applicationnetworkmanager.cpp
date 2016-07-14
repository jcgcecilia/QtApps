#include "applicationnetworkmanager.h"
#include "httprequest.h"
#include "httprequestworker.h"

NetworkManager::NetworkManager(QObject * )
    :username("DISPLAY"),
     password("Spiderman"),
     host("10.10.103.1"),
     port(80),
     type("xml"),
     scheme("http")
{
}

NetworkManager::~NetworkManager()
{

}

QString NetworkManager::getUsername() const
{
    return username;
}

void NetworkManager::setUsername(const QString &value)
{
    username = value;
}
QString NetworkManager::getPassword() const
{
    return password;
}

void NetworkManager::setPassword(const QString &value)
{
    password = value;
}
QString NetworkManager::getHost() const
{
    return host;
}

void NetworkManager::setHost(const QString &value)
{
    host = value;
}

int NetworkManager::getPort() const
{
    return port;
}

void NetworkManager::setPort(int value)
{
    port = value;
}

QString NetworkManager::getType() const
{
    return type;
}

void NetworkManager::setType(const QString &value)
{
    type = value;
}

QString NetworkManager::getScheme() const
{
    return scheme;
}

void NetworkManager::setScheme(const QString &value)
{
    scheme = value;
}


//bool NetworkManager::sendRequest(DataRequest *request)
//{
//    // Post request are sent regardless if a previous request is alredy been sent
//    HttpRequest * httprequest = static_cast<HttpRequest *>(request);

//    HttpRequestWorker * tmp;
//    if(httprequest->getMethod() == "POST")
//    {
//        tmp = new HttpRequestWorker(this, httprequest);
//        QObject::connect(tmp, SIGNAL(executionFinished()), this, SLOT(requestDone()));
//    }

//    // Only one get request is allow to be active
//    if(!httprequest->getProcessing())
//    {
//        tmp = new HttpRequestWorker(this, httprequest);
//        QObject::connect(tmp, SIGNAL(executionFinished()), this, SLOT(requestDone()));
//    }
//    return false;
//}

//bool NetworkManager::requestDone()
//{
//    return true;
//}
//QNetworkAccessManager *NetworkManager::getManager() const
//{
//    return manager;
//}

//void NetworkManager::setManager(QNetworkAccessManager *value)
//{
//    manager = value;
//}










