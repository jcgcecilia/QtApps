#include "popup.h"
#include "gui_components/screenscontainer.h"
#include <QPushButton>
#include <QLayout>

#include "popupbutton.h"
PopUp::PopUp(ScreensContainer *parent) : QWidget(parent)
{

    this->setWindowFlags(Qt::Popup);
    if (this->objectName().isEmpty())
        this->setObjectName("PopUpWithButtons");
    this->resize(800, 350);
    QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    this->setSizePolicy(sizePolicy);
    this->setMinimumSize(QSize(800, 350));
    this->setMaximumSize(QSize(1600, 700));
    this->setAutoFillBackground(true);

    QPixmap bkgnd(":alarmpopup");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    this->setGeometry(0, 50+30, this->width(), this->height());


//    QWidget * widget = new QWidget(this);
//    widget->setObjectName(QStringLiteral("widget"));
//    widget->setGeometry(QRect(485, 75, 202, 191));
//    QVBoxLayout* verticalLayout = new QVBoxLayout(widget);

//    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
//    verticalLayout->setContentsMargins(0, 0, 0, 0);

//    PopupButton * popupButton = new PopupButton(widget);
//    PopupButton * popupButton_2 = new PopupButton(widget);

//    verticalLayout->setGeometry(QRect(600, 60,popupButton->width() , popupButton->height()));
//    verticalLayout->addWidget(popupButton);
//    verticalLayout->addWidget(popupButton_2);
//    QPushButton * popupButton = new QPushButton(widget);

//    popupButton->setAutoFillBackground(true);
//    popupButton->setObjectName("popupButton");
//    QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
//    sizePolicy1.setHorizontalStretch(1);
//    sizePolicy1.setVerticalStretch(1);
//    sizePolicy1.setHeightForWidth(popupButton->sizePolicy().hasHeightForWidth());
//    popupButton->setSizePolicy(sizePolicy1);
//    popupButton->setMinimumSize(QSize(200, 50));
//    popupButton->setMaximumSize(QSize(400, 100));
//    QFont font;
//    font.setPointSize(18);
//    font.setBold(true);
//    font.setWeight(75);
//    font.setStyleStrategy(QFont::PreferAntialias);
//    popupButton->setFont(font);


//    QPushButton * popupButton_2 = new QPushButton(widget);
//    popupButton_2->setAutoFillBackground(true);
//    popupButton_2->setObjectName("popupButton_2");
//    sizePolicy1.setHeightForWidth(popupButton_2->sizePolicy().hasHeightForWidth());
//    popupButton_2->setSizePolicy(sizePolicy1);
//    popupButton_2->setMinimumSize(QSize(200, 50));
//    popupButton_2->setMaximumSize(QSize(400, 100));
//    popupButton_2->setFont(font);


//    popupButton->raise();
//    popupButton_2->lower();

}

#include <QDebug>
void PopUp::showEvent(QShowEvent *ev)
{
//    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__;
}

void PopUp::hideEvent(QHideEvent *ev)
{
//    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__;
}

#ifdef TOUCH
void PopUp::mouseReleaseEvent(QMouseEvent *)
{
    hidePopUp();
}
#endif
#ifdef KEYS
void PopUp::keyReleaseEvent(QKeyEvent *)
{
    hidePopUp();
}
#endif
void PopUp::showPopUp(QString text1, QString text2, QString text3)
{
    this->setVisible(true);
    this->setEnabled(true);
}

void PopUp::showPopup(int id)
{
//    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__ << id;
    this->setVisible(true);
    this->setEnabled(true);
    //    this->show();
}

void PopUp::hidePopUp()
{
    this->setVisible(false);
    this->setEnabled(false);
}
