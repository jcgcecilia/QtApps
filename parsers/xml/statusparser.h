#ifndef STATUSPARSER_H
#define STATUSPARSER_H

#include "parsers/xml/requestpaser.h"
#include "restdatacontrollers/statusobject.h"

class StatusXMLDocumentHandler : public XMLStreamDocumentHandler
{
    Q_OBJECT

public:
    StatusXMLDocumentHandler(StreamerParser *parser);
    ~StatusXMLDocumentHandler();

public slots:
    void endDoc();
    void startDoc();
    void startTag(QString tagName, QHash<QString, QString> attributes);
    void endTag(QString);


private:
    Status status;
    StatusText statusData;
    Led ledData;
    QHash<int, Led > leds;
};

#endif // STATUSPARSER_H
