#include "screenscontainer.h"
#include "custommenu.h"
#include <QMetaType>

ScreensContainer::ScreensContainer(QWidget *parent): QStackedWidget(parent)
{
    if (this->objectName().isEmpty())
        this->setObjectName("ScreenContainer");
    this->resize(800, 400);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    this->setSizePolicy(sizePolicy);
    this->setMinimumSize(QSize(800, 400)); // this includes the footer
    this->setMaximumSize(QSize(1600, 800));
    qRegisterMetaType<ScreensContainer::ScreenId>("ScreensContainer::ScreenId");
}

ScreensContainer::~ScreensContainer()
{

}


void ScreensContainer::addScreen(Screen *screen)
{
//    addWidget(screen);
   m_screens.insert(screen->id(), screen);
   addWidget(screen);
}

bool ScreensContainer::setScreen(ScreensContainer::ScreenId id)
{
    if(m_screens.contains(id))
    {
        m_screenStack.push_back(m_screens.value(id));
        setCurrentWidget(m_screens.value(id));
        return true;
    }
    return false;
}

bool ScreensContainer::setNextScreen(ScreensContainer::ScreenId id)
{
    return setScreen(id);
}

void ScreensContainer::setPreviousScreen()
{
    if(m_screens.size() > 1) //more than one screen
    {
        if(m_screenStack.size() > 1)
        {
            m_screenStack.pop_back();
            setCurrentWidget(m_screenStack.last());
        }
    }
}

