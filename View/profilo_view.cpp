#include "profilo_view.h"

profilo_view::profilo_view(const QSize& s, View* parent) : View(s, parent)
{
    table = new QTableWidget(this);
    table->setRowCount(5);
    table->setColumnCount(2);
    //da documentazione qt
    table->setVerticalHeaderLabels(const QStringList &labels)
    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
}

void profilo_view::closeEvent(QCloseEvent *event){
    if(QMessageBox::question(this,"Uscita","Vuoi uscire davvero?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes){
        event->accept();
        emit viewClosed();
    }
    else
        event->ignore();
}
