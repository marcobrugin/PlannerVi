QT       += core widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = PlannerVi
TEMPLATE = app
INCLUDEPATH += .
RC_ICONS = logo_consvi.ico
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RESOURCES = resources.qrc \
    resources.qrc

SOURCES += \
    Controller/admin_controller.cpp \
    Controller/controller.cpp \
    Controller/login_controller.cpp \
    Controller/menu_controller.cpp \
    Controller/mypren_controller.cpp \
    Controller/prenotazioni_controller.cpp \
    Controller/profilo_controller.cpp \
    Controller/registrazione_controller.cpp \
    Controller/salvataggio_dati.cpp \
    Model/aula.cpp \
    Model/aulaConcerto.cpp \
    Model/aulaStrumentale.cpp \
    Model/aulaStudio.cpp \
    Model/model.cpp \
    Model/prenotazione.cpp \
    Model/storage.cpp \
    Model/utente.cpp \
    View/admin_view.cpp \
    View/login_view.cpp \
    View/menu_view.cpp \
    View/mypren_view.cpp \
    View/prenotazioni_view.cpp \
    View/profilo_view.cpp \
    View/registrazione_view.cpp \
    View/view.cpp \
    main.cpp \

HEADERS += \
    Controller/admin_controller.h \
    Controller/controller.h \
    Controller/login_controller.h \
    Controller/menu_controller.h \
    Controller/mypren_controller.h \
    Controller/prenotazioni_controller.h \
    Controller/profilo_controller.h \
    Controller/registrazione_controller.h \
    Controller/salvataggio_dati.h \
    Model/aula.h \
    Model/aulaConcerto.h \
    Model/aulaStrumentale.h \
    Model/aulaStudio.h \
    Model/contenitore.h \
    Model/model.h \
    Model/prenotazione.h \
    Model/storage.h \
    Model/utente.h \
    View/admin_view.h \
    View/login_view.h \
    View/menu_view.h \
    View/mypren_view.h \
    View/prenotazioni_view.h \
    View/profilo_view.h \
    View/registrazione_view.h \
    View/view.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    file.json

