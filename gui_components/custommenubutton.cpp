#include "custommenubutton.h"

CustomMenuButton::CustomMenuButton(QWidget *parent, ScreensContainer::ScreenId id) : CustomButton(parent),m_selected(false), m_id(id)
{
    if (this->objectName().isEmpty())
        this->setObjectName("CustomButton");
    this->resize(200, 175);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(1);
    sizePolicy.setVerticalStretch(1);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    this->setSizePolicy(sizePolicy);
    this->setMinimumSize(QSize(180, 175));
    this->setMaximumSize(QSize(360, 350));
//    this->setFocusPolicy(Qt::StrongFocus);
    this->setAutoFillBackground(true);

    m_layout = new QVBoxLayout(this);
    m_layout->setSpacing(0);
    m_layout->setObjectName("customButtonLayout");
    m_layout->setContentsMargins(0, 0, 0, 0);


    m_image = new QLabel(this);
    m_image->setObjectName("image");
    sizePolicy.setHeightForWidth(m_image->sizePolicy().hasHeightForWidth());
    m_image->setSizePolicy(sizePolicy);
    m_image->setMinimumSize(QSize(180, 125));
    m_image->setMaximumSize(QSize(360, 250));
    m_image->setAlignment(Qt::AlignCenter);
    m_image->setAutoFillBackground(true);
    m_layout->addWidget(m_image);

    m_text = new QLabel(this);
    m_text->setObjectName("text");
    sizePolicy.setHeightForWidth(m_text->sizePolicy().hasHeightForWidth());
    m_text->setSizePolicy(sizePolicy);
    m_text->setMinimumSize(QSize(180, 50));
    m_text->setMaximumSize(QSize(360, 100));

//    QPalette palette1;
    QBrush brush2(QColor(80,87,94, 255));
    brush2.setStyle(Qt::SolidPattern);
    palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
    palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
    palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
    palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
    QBrush brush3(QColor(0,141,210));
    brush3.setStyle(Qt::SolidPattern);
    palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
    palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
    m_text->setPalette(palette1);
    m_text->setAutoFillBackground(true);


    QFont font;
    font.setPointSize(22);
    font.setBold(true);
    font.setWeight(75);
    m_text->setFont(font);
    m_text->setAutoFillBackground(true);
    m_text->setLineWidth(0);
    m_text->setTextFormat(Qt::PlainText);
    m_text->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    m_text->setWordWrap(false);

    m_layout->addWidget(m_text);

    //    QMetaObject::connectSlotsByName(CustomButton);

}

CustomMenuButton::~CustomMenuButton()
{
    delete m_image;
    delete m_text;
    delete m_layout;
}

void CustomMenuButton::setText(const QString & text)
{
    m_text->setText(text);
}

void CustomMenuButton::setImage(const QPixmap & image)
{
    m_image->setPixmap(image);
}

#ifdef TOUCH
void CustomMenuButton::mousePressEvent(QMouseEvent *)
{
    setSelected(true);
}

void CustomMenuButton::mouseReleaseEvent(QMouseEvent *)
{
    setSelected(false, true);
}

#endif

ScreensContainer::ScreenId CustomMenuButton::id() const
{
    return m_id;
}

void CustomMenuButton::setId(const ScreensContainer::ScreenId &id)
{
    m_id = id;
}

bool CustomMenuButton::selected() const
{
    return m_selected;
}

void CustomMenuButton::setSelected(bool selected, bool signal)
{
    m_selected = selected;
    QPalette PalText(m_text->palette());
    QPalette PalImage(m_image->palette());

    if(m_selected)
    {
//        PalImage.setColor(QPalette::Background, C_RED);
        PalText.setColor(QPalette::Background, C_LIGHTBLUE);
        PalText.setColor(QPalette::Foreground, C_LIGHTGREY);
        PalImage.setColor(QPalette::Background, C_DARKGREY);
        m_text->setPalette(PalText);
        m_image->setPalette(PalImage);
    }
    else
    {
        PalText.setColor(QPalette::Background, C_LIGHTGREY);
        m_text->setPalette(palette1);
        PalImage.setColor(QPalette::Background, C_LIGHTGREY);
        m_image->setPalette(PalImage);
        if(signal)
            emit buttonClicked(m_id);
    }

    m_image->setPalette(PalImage);
}




CustomButton::CustomButton(QWidget *parent) : QLabel(parent)
{

}

CustomButton::~CustomButton()
{

}
