#include "xmlstreamerparser.h"
#include <QMetaType>

#include <QDebug>
XMLStreamerParser::XMLStreamerParser()
{
    qRegisterMetaType<QHash<QString, QString> >("QHash<QString, QString>");

}

XMLStreamerParser::~XMLStreamerParser()
{

}

bool XMLStreamerParser::parse(const QString & input)
{
//    qDebug() << __PRETTY_FUNCTION__;
    try
    {
        streamParser.addData(input);
        streamParser.readNext();

        if(streamParser.hasError())
        {
            emit error(streamParser.errorString());
            return false;
        }
        if(streamParser.isStartDocument())
        {
            emit startDocument();
        }
        while (!streamParser.atEnd())
        {
            if (streamParser.isStartElement())
            {
                if(streamParser.name().toString() == QString("error"))
                {
                    emit error(streamParser.errorString());
                    break;
                }
                else
                {
                    QHash<QString, QString> tmp;
                    foreach (QXmlStreamAttribute attr, streamParser.attributes())
                    {
                        tmp.insert(attr.name().toString(), attr.value().toString());
                    }
                    emit startDataItem(streamParser.name().toString(), tmp);
                }
            }
            else if (streamParser.isEndElement())
            {
                emit endDataItem(streamParser.name().toString());
            }

            streamParser.readNext();
        }
        if (streamParser.hasError())
        {
            emit error(streamParser.errorString());
        }
        else if(streamParser.isEndDocument())
        {
            emit endDocument();
        }
    }
    catch (std::bad_alloc ba)
    {
        qWarning("Exception in StreamXMLParser: c++ bad_alloc: %s", ba.what());
    }
    catch (std::exception e)
    {
        qWarning("Exception in StreamXMLParser: c++ exception: %s", e.what());
    }
    catch (...)
    {
        qWarning("Exception in StreamXMLParser: unknown");
    }
    streamParser.clear();
    return true;
}
