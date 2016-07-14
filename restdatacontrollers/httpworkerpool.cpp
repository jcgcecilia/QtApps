#include "httpworkerpool.h"
#include "network/httprequestworker.h"

//QList<HttpRequestWorker *> HttpWorkerPool::workerPool;
#include "application/application.h"

HttpWorkerPool::HttpWorkerPool(ML300Application *serviceManager): RequestWorkerPool(serviceManager)
{
}

HttpWorkerPool::~HttpWorkerPool()
{

}

void HttpWorkerPool::initialize(int number_of_workers)
{
    for(int i = 0; i < number_of_workers; i++)
    {
        workerPool.append(new HttpRequestWorker(m_servicesManager->getNetworkManager()));
    }
}

RequestWorker *HttpWorkerPool::getWorker()
{
    QList<RequestWorker *>::iterator i;
    for(i = workerPool.begin();  i != workerPool.end(); ++i)
    {
        if(!(*i)->isBeingUsed())
        {
            (*i)->setIsBeingUsed(true);
            return (*i);
        }
    }
    // ALl Workers are being used so we create a new instance and
    // set it as deletable
    RequestWorker * tmp = new HttpRequestWorker(m_servicesManager->getNetworkManager());
    tmp->setIsDeletable(true);
    return tmp;
}


ML300Application *RequestWorkerPool::getServicesManager() const
{
    return m_servicesManager;
}

void RequestWorkerPool::setServicesManager(ML300Application *servicesManager)
{
    m_servicesManager = servicesManager;
}

bool RequestWorkerPool::sendRequest(DataRequest * req)
{
    RequestWorker * tmp = getWorker();//HttpWorkerPool::getWorker();//new HttpRequestWorker(request);
    tmp->setInputrequest(req);
    tmp->setIsBeingUsed(true);
    tmp->execute();
    return true;

}
