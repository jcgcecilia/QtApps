#ifndef ALARMMANAGER_H
#define ALARMMANAGER_H

#include <QObject>
#include "managerbase.h"
#include "network/httprequest.h"
#include "restdatacontrollers/alarmrestdata.h"
//class HttpRequest;
#include "application/application.h"
#include "mvc/customtablemodel.h"


class XMLStreamDocumentHandler;
class Alarm;

class AlarmManager  : public ManagerBase
{

    Q_OBJECT

public:
    AlarmManager(XMLStreamDocumentHandler * handler = NULL);
    ~AlarmManager();
    void init();
    bool isAlarmInList(int alarmId);
    bool isUnAckAlarm(int row, int *id);
    bool updateAlarm(Alarm * newAlarm);

public slots:

    virtual void data(RestDataItem * newItem);
    void done();
    void start();

protected:
    XMLStreamDocumentHandler * alarmDataHandler;
    QList<Alarm *> alarmList;
    QList<Alarm *> alarmData;
    bool test;
};

#endif // ALARMMANAGER_H
