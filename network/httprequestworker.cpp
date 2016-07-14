#include <QEventLoop>
//#include <QAuthenticator>

#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
#include <QUrlQuery>
#include <QtConcurrent/QtConcurrentRun>
#else
#include <QtConcurrentRun>
#include <QUrl>
#endif

#include "httprequestworker.h"
#include "network/httprequest.h"
#include "applicationnetworkmanager.h"
#include "application/application.h"

#include <QDebug>

int HttpRequestWorker::instanceCounter = 0;

HttpRequestWorker::HttpRequestWorker(NetworkManager *manager, DataRequest *_request)
    : RequestWorker(_request, manager)
{
    instanceCounter++;
}

HttpRequestWorker::~HttpRequestWorker()
{
    instanceCounter--;
}

void HttpRequestWorker::execute()
{
    this->setIsBeingUsed(true);
    NetworkManager * manager = m_manager;//ML300Application::getNetworkManager();
    HttpRequest * dataRequest = static_cast<HttpRequest *>(inputrequest);
    dataRequest->setProcessing(true);
    data = "";
    error_type = QNetworkReply::NoError;
    error_str = "";

    QUrl url;

    url.setPath(dataRequest->getPath());
    url.setScheme(manager->getScheme());
    url.setHost(manager->getHost());
    url.setPort(manager->getPort());
    url.setUserInfo(manager->getUsername() + ':' + manager->getPassword());

#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
    QUrlQuery query;
    foreach(QString key, dataRequest->getQuery().keys())
    {
        query.addQueryItem(key, dataRequest->getQuery()[key]);
    }
    url.setQuery(query);
#else
    foreach(QString key, dataRequest->getQuery().keys())
    {
        url.addQueryItem(key, dataRequest->getQuery()[key]);
    }
#endif

    url = QUrl::fromPercentEncoding(url.toString().toLocal8Bit());

//    qDebug() << url;
    QString concatenated = manager->getUsername() + ":" + manager->getPassword();
    //    QString concatenated = " : ";
    QByteArray data_ = concatenated.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data_;

    request.setUrl(url);
    request.setRawHeader("Accept", QString("application/" + manager->getType()).toLocal8Bit());
    request.setRawHeader("Accept-Charset", "utf-8");
    request.setRawHeader("Content-Type", QString("application/" + manager->getType()).toLocal8Bit());
    request.setRawHeader("Authorization", headerData.toLocal8Bit());

    if(dataRequest->getMethod() == "GET")
    {
        networkReply = manager->get(request);
    }
    else if (dataRequest->getMethod() == "POST")
    {
        networkReply = manager->post(request, dataRequest->getData().toLatin1());
    }

    connect(networkReply, SIGNAL(finished()), this, SLOT(finish()));
    setTimeout(dataRequest->getTimeout());
}

void HttpRequestWorker::done()
{
//    if(inputrequest->getDeletable())
//        delete inputrequest;

    emit workerDone(inputrequest);
    if(networkReply)
     networkReply->deleteLater();
    this->disconnect();

    if(!isDeletable())
    {
        this->setIsBeingUsed(false);
    }
    else
    {
        this->deleteLater();
    }

//    emit executionFinished("");
}

void HttpRequestWorker::finish()
{
    if(timer.isActive())
    {
        timer.stop();
        if(networkReply->error() > 0)
        {
            // handle error
            error_str = networkReply->errorString();
            qDebug()<<error_str;
        }
        else
        {
            error_type = networkReply->error();
            if (error_type == QNetworkReply::NoError)
            {
//                qDebug()<< networkReply->readAll();
                emit executionFinished(networkReply->readAll());
            }
            else {
                error_str = networkReply->errorString();
                qDebug()<<error_str;
            }
        }
    }
    else
    {
        if(networkReply)
        {
            disconnect(networkReply, SIGNAL(finished()), this, SLOT(finish()));
            networkReply->abort();
        }
    }
    done();
}

