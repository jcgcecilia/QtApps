#ifndef CHTTPREQUESTINPUT_H
#define CHTTPREQUESTINPUT_H

#include <QObject>
#include <QMap>
#include "parsers/xml/requestpaser.h"
#include "restdatacontrollers/restdata.h"


class DataRequest
{
public:
    DataRequest():deletable(false), processing(false){}
    ~DataRequest(){}
    bool getProcessing() const;
    void setProcessing(bool value);
    bool getDeletable() const;
    void setDeletable(bool value);

private:
    bool deletable;
    bool processing;
};


class HttpRequest : public DataRequest
{
public:
    HttpRequest();
    ~HttpRequest();

    void addQueryVariable(QString key, QString value);
    void addQueryVariables(const QMap<QString, QString> & variables);

    QString getMethod() const;
    void setMethod(const QString &value);

    QMap<QString, QString> getQuery() const;
    void setQuery(const QMap<QString, QString> &value);

    QString getPath() const;
    void setPath(const QString &value);

    int getTimeout() const;
    void setTimeout(int value);

    QString getData() const;
    void setData(const QString &value);

private:
    QString method;
    QString path;
    int timeout;
    QString data;
    QMap<QString, QString> query;
};

#endif // CHTTPREQUESTINPUT_H
