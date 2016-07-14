#ifndef GLOBALDICTIONARY_H
#define GLOBALDICTIONARY_H

#include <QObject>
#include <QHash>
#include "restdatacontrollers/textobject.h"
#include "managers/managerbase.h"

class RestDataItem;

class GlobalDictionary : public ManagerBase
{

    Q_OBJECT

public:
    GlobalDictionary(XMLStreamDocumentHandler * handler = NULL);
    ~GlobalDictionary();
    void init();

    QString getText(int id);

    QHash<int, QString> getTextDB() const;
    void setTextDB(const QHash<int, QString> &value);

public slots:
    void data(RestDataItem * newItem);
    void done();
    void start();

private:
    XMLStreamDocumentHandler * textsDataHandler;
    QHash<int, QString> textDB;
    Texts textData;
};

#endif // GLOBALDICTIONARY_H
