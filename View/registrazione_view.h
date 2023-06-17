#ifndef REGISTRAZIONE_VIEW_H
#define REGISTRAZIONE_VIEW_H

#include "view.h"

#include <QtWidgets>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>


class registrazione_view : public View
{
    Q_OBJECT

private:
    QLineEdit *nomeLineEdit;
    QLineEdit *cognomeLineEdit;
    QLineEdit *codLineEdit;
    QLineEdit *phoneLineEdit;
    QLineEdit *emailLineEdit;
    QRadioButton *docenteRadioButton;
    QRadioButton *studenteRadioButton;
    QLineEdit *passwordLineEdit;
    QLineEdit *confirmPasswordLineEdit;

protected:
    explicit registrazione_view();

public:
    explicit registrazione_view(const QSize& s, View *parent = nullptr);
    void closeEvent(QCloseEvent *event) override;

public slots:
    void onRegisterButtonClicked();
};

#endif // REGISTRAZIONE_VIEW_H
