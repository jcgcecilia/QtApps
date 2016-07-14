#ifndef GUIHANDLER_H
#define GUIHANDLER_H

#include <QObject>

class RestDataItem;

class GuiHandler : public QObject
{
    Q_OBJECT
public:
    explicit GuiHandler(QObject *parent = 0);
    virtual void footerAction(int col) = 0;
    virtual void navigationAction(int row = 0, int col = 0) = 0;
    virtual void okAction(int row = 0, int col = 0) = 0;

signals:
    void goToPrevious();
    void goToNext();
    void updateFooter(int col, bool active);

public slots:
    virtual void clearGui() = 0;
    virtual void addGuiItem(RestDataItem * ) = 0;
    virtual void removeGuiItem(int ) = 0;

};

#endif // GUIHANDLER_H
