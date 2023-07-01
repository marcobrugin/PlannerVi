#ifndef LOGIN_VIEW_H
#define LOGIN_VIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "view.h"

class login_view : public View {
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QLabel *logoLabel;
    QLabel *benvenutoLabel;

    QHBoxLayout *HLayout;
    QVBoxLayout *Vl1;
    QLabel *emailLabel;
    QLabel *passwLabel;
    QVBoxLayout *Vl2;
    QLineEdit *emailLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;
    QLabel *registerLabel;

protected:
    explicit login_view();

public:
    explicit login_view(const QSize& s, View *parent = nullptr);
    void closeEvent(QCloseEvent *event) override;

public slots:
    void onLoginButtonClicked();

signals:
    void ButtonClicked() const;
    void Login_signal(const string& e, const string& p) const;
    void Register_signal() const;
};

#endif // LOGIN_VIEW_H
