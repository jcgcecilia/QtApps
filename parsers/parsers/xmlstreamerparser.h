#ifndef XMLSTREAMERPARSER_H
#define XMLSTREAMERPARSER_H

#include <QObject>
#include "streamparser.h"
#include <QXmlStreamReader>

class XMLStreamerParser : public StreamerParser
{
    Q_OBJECT

public:
    XMLStreamerParser();
    ~XMLStreamerParser();
    bool parse(const QString &);

private:
    QXmlStreamReader streamParser;
};

#endif // XMLSTREAMERPARSER_H
