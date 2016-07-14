#ifndef MANAGERBASE_H
#define MANAGERBASE_H

#include <QObject>
class RestDataItem;
class RestData;

class ManagerBase : public QObject
{
    Q_OBJECT

public:
    explicit ManagerBase(QObject *parent = 0);
    ~ManagerBase();
    virtual void init() = 0;

    RestData *getDataHelper() const;
    void setDataHelper(RestData *value);

public slots:
    virtual void data(RestDataItem * ) = 0;
    virtual void done() = 0;
    virtual void start() = 0;

signals:
    void clearGui();
    void addGuiItem(RestDataItem * );
    void removeGuiItem(int );
    void showPopup(int id);
    void removePopup();
    void updateStatusText(int statusTextId);

protected:
    RestData * dataHelper;

};

#endif // MANAGERBASE_H
