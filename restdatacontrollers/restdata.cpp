#include "restdata.h"
#include "parsers/xml/requestpaser.h"
#include "network/applicationnetworkmanager.h"
#include "network/httprequestworker.h"
#include "restdatacontrollers/httpworkerpool.h"
#include <QDebug>

RestData::RestData(RequestWorkerPool * worker, bool _singleShot): m_workers(worker), enabled(true), m_singleShot(_singleShot)
{

}


RestData::~RestData()
{

}

DataRequest *RestData::getDefaultRequest() const
{
    return defaultRequest;
}

void RestData::setDefaultRequest(DataRequest *value)
{
    defaultRequest = value;
}

bool RestData::dispatchCyclicRequest()
{
   return dispatchRequest(defaultRequest);
}


bool RestData::dispatchRequest(DataRequest *value)
{
//    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__;
    if(enabled)
    {
        if(value && !value->getProcessing())
        {
//            m_workers->sendRequest(value);
            RequestWorker * tmp = m_workers->getWorker();//HttpWorkerPool::getWorker();//new HttpRequestWorker(request);
//            qDebug() << "WORKER" << tmp;
            connect(tmp, SIGNAL(workerDone(DataRequest *)), this, SLOT(workerDone(DataRequest *)));
            connect(tmp, SIGNAL(executionFinished(QByteArray)), this, SIGNAL(executionFinished(QByteArray)));
            tmp->setInputrequest(value);
            tmp->execute();
            return true;
        }
        else
        {
            qDebug() << __FILE__ << __LINE__ << "Request not sendt";
            return false;
        }
    }
    else
        return false;
}

void RestData::workerDone(DataRequest * req)
{
//    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__;
    req->setProcessing(false);
    if(req->getDeletable())
        delete req;
}

bool RestData::getSingleShot() const
{
    return m_singleShot;
}

void RestData::setSingleShot(bool singleShot)
{
    m_singleShot = singleShot;
}


bool RestDataItem::getUpdated() const
{
    return updated;
}

void RestDataItem::setUpdated(bool value)
{
    updated = value;
}
