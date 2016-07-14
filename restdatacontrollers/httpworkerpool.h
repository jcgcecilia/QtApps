#ifndef WORKERPOOL_H
#define WORKERPOOL_H

#include <QList>
class HttpRequestWorker;
class RequestWorker;
class NetworkManager;
class ML300Application;
class DataRequest;

class RequestWorkerPool
{

public:
    RequestWorkerPool(ML300Application * serviceManager = NULL):m_servicesManager(serviceManager) {}
    virtual ~RequestWorkerPool(){}
    virtual void initialize(int number_of_workers) = 0;
    virtual RequestWorker * getWorker() = 0 ;
    ML300Application *getServicesManager() const;
    void setServicesManager(ML300Application *servicesManager);
    bool sendRequest(DataRequest * req);

protected:
    QList<RequestWorker *> workerPool;
    ML300Application * m_servicesManager;

};


class HttpWorkerPool : public RequestWorkerPool
{
public:
    HttpWorkerPool(ML300Application * serviceManager);
    ~HttpWorkerPool();
    virtual void initialize(int number_of_workers);
    virtual RequestWorker * getWorker();

private:
    NetworkManager * m_manager;

};

#endif // WORKERPOOL_H
