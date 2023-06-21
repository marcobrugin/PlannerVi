#include "controller.h"

Controller::Controller(Model* m, View* v ,Controller* parent) : QObject(parent), mod(m), view(v){
    connect(view,SIGNAL(viewClosed()),this,SLOT(onViewClosed()));
}
Controller::~Controller(){
    for (auto i: children()){
        delete i;
    }
    delete mod;
    delete view;
}
Controller::Controller(){}
void Controller::show() const {
    view->show();
}
void Controller::hide() const {
    view->hide();
}
