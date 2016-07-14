#ifndef ALARMSXMLPARSER_H
#define ALARMSXMLPARSER_H

#include "requestpaser.h"

class Alarm;
class Param;
class StreamerParser;

class AlarmXMLDocumentHandler : public XMLStreamDocumentHandler
{
    Q_OBJECT

public:
    AlarmXMLDocumentHandler(StreamerParser *parser);
    ~AlarmXMLDocumentHandler();

public slots:
    virtual void endDoc();
    virtual void startDoc();
    virtual void startTag(QString tagName, QHash<QString, QString> attributes);
    virtual void endTag(QString);

private:
    Alarm * alarmData;
    Alarm * proto;
    Param * paramData;
//    QList<Alarm *> alarmList;

};
#endif // ALARMSXMLPARSER_H
