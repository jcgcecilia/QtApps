#ifndef ALARMGUIHANDLER_H
#define ALARMGUIHANDLER_H

#include <QObject>
#include "guihandler.h"
#include "mvc/customtablemodel.h"
#include <QStyledItemDelegate>

class ManagerBase;
class CustomFooter;

class AlarmIconDelegate : public QStyledItemDelegate
{
public:
    AlarmIconDelegate(){}
protected:
    void paint(QPainter *painter,const QStyleOptionViewItem &option, const QModelIndex &index);
};


class TableGuiHandler : public GuiHandler
{
    Q_OBJECT
public:
    TableGuiHandler(QObject *parent);
    virtual ~TableGuiHandler();

    void setModel(CustomTableModel *model);
    CustomTableModel *model() const;

    int getActiVeRow() const;
    void setActiVeRow(int value);

public slots:
    virtual void clearGui() = 0;
    virtual void addGuiItem(RestDataItem * ) = 0;
    virtual void removeGuiItem(int ) = 0;

protected:
       CustomTableModel * m_model;
       int actiVeRow;
};


class AlarmGuiHandler : public TableGuiHandler
{
        Q_OBJECT
public:
    AlarmGuiHandler(QObject * parent,
                    ManagerBase * guiData);
    ~AlarmGuiHandler();
    void initialize();

    virtual void footerAction(int col);
    virtual void navigationAction(int row = 0, int col = 0);
    virtual void okAction(int row = 0, int col = 0);


signals:
    void ackAlarm(int );

public slots:
    virtual void clearGui();
    virtual void addGuiItem(RestDataItem * item);
    virtual void removeGuiItem(int );

private:
//    CustomTableModel * m_alarmModel;
    ManagerBase* m_businessDataManager;
    CustomFooter  * m_screenFooter;
    QList<int> itemIdList;
};

#endif // ALARMGUIHANDLER_H
