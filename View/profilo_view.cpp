#include "profilo_view.h"

profilo_view::profilo_view(const QSize& s, const utente* ut, View* parent) : View(s, parent), persona(ut)
{
    //view->setTitle="SCHEDA UTENTE"
    hbox= new QHBoxLayout(this);
    vbox1 = new QVBoxLayout(this);
    vbox2 = new QVBoxLayout(this);

    QLabel* nome = new QLabel ("Nome", this);
    QLabel* cognome = new QLabel ("Cognome", this);
    QLabel* cod = new QLabel ("Codice Fiscale", this);
    QLabel* telefono = new QLabel ("Telefono", this);
    QLabel* email = new QLabel ("Email", this);
    QLabel* ruolo = new QLabel ("Ruolo", this);
    vbox1->addWidget(nome);
    vbox1->addWidget(cognome);
    vbox1->addWidget(cod);
    vbox1->addWidget(telefono);
    vbox1->addWidget(email);
    vbox1->addWidget(ruolo);
    hbox->addLayout(vbox1);

    QLabel* _nome = new QLabel (QString::fromStdString(ut->getNome()), this);
    QLabel* _cognome = new QLabel (QString::fromStdString(ut->getCognome()), this);
    QLabel* _cod = new QLabel (QString::fromStdString(ut->getCodiceFiscale()), this);
    QLabel* _telefono = new QLabel (QString::fromStdString(ut->getTelefono()), this);
    QLabel* _email = new QLabel (QString::fromStdString(ut->getEmail()), this);
    QLabel* _ruolo = new QLabel (QString::fromStdString(ut->getRuolo()), this);
    indietro = new QPushButton ("Indietro", this);
    vbox2->addWidget(_nome);
    vbox2->addWidget(_cognome);
    vbox2->addWidget(_cod);
    vbox2->addWidget(_telefono);
    vbox2->addWidget(_email);
    vbox2->addWidget(_ruolo);
    vbox2->addWidget(indietro);
    hbox->addLayout(vbox2);

    connect(indietro,SIGNAL(clicked(bool)),this,SIGNAL(indietro_signal()));
}

void profilo_view::closeEvent(QCloseEvent *event){
    if(QMessageBox::question(this,"Uscita","Vuoi uscire davvero?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes){
        event->accept();
        emit viewClosed();
    }
    else
        event->ignore();
}
