#ifndef MENU_VIEW_H
#define MENU_VIEW_H

#include "view.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QObject>

class menu_view : public View {
    Q_OBJECT
private:
    QVBoxLayout *vbox;
    QLabel* logoLabel;
    QLabel* benvenuto;
    QHBoxLayout* HLayout;
    QPushButton* viewProfilo;
    QPushButton* viewMyPren;
    QPushButton* viewTuttePren;

protected:
    explicit menu_view();//costr

public:
    explicit menu_view(const QSize&, View*);
    void closeEvent(QCloseEvent *event) override;

signals:
    void View_profilo_signal() const;
    void View_my_signal() const;
    void View_tutte_signal() const;
};

#endif // MENU_VIEW_H
