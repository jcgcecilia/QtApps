#include "keyitem.h"

#include <QDebug>

KeyItem::KeyItem(const QString &text, QWidget *parent) : QLabel(parent),
    m_text(text)
{
    if (this->objectName().isEmpty())
        this->setObjectName(text);
    this->resize(400, 300);
    QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    this->setSizePolicy(sizePolicy);
    this->setMinimumSize(QSize(75, 75));
    this->setAutoFillBackground(true);

    QFont font;
    font.setPointSize(28);
    font.setBold(true);
    font.setWeight(75);
    font.setStyleStrategy(QFont::PreferAntialias);
    this->setFont(font);
    this->setLineWidth(0);
    this->setAlignment(Qt::AlignLeading|Qt::AlignHCenter|Qt::AlignVCenter);
    this->setMargin(10);

    QPalette palette1;
    QBrush brush2(QColor(Qt::red));
    brush2.setStyle(Qt::SolidPattern);
    palette1.setBrush(QPalette::Text, brush2);
    this->setPalette(palette1);
//    qDebug() << __PRETTY_FUNCTION__ << text;
    setText(text);
}

void KeyItem::setSelected(bool selected)
{
    QPalette PalText(this->palette());
    if(selected)
    {
        PalText.setColor(QPalette::Background, C_LIGHTBLUE);
        PalText.setColor(QPalette::Foreground, C_LIGHTGREY);
//        this->setFixedSize(this->width()+10, this->height()+10);
        emit keyBoardPressed(m_text);
    }
    else
    {
        PalText.setColor(QPalette::Background, C_LIGHTGREY);
    }
    this->setPalette(PalText);
}

#ifdef TOUCH
void KeyItem::mousePressEvent(QMouseEvent *)
{
    setSelected(false);
}

void KeyItem::mouseReleaseEvent(QMouseEvent *)
{
    setSelected(true);
}
#endif


