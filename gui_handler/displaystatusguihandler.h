#ifndef DISPLAYSTATUSGUIHANDLER_H
#define DISPLAYSTATUSGUIHANDLER_H
#include "guihandler.h"

class DisplayStatusGuiHandler
{
public:
    DisplayStatusGuiHandler();

public slots:
    void updateText(int textId);

private:
    int m_textId;
};

#endif // DISPLAYSTATUSGUIHANDLER_H
