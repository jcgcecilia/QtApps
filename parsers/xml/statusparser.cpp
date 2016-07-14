#include "statusparser.h"


#include <QDebug>

StatusXMLDocumentHandler::StatusXMLDocumentHandler(StreamerParser *parser) : XMLStreamDocumentHandler(parser)
{
    /**
     * Register Mandatory attributes
     */
    registerAttribute("Led", "id");
    registerAttribute("Led", "color");
    registerAttribute("Led", "blink");
    registerAttribute("StatusText", "name_text_id");
    status.setStatusText(statusData);
}

StatusXMLDocumentHandler::~StatusXMLDocumentHandler()
{

}

void StatusXMLDocumentHandler::endDoc()
{
    emit data(&status);
}

void StatusXMLDocumentHandler::startDoc()
{

}

void StatusXMLDocumentHandler::startTag(QString tagName, QHash<QString, QString> attributes)
{
    setStatus(false);
    bool tmp = true;
    if(tagName == "DisplayStatus")
    {
    }
    if(checkData(attributeList.value(tagName), attributes))
    {
        if(tagName == "StatusText")
        {
            int p;
            float f;


            if(validateAttribute(attributes.value("name_text_id"), _int, &p, &tmp))
                statusData.setNameTextId(p);

            if(attributes.contains("value"))
            {
                if(validateAttribute(attributes.value("value"), _float, &f, &tmp))
                    statusData.setValue(f);

                if(validateAttribute(attributes.value("unit_text_id"), _int, &p, &tmp))
                    statusData.setUnitTextId(p);

                if(validateAttribute(attributes.value("precision"), _int, &p, &tmp))
                    statusData.setPrecision(p);
            }
        }
        else if(tagName == "Led")
        {
            int p;
            QString s;

            Led led;
            if(validateAttribute(attributes.value("id"), _int, &p, &tmp))
            {
                if(!leds.contains(p))
                {
                    led.setId(p);
//                    leds.insert(p,led);

//                    status.addLed(led);
                }
                else
                {
//                    led = leds.value(p);
                }
            }


            if(validateAttribute(attributes.value("color"), _string, &s, &tmp))
            {
//                if(ledData)
                    led.setColor(s);
            }

            if(validateAttribute(attributes.value("blink"), _int, &p, &tmp))
            {
//                if(ledData)
                    led.setBlink(p);
            }

        }
    }
    else
    {
        error("Not all mandatory attributes are validated");
    }
    setStatus(tmp);
}

void StatusXMLDocumentHandler::endTag(QString tag)
{
    if(tag == "Led")
    {
        //        if(status)
//       status.addLed(ledData);
    }
    else if(tag == "StatusText")
    {
//        if(status)
            status.setStatusText(statusData);
    }
}
