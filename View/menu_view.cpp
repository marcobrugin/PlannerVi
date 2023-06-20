#include "menu_view.h"

menu_view::menu_view(const QSize & s, const QString& m, View * parent) : View(s,parent), mail(m) {

    vbox = new QVBoxLayout(this);

    //logo
    QPixmap logo(":/Images/logo_consvi.svg");
    logoLabel=new QLabel(this);
    logoLabel->setPixmap(logo.scaledToHeight(256));
    logoLabel->setAlignment(Qt::AlignHCenter);
    vbox->addWidget(logoLabel);

    benvenuto = new QLabel("Benvenuto!", this);
    benvenuto->setAlignment(Qt::AlignCenter);
    vbox->addWidget(benvenuto);
    QLabel* ut = new QLabel ("Accesso effettuato come "+m, this);
    vbox->addWidget(ut);
    vbox->addStretch();

    viewProfilo= new QPushButton("Visualizza Profilo", this);
    vbox->addWidget(viewProfilo);
    vbox->addStretch();
    viewMyPren= new QPushButton("Visualizza le mie prenotazioni", this);
    vbox->addWidget(viewMyPren);
    vbox->addStretch();
    viewTuttePren= new QPushButton("Visualizza tutte prenotazioni", this);
    vbox->addWidget(viewTuttePren);

    // Connessione dei pulsanti ai segnali
    connect(viewProfilo,SIGNAL(clicked(bool)),this,SIGNAL(View_profilo_signal(m)));
    connect(viewMyPren,SIGNAL(clicked(bool)),this,SIGNAL(View_my_signal(m)));
    connect(viewTuttePren,SIGNAL(clicked(bool)),this,SIGNAL(View_tutte_signal(m)));
}

void menu_view::closeEvent(QCloseEvent *event){
    if(QMessageBox::question(this,"Uscita","Vuoi uscire davvero?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes){
        event->accept();
        emit viewClosed();
    }
    else
        event->ignore();
}
