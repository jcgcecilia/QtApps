#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QLayout>

#include "gui_components/custommenubutton.h"
#include "gui_components/custommenu.h"
#include "gui_components/customheader.h"
#include "gui_components/customsubheader.h"
#include "gui_components/screenscontainer.h"
#include "mvc/customtablemodel.h"
#include "gui_components/customtable.h"
#include "gui_components/customfooter.h"
#include "gui_handler/footerhander.h"
#include "guithread.h"

#include "gui_handler/alarmguihandler.h"
#include "managers/alarmmanager.h"
#include "managers/statusmanager.h"
#include "restdatacontrollers/httpworkerpool.h"
#include "network/applicationnetworkmanager.h"
#include "popup/popup.h"
#include "keyboard/keyboard.h"
#include "parsers/parsers/xmlstreamerparser.h"
#include "gui_components/customcombobox.h"
#include "restdatacontrollers/statusrestdata.h"
#include "restdatacontrollers/textsrestdata.h"
#include "parsers/xml/statusparser.h"
#include "parsers/xml/textxmlparser.h"

void buildGui(QWidget * mainWidget, ML300Application * appl)
{

    QRect rec = QApplication::desktop()->screenGeometry();
    qDebug() << rec.height();
    qDebug() << rec.width();

    mainWidget->resize(800, 480);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(mainWidget->sizePolicy().hasHeightForWidth());
    mainWidget->setSizePolicy(sizePolicy);
    mainWidget->setMinimumSize(QSize(800, 400)); // this includes the footer
    mainWidget->setMaximumSize(QSize(1600, 800));
//    mainWidget->setFocusPolicy(Qt::StrongFocus);

    ScreensContainer * screenContainer= new ScreensContainer(mainWidget);
    PopUp * popup = new PopUp(screenContainer);

    QVBoxLayout * appLayout = new QVBoxLayout;
    appLayout->setContentsMargins(0,0,0,0);
    appLayout->setSpacing(0);


    CustomMenu * menu = new CustomMenu(ScreensContainer::homeScreen, screenContainer);
//    FooterHandler * footerMenuHandler = new FooterHandler(menu);
//    QObject::connect(menu, SIGNAL(updateFooter(bool)), footerMenuHandler, SLOT(meunuItemAction(bool)));
//    menu->initialize();
    CustomMenuButton * tmp = new CustomMenuButton(menu);
    tmp->setId(ScreensContainer::tableScreen);
    tmp->setText("Alarms");
    tmp->setImage(QPixmap(":alarm"));
    menu->addMenuItem(tmp, 0, 0);
    tmp = new CustomMenuButton(menu);
    tmp->setText("SD Card");
    tmp->setImage(QPixmap(":sdcard"));
    menu->addMenuItem(tmp, 0, 1);
    tmp = new CustomMenuButton(menu);
    tmp->setText("Parameters");
    tmp->setImage(QPixmap(":parameters"));
    menu->addMenuItem(tmp, 0, 2);
    tmp = new CustomMenuButton(menu);
    tmp->setText("Display");
    tmp->setImage(QPixmap(":ml300_display"));
    menu->addMenuItem(tmp, 0, 3);

    screenContainer->addScreen(menu);
    CustomFooter * footerTmp = new CustomFooter(menu);
    footerTmp->initialize();
//    footerTmp->setText(0, "test");
#ifdef KEYS
    footerTmp->setImage(0, QPixmap(":up"));
    footerTmp->setImage(1, QPixmap(":up"));
    footerTmp->setImage(2, QPixmap(":up"));
    footerTmp->setImage(3, QPixmap(":up"));
#endif

#ifdef TOUCH
//    footerTmp->setText(0, "Back");
#endif

    menu->setFooter(footerTmp);

    tmp = new CustomMenuButton(menu);
    tmp->setText("LiveData");
    tmp->setImage(QPixmap(":livedata"));
    menu->addMenuItem(tmp, 1, 0);
    tmp = new CustomMenuButton(menu);
    tmp->setText("Schedule");
    tmp->setImage(QPixmap(":schedule"));
    menu->addMenuItem(tmp, 1, 1);
    tmp = new CustomMenuButton(menu);
    tmp->setText("User");
    tmp->setImage(QPixmap(":user"));
    menu->addMenuItem(tmp, 1, 2);
    tmp = new CustomMenuButton(menu);
    tmp->setText("Batch");
    tmp->setImage(QPixmap(":batch"));
    menu->addMenuItem(tmp, 1, 3);


    tmp = new CustomMenuButton(menu);
    tmp->setText("hola");
    tmp->setImage(QPixmap(":batch"));
    menu->addMenuItem(tmp, 2, 3);

    CustomMenu * menu2 = new CustomMenu(ScreensContainer::configureScreen, screenContainer);
    footerTmp = new CustomFooter(menu2);
    footerTmp->initialize();
    menu2->setFooter(footerTmp);
    screenContainer->addScreen(menu2);

    KeyBoard * keyboard = new KeyBoard(ScreensContainer::keyboard, screenContainer);
    keyboard->init();
    footerTmp = new CustomFooter(keyboard);
    footerTmp->initialize();
    keyboard->setFooter(footerTmp);
    screenContainer->addScreen(keyboard);


#ifdef KEYS
    menu->resetMenu();
#endif

    RequestWorkerPool * pool = new HttpWorkerPool(appl);
    pool->initialize(5);
    /*
     *
     */
    RestData * textRestData = new TextsRestData(pool);
    textRestData->initialize();
    appl->getTimer()->addTimeListener(textRestData);

    /**
     * @brief alarmsRestData
     */
    RestData * alarmsRestData = new AlarmRestData(pool);
    alarmsRestData->initialize();
    appl->getTimer()->addTimeListener(alarmsRestData, 1000);

    /**
     *
     */
    RestData * statusRestData = new StatusRestData(pool);
    statusRestData->initialize();
    appl->getTimer()->addTimeListener(statusRestData, 500);


    /**
      */
    StreamerParser * textParer = new  XMLStreamerParser();
    XMLStreamDocumentHandler* textDocument = new TextXMLDocumentHandler(textParer);
    textDocument->initialize();
    ManagerBase * textManager = new  GlobalDictionary(textDocument);
    textManager->init();
    ML300Application::setDictionary(static_cast<GlobalDictionary *>(textManager));

    /**
     * @brief alarmParer
     */
    StreamerParser * alarmParer = new  XMLStreamerParser();
    XMLStreamDocumentHandler* alarmDocument = new AlarmXMLDocumentHandler(alarmParer);
    alarmDocument->initialize();
    ManagerBase * alarmManager = new  AlarmManager(alarmDocument);
    alarmManager->init();

    /**
     * @brief QObject::connect
     */
    StreamerParser * statusParser = new  XMLStreamerParser();
    XMLStreamDocumentHandler* statusDocument = new StatusXMLDocumentHandler(statusParser);
    statusDocument->initialize();
    ManagerBase * statusManager = new  StatusManager(statusDocument);
    statusManager->init();


    QObject::connect(alarmsRestData, SIGNAL(executionFinished(QByteArray)), alarmDocument, SLOT(rowData(QByteArray)));
    QObject::connect(statusRestData, SIGNAL(executionFinished(QByteArray)), statusDocument, SLOT(rowData(QByteArray)));
    QObject::connect(textRestData, SIGNAL(executionFinished(QByteArray)), textDocument, SLOT(rowData(QByteArray)));

    QObject::connect(alarmManager, SIGNAL(showPopup(int)), popup, SLOT(showPopup(int)));
    QObject::connect(alarmManager, SIGNAL(removePopup()), popup, SLOT(hidePopUp()));

    CustomTableModel *model = new CustomTableModel;
    AlarmGuiHandler * guiHandler = new AlarmGuiHandler( NULL ,alarmManager);
    guiHandler->setModel(model);
    QObject::connect(guiHandler, SIGNAL(ackAlarm(int)), static_cast<AlarmRestData *>(alarmsRestData), SLOT(ackAlarm(int)));

    CustomTable * table = new CustomTable(ScreensContainer::tableScreen, screenContainer, guiHandler);

    guiHandler->initialize();
    table->setScreenTitle("Alarms");
    QList<int>dim =  QList<int>()<< 70<< 100 << 305<< 100<< 100<< 80;
    table->initialize();
    table->setTableModel(guiHandler->model());
    table->setColsWidth(dim);
    footerTmp = new CustomFooter(table);
    footerTmp->initialize();

//    footerTmp->setText(0,"Options");

    CustomComboBox * combo = new CustomComboBox(tmp);
    combo->init();
    footerTmp->setComboBox(1, combo);
    footerTmp->setText(1, "Config");
    footerTmp->setText(3, "Ack", false);
#ifdef TOUCH
    footerTmp->setText(0, "Back");
#endif

    table->setFooter(footerTmp);

    screenContainer->addScreen(table);


    screenContainer->setScreen(ScreensContainer::homeScreen);

    CustomHeader * header = new CustomHeader(mainWidget);
    appLayout->addWidget(header);

    QObject::connect(statusManager, SIGNAL(updateStatusText(int)), header, SLOT(updateHeaderText(int)));


    appLayout->addWidget(new CustomSubheader(mainWidget));
    appLayout->addWidget(screenContainer);



    appl->getTimer()->init();

    mainWidget->setLayout(appLayout);
    mainWidget->show();

}
#include <QFontDatabase>
int main(int argc, char *argv[])
{
    ML300Application ml300(argc, argv);
    GlobalTimer * timer = new GlobalTimer;
    NetworkManager * manager = new NetworkManager;
    ml300.setTimer(timer);
    ml300.setNetworkManager(manager);
    // Lod Font
    QFontDatabase::addApplicationFont(":/freesans");
    QFont ml300Font;
    ml300Font.setFamily("FreeSans");
    ml300.setFont(ml300Font);

    QWidget * mainWidget = new QWidget;
#ifndef WIN
    ml300.setOverrideCursor( QCursor( Qt::BlankCursor ) );
    mainWidget->setWindowFlags(Qt::FramelessWindowHint);
#endif
    buildGui(mainWidget, &ml300);

    return ml300.exec();

}
