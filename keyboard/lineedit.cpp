#include "lineedit.h"
#define C_DEEPGREY QColor(80,87,94)

LineEdit:: LineEdit(QWidget *parent)
    :QLineEdit(parent)
{
    if (this->objectName().isEmpty())
        this->setObjectName("valueEdit");
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->resize(QSize(600, 50));
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    this->setSizePolicy(sizePolicy);
    this->setMinimumSize(QSize(600, 50));
    this->setMaximumSize(QSize(600, 50));

    setEchoMode(QLineEdit::Normal);
    setFrame(false);
    QFont font("FreeSans", 45);
    setFont(font);
    setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    setMaxLength(50);
    setCursor(Qt::IBeamCursor);
    QPalette palette;
    palette.setColor(QPalette::Text, C_DEEPGREY);
//    palette.setBrush(QPalette::Base, *mNormal);
    setPalette(palette);
    setFocus();
    setCursorPosition(0);
    setReadOnly(false);
}

LineEdit::~LineEdit()
{
}

void LineEdit::pressKey(QString text)
{
    setFocus();
    insert(text);
}


