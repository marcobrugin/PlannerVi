#include "admin_view.h"

#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QPushButton>

admin_view::admin_view(const QSize& s, View* parent) : View(s, parent)
{
    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* titolo = new QLabel("ADMIN", this);
    vbox->addWidget(titolo);
    vbox->addStretch();

    QPushButton* new_aulaConcerto = new QPushButton ("Nuova aula concerto", this);
    QPushButton* new_aulaStrumentale = new QPushButton ("Nuova aula strumentale", this);
    QPushButton* new_aulaStudio = new QPushButton ("Nuova aula studio", this);
    vbox->addWidget(new_aulaConcerto);
    vbox->addWidget(new_aulaStrumentale);
    vbox->addWidget(new_aulaStudio);
    hbox->addLayout(vbox);

    //ora devo creare un QTable al cui interno avere 2 colonne, la prima contiene i vari oggetti Aula, la seconda contiene i pulsanti modify e delete

    //connessione ai segnali
    connect(new_aulaConcerto,SIGNAL(clicked(bool)),this,SIGNAL(addAConcerto_signal()));
    connect(new_aulaStrumentale,SIGNAL(clicked(bool)),this,SIGNAL(addAStrumentale_signal()));
    connect(new_aulaStudio,SIGNAL(clicked(bool)),this,SIGNAL(addAStudio_signal()));

    //mancano i segnali di modify della singola aula e di delete


 //l'idea è quella di inserire nella scroll_area le varie aule tramite un for...per visualizzarle tutte
    // vicino ad ogni aula devono esserci 2 pulsanti: "MODIFICA" ed "ELIMINA"

    //MODIFICA porta a scheda_modifica.h mentre ELIMINA deve eliminare l'aula dallo storage

}

void admin_view::visualizza_aule(contenitore<prenotazione*>& ) const{
    foreach()
}

//MI SERVE SOLO COME SPUNTO!!!
/*void ResultsWidget::showResults(Engine::Query query, Engine::ResultSet results) {
    // Clears previous data
    while (!lookup.isEmpty()) {
        WidgetLookup info = lookup.takeLast();
        delete info.getWidget();
    }

    // Shows new data
    if (results.getTotal() > 0) {
        results_total->setText(QString::number(results.getTotal()) + " results for \"" + QString::fromStdString(query.getText()) + "\":");
    }
    else {
        results_total->setText("No results for \"" + QString::fromStdString(query.getText()) + "\".");
    }
    previous_page->setEnabled(query.getOffset() > 0);
    next_page->setEnabled(results.getItems().size() == query.getSize());
    renderer->render(grid, results, &lookup);

    // Connects signals
    for (
        QVector<WidgetLookup>::const_iterator it = lookup.begin();
        it != lookup.end();
        it++
        ) {
        if (it->getEditButton()) {
            connect(it->getEditButton(), &QPushButton::clicked, std::bind(&ResultsWidget::editItem, this, it->getItem()));
        }
        if (it->getDeleteButton()) {
            connect(it->getDeleteButton(), &QPushButton::clicked, std::bind(&ResultsWidget::deleteItem, this, it->getItem()));
        }
    }
}
*/
