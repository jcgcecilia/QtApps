#include "globaltimer.h"
#include "restdatacontrollers/restdata.h"

GlobalTimer::GlobalTimer(int _interval) : tickinterval(_interval)
{
    setInterval(tickinterval);
    QObject::connect(this, SIGNAL(timeout()), SLOT(timeout()));
}

GlobalTimer::~GlobalTimer()
{

}

void GlobalTimer::init()
{
    QList<GlobalTimer::SubscriberInfo *>::iterator i;
    for (i = subscribersNonCyclic.begin(); i != subscribersNonCyclic.end(); ++i)
    {
        (*i)->subscriber->dispatchCyclicRequest();
    }

    for (i = subscribersNonCyclic.begin(); i != subscribersNonCyclic.end(); ++i)
    {
        delete (*i);
    }
    subscribersNonCyclic.clear();
    start();
}

void GlobalTimer::forceRun()
{
    timeout();
}

//bool GlobalTimer::addTimeListener(RestData *controller)
//{
//    if(controller)
//    {
//        controllers.append(controller);
//        return true;
//    }
//    return false;
//}

bool GlobalTimer::removeTimeListener(RestData *controller)
{
    if(!controllers.contains(controller))
    {
        return false;
    }
    controllers.removeOne(controller);
    return true;
}

bool GlobalTimer::removerSubscriber(SubscriberInfo * subscriber)
{

    delete subscriber;
    return true;
}

void GlobalTimer::timeout()
{
    QList<GlobalTimer::SubscriberInfo *>::iterator i;
    for (i = subscribersCyclic.begin(); i != subscribersCyclic.end(); ++i)
    {
        if((*i)->ticks == (*i)->interval)
        {
            (*i)->ticks = 0;
            (*i)->subscriber->dispatchCyclicRequest();
        }
        else
        {
            (*i)->ticks++;
        }
    }
    if(!subscribersNonCyclic.isEmpty())
    {
       // Do stuff here
    }
}
int GlobalTimer::getTickinterval() const
{
    return tickinterval;
}

void GlobalTimer::setTickinterval(int value)
{
    tickinterval = value;
}

bool GlobalTimer::addTimeListener(RestData *controller, int interval)
{
    GlobalTimer::SubscriberInfo * tmp = new GlobalTimer::SubscriberInfo;

    int ticks_;
    if(interval >= tickinterval)
        ticks_= (interval/tickinterval) - 1;
    else
        ticks_ = 0;

    tmp->interval = ticks_;
    tmp->subscriber = controller;
    tmp->ticks = 0;
    tmp->sigleShot = controller->getSingleShot();
    if(tmp->sigleShot)
        subscribersNonCyclic.append(tmp);
    else
        subscribersCyclic.append(tmp);
    return true;
}
