#ifndef CRESTDATACONTROLLER_H
#define CRESTDATACONTROLLER_H

#include <QObject>
#include <QVariant>
#include <QStringList>
#include "network/httprequest.h"


class RestDataItem
{

public:

    RestDataItem():updated(false){}
    virtual ~RestDataItem(){}

    bool getUpdated() const;
    void setUpdated(bool value);

private:
    bool updated;
};


class DataRequest;
class RequestWorkerPool;

class RestData : public QObject
{

    Q_OBJECT

public:

    RestData(RequestWorkerPool * workers = NULL, bool _singleShot = true);
    virtual ~RestData();
    virtual void initialize() = 0;
    DataRequest *getDefaultRequest() const;
    void setDefaultRequest(DataRequest *value);

    bool getSingleShot() const;
    void setSingleShot(bool singleShot);

public slots:
    virtual bool dispatchCyclicRequest();
    virtual bool dispatchRequest(DataRequest *value);
    void workerDone(DataRequest *);

signals:
    void executionFinished(QByteArray);

protected:
    RequestWorkerPool* m_workers;
    DataRequest * defaultRequest;
    bool enabled;
    bool m_singleShot;
};

#endif // CRESTDATACONTROLLER_H
