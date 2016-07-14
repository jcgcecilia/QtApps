#include "statusrestdata.h"
#include "network/httprequestworker.h"
#include "restdatacontrollers/httpworkerpool.h"
#include "application/application.h"

StatusRestData::StatusRestData( RequestWorkerPool* workers, DataRequest * _request)
    : RestData(workers, false)
{

}

void StatusRestData::initialize()
{
    defaultRequest = new HttpRequest;
    static_cast<HttpRequest *>(defaultRequest)->addQueryVariable("cmd","DisplayStatus");
}
