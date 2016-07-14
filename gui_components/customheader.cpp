#include "customheader.h"
#include "application/application.h"
#include "application/globaldictionary.h"

CustomHeader::CustomHeader(QWidget *parent) : QWidget(parent)
{
    if (this->objectName().isEmpty())
        this->setObjectName("this");
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
    m_horizontalLayout = new QHBoxLayout(this);
    m_horizontalLayout->setSpacing(0);
    m_horizontalLayout->setObjectName("horizontalLayout");
    m_horizontalLayout->setContentsMargins(0, 0, 0, 0);
    m_headerText = new QLabel(this);
    m_headerText->setObjectName("label");
    sizePolicy.setHeightForWidth(m_headerText->sizePolicy().hasHeightForWidth());
    m_headerText->setSizePolicy(sizePolicy);
    m_headerText->setMinimumSize(QSize(500, 50));
    m_headerText->setMaximumSize(QSize(1000, 100));
    QPalette palette1;
    QBrush brush2(QColor(245, 245, 245, 255));
    brush2.setStyle(Qt::SolidPattern);
    palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
    palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
    palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
    palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
    QBrush brush3(QColor(159, 158, 158, 255));
    brush3.setStyle(Qt::SolidPattern);
    palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
    palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
    m_headerText->setPalette(palette1);
    this->setAutoFillBackground(true);
    QFont font;
    font.setPointSize(28);
    font.setBold(true);
    font.setWeight(75);
    font.setStyleStrategy(QFont::PreferAntialias);
    m_headerText->setFont(font);
    m_headerText->setLineWidth(0);
    m_headerText->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
    m_headerText->setMargin(10);

    m_horizontalLayout->addWidget(m_headerText);

    m_icons = new QWidget(this);
    m_icons->setObjectName("widget");
    sizePolicy.setHeightForWidth(m_icons->sizePolicy().hasHeightForWidth());
    m_icons->setSizePolicy(sizePolicy);
    m_icons->setMinimumSize(QSize(300, 50));
    m_icons->setMaximumSize(QSize(600, 100));

    m_horizontalLayout->addWidget(m_icons);
}

CustomHeader::~CustomHeader()
{
    delete m_horizontalLayout;
}

void CustomHeader::updateHeaderText(int text )
{
    m_headerText->setText(ML300Application::getDictionary()->getText(text));
}

