#include "alarmrestdata.h"
#include "network/httprequestworker.h"
#include "restdatacontrollers/httpworkerpool.h"
#include "application/application.h"
#include <QXmlStreamWriter>

AlarmRestData::AlarmRestData( RequestWorkerPool* workers, DataRequest * _request)
    : RestData(workers, false)
{
}

AlarmRestData::~AlarmRestData()
{

}

void AlarmRestData::initialize()
{
    defaultRequest = new HttpRequest;
    static_cast<HttpRequest *>(defaultRequest)->addQueryVariable("cmd","Alarms");
}

void AlarmRestData::ackAlarm(int id)
{
    QString data;
    QXmlStreamWriter xmlWriter(&data);

    /* Writes a document start with the XML version number. */
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("Alarms");
    xmlWriter.writeAttribute("name","PPM 300");
    xmlWriter.writeAttribute("version","PPM 300");
    xmlWriter.writeAttribute("revision","PPM 300");
    xmlWriter.writeAttribute("rest_version","PPM 300");
    xmlWriter.writeStartElement("Alarm");
    xmlWriter.writeAttribute("id",QString::number(id));
    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();


    HttpRequest * postrequest = new HttpRequest;
    postrequest->setMethod("POST");
    postrequest->addQueryVariable("cmd","Alarms");
    postrequest->setData(data);

    qDebug() << data;
//    dispatchRequest(postrequest);

}

void AlarmRestData::ackAlarm(QList<int> )
{
//    dispatchRequest(NULL);
}







