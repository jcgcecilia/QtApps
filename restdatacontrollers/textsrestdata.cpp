#include "textsrestdata.h"

TextsRestData::TextsRestData( RequestWorkerPool* workers, DataRequest * _request)
    : RestData(workers)
{

}

void TextsRestData::initialize()
{
    defaultRequest = new HttpRequest;
    static_cast<HttpRequest *>(defaultRequest)->setPath("/cgi-bin/rest/langcgi");
    static_cast<HttpRequest *>(defaultRequest)->addQueryVariable("Language","ma");
}
