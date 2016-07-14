#ifndef SCREENSCONTAINER_H
#define SCREENSCONTAINER_H

#include <QWidget>
#include <QStackedWidget>
#include <QHash>


class Screen;

class ScreensContainer : public QStackedWidget
{
    Q_OBJECT
    Q_ENUMS(ScreenId)
public:
    enum ScreenId
    {
        notAssigned = -1,
        homeScreen = 0,
        configureScreen,
        tableScreen,
        keyboard
    };
    ScreensContainer(QWidget * parent );
    ~ScreensContainer();

    void addScreen(Screen * screen);
    bool setScreen(ScreenId id);
//    void gotoScreen(ScreenId id);

public slots:
    bool setNextScreen(ScreenId id);
    void setPreviousScreen();

private:
     QHash<ScreenId, Screen *> m_screens;
     QList<Screen *> m_screenStack;

};

#endif // SCREENSCONTAINER_H
