#include "httprequest.h"

#include <QDebug>

HttpRequest::HttpRequest()
    :
      method("GET"),
      path("/rest/hmi/interface"),
      timeout(2)
{

}

HttpRequest::~HttpRequest()
{

}

void HttpRequest::addQueryVariable(QString key, QString value)
{
    query.insert(key, value);
}

void HttpRequest::addQueryVariables(const QMap<QString, QString> &variables)
{
    query = variables;
}

QString HttpRequest::getMethod() const
{
    return method;
}

void HttpRequest::setMethod(const QString &value)
{
    method = value;
}

QMap<QString, QString> HttpRequest::getQuery() const
{
    return query;
}

void HttpRequest::setQuery(const QMap<QString, QString> &value)
{
    query = value;
}


QString HttpRequest::getPath() const
{
    return path;
}

void HttpRequest::setPath(const QString &value)
{
    path = value;
}

int HttpRequest::getTimeout() const
{
    return timeout;
}

void HttpRequest::setTimeout(int value)
{
    timeout = value;
}

QString HttpRequest::getData() const
{
    return data;
}

void HttpRequest::setData(const QString &value)
{
    data = value;
}

bool DataRequest::getProcessing() const
{
    return processing;
}

void DataRequest::setProcessing(bool value)
{
    processing = value;
}

bool DataRequest::getDeletable() const
{
    return deletable;
}

void DataRequest::setDeletable(bool value)
{
    deletable = value;
}

