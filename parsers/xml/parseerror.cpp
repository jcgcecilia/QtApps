#include "parseerror.h"

ParseError::ParseError()
{

}

ParseError::~ParseError()
{

}

QString ParseError::getErrorString() const
{
    return errorString;
}

void ParseError::setErrorString(const QString &value)
{
    errorString = value;
}
