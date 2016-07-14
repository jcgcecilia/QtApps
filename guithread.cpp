#include "guithread.h"

GuiThread::GuiThread()
{

}

void GuiThread::setUp(QThread & cThread)
{
    connect(&cThread, SIGNAL(started()), this, SLOT(StartGui()));
    this->moveToThread(&cThread);
}

void GuiThread::StartGui()
{
    while(1)
    {

    }
}

