#ifndef GLOBALTIMER_H
#define GLOBALTIMER_H

#include <QTimer>


class RestData;

class GlobalTimer : public QTimer
{
    Q_OBJECT

public:
    struct SubscriberInfo
    {
        int interval;
        int ticks;
        bool sigleShot;
        RestData * subscriber;
    };

    GlobalTimer(int _interval = 250); //Interval given in miliseconds
    ~GlobalTimer();
    void init();

    void forceRun();

//    bool addTimeListener(RestData * controller);
    bool addTimeListener(RestData * controller,  int interval = 0);
    bool removeTimeListener(RestData * controller);
    bool removerSubscriber(SubscriberInfo *subscriber);

    int getTickinterval() const;
    void setTickinterval(int value);

private slots:
    void timeout();

private:
    QList<RestData *> controllers;
    QList<SubscriberInfo *> subscribersNonCyclic;
    QList<SubscriberInfo *> subscribersCyclic;
    int tickinterval;
};

#endif // GLOBALTIMER_H
