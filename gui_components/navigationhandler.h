#ifndef NAVIGATIONHANDLER_H
#define NAVIGATIONHANDLER_H

#include <QObject>
#include <QWidget>

class NavigationHandler : public QWidget
{
    Q_OBJECT
public:
    explicit NavigationHandler(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *ev);

signals:

public slots:
};

#endif // NAVIGATIONHANDLER_H
