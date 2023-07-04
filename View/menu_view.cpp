#include "menu_view.h"

menu_view::menu_view(){}
QString menu_view::getMail() const { return mail; }

menu_view::menu_view(const QSize & s, const QString& m, View * parent) : View(s,parent), mail(m) {

    vbox = new QVBoxLayout(this);

    //logo
    QPixmap logo(":/Images/logo_consvi.svg");
    logoLabel=new QLabel(this);
    logoLabel->setPixmap(logo.scaledToHeight(256));
    logoLabel->setAlignment(Qt::AlignHCenter);
    vbox->addWidget(logoLabel);

    QFont font;
    font.setBold(true);
    font.setPointSize(14);

    benvenuto = new QLabel("Benvenuto!", this);
    benvenuto->setAlignment(Qt::AlignCenter);
    benvenuto->setFont(font);
    vbox->addWidget(benvenuto);
    QLabel* ut = new QLabel ("Accesso effettuato come "+m, this);
    ut->setAlignment(Qt::AlignCenter);
    vbox->addWidget(ut);

    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    viewProfilo= new QPushButton("Visualizza profilo utente", this);
    viewProfilo->setSizePolicy(sizePolicy);
    vbox->addWidget(viewProfilo);
    viewMyPren= new QPushButton("Visualizza le mie prenotazioni", this);
    viewMyPren->setSizePolicy(sizePolicy);
    vbox->addWidget(viewMyPren);
    viewTuttePren= new QPushButton("Visualizza tutte le prenotazioni", this);
    viewTuttePren->setSizePolicy(sizePolicy);
    vbox->addWidget(viewTuttePren);

    QString ml= this->getMail();

    // Connessione dei pulsanti ai segnali
    connect(viewProfilo,SIGNAL(clicked(bool)),this,SIGNAL(View_profilo_signal(ml)));
    //connect(viewMyPren,SIGNAL(clicked(bool)),this,SIGNAL(View_my_signal(m)));
    connect(viewTuttePren,SIGNAL(clicked(bool)),this,SIGNAL(View_tutte_signal(ml)));
}

void menu_view::closeEvent(QCloseEvent *event){
    if(QMessageBox::question(this,"Uscita","Vuoi uscire davvero?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes){
        event->accept();
        emit viewClosed();
    }
    else
        event->ignore();
}
