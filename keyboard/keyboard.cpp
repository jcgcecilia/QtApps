#include "keyboard.h"
#include <QGridLayout>
#include <QStackedWidget>

#include "keyitem.h"
#define ROWS 3
#define COLS 10
#include <QDebug>
#include <QPropertyAnimation>
#include "lineedit.h"
#include <QHideEvent>


KeyBoard::KeyBoard(ScreensContainer::ScreenId id, ScreensContainer *parent, GuiHandler *GuiHandler) :
    Screen(id, GuiHandler, parent), mCurrentKeyboard(0)
{
    if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("this"));
    this->resize(800, 350);
    QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    this->setSizePolicy(sizePolicy);
    this->setMinimumSize(QSize(800, 350));
    this->setMaximumSize(QSize(1600, 700));
    this->setAutoFillBackground(true);
}

void KeyBoard::init()
{
    editLine = new LineEdit(this);

    mKeyboards = new QStackedWidget(this);
    mKeyboards->setMinimumHeight(300);
    generateKeyboards(mKeyboards);

    mKeyboards->setCurrentIndex(0);
    m_mainGrid->addWidget(editLine, 0, 0, 1, 1, Qt::AlignHCenter);
    m_mainGrid->addWidget(mKeyboards, 1, 0, 1, 1, Qt::AlignHCenter);
}

void KeyBoard::showEvent(QShowEvent *)
{
    editLine->clear();
}

void KeyBoard::hideEvent(QHideEvent *)
{

}

void KeyBoard::leftFooterItemPressed()
{
    if(mCurrentKeyboard < 3 )
        mCurrentKeyboard ++;
    else
        mCurrentKeyboard = 0;
    mKeyboards->setCurrentIndex(mCurrentKeyboard);
}

void KeyBoard::leftCenterFooterItemPressed()
{
    editLine->backspace();
    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__ << editLine->text();
}

void KeyBoard::generateKeyboards( QStackedWidget * stack)
{

    QWidget* tmpW;
    QGridLayout * tmpG;
    for(int i = 0; i < 4; i++)
    {
        tmpW = new QWidget();
        tmpW->setMinimumHeight(210);
        tmpW->setMinimumWidth(800);
        tmpG = new QGridLayout(tmpW);
        tmpG->setContentsMargins(50,10,50,10);
        tmpG->setSpacing(0);
        buildKeyboard(tmpG, false);
        stack->addWidget(tmpW);
    }

}

//static int const ROWS=3;
//static int const COLS=10
void KeyBoard::buildKeyboard(QGridLayout* layout, bool)
{
    //keyboards do always have 3 rows and 10
    static QString lowerKeys[3][10] =
    {
        {"q", "w", "e", "r", "t", "y", "u", "i", "o", "p"},
        {"a", "s", "d", "f", "g", "h", "j", "k", "l", "-"},
        {"z", "x", "c", "v", "b", "n", "m", " ", "", ""},
    };
    // m_validator = new BoolValidator();
    static QString upperKeys[3][10] =
    {
        {"Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P"},
        {"A", "S", "D", "F", "G", "H", "J", "K", "L", "-"},
        {"Z", "X", "C", "V", "B", "N", "M", " ", "" , ""},
    };


    static QString specialKeys[3][10] =
    {
        {"#", "/", ":"    , ";" , "(", ")", "&", "@", "?", "!"},
        {".", ",", "_"    , "\""  , "'", "<", ">", "+", "-", "*"},
        {"=", "%", "\260C" , "\\", "" , "" , "" , " ", "" , "" },
    };
//QString::fromUtf8("\xC2\xB1")
    static QString numberKeys[3][10]  =
    {
        {"", "", "", "1", "2", "3", "", "", "", ""},
        {"", "", "", "4", "5", "6", "" , "", "", ""},
        {"", "", ".", "7", "8", "9", "0","", QString::fromUtf8("\xC2\xB1") , "" },
    };

    static int layoutindex = 0;
    typedef QString keyboardlayout[ROWS][COLS];
    keyboardlayout* keyboards[5];
    keyboardlayout* keyboard;

    keyboards[0] = &lowerKeys;
    keyboards[1] = &upperKeys;
    keyboards[2] = &specialKeys;
    keyboards[3] = &numberKeys;

    keyboard = keyboards[layoutindex++];

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            layout->setColumnStretch(j, 1);
            QString& key = (*keyboard)[i][j];
            if(i == ROWS - 1 && j == COLS - 1)
            {
                continue;
            }
            if(i == ROWS - 1 && j == COLS - 2)
            {
                KeyItem* tmp = new KeyItem("Done", this);
                layout->addWidget(tmp, i, j, 1, 2, Qt::AlignCenter);
                //connect(tmp, SIGNAL(keypressed(QString)), editLine, SLOT(pressKey(QString)));
            }
            else
            {
                if(!key.isEmpty())
                {
                    KeyItem* tmp = new KeyItem(key, this);
                    layout->addWidget(tmp , i, j, Qt::AlignCenter);
//                    connect(tmp, SIGNAL(keypressed(QString)), editLine, SLOT(pressKey(QString)));
                }
                else
                {

                }
            }
        }
    }

}
