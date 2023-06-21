#include "admin_view.h"

admin_view::admin_view(const QSize& s, View* parent) : View(s, parent){
    vbox=new QVBoxLayout(this);
    hbox=new QHBoxLayout(this);
    QLabel* titolo=new QLabel("VISUALIZZAZIONE ADMIN PRENOTAZIONI ", this);
    hbox->addWidget(titolo);
    indietro = new QPushButton("Torna al menu", this);
    hbox->addWidget(indietro);

    vbox->addLayout(hbox);
    connect(indietro,SIGNAL(clicked(bool)),this,SIGNAL(indietro_signal()));
}

void admin_view::create_table(const QStringList& intestazioni){
    pren_table->setColumnCount(7);
    pren_table->setHorizontalHeaderLabels(intestazioni);
    pren_table->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    pren_table->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    pren_table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
    vbox->addWidget(pren_table);
}

void admin_view::visualizza_prenotazioni(const contenitore<prenotazione*>& pren){
    int i=0;
    for(auto j: pren){
        pren_table->insertRow(i);
        QLabel* aulaLabel = new QLabel(j->getNumero, this); //dell'aula mi serve solo il numero
        pren_table->setCellWidget(i, 0, aulaLabel);
        QLabel* dataLabel = new QLabel(j->getData(), this);
        pren_table->setCellWidget(i, 0, dataLabel);
        i++;
    }

    QDate oggi = QDate::currentDate();

    int annoAccademico=oggi.year();
    if (oggi.month() > 7 || (oggi.month() == 7 && oggi.day() >= 15)) {
        annoAccademico++; // Incrementa il range di annuale disponibile se oggi>15.07
    }

    pren_table->insertRow(i);
    _aula = new QLineEdit(this);
    pren_table->setCellWidget(i,0,_aula);
    _data = new QDateEdit(this);
    _data->setCalendarPopup(true); // Abilita il calendario a comparsa
    _data->setDateRange(oggi.addDays(1), QDate(annoAccademico, 7, 15)); // Imposta il range di date
    pren_table->setCellWidget(i,1,_data);
    _oraArrivo = new QTimeEdit(this);
    _oraArrivo->setDisplayFormat("hh:mm");
    _oraArrivo->setTimeRange(QTime(9, 0), QTime(18, 30));
    pren_table->setCellWidget(i,2,_oraArrivo);
    _oraUscita = new QTimeEdit(this);
    _oraUscita->setDisplayFormat("hh:mm"); // Imposta il formato di visualizzazione senza i secondi
    _oraUscita->setTimeRange(QTime(9, 30), QTime(19, 0));
    pren_table->setCellWidget(i,3,_oraUscita);
    _causale = new QTextEdit(this);
    pren_table->setCellWidget(i,4,_causale);
    _mail = new QLabel(mail, this);
    pren_table->setCellWidget(i,5,_mail);

    aggiungi = new QPushButton ("+", this);
    pren_table->setCellWidget(i,6,aggiungi);

    // Connessione del pulsante di login allo slot onLoginButtonClicked()
    connect(aggiungi, SIGNAL(clicked()), this, SIGNAL (ButtonClicked()));
    connect(this,SIGNAL(ButtonClicked()),this,SLOT(aggiungi_pren()));
}


void admin_view::aggiungi_pren(){
    QString aula = _aula->text();
    QDate data = _data->date();
    QTime oraArrivo= _oraArrivo->time();
    QTime oraUscita= _oraArrivo->time();
    QString causale= _causale->toPlainText();

    //controllo errori basilari
    if(aula.isNull() || aula.isEmpty() || data.isNull() || oraArrivo.isNull() || oraUscita.isNull() || causale.isEmpty() || causale.isNull()){
        static_cast<View*>(this)->showError("Inserimento non valido", "I valori inseriti non sono accettati");
    }
    else{
        emit aggiungi_signal(aula, data, oraArrivo, oraUscita, causale, mail);
    }
}

void admin_view::rimuovi_prenotazione(uint i){
    pren_table->removeRow(i);
}

void admin_view::closeEvent(QCloseEvent *event){
    if(QMessageBox::question(this,"Uscita","Vuoi uscire davvero?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes){
        event->accept();
        emit viewClosed();
    }
    else
        event->ignore();
}

