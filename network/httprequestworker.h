#ifndef CHTTPREQUESTWORKER_H
#define CHTTPREQUESTWORKER_H

#include <QObject>
#include <QTimer>
#include <QtNetwork/QNetworkReply>
#include "requestworker.h"

class NetworkManager;
class HttpRequest;
class QAuthenticator;
class DataRequest;

class HttpRequestWorker : public RequestWorker
{
    Q_OBJECT

public:
    HttpRequestWorker(NetworkManager * manager = NULL, DataRequest *_request = NULL);
    ~HttpRequestWorker();

    void execute();

public slots:
    void done();

private slots:
    void finish();

private:
    QNetworkReply::NetworkError error_type;
    QString error_str;
    QNetworkRequest request;
    QNetworkReply * networkReply;
    static int instanceCounter;
};

#endif // CHTTPREQUESTWORKER_H
