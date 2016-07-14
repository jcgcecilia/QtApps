#ifndef FOOTERHANDER_H
#define FOOTERHANDER_H

#include <QObject>

class Screen;

class FooterHandler : public QObject
{
    Q_OBJECT
public:
    explicit FooterHandler(Screen * screen = 0, QObject *parent = 0);

    Screen *screen() const;
    void setScreen(Screen *screen);

signals:

public slots:
    void meunuItemAction(bool action);
    void listItemEnteredAction(int row);
    void listItemSelectedAction(int row);
    void footerItemAction(int col);
private:
    Screen * m_screen;
};

#endif // FOOTERHANDER_H
