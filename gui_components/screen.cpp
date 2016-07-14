#include "screen.h"
#include "navigationhandler.h"
#include <QLayout>
#include "customfooter.h"
#include <QLabel>
#include <QKeyEvent>
#include <QDebug>
#include <QMetaEnum>
#include "gui_handler/guihandler.h"

Screen::Screen(ScreensContainer::ScreenId id , GuiHandler *guiHandler, ScreensContainer *parent)
    : m_id(id),
      m_footer(NULL),
      m_screenManager(parent),
      m_guiHandler(guiHandler)
{
    const QMetaObject &mo = ScreensContainer::staticMetaObject;
    int index = mo.indexOfEnumerator("ScreenId"); // watch out during refactorings
    QMetaEnum metaEnum = mo.enumerator(index);

    if (this->objectName().isEmpty())
        this->setObjectName(metaEnum.valueToKey(id));
    this->resize(800, 400);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    this->setSizePolicy(sizePolicy);
    this->setMinimumSize(QSize(800, 400)); // this includes the footer
    this->setMaximumSize(QSize(1600, 800));

    m_mainGrid = new QGridLayout(this);
    m_mainGrid->setSpacing(0);
    m_mainGrid->setObjectName("gridLayout");
    m_mainGrid->setContentsMargins(0, 0, 5, 0);
    QPalette palette;
    QBrush brush1(QColor(245, 245, 245, 255));
    brush1.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    connect(m_guiHandler, SIGNAL(goToPrevious()), this, SLOT(goToPrevious()));
}

Screen::~Screen()
{
    delete m_footer;
}

void Screen::setFooter(CustomFooter *footer)
{
//    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__;
    m_footer = footer;
//    m_footer->setParent(this);
    m_mainGrid->addWidget(m_footer, 2, 0, 1, 1);
#if TOUCH
    connect(footer, SIGNAL(footerItemSelected(int)), this, SLOT(footerItemSelected(int)));
#endif
}

CustomFooter *Screen::footer() const
{
    return m_footer;
}


ScreensContainer::ScreenId Screen::id() const
{
    return m_id;
}

void Screen::setId(const ScreensContainer::ScreenId &id)
{
    m_id = id;
}

void Screen::goToPrevious()
{
    m_screenManager->setPreviousScreen();
}

void Screen::goToNext()
{

}

void Screen::footerItemSelected(int col)
{
//    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__;
    if(m_guiHandler)
        m_guiHandler->footerAction(col);
    //    emit footerSelected(col);
}

void Screen::updateFooter(int col, bool active)
{
    m_footer->updateFooterItem(col, active);
}
#ifdef KEYS
void Screen::keyPressEvent(QKeyEvent *ev)
{

}

void Screen::keyReleaseEvent(QKeyEvent *ev)
{
    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__;
    switch (ev->key())
    {
    case key_return:
        goToPrevious();
    default:
        break;
    }
    ev->accept();
}
#endif



