#ifndef STATUSRESTDATA_H
#define STATUSRESTDATA_H

#include <QObject>
#include "restdata.h"

class HttpRequest;
class CommunicationManager;
class DataRequest;
class RequestWorker;
class RequestWorkerPool;

class StatusRestData : public RestData
{
    Q_OBJECT
public:
    StatusRestData(RequestWorkerPool* workers = NULL, DataRequest *_request = NULL);
    void initialize();
};

#endif // STATUSRESTDATA_H
