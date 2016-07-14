#ifndef ALARMRESTDATACONTROLLER_H
#define ALARMRESTDATACONTROLLER_H

#include "restdata.h"
class Param : public RestDataItem
{

public:
    Param();
    Param(int _id);
    ~Param();
    int getId() const;
    void setId(int value);

    QString getType() const;
    void setType(const QString &value);

private:
    int id;
    QString type;

};

class Alarm : public RestDataItem
{

public:

    Alarm();
//    Alarm(int _id);
    ~Alarm();

    Alarm * clone();
    int getId() const;
    void setId(int value);

    int getNameTextId() const;
    void setNameTextId(int value);

    int getUnitTextId() const;
    void setUnitTextId(int value);

    int getCustomTextId() const;
    void setCustomTextId(int value);

    int getPrecision() const;
    void setPrecision(int value);

    int getUtcTime() const;
    void setUtcTime(int value);

    int getUtcTimeMs() const;
    void setUtcTimeMs(int value);

    int getActionValue() const;
    void setActionValue(int value);

    bool getLatched() const;
    void setLatched(bool value);

    bool getAutoAck() const;
    void setAutoAck(bool value);

    float getTriggerValue() const;
    void setTriggerValue(float value);

    QString getPrettyName() const;
    void setPrettyName(const QString &value);

    QString getState() const;
    void setState(const QString &value);

    QString getTriggerImage() const;
    void setTriggerImage(const QString &value);

    QList<Param *> getParams() const;
    void setParams(const QList<Param *> &value);
    void addParam(Param * param);


    void print();
//    Alarm * clone() const;

    float getSetPointValue() const;
    void setSetPointValue(float value);

    bool getHasTriggeredPopUp() const;
    void setHasTriggeredPopUp(bool value);

private:
    int id;
    int nameTextId;
    int unitTextId;
    int customTextId;
    int precision;
    int utcTime;
    int utcTimeMs;
    int actionValue;
    bool latched;
    bool autoAck;
    float triggerValue;
    float setPointValue;
    QString prettyName;
    QString state;
    QString triggerImage;
    QList<Param *> params;

    bool hasCustomText;
    bool areExtraMandatoryValues;
    bool hasTriggeredPopUp;
    static int alarmCounter;
};

//class HttpRequest;
//class CommunicationManager;
//class DataRequest;

//class HttpAlarmRestDataController : public RestDataController
//{
//    Q_OBJECT

//public:

//    HttpAlarmRestDataController(CommunicationManager *network= 0, RequestParser * _parser = 0);
//    ~HttpAlarmRestDataController();
//    virtual void timeTick();
//    bool data();

//private:
//    HttpRequest getRequest;

//};

#endif // ALARMRESTDATACONTROLLER_H
