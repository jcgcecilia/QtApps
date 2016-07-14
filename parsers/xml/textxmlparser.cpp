#include "textxmlparser.h"
#include "restdatacontrollers/textobject.h"

#include <QDebug>

TextXMLDocumentHandler::TextXMLDocumentHandler(StreamerParser *parser) : XMLStreamDocumentHandler(parser)
{
    registerAttribute("Text","id");
    registerAttribute("Text","value");
//    textsData = new Texts;
}

TextXMLDocumentHandler::~TextXMLDocumentHandler()
{

}

void TextXMLDocumentHandler::endDoc()
{
    emit data(&textsData);
}

void TextXMLDocumentHandler::startDoc()
{
        textsData.clean();
}

void TextXMLDocumentHandler::startTag(QString tagName, QHash<QString, QString> attributes)
{
    setStatus(false);
    bool tmp = true;

    if(checkData(attributeList.value(tagName), attributes)) // All Mandatarory attributes found
    {
        int p;
        QString s;
        if(tagName == "Text")
        {
            if(validateAttribute(attributes.value("id"), _int, &p, &tmp))
            {
                if(validateAttribute(attributes.value("value"), _string, &s, &tmp))
                {
                    textsData.addText(p, s);
                }
            }
        }
    }
    else
    {
        //Missing mandatory attributes
    }
    setStatus(tmp);
}

void TextXMLDocumentHandler::endTag(QString)
{

}


