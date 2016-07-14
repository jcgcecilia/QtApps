#ifndef CHTTPREQUESTWORKER_HH
#define CHTTPREQUESTWORKER_HH

#include <QObject>
#include <QNetworkAccessManager>

class HttpRequest;
class DataRequest;

class CommunicationManager : public QObject
{
    Q_OBJECT

public:
    CommunicationManager(QObject * parent = NULL){Q_UNUSED(parent)}
    ~CommunicationManager(){}

    virtual bool sendRequest(DataRequest * request) = 0;
public slots:
    virtual bool requestDone() = 0;
};


class NetworkManager : public QNetworkAccessManager
{
    Q_OBJECT

public:
    NetworkManager(QObject *parent = 0);
    ~NetworkManager();

    QString getUsername() const;
    void setUsername(const QString &value);

    QString getPassword() const;
    void setPassword(const QString &value);

    QString getHost() const;
    void setHost(const QString &value);

    int getPort() const;
    void setPort(int value);

//    bool sendRequest(DataRequest * request);

//public slots:
//    bool requestDone();

    QString getType() const;
    void setType(const QString &value);

    QString getScheme() const;
    void setScheme(const QString &value);

private:
    QString username;
    QString password;
    QString host;
    int port;
    QString type;
    QString scheme;

};

#endif // CHTTPREQUESTWORKER_HH
