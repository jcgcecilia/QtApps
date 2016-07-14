#include "requestworker.h"
#include "network/httprequest.h"
#include <QDebug>

RequestWorker::RequestWorker(DataRequest *_request, NetworkManager *manager)
    : inputrequest(_request), mIsBeingUsed(false), mIsDeletable(false), m_manager(manager)
{
    qRegisterMetaType<DataRequest *>("DataRequest");
}

RequestWorker::~RequestWorker()
{

}
QByteArray RequestWorker::getData() const
{
    return data;
}

void RequestWorker::setData(const QByteArray &value)
{
    data = value;
}


void RequestWorker::setTimeout(int timeout_)
{
    if(timeout_ > 0)
    {
        timer.setSingleShot(true);
        connect(&timer, SIGNAL(timeout()), this, SLOT(finish()));
        timer.start(timeout_*1000);   // 30 secs. timeout
    }
}
DataRequest *RequestWorker::getInputrequest() const
{
    return inputrequest;
}

void RequestWorker::setInputrequest(DataRequest *value)
{
    inputrequest = value;
}

bool RequestWorker::isBeingUsed() const
{
    return mIsBeingUsed;
}

void RequestWorker::setIsBeingUsed(bool isBeingUsed)
{
    mIsBeingUsed = isBeingUsed;
}
bool RequestWorker::isDeletable() const
{
    return mIsDeletable;
}

void RequestWorker::setIsDeletable(bool isDeletable)
{
    mIsDeletable = isDeletable;
}







