#ifndef MENU_VIEW_H
#define MENU_VIEW_H

#include "view.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QObject>
#include <QPixmap>

class menu_view : public View {
    Q_OBJECT
private:
    QVBoxLayout* vbox;
    QLabel* logoLabel;
    QLabel* benvenuto;
    QHBoxLayout* HLayout;
    QPushButton* viewProfilo;
    QPushButton* viewMyPren;
    QPushButton* viewTuttePren;
    QString mail;

protected:
    explicit menu_view();//costr

public:
    explicit menu_view(const QSize& s, const QString& m, View* parent=nullptr);
    void closeEvent(QCloseEvent *event) override;
    QString getMail() const;

signals:
    void View_profilo_signal(QString&) const;
    //void View_my_signal(const QString&) const;
    void View_tutte_signal(const QString&) const;
};

#endif // MENU_VIEW_H
