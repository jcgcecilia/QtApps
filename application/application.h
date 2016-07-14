#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QApplication>
#include "globaldictionary.h"
#include "globaltimer.h"

#define TEXT ML300Application::getDictionary()

class GlobalDictionary;
class CommunicationManager;
class NetworkManager;
class GlobalTimer;

class ML300Application : public QApplication
{
public:
    ML300Application(int &argc, char **argv);
    ~ML300Application();


    static QString getText(int id);

    static CommunicationManager *getCommunicationManager();
    static void setCommunicationManager(CommunicationManager *value);


    static NetworkManager *getNetworkManager();
    static void setNetworkManager(NetworkManager *value);

    static GlobalDictionary *getDictionary();
    static void setDictionary(GlobalDictionary *value);

    static GlobalTimer *getTimer();
    static void setTimer(GlobalTimer *value);

private:
    static GlobalDictionary *dictionary;
    static CommunicationManager * communicationManager; // Shall this varible be global from here?
    static GlobalTimer * timer;
    static NetworkManager * networkManager;
};

#endif // APPLICATION_H
