#ifndef CREQUESTPASER_H
#define CREQUESTPASER_H

#include <QObject>

#include <QVariant>
#include <QStringList>
#include "restdatacontrollers/restdata.h"


class RestDataItem;

enum dataType{
    _int,
    _float,
    _bool,
    _hex,
    _string
};

#include <QFutureWatcher>
#include <QFuture>
class StreamerParser;

class XMLStreamDocumentHandler : public QObject
{
    Q_OBJECT

public:
    XMLStreamDocumentHandler(StreamerParser *parser);
    virtual ~XMLStreamDocumentHandler(){}
    void initialize();

signals:
    void data(RestDataItem *);
    void parsingStarted();
    void parsingFinished();

public slots:
    void parseDone();
    void rowData(QByteArray str);
    bool getStatus() const;
    void setStatus(bool value);

    virtual void endDoc() = 0; //End tag
    virtual void startDoc() = 0; // start document
    virtual void startTag(QString tagName, QHash<QString, QString> attributes) = 0;
    virtual void endTag(QString) = 0;
    virtual void error(QString);


protected:
    bool checkData(const QStringList & tag, QHash<QString, QString> attributes);
    void registerAttribute(QString tag, QString attribute);
    bool validateAttribute(const QString &attributeValue, dataType type, void *dataContainer, bool *ok);

protected:
    QHash<QString, QStringList> attributeList;

private:
    bool status;
    StreamerParser * m_parser;
    QFutureWatcher<void> * watcher;
    QFuture<void> * future;
};

#endif // CREQUESTPASER_H
