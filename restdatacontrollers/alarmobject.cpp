#include "alarmobject.h"
#include "network/applicationnetworkmanager.h"
#include "network/httprequest.h"
#include <QDebug>

/*
 * ALARM
 *
 */

int Alarm::alarmCounter = 0;
Alarm::Alarm():
    RestDataItem(),
    id(-1),
    nameTextId(-1),
    unitTextId(-1),
    customTextId(-1),
    precision(-1),
    utcTime(-1),
    utcTimeMs(-1),
    actionValue(-1),
    latched(false),
    autoAck(false),
    triggerValue(-1.0),
    setPointValue(-1.0),
    prettyName(""),
    state(""),
    triggerImage(""),
    hasTriggeredPopUp(false)
{
}

//Alarm::Alarm(int _id)
//{
//    setId(_id);
//}

Alarm::~Alarm()
{
    alarmCounter--;
//    qDebug() << __PRETTY_FUNCTION__ << "Deleting alarm"<< this << alarmCounter;
    foreach(Param * param, params)
    {
        delete param;
    }
}

Alarm *Alarm::clone()
{
    alarmCounter++;
//    qDebug() << __PRETTY_FUNCTION__ << "Creating alarm" << alarmCounter;
    return new Alarm(*this);
}

int Alarm::getId() const
{
    return id;
}

void Alarm::setId(int value)
{
    id = value;
}

int Alarm::getNameTextId() const
{
    return nameTextId;
}

void Alarm::setNameTextId(int value)
{
    nameTextId = value;
}

int Alarm::getUnitTextId() const
{
    return unitTextId;
}

void Alarm::setUnitTextId(int value)
{
    unitTextId = value;
}

int Alarm::getCustomTextId() const
{
    return customTextId;
}

void Alarm::setCustomTextId(int value)
{
    customTextId = value;
    hasCustomText = true;
}

int Alarm::getPrecision() const
{
    return precision;
}

void Alarm::setPrecision(int value)
{
    precision = value;
}

int Alarm::getUtcTime() const
{
    return utcTime;
}

void Alarm::setUtcTime(int value)
{
    utcTime = value;
}

int Alarm::getUtcTimeMs() const
{
    return utcTimeMs;
}

void Alarm::setUtcTimeMs(int value)
{
    utcTimeMs = value;
}

int Alarm::getActionValue() const
{
    return actionValue;
}

void Alarm::setActionValue(int value)
{
    actionValue = value;
}

bool Alarm::getLatched() const
{
    return latched;
}

void Alarm::setLatched(bool value)
{
    latched = value;
}

bool Alarm::getAutoAck() const
{
    return autoAck;
}

void Alarm::setAutoAck(bool value)
{
    autoAck = value;
}

float Alarm::getTriggerValue() const
{
    return triggerValue;
}

void Alarm::setTriggerValue(float value)
{
    triggerValue = value;
}

QString Alarm::getPrettyName() const
{
    return prettyName;
}

void Alarm::setPrettyName(const QString &value)
{
    prettyName = value;
}

QString Alarm::getState() const
{
    return state;
}

void Alarm::setState(const QString &value)
{
    state = value;
}

QString Alarm::getTriggerImage() const
{
    return triggerImage;
}

void Alarm::setTriggerImage(const QString &value)
{
    triggerImage = value;
}

QList<Param *> Alarm::getParams() const
{
    return params;
}

void Alarm::setParams(const QList<Param *> &value)
{
    params = value;
}

void Alarm::addParam(Param * param)
{
    params.append(param);
}

void Alarm::print()
{
    qDebug() << "Alarm";
    qDebug() << "Id" << getId();
    qDebug() << "state" << getState();
}


float Alarm::getSetPointValue() const
{
    return setPointValue;
}

void Alarm::setSetPointValue(float value)
{
    setPointValue = value;
}

bool Alarm::getHasTriggeredPopUp() const
{
    return hasTriggeredPopUp;
}

void Alarm::setHasTriggeredPopUp(bool value)
{
    hasTriggeredPopUp = value;
}


/*
 *
 */

int Param::getId() const
{
    return id;
}

void Param::setId(int value)
{
    id = value;
}

QString Param::getType() const
{
    return type;
}

void Param::setType(const QString &value)
{
    type = value;
}


Param::Param() : RestDataItem()
{

}

Param::Param(int _id)
{
    setId(_id);
}

Param::~Param()
{

}
