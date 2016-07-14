#include "popup/popupbutton.h"
#include <QDebug>

PopupButton::PopupButton(QWidget *parent) : QLabel(parent), m_pointerToScreen(ScreensContainer::notAssigned)
{
    this->setObjectName("this");
    QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    sizePolicy1.setHorizontalStretch(1);
    sizePolicy1.setVerticalStretch(1);
    sizePolicy1.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    this->setSizePolicy(sizePolicy1);
    this->setMinimumSize(QSize(200, 50));
    this->setMaximumSize(QSize(400, 100));

    QPalette palette;
    QBrush brush(QColor(227,30,36, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Base, brush);
    QBrush brush1(QColor(227,30,36, 255));
    brush1.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    this->setPalette(palette);
    this->setAutoFillBackground(true);
    QFont font;
    font.setPointSize(28);
    font.setBold(true);
    font.setWeight(75);
    font.setStyleStrategy(QFont::PreferAntialias);
    this->setFont(font);
    this->setLineWidth(0);
    this->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
    this->setMargin(10);
    this->setText("Hola");
    this->setFrameShape(QFrame::Box);
    this->setFrameShadow(QFrame::Raised);
}

void PopupButton::setSelected(bool selected)
{
    m_selected = selected;

    if(m_selected)
    {
        QPalette Pal(this->palette());
        Pal.setColor(QPalette::Background, QColor(139,0,0));
//        Pal.setColor(QPalette::Foreground, C_LIGHTGREY);
        this->setPalette(Pal);
    }
    else
    {
        QPalette Pal(this->palette());
        Pal.setColor(QPalette::Background, QColor(227,30,36));
        this->setPalette(Pal);
//        if(signal)
//           emit buttonClicked(m_id);
    }
}

#ifdef TOUCH
void PopupButton::mousePressEvent(QMouseEvent *)
{
    setSelected(true);
}

void PopupButton::mouseReleaseEvent(QMouseEvent *)
{
    setSelected(false);
}

ScreensContainer::ScreenId PopupButton::pointerToScreen() const
{
    return m_pointerToScreen;
}

void PopupButton::setPointerToScreen(const ScreensContainer::ScreenId &pointerToScreen)
{
    m_pointerToScreen = pointerToScreen;
}
#endif
