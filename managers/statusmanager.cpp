#include "statusmanager.h"

#include <QDebug>
StatusManager::StatusManager(XMLStreamDocumentHandler *handler): statusDataHandler(handler), test(true)
{
    qRegisterMetaType<RestDataItem *>("RestDataItem");
    //    if(statusDataHandler)
    //    {
    //        QObject::connect(statusDataHandler, SIGNAL(data(RestDataItem*)),
    //                         this, SLOT(data(RestDataItem*)));
    //        QObject::connect(statusDataHandler, SIGNAL(parsingFinished()),
    //                         this, SLOT(done()));
    //        QObject::connect(statusDataHandler, SIGNAL(parsingStarted()),
    //                         this, SLOT(start()));
    //    }
}

StatusManager::~StatusManager()
{

}

void StatusManager::init()
{
    if(statusDataHandler)
    {
        QObject::connect(statusDataHandler, SIGNAL(data(RestDataItem*)),
                         this, SLOT(data(RestDataItem*)));
        QObject::connect(statusDataHandler, SIGNAL(parsingFinished()),
                         this, SLOT(done()));
        QObject::connect(statusDataHandler, SIGNAL(parsingStarted()),
                         this, SLOT(start()));
    }
}

void StatusManager::data(RestDataItem *newData)
{
    Status tmp;
    tmp = *(static_cast<Status *>(newData));
    if(status.getStatusText().getNameTextId() != tmp.getStatusText().getNameTextId())
    {
        emit updateStatusText(tmp.getStatusText().getNameTextId());
    }
    status = tmp;
}

void StatusManager::done()
{
//    qDebug() << __FILE__ << __LINE__;
}

void StatusManager::start()
{
//    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__;
}



