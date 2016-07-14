#include "alarmsxmlhandler.h"
#include "restdatacontrollers/alarmobject.h"
#include "application/application.h"
#include "parsers/parsers/streamparser.h"
#include <QMetaType>

AlarmXMLDocumentHandler::AlarmXMLDocumentHandler(StreamerParser *parser) : XMLStreamDocumentHandler(parser)
{
    registerAttribute("Alarm", "id");
    registerAttribute("Alarm", "name_text_id");
    //    registerAttribute("Alarm", "custom_text_id");
    registerAttribute("Alarm", "state");
    registerAttribute("Alarm", "latched");
    registerAttribute("Alarm", "utc_time");
    registerAttribute("Alarm", "utc_time_ms");
    registerAttribute("Alarm", "action_value");
    registerAttribute("Alarm", "auto_ack");
    //    registerAttribute("Alarm", "triggered_value");
    //    registerAttribute("Alarm", "setpoint_value");
    //    registerAttribute("Alarm", "unit_text_id");
    //    registerAttribute("Alarm", "precision");
    //    registerAttribute("Alarm", "trigger_image_type");

    registerAttribute("Param", "id");
    registerAttribute("Param", "type");
    proto = new Alarm;
//    connect(parser, SIGNAL(endDocument()), this, SLOT(endDoc()));
//    connect(parser, SIGNAL(endDataItem(QString)), this, SLOT(endTag(QString)));
//    connect(parser, SIGNAL(startDocument()), this, SLOT(startDoc()));
//    connect(parser, SIGNAL(startDataItem(QString,QHash<QString,QString>)), this, SLOT(startTag(QString,QHash<QString,QString>)));
}

AlarmXMLDocumentHandler::~AlarmXMLDocumentHandler()
{

}

void AlarmXMLDocumentHandler::endDoc()
{
//    emit data(alarmList);
}

void AlarmXMLDocumentHandler::startDoc()
{
//    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__;
//    alarmList.clear();
}

void AlarmXMLDocumentHandler::startTag(QString tagName, QHash<QString, QString> attributes)
{
    setStatus(false);
    bool tmp = true;

    if(checkData(attributeList.value(tagName), attributes)) // All Mandatarory attributes found
    {
        int p;
        float f;
        QString s;
        bool b;
        if(tagName == "Alarm")
        {
            alarmData = proto->clone();

            if(validateAttribute(attributes.value("id"), _int, &p, &tmp))
                alarmData->setId(p);
            if(validateAttribute(attributes.value("name_text_id"), _int, &p, &tmp))
                alarmData->setNameTextId(p);
            if(attributes.contains("custom_text_id"))
            {
                if(validateAttribute(attributes.value("custom_text_id"), _int, &p, &tmp))
                    alarmData->setCustomTextId(p);
            }
            if(validateAttribute(attributes.value("state"), _string, &s, &tmp))
                alarmData->setState(s);
            if(validateAttribute(attributes.value("latched"), _bool, &b, &tmp))
                alarmData->setLatched(b);
            if(validateAttribute(attributes.value("utc_time"), _int, &p, &tmp))
                alarmData->setUtcTime(p);
            if(validateAttribute(attributes.value("utc_time_ms"), _int, &p, &tmp))
                alarmData->setUtcTimeMs(p);
            if(validateAttribute(attributes.value("action_value"), _int, &p, &tmp))
                alarmData->setActionValue(p);
            if(validateAttribute(attributes.value("auto_ack"), _bool, &b, &tmp))
                alarmData->setAutoAck(b);
            if(attributes.contains("triggered_value") || attributes.contains("setpoint_value"))
            {
                if(validateAttribute(attributes.value("triggered_value"), _float, &f, &tmp))
                    alarmData->setTriggerValue(f);
                if(validateAttribute(attributes.value("setpoint_value"), _float, &f, &tmp))
                    alarmData->setSetPointValue(f);
                if(validateAttribute(attributes.value("unit_text_id"), _int, &p, &tmp))
                    alarmData->setUnitTextId(p);
                if(validateAttribute(attributes.value("precision"), _int, &p, &tmp))
                    alarmData->setPrecision(p);
            }
            if(attributes.contains("trigger_image_type"))
            {
                if(validateAttribute(attributes.value("trigger_image_type"), _string, &s, &tmp))
                    alarmData->setTriggerImage(s);
            }
        }
        else if(tagName == "Param")
        {
            paramData = new Param();
            if(validateAttribute(attributes.value("id"), _int, &p, &tmp))
                paramData->setId(p);
            if(validateAttribute(attributes.value("type"), _string, &s, &tmp))
                paramData->setType(s);
        }
    }
    else
    {
        //Missing mandatory attributes
    }
    setStatus(tmp);
}


void AlarmXMLDocumentHandler::endTag(QString tag)
{
    if(alarmData)
    {
//        TEXT(alarmData->getNameTextId());
//        qDebug() << "ALARM TEXT" <<ML300Application::getDictionary()->getText(alarmData->getNameTextId());
        if(tag == "Alarm")
        {
            emit data(alarmData);
        }
        else if (tag == "Param")
        {
            alarmData->addParam(paramData);
        }
    }
}


