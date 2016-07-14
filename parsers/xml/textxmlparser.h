#ifndef TEXTXMLPARSER_H
#define TEXTXMLPARSER_H
#include "requestpaser.h"
#include "restdatacontrollers/textobject.h"

class TextXMLDocumentHandler  : public XMLStreamDocumentHandler
{
        Q_OBJECT

public:
    TextXMLDocumentHandler(StreamerParser *parser);
    ~TextXMLDocumentHandler();

public slots:
    void endDoc();
    void startDoc();
    void startTag(QString tagName, QHash<QString, QString> attributes);
    void endTag(QString);

//signals:
//    void data(Texts *);

private:
    Texts textsData;
};

#endif // TEXTXMLPARSER_H
