#-------------------------------------------------
#
# Project created by QtCreator 2016-02-12T13:52:39
#
#-------------------------------------------------

#exoralterakit.local

QT += core gui network xml

greaterThan(QT_MAJOR_VERSION, 4){
    message(Building for QT5)
    DEFINES += QT5
    QT += widgets
}
else {
    message(Building for QT4)
    DEFINES += QT4
}

CONFIG(agi) {
message(Building for AGI)
DEFINES += TOUCH
}

CONFIG(du) {
message(Building for DU300)
DEFINES += KEYS
DEFINES += ARM
}


CONFIG(win) {
message(Building for WINDOW)
DEFINES += WIN
DEFINES += TOUCH
DEFINES += KEYS
}

TEMPLATE = app

TARGET = QtApp300
target.path = /app/qt
INSTALLS += target


SOURCES += main.cpp\
        mainwindow.cpp \
    gui_components/customfooter.cpp \
    gui_components/customfooteritem.cpp \
    gui_components/customgrid.cpp \
    gui_components/customheader.cpp \
    gui_components/custommenu.cpp \
    gui_components/custommenubutton.cpp \
    gui_components/customsubheader.cpp \
    application/application.cpp \
    application/globaldictionary.cpp \
    application/globaltimer.cpp \
    managers/alarmmanager.cpp \
    managers/managerbase.cpp \
    managers/statusmanager.cpp \
    network/applicationnetworkmanager.cpp \
    network/httprequest.cpp \
    network/httprequestworker.cpp \
    network/requestworker.cpp \
    parsers/xml/alarmsxmlhandler.cpp \
    parsers/xml/requestpaser.cpp \
    parsers/xml/statusparser.cpp \
    parsers/xml/textxmlparser.cpp \
    restdatacontrollers/alarmobject.cpp \
    restdatacontrollers/statusobject.cpp \
    restdatacontrollers/textobject.cpp \
    gui_components/screenscontainer.cpp \
    mvc/customtablemodel.cpp \
    guithread.cpp \
    mvc/customtableview.cpp \
    gui_components/customtable.cpp \
    gui_components/navigationhandler.cpp \
    gui_components/screen.cpp \
    gui_components/customcombobox.cpp \
    gui_components/customscrollwidgets.cpp \
    gui_handler/footerhander.cpp \
    business_data/businessdatamodel.cpp \
    gui_handler/menuguihandler.cpp \
    gui_handler/guihandler.cpp \
    gui_handler/alarmguihandler.cpp \
    parsers/parsers/streamparser.cpp \
    parsers/parsers/xmlstreamerparser.cpp \
    parsers/xml/parseerror.cpp \
    popup/popup.cpp \
    restdatacontrollers/restdata.cpp \
    restdatacontrollers/alarmrestdata.cpp \
    restdatacontrollers/httpworkerpool.cpp \
    subsciber/csubscribemanager.cpp \
    popup/popupbutton.cpp \
    selectionlist/selectionlist.cpp \
    keyboard/keyboard.cpp \
    keyboard/keyitem.cpp \
    keyboard/lineedit.cpp \
    restdatacontrollers/statusrestdata.cpp \
    gui_handler/displaystatusguihandler.cpp \
    restdatacontrollers/textsrestdata.cpp \
    documentBuilder/documentbuilder.cpp

HEADERS  += mainwindow.h \
    gui_components/customfooter.h \
    gui_components/customfooteritem.h \
    gui_components/customgrid.h \
    gui_components/customheader.h \
    gui_components/custommenu.h \
    gui_components/custommenubutton.h \
    gui_components/customsubheader.h \
    application/application.h \
    application/globaldictionary.h \
    application/globaltimer.h \
    managers/alarmmanager.h \
    managers/managerbase.h \
    managers/statusmanager.h \
    network/applicationnetworkmanager.h \
    network/httprequest.h \
    network/httprequestworker.h \
    network/requestworker.h \
    parsers/xml/alarmsxmlhandler.h \
    parsers/xml/requestpaser.h \
    parsers/xml/statusparser.h \
    parsers/xml/textxmlparser.h \
    restdatacontrollers/alarmobject.h \
    restdatacontrollers/statusobject.h \
    restdatacontrollers/textobject.h \
    gui_components/screenscontainer.h \
    mvc/customtablemodel.h \
    guithread.h \
    mvc/customtableview.h \
    gui_components/customtable.h \
    gui_components/navigationhandler.h \
    gui_components/screen.h \
    gui_components/customcombobox.h \
    gui_components/customscrollwidgets.h \
    gui_handler/footerhander.h \
    business_data/businessdatamodel.h \
    gui_handler/menuguihandler.h \
    gui_handler/guihandler.h \
    gui_handler/alarmguihandler.h \
    parsers/parsers/streamparser.h \
    parsers/parsers/xmlstreamerparser.h \
    parsers/xml/parseerror.h \
    popup/popup.h \
    restdatacontrollers/restdata.h \
    restdatacontrollers/alarmrestdata.h \
    restdatacontrollers/httpworkerpool.h \
    subsciber/csubscribemanager.h \
    popup/popupbutton.h \
    selectionlist/selectionlist.h \
    keyboard/keyboard.h \
    keyboard/keyitem.h \
    keyboard/lineedit.h \
    restdatacontrollers/statusrestdata.h \
    gui_handler/displaystatusguihandler.h \
    restdatacontrollers/textsrestdata.h \
    documentBuilder/documentbuilder.h

RESOURCES += \
    image.qrc

FORMS +=


