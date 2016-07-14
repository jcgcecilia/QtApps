#ifndef CUSTOMMENU_H
#define CUSTOMMENU_H

#include <QWidget>
#include <QLayout>
#include <QScrollArea>
#include "screen.h"


class CustomMenuButton;
class GuiHandler;

class CustomMenu : public Screen
{
    Q_OBJECT

public:
    explicit CustomMenu(ScreensContainer::ScreenId id,  ScreensContainer *parent , GuiHandler * guiHandler = NULL);
    ~CustomMenu();
    void addMenuItem(CustomMenuButton * item, int row, int col);

#ifdef KEYS
    void resetMenu();
#endif

    CustomGrid *contentGrid() const;
    void setContentGrid(CustomGrid *contentGrid);

protected:
    virtual void showEvent(QShowEvent * event);
    virtual void hideEvent(QHideEvent * event);

#ifdef KEYS
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *ev);
#endif

signals:
    void updateFooter(bool state);

public slots:
    void menuButtonPressed(ScreensContainer::ScreenId id);
    // FIXME
//    virtual void footerItemSelected(int );

private:
    QScrollArea *m_scrollArea;
    QWidget *m_scrollAreaWidgetContents;
    CustomGrid *m_contentGrid;
};

#endif // CUSTOMMENU_H
