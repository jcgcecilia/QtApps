#include "application.h"
#include "globaldictionary.h"
#include <QXmlStreamAttributes>
#include <QMetaType>

GlobalDictionary * ML300Application::dictionary = NULL;
CommunicationManager * ML300Application::communicationManager = NULL;
NetworkManager * ML300Application::networkManager = NULL;
GlobalTimer * ML300Application::timer = NULL;

ML300Application::ML300Application(int &argc, char **argv)
    : QApplication(argc, argv)
{

    qRegisterMetaType<QXmlStreamAttributes>("QXmlStreamAttributes");

}

ML300Application::~ML300Application()
{
    delete dictionary;
}

QString ML300Application::getText(int id)
{
    return dictionary->getText(id);
}
CommunicationManager *ML300Application::getCommunicationManager()
{
    return communicationManager;
}

void ML300Application::setCommunicationManager(CommunicationManager *value)
{
    communicationManager = value;
}
NetworkManager *ML300Application::getNetworkManager()
{
    return networkManager;
}

void ML300Application::setNetworkManager(NetworkManager *value)
{
    networkManager = value;
}

GlobalDictionary *ML300Application::getDictionary()
{
    return dictionary;
}

void ML300Application::setDictionary(GlobalDictionary *value)
{
    dictionary = value;
}

GlobalTimer *ML300Application::getTimer()
{
    return timer;
}

void ML300Application::setTimer(GlobalTimer *value)
{
    timer = value;
}






