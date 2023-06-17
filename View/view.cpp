#include "view.h"

//la Size deve essere coerente
void View::setDim(const QSize& m){
    resize(m);
}
View::View(const QSize& s, View* v): QWidget(v,Qt::Window){
    setDim(s);

}
View::~View(){
    setParent(nullptr);
}
void View::showMessage(const QString& t,const QString& i)  {
    QMessageBox::information(this,t,i,QMessageBox::Ok);

}
void View::showError(const QString& t ,const QString& i )  {
    QMessageBox::critical(this,t,i,QMessageBox::Ok);
}
void View::setViewTitle(const QString &title) {
    setWindowTitle(title);
}
void View::closeEvent(QCloseEvent *event){
    event->accept();
    hide();
    emit viewClosed();
}

View::View(){}
