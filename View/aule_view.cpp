#include "aule_view.h"

aule_view::aule_view(const QSize& s, View* parent) : View(s, parent)
{
    QVBoxLayout* vbox = new QVBoxLayout(this);
    QHBoxLayout* hbox1 = new QHBoxLayout(this);
    QLabel* titolo = new QLabel("VISUALIZZAZIONE AULE", this);
    hbox1->addWidget(titolo);
    indietroButton = new QPushButton("Indietro", this);
    hbox1->addWidget(indietroButton);

    vbox->addLayout(hbox1);

    //ora devo creare una scroll_area in cui si visualizzano semplicemente tutte le aule in ordine di numero
    //vicino ad ogni aula deve apparire il pulsante "VISUALIZZA_PRENOTAZIONI" che porta alla prenotazione_view avendo come parametro l'aula

    //connect(indietroButton,SIGNAL(clicked(bool)),this,SLOT(onLoginButtonClicked()));
}

void aule_view::closeEvent(QCloseEvent *event){
    if(QMessageBox::question(this,"Uscita","Vuoi uscire davvero?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes){
        event->accept();
        emit viewClosed();
    }
    else
        event->ignore();
}
