#include "customfooteritem.h"
#include "QKeyEvent"
#include <QDebug>
#include "gui_components/customcombobox.h"
CustomFooterItem::CustomFooterItem(int col, QWidget *parent): QLabel(parent), m_col(col), m_comboBox(NULL), m_comboVisible(false)
{
    if (this->objectName().isEmpty())
        this->setObjectName("FooterItem");
    this->resize(200, 50);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(1);
    sizePolicy.setVerticalStretch(1);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    this->setSizePolicy(sizePolicy);
    this->setMinimumSize(QSize(200, 50));
    this->setMaximumSize(QSize(400, 100));

    QPalette palette1;
    QBrush brush2(QColor(245,245,245, 255));
    brush2.setStyle(Qt::SolidPattern);
    palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
    palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
    palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
    palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
    QBrush brush3(QColor(0,141,210, 255));
    brush3.setStyle(Qt::SolidPattern);
    palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
    palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
    this->setPalette(palette1);
    this->setAutoFillBackground(true);

    QFont font;
    font.setPointSize(24);
    font.setBold(true);
    font.setWeight(75);
    font.setStyleStrategy(QFont::PreferAntialias);
    this->setFont(font);
    this->setLineWidth(0);
    this->setAlignment(Qt::AlignLeading|Qt::AlignHCenter|Qt::AlignVCenter);
    this->setMargin(10);
    this->setEnabled(false);
}

CustomFooterItem::~CustomFooterItem()
{

}

void CustomFooterItem::popUp()
{
    if(m_comboBox)
    {
        if(!m_comboVisible)
        {
            m_comboVisible = true;
            m_comboBox->move(this->x() , 480-50-m_comboBox->height() );
            m_comboBox->setVisible(true);
            m_comboBox->setEnabled(true);
        }
        else
        {
            m_comboVisible = false;
        }
    }
}
#ifdef TOUCH
void CustomFooterItem::mouseReleaseEvent(QMouseEvent * ev)
{
    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__;
    popUp();
    emit footerClicked(m_col);
    ev->ignore();
}
#endif
void CustomFooterItem::setComboBox(CustomComboBox *comboBox)
{
//    this->setEnabled(true);
    m_comboBox = comboBox;
}

