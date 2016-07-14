#include "customcombobox.h"
#include <QAbstractItemView>
#include <QMouseEvent>
#include "screen.h"

#include <QDebug>
CustomComboBox::CustomComboBox(QWidget *parent) :
     QWidget(parent), m_selectionListContainer(this)
{
    this->setWindowFlags(Qt::Popup);
    if (this->objectName().isEmpty())
        this->setObjectName("PopUpWithButtons");
    QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    this->setSizePolicy(sizePolicy2);
    this->setMinimumSize(QSize(0, 0));
    this->setMaximumSize(QSize(400, 400));
    this->setAutoFillBackground(true);
    this->setVisible(false);
    m_selectionListContainer.setSpacing(2);
    m_selectionListContainer.setContentsMargins(0,0,0,0);

}

void CustomComboBox::init()
{
    CustomComboBoxItem *tmp = new CustomComboBoxItem(0, this);
    tmp->setText("Config");
    addMenuItem(tmp, 0);
    this->setMinimumSize(200, this->height()+50);

    tmp = new CustomComboBoxItem(1, this);
    tmp->setText("Livedata");
    addMenuItem(tmp, 1);
    this->setMinimumSize(200, this->height()+50);

    tmp = new CustomComboBoxItem(2, this);
    tmp->setText("Control Panel");
    addMenuItem(tmp, 2);
//    addMenuItem(new CustomComboBoxItem(2, this), 2);
    this->setMinimumSize(200, this->height()+50);

    tmp = new CustomComboBoxItem(3, this);
    tmp->setText("Login");
    addMenuItem(tmp, 3);
//    addMenuItem(new CustomComboBoxItem(3, this), 3);
    this->setMinimumSize(200, this->height()+50);
}

void CustomComboBox::addMenuItem(CustomComboBoxItem *item, int row)
{
    m_selectionListContainer.addWidget(item, row, 0, 1, 1);
    //    m_selectionListContainer.addRowActive(col);
    connect(item, SIGNAL(selectioItemPressed(int)),
            this, SLOT(selectionItemSelected(int)));
}

void CustomComboBox::showEvent(QShowEvent *)
{
#ifdef KEYS
    m_selectionListContainer.selectCell(1,0, true);
#endif
}

void CustomComboBox::hideEvent(QHideEvent *)
{
    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__;
}

#ifdef KEYS
void CustomComboBox::keyPressEvent(QKeyEvent *)
{

}

void CustomComboBox::keyReleaseEvent(QKeyEvent * ev)
{
    switch (ev->key()) {
    case key_up:
        m_selectionListContainer.navigateDown();
        break;
    case key_down:
        m_selectionListContainer.navigateUp();
        break;
    case key_ok:

        break;
    default:
        this->hide();
        break;
    }
}

#endif

CustomComboBoxItem::CustomComboBoxItem(int _id, QWidget *parent)
    : CustomButton(parent),
      m_id(_id)
{
    if (this->objectName().isEmpty())
        this->setObjectName("SelectionCustomButton");
    this->resize(200, 50);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(1);
    sizePolicy.setVerticalStretch(1);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    this->setSizePolicy(sizePolicy);
    this->setMinimumSize(QSize(200, 50));
    this->setMaximumSize(QSize(400, 100));
    this->setAutoFillBackground(true);

    QPalette Pal(this->palette());
    Pal.setColor(QPalette::Background, QColor(80, 87, 94));
    Pal.setColor(QPalette::Foreground, C_LIGHTGREY);
    this->setPalette(Pal);
//   setMouseTracking(true);

    QFont font;
    font.setPointSize(22);
    font.setBold(true);
    font.setWeight(75);
    this->setFont(font);
    this->setAutoFillBackground(true);
    this->setLineWidth(0);
    this->setTextFormat(Qt::PlainText);
    this->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    this->setWordWrap(false);
}

CustomComboBoxItem::~CustomComboBoxItem()
{

}

//void CustomComboBoxItem::setText(const QString & _text)
//{
//    m_selectionItemText->setText(_text);
//}

void CustomComboBoxItem::setSelected(bool selected, bool signal)
{
    QPalette Pal(this->palette());
    if(selected)
    {
//        PalImage.setColor(QPalette::Background, C_RED);
        Pal.setColor(QPalette::Background, C_LIGHTBLUE);
        Pal.setColor(QPalette::Foreground, C_LIGHTGREY);
    }
    else
    {
        Pal.setColor(QPalette::Background, QColor(80, 87, 94));
        Pal.setColor(QPalette::Foreground, C_LIGHTGREY);
        if(signal)
        {

        }
//            emit buttonClicked(m_id);
    }
    this->setPalette(Pal);
}


#ifdef TOUCH
void CustomComboBoxItem::mousePressEvent(QMouseEvent *)
{
    setSelected(true, false);
}
void CustomComboBoxItem::mouseReleaseEvent(QMouseEvent * ev)
{
    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__<< m_id;
//    emit selectioItemPressed(m_id);
    setSelected(false, true);
    ev->ignore();
}

void CustomComboBoxItem::mouseDoubleClickEvent(QMouseEvent * ev)
{
    ev->ignore();
}

//void SelectionListItem::mouseMoveEvent(QMouseEvent *)
//{
//    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__;
//}
#endif
