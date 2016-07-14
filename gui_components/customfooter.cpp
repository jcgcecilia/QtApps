#include "customfooter.h"
#include "customfooteritem.h"
#include <QKeyEvent>
#include <QDebug>
#include "application/application.h"
#include "application/globaldictionary.h"
#include "selectionlist/selectionlist.h"
CustomFooter::CustomFooter(Screen *parent) : m_parentScreen(parent)
{
    if (this->objectName().isEmpty())
        this->setObjectName("Footer");
    this->resize(800, 50);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    this->setSizePolicy(sizePolicy);
    this->setMinimumSize(QSize(800, 50));
    this->setMaximumSize(QSize(1600, 100));
    QPalette palette;
    QBrush brush(QColor(255, 255, 255, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Base, brush);
    QBrush brush1(QColor(80, 87, 94, 255));
    brush1.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    this->setPalette(palette);
    this->setAutoFillBackground(true);
    m_horizontalLayout = new QHBoxLayout(this);
    m_horizontalLayout->setObjectName("horizontalLayout");
    m_horizontalLayout->setSpacing(0);
    m_horizontalLayout->setContentsMargins(0,0,0,0);
    this->setFocusPolicy(Qt::StrongFocus);
}

CustomFooter::~CustomFooter()
{
    delete m_horizontalLayout;
}

void CustomFooter::initialize()
{
    for(int i = 0 ;  i < 4 ; i++)
    {
        CustomFooterItem * tmp = new CustomFooterItem(i, this);
        tmp->setVisible(true);
        m_horizontalLayout->addWidget(tmp, 1);
        connect(tmp, SIGNAL(footerClicked(int)), this, SIGNAL(footerItemSelected(int)));
    }
}

void CustomFooter::setText(int col, const QString & text,  bool active)
{
    QWidget * tmp = m_horizontalLayout->itemAt(col)->widget();
    static_cast<CustomFooterItem *>(tmp)->setText(text);
    static_cast<CustomFooterItem *>(tmp)->setVisible(active);
    static_cast<CustomFooterItem *>(tmp)->setEnabled(active);
}

void CustomFooter::setImage(int col, const QPixmap & image, bool active)
{
    QWidget * tmp = m_horizontalLayout->itemAt(col)->widget();
    static_cast<CustomFooterItem *>(tmp)->setPixmap(image);
    static_cast<CustomFooterItem *>(tmp)->setVisible(active);
    static_cast<CustomFooterItem *>(tmp)->setEnabled(active);
}

void CustomFooter::setComboBox(int col, CustomComboBox *combo, bool active)
{
    QWidget * tmp = m_horizontalLayout->itemAt(col)->widget();
    static_cast<CustomFooterItem *>(tmp)->setComboBox(combo);
    static_cast<CustomFooterItem *>(tmp)->setVisible(active);
    static_cast<CustomFooterItem *>(tmp)->setEnabled(active);
}

void CustomFooter::updateFooterItem(int col, bool visible)
{
    QWidget * tmp = m_horizontalLayout->itemAt(col)->widget();
    static_cast<CustomFooterItem *>(tmp)->setVisible(visible);
    static_cast<CustomFooterItem *>(tmp)->setEnabled(visible);
}

bool CustomFooter::isItemEnabled(int col)
{
    return m_horizontalLayout->itemAt(col)->widget()->isEnabled();
}

#ifdef KEYS
void CustomFooter::keyPressEvent(QKeyEvent * ev)
{
    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__;
    ML300Application::sendEvent(m_parentScreen, ev);
}

void CustomFooter::keyReleaseEvent(QKeyEvent * ev)
{
    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__;
    switch (ev->key())
    {
    QWidget * tmp;
    case key_left:
        tmp = m_horizontalLayout->itemAt(0)->widget();
        static_cast<CustomFooterItem *>(tmp)->popUp();
        break;
    case key_leftcenter:
       tmp = m_horizontalLayout->itemAt(1)->widget();
        static_cast<CustomFooterItem *>(tmp)->popUp();
        break;
    case key_rightcenter:
        tmp = m_horizontalLayout->itemAt(2)->widget();
        static_cast<CustomFooterItem *>(tmp)->popUp();
        break;
    case key_right:
        tmp = m_horizontalLayout->itemAt(3)->widget();
        static_cast<CustomFooterItem *>(tmp)->popUp();
        break;
    default:
        ev->ignore();
        break;
    }
    ML300Application::sendEvent(m_parentScreen, ev);
}
#endif


