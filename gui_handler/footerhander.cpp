#include "footerhander.h"
#include "gui_components/screen.h"
#include "gui_components/customgrid.h"
#include "gui_components/custommenu.h"
#include "gui_components/customfooter.h"
#include "gui_components/customtable.h"


#include <QDebug>
FooterHandler::FooterHandler(Screen * screen,QObject *parent) : QObject(parent), m_screen(screen)
{

}

Screen *FooterHandler::screen() const
{
    return m_screen;
}

void FooterHandler::setScreen(Screen *screen)
{
    m_screen = screen;
}


void FooterHandler::footerItemAction(int col)
{
    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__ << col;
    #ifdef TOUCH
    if(col == 0)
        m_screen->goToPrevious();
    #endif
}

void FooterHandler::listItemEnteredAction(int row)
{
    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__ << row;
    CustomTable * alarmTable = static_cast<CustomTable *>(m_screen);
    CustomFooter * footer = m_screen->footer();
    if(row % 2 == 0)
    {
        footer->updateFooterItem(3, true);
    }
    else
    {
        footer->updateFooterItem(3, false);
    }
}

void FooterHandler::listItemSelectedAction(int row)
{

}

void FooterHandler::meunuItemAction( bool action)
{
//    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__;
    CustomMenu * menu = static_cast<CustomMenu *>(m_screen);
    CustomFooter * footer = m_screen->footer();

//    foreach(int i, menu->contentGrid()->getRows())
//    {
//        footer->updateFooterItem(i, action);
//    }
}

