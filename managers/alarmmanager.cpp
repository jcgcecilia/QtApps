#include "alarmmanager.h"
#include "restdatacontrollers/alarmobject.h"
#include "network/httprequest.h"
#include "restdatacontrollers/alarmobject.h"
#include "parsers/xml/alarmsxmlhandler.h"

AlarmManager::AlarmManager(XMLStreamDocumentHandler * handler): alarmDataHandler(handler), test(true)
{
    qRegisterMetaType<RestDataItem *>("RestDataItem");

}

AlarmManager::~AlarmManager()
{
}

void AlarmManager::init()
{
    if(alarmDataHandler)
    {
        QObject::connect(alarmDataHandler, SIGNAL(data(RestDataItem*)),
                         this, SLOT(data(RestDataItem*)));
        QObject::connect(alarmDataHandler, SIGNAL(parsingFinished()),
                         this, SLOT(done()));
        QObject::connect(alarmDataHandler, SIGNAL(parsingStarted()),
                         this, SLOT(start()));
    }
}

void AlarmManager::data(RestDataItem * newItem)
{
    if(test)
        alarmList.append(static_cast<Alarm *>(newItem));
}

void AlarmManager::done()
{
//    if(test)
//        test = false;
//    else
//        test = true;
    bool triggerPopup = false;
    int triggerAlarmId = -1;
    foreach (Alarm * alarm, alarmData) {
        alarm->setUpdated(false);
    }

    foreach (Alarm * alarm, alarmList)
    {
        if(!isAlarmInList(alarm->getId()))
        {
            alarmData.append(alarm);
            alarm->setUpdated(true);
            if(alarm->getState() == "UNACK")
            {
                alarm->setHasTriggeredPopUp(true);
                triggerPopup |= true;
                triggerAlarmId = alarm->getId();
                emit addGuiItem(alarm);
            }
        }
        else
        {
            updateAlarm(alarm);
            delete alarm;
        }
    }

    alarmList.clear();
    foreach (Alarm * alarm, alarmData)
    {
        if(!(alarm->getUpdated()))
        {
            emit removeGuiItem(alarm->getId());
            delete alarm;
            alarmData.removeOne(alarm);
        }
    }
    if(triggerPopup)
    {
        qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__;
        emit showPopup(triggerAlarmId);
    }
//    else
//        emit removePopup();
}

void AlarmManager::start()
{
}

bool AlarmManager::isAlarmInList(int alarmId)
{
    foreach (Alarm * alarm, alarmData)
    {
        if(alarm->getId() == alarmId)
        {
            return true;
        }
    }
    return false;
}

bool AlarmManager::isUnAckAlarm(int row, int *id)
{
    if(row >=0 && row < alarmData.size())
    {
        Alarm * alarm = alarmData.at(row);
        if(alarm->getState() == "UNACK" )
        {
            if(id)
                *id = alarm->getId();
            return true;
        }
        else
            return false;
    }
    return false;
}

bool AlarmManager::updateAlarm(Alarm *newAlarm)
{
    foreach (Alarm * alarm, alarmData)
    {
        if(alarm->getId() == newAlarm->getId())
        {
            alarm->setState(newAlarm->getState());
            alarm->setLatched(newAlarm->getLatched());
            alarm->setUpdated(true);
            return true;
        }
    }
    return false;
}

