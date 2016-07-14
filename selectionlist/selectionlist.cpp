#include "selectionlist.h"
#include <QMouseEvent>
#include <QLabel>

#include <QDebug>
SelectionList::SelectionList(QWidget *parent) :
    m_comboVisible(false)
{
    if (this->objectName().isEmpty())
        this->setObjectName("PopUpWithButtons");
    QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    this->setSizePolicy(sizePolicy);
    this->setMinimumSize(QSize(200, 50));
    this->setMaximumSize(QSize(400, 100));
    this->setAutoFillBackground(true);
}

#ifdef TOUCH
void SelectionList::mousePressEvent(QMouseEvent *)
{
    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__;
}

void SelectionList::mouseReleaseEvent(QMouseEvent * ev)
{
    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__;/*
    if(m_comboBox->isVisible())
    {
        m_comboBox->setVisible(false);
        m_comboBox->setEnabled(false);
    }
    else
    {*/
    popUp();
//    if(!m_comboVisible)
//    {
//        m_comboVisible = true;
//        m_comboBox->move(this->x() , 480-50-m_comboBox->height() );
//        m_comboBox->setVisible(true);
//        m_comboBox->setEnabled(true);
//    }
//    else
//    {
//        m_comboVisible = false;
//    }
    //    }
    ev->accept();
}
#endif

#ifdef KEYS
//void SelectionList::keyPressEvent(QKeyEvent *ev)
//{
//    if(m_comboBox.isVisible())
//    {
//        m_comboBox.setVisible(false);
//        m_comboBox.setEnabled(false);
//    }
//}


#endif

void SelectionList::selectionItemSelected(int id)
{
    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__ << id ;
    m_comboBox->setVisible(false);
    m_comboBox->setEnabled(false);
}

void SelectionList::setComboBox(CustomComboBox *comboBox)
{
    m_comboBox = comboBox;
}

void SelectionList::popUp()
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


