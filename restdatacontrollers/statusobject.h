#ifndef STATUSRESTDATACONTROLLER_H
#define STATUSRESTDATACONTROLLER_H
#include "restdata.h"

class Led : public RestDataItem
{
public:
    Led();
    ~Led();
    int getId() const;
    void setId(int value);

    int getBlink() const;
    void setBlink(int value);

    QString getColor() const;
    void setColor(const QString &value);

private:
    int id;
    int blink;
    QString color;

};

class StatusText : public RestDataItem
{
public:
    StatusText();
    ~StatusText();
    int getNameTextId() const;
    void setNameTextId(int value);

    float getValue() const;
    void setValue(float value);

    int getUnitTextId() const;
    void setUnitTextId(int value);

    int getPrecision() const;
    void setPrecision(int value);

    bool areEquals(StatusText * obj);
private:
    int nameTextId;
    float value;
    int unitTextId;
    int precision;
};

class Status : public RestDataItem
{
public:
    Status();
    ~Status();

    QList<Led> getLeds() const;
    void setLeds(const QList<Led> &value);
    void addLed(Led &led);

    StatusText & getStatusText();
    void setStatusText(StatusText &value);
    bool areEquals(Status & obj);

    void print();
private:
    QList<Led> leds;
    StatusText statusText;
    static int statusCounter;
};

#endif // STATUSRESTDATACONTROLLER_H
