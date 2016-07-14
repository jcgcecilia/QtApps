#ifndef CUSTOMTABLE_H
#define CUSTOMTABLE_H

#include <QObject>
#include "custommenu.h"
#include "navigationhandler.h"
#include "mvc/customtableview.h"
//class CustomTableView;
class CustomTableModel;
class QKeyEvent;
class NavigationHandler;
class QLabel;
class TableGuiHandler;
class QStyledItemDelegate;
class CustomTable : public Screen
{
    Q_OBJECT
public:
    CustomTable(ScreensContainer::ScreenId id, ScreensContainer *parent = 0, TableGuiHandler *guiHandler = NULL);

    void initialize();
    void populate();

//    CustomTableModel * tableModel() const;
   void setTableModel(CustomTableModel *tableModel);

    void setColsWidth(const QList<int> & cols);
    void setScreenTitle(const QString & title);

//    void setDelegate(int col, QStyledItemDelegate * delegate);
protected:
#ifdef KEYS
    void keyPressEvent(QKeyEvent * ev);
    void keyReleaseEvent(QKeyEvent *ev);
#endif

public slots:
    void rowSelected(int row);
    void rowEntered(int row);

signals:
protected:
#ifndef KEYS

#endif
    void showEvent(QShowEvent *event);
private:
    QLabel * m_screenTitle;
    CustomTableView m_tableView;
};

#endif // CUSTOMTABLE_H
