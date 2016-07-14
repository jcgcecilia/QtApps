#ifndef TEXTSRESTDATA_H
#define TEXTSRESTDATA_H

#include <QObject>
#include "restdata.h"
class TextsRestData : public RestData
{
public:
    TextsRestData(RequestWorkerPool* workers = NULL, DataRequest *_request = NULL);
    void initialize();
};

#endif // TEXTSRESTDATA_H
