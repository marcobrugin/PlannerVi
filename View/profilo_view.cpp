#include "profilo_view.h"

profilo_view::profilo_view(const QSize& s, const utente* ut, View* parent) : View(s, parent), persona(ut)
{
    // Set window title
    this->setTitolo("SCHEDA UTENTE");

    // Create main layout
    layout = new QGridLayout(this);

    // Create labels
    QLabel* nome = new QLabel ("Nome", this);
    QLabel* cognome = new QLabel ("Cognome", this);
    QLabel* cod = new QLabel ("Codice Fiscale", this);
    QLabel* telefono = new QLabel ("Telefono", this);
    QLabel* email = new QLabel ("Email", this);
    QLabel* ruolo = new QLabel ("Ruolo", this);

    // Create labels for user information
    QLabel* _nome = new QLabel (QString::fromStdString(ut->getNome()), this);
    QLabel* _cognome = new QLabel (QString::fromStdString(ut->getCognome()), this);
    QLabel* _cod = new QLabel (QString::fromStdString(ut->getCodiceFiscale()), this);
    QLabel* _telefono = new QLabel (QString::fromStdString(ut->getTelefono()), this);
    QLabel* _email = new QLabel (QString::fromStdString(ut->getEmail()), this);
    QLabel* _ruolo = new QLabel (QString::fromStdString(ut->getRuolo()), this);

    // Create "Indietro" button
    indietro = new QPushButton("INDIETRO", this);

    // Add labels and values to the layout
    layout->addWidget(nome, 0, 0);
    layout->addWidget(_nome, 0, 1);
    layout->addWidget(cognome, 1, 0);
    layout->addWidget(_cognome, 1, 1);
    layout->addWidget(cod, 2, 0);
    layout->addWidget(_cod, 2, 1);
    layout->addWidget(telefono, 3, 0);
    layout->addWidget(_telefono, 3, 1);
    layout->addWidget(email, 4, 0);
    layout->addWidget(_email, 4, 1);
    layout->addWidget(ruolo, 5, 0);
    layout->addWidget(_ruolo, 5, 1);

    nome->setStyleSheet("background-color: #FFFFFF;");
    _nome->setStyleSheet("background-color: #FFE6CC;");
    cognome->setStyleSheet("background-color: #F0F0F0;");
    _cognome->setStyleSheet("background-color: #FFE6CC;");
    cod->setStyleSheet("background-color: #FFFFFF;");
    _cod->setStyleSheet("background-color: #FFE6CC;");
    telefono->setStyleSheet("background-color: #F0F0F0;");
    _telefono->setStyleSheet("background-color: #FFE6CC;");
    email->setStyleSheet("background-color: #FFFFFF;");
    _email->setStyleSheet("background-color: #FFE6CC;");
    ruolo->setStyleSheet("background-color: #F0F0F0;");
    _ruolo->setStyleSheet("background-color: #FFE6CC;");

    // Add "Indietro" button to the layout
    layout->addWidget(indietro, 6, 0, 1, 2, Qt::AlignCenter);

    // Set layout on the main widget
    setLayout(layout);

    // Connect "Indietro" button click signal
     connect(indietro,SIGNAL(clicked(bool)),this,SIGNAL(indietro_signal()));
}

void profilo_view::closeEvent(QCloseEvent* event)
{
    if (QMessageBox::question(this, "Uscita", "Vuoi uscire davvero?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
        event->accept();
        emit viewClosed();
    }
    else {
        event->ignore();
    }
}
