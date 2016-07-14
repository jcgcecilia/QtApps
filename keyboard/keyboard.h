#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QObject>
#include <QWidget>
#include "gui_components/screen.h"
#include <QVariant>

class QStackedWidget;
class QGridLayout;
class LineEdit;
class  GuiHandler;

class KeyBoard : public Screen
{
    Q_OBJECT
public:
    explicit KeyBoard(ScreensContainer::ScreenId id,ScreensContainer *parent  , GuiHandler * GuiHandler= 0);
    void init();
signals:
    void enteredValue(QVariant );

protected:
    virtual void showEvent(QShowEvent *);
    virtual void hideEvent(QHideEvent *);

public slots:
    virtual void leftFooterItemPressed();
    virtual void leftCenterFooterItemPressed();

private:
    int mCurrentKeyboard;
    QStackedWidget * mKeyboards;
    void generateKeyboards( QStackedWidget * stack);
    void buildKeyboard(QGridLayout* layout, bool);
    LineEdit * editLine;
};

#endif // KEYBOARD_H
