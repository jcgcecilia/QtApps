#include "managerbase.h"
#include "restdatacontrollers/restdata.h"


ManagerBase::ManagerBase(QObject *parent) : QObject(parent)
{

}

ManagerBase::~ManagerBase()
{

}

RestData *ManagerBase::getDataHelper() const
{
    return dataHelper;
}

void ManagerBase::setDataHelper(RestData *value)
{
    dataHelper = value;
}


