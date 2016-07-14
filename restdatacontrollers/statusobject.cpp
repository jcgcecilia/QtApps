#include "statusobject.h"
#include "network/applicationnetworkmanager.h"
#include "network/httprequest.h"
#include <QDebug>

//HttpStatusRestDataController::HttpStatusRestDataController(CommunicationManager *network, RequestParser *_parser)
//    : RestDataController(network, _parser)
//{
//    getRequest.setController(this);
//    getRequest.addQueryVariable("cmd", "DisplayStatus");
//    getRequest.setMethod("GET");
//}

//HttpStatusRestDataController::~HttpStatusRestDataController()
//{

//}

//void HttpStatusRestDataController::timeTick()
//{
//    data();
//}

//bool HttpStatusRestDataController::data()
//{
//    if(!getRequest.getProcessing())
//        return RestDataController::data(&getRequest);
//    else
//    {
//        qDebug() << __FILE__ << __LINE__ << "Request not sendt";
//        return false;
//    }
//}

//DataRequest HttpStatusRestDataController::getGetRequest() const
//{
//    return getRequest;
//}

//void HttpStatusRestDataController::setGetRequest(const DataRequest &value)
//{
//    getRequest = value;
//}



/*
 *
 * DATA
 *
 */

Led::Led() : id(-1), blink(-1), color("")
{

}

Led::~Led()
{

}

int Led::getId() const
{
    return id;
}

void Led::setId(int value)
{
    id = value;
}

int Led::getBlink() const
{
    return blink;
}

void Led::setBlink(int value)
{
    blink = value;
}
QString Led::getColor() const
{
    return color;
}

void Led::setColor(const QString &value)
{
    color = value;
}


QList<Led> Status::getLeds() const
{
    return leds;
}


void Status::setLeds(const QList<Led> &value)
{
    leds = value;
}

int Status::statusCounter = 0;

Status::Status()  : statusText()
{
    statusCounter++;
    //    qDebug() << __PRETTY_FUNCTION__ << statusCounter;
}

Status::~Status()
{
    statusCounter--;
    //    delete statusText;
    //    foreach (Led * led , leds) {
    //        delete led;
    //    }
//    leds.clear();
}


void Status::addLed(Led & led)
{
    leds.append(led);
}

StatusText & Status::getStatusText()
{
    return statusText;
}

void Status::setStatusText(StatusText &value)
{
    //    delete statusText;
    statusText = value;
}

bool Status::areEquals(Status &)
{
    /*
  bool status = true;
    status &= statusText->getNameTextId() == obj->getStatusText()->getNameTextId() && \
                 statusText->getPrecision() == obj->getStatusText()->getPrecision() && \
                 statusText->getUnitTextId() == obj->getStatusText()->getUnitTextId();

    return status;
    if()
*/
    return true;
}

void Status::print()
{
    //    qDebug() << "STATUSTEXT" << this <<statusText->getNameTextId();
    foreach (Led led, leds) {
        qDebug() << "LED" << led.getId()
                 << led.getColor() << led.getBlink();
    }
}


StatusText::StatusText()
    : nameTextId(-1),
      value(-1.0),
      unitTextId(-1),
      precision(-1)
{

}

StatusText::~StatusText()
{
//    qDebug()<< "Deleting"<< this;
}

int StatusText::getNameTextId() const
{
    return nameTextId;
}

void StatusText::setNameTextId(int value)
{
    nameTextId = value;
}
float StatusText::getValue() const
{
    return value;
}

void StatusText::setValue(float value)
{
    value = value;
}
int StatusText::getUnitTextId() const
{
    return unitTextId;
}

void StatusText::setUnitTextId(int value)
{
    unitTextId = value;
}
int StatusText::getPrecision() const
{
    return precision;
}

void StatusText::setPrecision(int value)
{
    precision = value;
}

bool StatusText::areEquals(StatusText *obj)
{
    bool status = true;
    status &= nameTextId == obj->getNameTextId() && \
            precision == obj->getPrecision() && \
            unitTextId == obj->getUnitTextId() && \
            value == obj->getValue();

    return status;
}
