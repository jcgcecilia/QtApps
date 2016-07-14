#ifndef STREAMPARSER_H
#define STREAMPARSER_H

#include <QObject>
#include <QHash>

class StreamerParser : public QObject
{
    Q_OBJECT

public:

    StreamerParser() /*: error(NULL)*/{}
    virtual ~StreamerParser(){}

    virtual bool parse(const QString &) = 0;

signals:
    void endDocument(); //End tag
    void startDocument(); // start document
    void startDataItem(QString itemName, QHash<QString, QString> attributes);
    void endDataItem(QString);
    void error(QString);

};


#endif // STREAMPARSER_H
