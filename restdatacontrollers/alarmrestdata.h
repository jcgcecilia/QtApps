#ifndef HTTPRESTDATACONTROLLER_H
#define HTTPRESTDATACONTROLLER_H

#include <QObject>
#include "restdata.h"
#include "network/httprequest.h"
#include "parsers/xml/alarmsxmlhandler.h"

class HttpRequest;
class CommunicationManager;
class DataRequest;
class RequestWorker;
class RequestWorkerPool;

class AlarmRestData : public RestData
{
    Q_OBJECT

public:
    AlarmRestData(RequestWorkerPool* workers = NULL, DataRequest *_request = NULL);
    ~AlarmRestData();
    void initialize();


public slots:
    void ackAlarm(int alarmId);
    void ackAlarm(QList<int> alarmIds);

};

#endif // HTTPRESTDATACONTROLLER_H
