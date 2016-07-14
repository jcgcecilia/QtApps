#include "customtableview.h"
#include <QScrollBar>
#include <QDebug>
#include <QHeaderView>
#include "gui_components/screen.h"
#include <QKeyEvent>

CustomTableView::CustomTableView(QWidget *parent) : QTableView(parent)
{
    this->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->setSelectionMode(QAbstractItemView::SingleSelection);
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);

    if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("this"));
    this->resize(800, 300);
    QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    this->setSizePolicy(sizePolicy);
    this->setMinimumSize(QSize(800, 300));
    this->setMaximumSize(QSize(1600, 700));
    this->setAutoFillBackground(true);

    this->setFrameShape(QFrame::NoFrame);
    this->setFrameShadow(QFrame::Plain);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setAlternatingRowColors(true);
    this->setShowGrid(false);
    this->setGridStyle(Qt::NoPen);
    this->setSortingEnabled(true);
    this->setFocusPolicy(Qt::NoFocus);
    this->verticalHeader()->hide();

    //    this->setStyleSheet("QTableView::item:focus { background-color:#008DD2;  border: 0px }");

    QScrollBar* bar = new QScrollBar(this);


    bar->setStyleSheet("QScrollBar:vertical {border-left: 0px solid #F5F5F5 ; border-right: 0px solid #F5F5F5 ;border-top: 0px solid #F5F5F5; border-bottom: 0px solid #F5F5F5 ;background: #F5F5F5 ;width: 45px;margin: 0px 0 0px 0;}"
                       "QScrollBar::handle:vertical {background: #008DD2; min-height: 5px;}"
                       "QScrollBar::add-line:vertical {border-left: 0px solid #F5F5F5 ; border-right: 0px solid #F5F5F5 ;border-top: 0px solid #F5F5F5; border-bottom: 0px solid #F5F5F5 ; background: #F5F5F5;height: 10px;subcontrol-position: bottom;subcontrol-origin: margin;}"
                       "QScrollBar::sub-line:vertical { border-left: 0px solid #F5F5F5 ; border-right: 0px solid #F5F5F5 ;border-top: 0px solid #F5F5F5; border-bottom: 0px solid #F5F5F5 ; background: #F5F5F5; height: 10px;subcontrol-position: top;subcontrol-origin: margin;}"
                       "QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {border-left: 0px solid #F5F5F5 ; border-right: 0px solid #F5F5F5;height: 30px;background: #008DD2;}"
                       "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {background: none;}");

    setVerticalScrollBar(bar);
    verticalHeader()->hide();
    // Set Row height. Not applied to header
    verticalHeader()->setDefaultSectionSize(35);
    QHeaderView * hheader = horizontalHeader();
    //    hheader->setFont();
    QSizePolicy sizePolicyH(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    sizePolicyH.setHorizontalStretch(0);
    sizePolicyH.setVerticalStretch(0);
    sizePolicyH.setHeightForWidth(hheader->sizePolicy().hasHeightForWidth());
    hheader->setSizePolicy(sizePolicyH);
    hheader->setMinimumSize(QSize(800, 35));
    hheader->setMaximumSize(QSize(1600, 70));

    QFont fontH;
    fontH.setPointSize(15);
    hheader->setFont(fontH);

    hheader->setDefaultAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    hheader->setStyleSheet("QHeaderView::section {border-right: 0px solid #F5F5F5 ;border-top: 0px solid #F5F5F5; border-bottom: 0px solid #F5F5F5}"
                           "QHeaderView::down-arrow,QHeaderView::up-arrow {width: 0px; height: 0px}"
                           "QHeaderView::section { background-color: #C0C1C3 }"
                           "QHeaderView::section { color: #E5E5E5 }");


    // Set the normal/active, background color
    // QPalette::Background is obsolete, use QPalette::Window
//    QPalette palette = horizontalHeader()->palette();
//    palette.setColor( QPalette::Normal, QPalette::Window, Qt::red );
//    horizontalHeader()->setPalette( palette );

    // Set the palette on the header.

    QFont font;
    font.setPointSize(15);
    this->setFont(font);

    QPalette Pal(this->palette());
    Pal.setColor(QPalette::Highlight, C_LIGHTBLUE);
    Pal.setColor(QPalette::HighlightedText, C_WHITE);
    Pal.setColor(QPalette::Text, C_DEEPGREY);
    Pal.setColor(QPalette::Base, C_LIGHTGREY);
    Pal.setColor(QPalette::AlternateBase, C_LIGHTGREY2);
    this->setPalette(Pal);

//    connect(this, SIGNAL(clicked(QModelIndex)), this, SLOT(enteredRow(QModelIndex)));
//    connect(this, SIGNAL(entered(QModelIndex)), this, SLOT(enteredRow(QModelIndex)));
    connect(this, SIGNAL(doubleClicked(QModelIndex)), this,SLOT(selectedRow(QModelIndex)));
    //    connect(this, SIGNAL(enteredRow(int)), this, SLOT(enteredRow_(int)));
}

void CustomTableView::setColsWidth(const QList<int> &colsWidth)
{
    for(int i = 0; i < colsWidth.size(); i++)
    {
        setColumnWidth(i, colsWidth.at(i));
    }
}

void CustomTableView::scrollUp()
{
    if(currentIndex().isValid())
    {
        if(currentIndex().row() + 1 < model()->rowCount())
        {
            selectRow(currentIndex().row() + 1);
            emit enteredRow(currentIndex().row());
        }
    }
}

void CustomTableView::scrollDown()
{
    if(currentIndex().isValid())
    {
        if(currentIndex().row() - 1 >= 0 )
        {
            selectRow(currentIndex().row() - 1);
            emit enteredRow(currentIndex().row());
        }
    }
}

void CustomTableView::mouseReleaseEvent(QMouseEvent *event)
{
//    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__;
    emit enteredRow(currentIndex().row());
}

void CustomTableView::enteredRow(const QModelIndex & index)
{
//    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__;
    selectRow(index.row());
}

void CustomTableView::selectedRow(const QModelIndex &index)
{
//    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__ << index.row();
    emit selectedRow(currentIndex().row());
}
