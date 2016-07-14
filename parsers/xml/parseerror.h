#ifndef PARSEERROR_H
#define PARSEERROR_H

#include <QString>

class ParseError
{
public:
    ParseError();
    ~ParseError();

    QString getErrorString() const;
    void setErrorString(const QString &value);

protected:
    QString errorString;
};

#endif // PARSEERROR_H
