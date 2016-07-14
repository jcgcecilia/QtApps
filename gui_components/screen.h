#ifndef SCREEN_H
#define SCREEN_H

#include <QObject>
#include <QWidget>
#include "screenscontainer.h"
//#include "customfooter.h"

class CustomGrid;
class NavigationHandler;
class CustomFooter;
class QGridLayout;
class QLabel;

#ifndef ARM
enum KeyMapping
{
    key_up          =  Qt::Key_Up ,
    key_ok          =  Qt::Key_Return,
    key_down        =  Qt::Key_Down ,
    key_mute        =  Qt::Key_M ,
    key_left        =  Qt::Key_1  ,
    key_leftcenter  =  Qt::Key_2 ,
    key_rightcenter =  Qt::Key_3 ,
    key_right       =  Qt::Key_4  ,
    key_return      =  Qt::Key_Backspace  ,
    key_black       =  Qt::Key_P,
    key_on          =  Qt::Key_F1  ,
    key_off         =  Qt::Key_F2   ,
    key_gbon        =  Qt::Key_F3,
    key_gboff       =  Qt::Key_F4  ,
    key_tbon        =  Qt::Key_F5  ,
    key_tboff       =  Qt::Key_F6  ,
    key_auto        =  Qt::Key_F7   ,
    key_direction   =  Qt::Key_F8 ,
    key_priority    =  Qt::Key_F9  ,
    key_semi        =  Qt::Key_F10
};
#else
enum KeyMapping
{
    key_up          =  16777235 ,       //Key 1, code 0x31
    key_ok          =  16777220 ,      //Key 2, code 0x33
    key_down        =  16777237 ,     //Key 3, code 0x32
    key_mute        =  Qt::Key_0 ,      //Key 4, code 0x31
    key_left        =  16777264  ,     //Key 5, code 0x35
    key_leftcenter  =  16777265 ,      //Key 6, code 0x30
    key_rightcenter =  16777266 ,  //Key 7, code 0x2d
    key_right       =  16777267  ,     //Key 8, code 0x52
    key_return      =  16777219  ,     //Key 9, code 0x38
    key_black       =  Qt::Key_3,
    key_on          =  Qt::Key_1  ,      // code 0x36
    key_off         =  Qt::Key_2   ,     // code 0x34
    key_gbon        =  16777268  ,  // code 0x3D
    key_gboff       =  16777270  ,      // code 0x39
    key_tbon        =  16777269  ,  // code 0x57
    key_tboff       =  16777271  ,  // code 0x51
    key_auto        =  16777272   , // code 0x37
    key_direction   =  16777275 ,   // code 0x54
    key_priority    =  16777273  ,  // code 0x45
    key_semi        =  16777274
};
#endif
class CustomFooter;
class GuiHandler;

class Screen : public QWidget
{
    Q_OBJECT

public:

    Screen(ScreensContainer::ScreenId id, GuiHandler * guiHandler, ScreensContainer *parent = 0);
    virtual ~Screen();
    void setFooter(CustomFooter *footer);
    CustomFooter* footer() const;

    ScreensContainer::ScreenId id() const;
    void setId(const ScreensContainer::ScreenId &id);

public slots:
    virtual void footerItemSelected(int col);
    void updateFooter(int col, bool active = false);
    void goToPrevious();
    void goToNext();

signals:
    void footerSelected(int );

protected:
#ifdef KEYS
    void keyPressEvent(QKeyEvent * ev);
    void keyReleaseEvent(QKeyEvent *ev);
#endif
    QGridLayout *m_mainGrid;
    ScreensContainer::ScreenId m_id;
    CustomFooter * m_footer;
    //    QLabel * m_screenTitle;
    ScreensContainer * m_screenManager;
    GuiHandler * m_guiHandler;
};

#endif // SCREEN_H
