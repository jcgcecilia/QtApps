#include "customscrollwidgets.h"
#include <QScrollBar>
#include <QKeyEvent>

#include "custommenubutton.h"
#include "customgrid.h"


CustomScrollWidgets::CustomScrollWidgets(QWidget *parent) : QWidget(parent)
{

//    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//    sizePolicy.setHorizontalStretch(0);
//    sizePolicy.setVerticalStretch(0);
//    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
//    this->setSizePolicy(sizePolicy);
    this->setMinimumSize(QSize(800, 300)); //Exclude footer
    this->setMaximumSize(QSize(1600, 600));
    m_scrollArea = new QScrollArea(this);
    m_scrollArea->setObjectName("scrollArea");
    m_scrollArea->setMinimumSize(QSize(800, 300)); //Exclude footer
    m_scrollArea->setMaximumSize(QSize(1600, 600));
    m_scrollArea->setAutoFillBackground(true);
    m_scrollArea->setFrameShape(QFrame::NoFrame);
    m_scrollArea->setFrameShadow(QFrame::Plain);
    m_scrollArea->setLineWidth(0);
    m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_scrollArea->setWidgetResizable(true);

    QScrollBar * verticalScrollBar = m_scrollArea->verticalScrollBar();
    verticalScrollBar->setStyleSheet("QScrollBar:vertical {border-left: 3px solid #F5F5F5 ; border-right: 0px solid #F5F5F5 ;border-top: 0px solid #F5F5F5; border-bottom: 0px solid #F5F5F5 ;background: #F5F5F5 ;width: 10px;margin: 0px 0 0px 0;}"
                                     "QScrollBar::handle:vertical {background: #008DD2; min-height: 5px;}"
                                     "QScrollBar::add-line:vertical {border-left: 1px solid #F5F5F5 ; border-right: 1px solid #F5F5F5 ;border-top: 0px solid #F5F5F5; border-bottom: 1px solid #F5F5F5 ; background: #F5F5F5;height: 10px;subcontrol-position: bottom;subcontrol-origin: margin;}"
                                     "QScrollBar::sub-line:vertical { border-left: 1px solid #F5F5F5 ; border-right: 1px solid #F5F5F5 ;border-top: 1px solid #F5F5F5; border-bottom: 0px solid #F5F5F5 ; background: #F5F5F5; height: 10px;subcontrol-position: top;subcontrol-origin: margin;}"
                                     "QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {border: none solid #F5F5F5;height: 0px;background: #F5F5F5;}"
                                     "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {background: none;}");

    m_scrollAreaWidgetContents = new QWidget();

    m_contentGrid = new CustomGrid(m_scrollAreaWidgetContents);
    m_contentGrid->setSpacing(0);
    m_contentGrid->setObjectName("gridLayout_2");
    m_contentGrid->setContentsMargins(0, 0, 0, 0);
    m_scrollArea->setWidget(m_scrollAreaWidgetContents);
}

void CustomScrollWidgets::addMenuItem(CustomButton *item, int row, int col)
{
    m_contentGrid->addWidget(item, row, col, 1, 1);
}

void CustomScrollWidgets::resetGrid(int row, int col)
{
   m_contentGrid->selectCell(row,col);
}

