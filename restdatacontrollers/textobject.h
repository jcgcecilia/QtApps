#ifndef TEXTRESTDATACONTROLLER_H
#define TEXTRESTDATACONTROLLER_H

#include <QObject>
#include "restdata.h"

class Texts : public RestDataItem
{
public:
    Texts();
    ~Texts();
    void addText(int id, QString text);

    QHash<int, QString> &getTexts();
    void setTexts(const QHash<int, QString> &value);
    void clean();
private:
    QHash<int , QString> texts;
};

#endif // TEXTRESTDATACONTROLLER_H
