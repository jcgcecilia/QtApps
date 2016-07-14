#ifndef MENUGUIHANDLER_H
#define MENUGUIHANDLER_H

#include <QObject>
#include "guihandler.h"
class MenuGuiHandler : public GuiHandler
{
    Q_OBJECT
public:
    explicit MenuGuiHandler(QObject *parent = 0);

signals:

public slots:
};

#endif // MENUGUIHANDLER_H
