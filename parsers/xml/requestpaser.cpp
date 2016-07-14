#include "requestpaser.h"
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
#include <QtConcurrent/QtConcurrentRun>
#else
#include <QtConcurrentRun>
#endif
#include <QDebug>
#include <QHash>
#include "parsers/parsers/streamparser.h"
#include "parsers/parsers/xmlstreamerparser.h"
void XMLStreamDocumentHandler::error(QString)
{

}


bool XMLStreamDocumentHandler::validateAttribute(const QString &attributeValue, dataType type, void *dataContainer, bool *ok)
{
    bool validate = false;
    switch (type)
    {
    case _int:
        *(static_cast<int *>(dataContainer)) = attributeValue.toInt(&validate);
        break;
    case _float:
        *(static_cast<float *>(dataContainer)) = attributeValue.toFloat(&validate);
        break;
    case _bool:
    {
        if(attributeValue == "1" || attributeValue == "true")
        {
            validate = true;
            *(static_cast<int *>(dataContainer)) = true;
        }
        else if(attributeValue == "0" || attributeValue == "false")
        {
            validate = true;
            *(static_cast<int *>(dataContainer)) = false;
        }
        else
        {
            validate = false;
            *(static_cast<int *>(dataContainer)) = false;
        }
        break;
    }
    case _string:
        validate = true;
        *(static_cast<QString *>(dataContainer)) = attributeValue;
        break;
    default:
        break;
    }
    *ok = validate & *ok;
    return validate;
}


void XMLStreamDocumentHandler::parseDone()
{
//    qDebug() << __PRETTY_FUNCTION__;
    if(future)
    {
        delete future;
        future = NULL;
    }
    if(watcher)
    {
        delete watcher;
        watcher = NULL;
    }
    emit parsingFinished();
//    this->disconnect();
}


XMLStreamDocumentHandler::XMLStreamDocumentHandler(StreamerParser *parser):
    m_parser(parser),
    watcher(NULL), future(NULL)
{
}

void XMLStreamDocumentHandler::initialize()
{
    connect(m_parser, SIGNAL(endDocument()), this, SLOT(endDoc()));
    connect(m_parser, SIGNAL(endDataItem(QString)), this, SLOT(endTag(QString)));
    connect(m_parser, SIGNAL(startDocument()), this, SLOT(startDoc()));
    connect(m_parser, SIGNAL(startDataItem(QString,QHash<QString,QString>)), this, SLOT(startTag(QString,QHash<QString,QString>)));
}

void XMLStreamDocumentHandler::registerAttribute(QString tag, QString attribute)
{
    if(attributeList.contains(tag))
    {

        attributeList.insert(tag, QStringList());
    }
    QStringList tmp = attributeList.value(tag);
    tmp.append(attribute);
    attributeList.insert(tag, tmp);
}


bool XMLStreamDocumentHandler::checkData(const QStringList &tag, QHash<QString, QString> attributes)
{
    if(tag.isEmpty())
        return false;
    foreach(QString attr, tag)
    {
        if(!attributes.contains(attr))
        {
            return false;
        }
    }
    return true;
}


bool XMLStreamDocumentHandler::getStatus() const
{
    return status;
}

void XMLStreamDocumentHandler::setStatus(bool value)
{
    status = value;
}

void XMLStreamDocumentHandler::rowData(QByteArray str)
{
    QString data(QString::fromUtf8(str.data(), str.count()));
    future = new QFuture<void>;
    watcher = new QFutureWatcher<void>;
    emit parsingStarted();
    *future = QtConcurrent::run(m_parser, &StreamerParser::parse, data);
    connect(watcher, SIGNAL(finished()), this, SLOT(parseDone()));
    watcher->setFuture(*future);
}


