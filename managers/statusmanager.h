#ifndef STATUSMANAGER_H
#define STATUSMANAGER_H
#include "restdatacontrollers/statusobject.h"
#include "managerbase.h"
#include "restdatacontrollers/restdata.h"

class Status;

class StatusManager : public ManagerBase
{
    Q_OBJECT

public:
    StatusManager(XMLStreamDocumentHandler * handler = NULL);
    ~StatusManager();
    void init();

public slots:
    void data(RestDataItem * newData);
    void done();
    void start();

signals:
//    void updateStatusText(int statusTextId);

private:
    Status status;
    XMLStreamDocumentHandler * statusDataHandler;
    bool test;
};

#endif // STATUSMANAGER_H
