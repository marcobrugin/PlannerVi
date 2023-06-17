#include "menu_view.h"

MenuWindow::MenuWindow(const QSize & s, View * parent) : View(s,parent) {

    layout = new QVBoxLayout(this);

    //logo

    benvenuto = new QLabel("Benvenuto" /*+ getNome() + " "+ getCognome() */, this);
    layout->addWidget(benvenuto);

    HLayout = new QHBoxLayout(this);
    viewAuleButton= new QPushButton("Visualizza Aule", this);
    HLayout->addWidget(viewAuleButton);
    HLayout->addStretch();
    viewPrenButton= new QPushButton("Visualizza Prenotazioni", this);
    HLayout->addWidget(viewPrenButton);

    layout->addLayout(HLayout);

    // Connessione del pulsante allo slot
    connect(viewAuleButton,SIGNAL(clicked(bool)),this,SLOT(onViewAuleButtonClicked()));
    connect(viewPrenButton,SIGNAL(clicked(bool)),this,SLOT(onViewPrenButtonClicked()));
}
void MenuWindow::onViewPrenButtonClicked(){

}
void MenuWindow::onViewAuleButtonClicked(){

}
void MenuWindow::closeEvent(QCloseEvent *event){
    if(QMessageBox::question(this,"Uscita","Vuoi uscire davvero?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes){
        event->accept();
        emit viewClosed();
    }
    else
        event->ignore();
}
