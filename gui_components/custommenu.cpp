#include "custommenu.h"
#include <QScrollBar>
#include <QKeyEvent>
#include "custommenubutton.h"
#include "customgrid.h"
#include "screenscontainer.h"
#include "customfooter.h"

#include <QDebug>


CustomMenu::CustomMenu(ScreensContainer::ScreenId id, ScreensContainer *parent, GuiHandler *guiHandler) :
    Screen(id,guiHandler, parent)
{   
    m_scrollArea = new QScrollArea(this);
    m_scrollArea->setObjectName("scrollArea");
    m_scrollArea->setMinimumSize(QSize(800, 350)); //Exclude footer
    m_scrollArea->setMaximumSize(QSize(1600, 700));
    m_scrollArea->setAutoFillBackground(true);
    m_scrollArea->setFrameShape(QFrame::NoFrame);
    m_scrollArea->setFrameShadow(QFrame::Plain);
    m_scrollArea->setLineWidth(0);
    m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_scrollArea->setWidgetResizable(true);

    QScrollBar * verticalScrollBar = m_scrollArea->verticalScrollBar();
//    verticalScrollBar->setStyleSheet("QScrollBar:vertical {border-left: 3px solid #F5F5F5 ; border-right: 0px solid #F5F5F5 ;border-top: 0px solid #F5F5F5; border-bottom: 0px solid #F5F5F5 ;background: #F5F5F5 ;width: 10px;margin: 0px 0 0px 0;}"
//                                     "QScrollBar::handle:vertical {background: #008DD2; min-height: 5px;}"
//                                     "QScrollBar::add-line:vertical {border-left: 1px solid #F5F5F5 ; border-right: 1px solid #F5F5F5 ;border-top: 0px solid #F5F5F5; border-bottom: 1px solid #F5F5F5 ; background: #F5F5F5;height: 10px;subcontrol-position: bottom;subcontrol-origin: margin;}"
//                                     "QScrollBar::sub-line:vertical { border-left: 1px solid #F5F5F5 ; border-right: 1px solid #F5F5F5 ;border-top: 1px solid #F5F5F5; border-bottom: 0px solid #F5F5F5 ; background: #F5F5F5; height: 10px;subcontrol-position: top;subcontrol-origin: margin;}"
//                                     "QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {border: none solid #F5F5F5;height: 0px;background: #F5F5F5;}"
//                                     "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {background: none;}");

    verticalScrollBar->setStyleSheet("QScrollBar:vertical {border-left: 0px solid #F5F5F5 ; border-right: 0px solid #F5F5F5 ;border-top: 0px solid #F5F5F5; border-bottom: 0px solid #F5F5F5 ;background: #F5F5F5 ;width: 45px;margin: 0px 0 0px 0;}"
                       "QScrollBar::handle:vertical {background: #008DD2; min-height: 5px;}"
                       "QScrollBar::add-line:vertical {border-left: 0px solid #F5F5F5 ; border-right: 0px solid #F5F5F5 ;border-top: 0px solid #F5F5F5; border-bottom: 0px solid #F5F5F5 ; background: #F5F5F5;height: 10px;subcontrol-position: bottom;subcontrol-origin: margin;}"
                       "QScrollBar::sub-line:vertical { border-left: 0px solid #F5F5F5 ; border-right: 0px solid #F5F5F5 ;border-top: 0px solid #F5F5F5; border-bottom: 0px solid #F5F5F5 ; background: #F5F5F5; height: 10px;subcontrol-position: top;subcontrol-origin: margin;}"
                       "QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {border-left: 0px solid #F5F5F5 ; border-right: 0px solid #F5F5F5;height: 30px;background: #008DD2;}"
                       "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {background: none;}");
    m_scrollAreaWidgetContents = new QWidget();
    m_scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");

    m_contentGrid = new CustomGrid(m_scrollAreaWidgetContents);
    m_contentGrid->setSpacing(0);
    m_contentGrid->setObjectName("gridLayout_2");
    m_contentGrid->setContentsMargins(5, 5, 5, 5);

    m_scrollArea->setWidget(m_scrollAreaWidgetContents);
    m_mainGrid->addWidget(m_scrollArea, 1, 0, 1, 1);
}

CustomMenu::~CustomMenu()
{
    delete m_mainGrid;
    delete m_scrollArea;
    delete m_scrollAreaWidgetContents;
    delete m_contentGrid;
}

void CustomMenu::addMenuItem(CustomMenuButton *item, int row, int col)
{
//    item->setParent(this);
    m_contentGrid->addWidget(item, row, col, 1, 1);
    m_contentGrid->addRowActive(col);
    connect(item, SIGNAL(buttonClicked(ScreensContainer::ScreenId)), this, SLOT(menuButtonPressed(ScreensContainer::ScreenId)));
}



void CustomMenu::showEvent(QShowEvent *event)
{
    footer()->setFocus();
    emit updateFooter(true);
}

void CustomMenu::hideEvent(QHideEvent *event)
{
    emit updateFooter(false);
}

#ifdef KEYS
void CustomMenu::resetMenu()
{
    m_contentGrid->selectCell(0,0);
}

void CustomMenu::keyPressEvent(QKeyEvent *)
{

}

void CustomMenu::keyReleaseEvent(QKeyEvent * ev)
{
//    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__ << ev->key();
    switch (ev->key())
    {
    case key_down:
        m_contentGrid->navigateUp();
        m_scrollArea->ensureWidgetVisible(m_contentGrid->getItem(), 0, 0);
        ev->accept();
        break;
    case key_up:
        m_contentGrid->navigateDown();
        m_scrollArea->ensureWidgetVisible(m_contentGrid->getItem(), 0, 0);
        ev->accept();
        break;
    case key_left:
        m_contentGrid->navigateCol(0);
        footerItemSelected(0);
        break;
    case key_leftcenter:
        m_contentGrid->navigateCol(1);
        footerItemSelected(1);
        break;
    case key_rightcenter:
        m_contentGrid->navigateCol(2);
        footerItemSelected(2);
        break;
    case key_right:
        m_contentGrid->navigateCol(3);
        footerItemSelected(3);
        break;
    case key_ok:
        ev->accept();
        m_contentGrid->selectCurrent();
        break;
    default:
        ev->ignore();
        break;
    }
}

#endif
void CustomMenu::menuButtonPressed(ScreensContainer::ScreenId id)
{
//    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__;
    m_screenManager->setScreen(id);
}

//void CustomMenu::footerItemSelected(int col)
//{
//    m_contentGrid->navigateCol(col);
//    emit footerSelected(col);
//}

CustomGrid *CustomMenu::contentGrid() const
{
    return m_contentGrid;
}

void CustomMenu::setContentGrid(CustomGrid *contentGrid)
{
    m_contentGrid = contentGrid;
}



