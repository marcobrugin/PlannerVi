#include "login_view.h"
#include <QDebug>

login_view::login_view(const QSize& s, View* parent) : View(s, parent) {

    layout = new QVBoxLayout(this);

    // Aggiungi il logo
    QPixmap logoPixmap(":/Images/consvi.svg");
    logoLabel = new QLabel(this);
    logoLabel->setPixmap(logoPixmap.scaledToHeight(150));
    logoLabel->setAlignment(Qt::AlignHCenter);
    layout->addWidget(logoLabel);

    QFont font1;
    font1.setBold(true);
    font1.setPointSize(14);
    QFont font2;
    font2.setItalic(true);
    font2.setPointSize(11);

    QLabel* t1= new QLabel("PlannerVi",this);
    t1->setAlignment(Qt::AlignCenter);
    t1->setFont(font1);
    QLabel* t2= new QLabel("Software di prenotazione delle aule del Conservatorio di Vicenza",this);
    t2->setAlignment(Qt::AlignCenter);
    t2->setFont(font2);
    layout->addWidget(t1);
    layout->addWidget(t2);

    HLayout = new QHBoxLayout(this);
    layout->addLayout(HLayout);

    Vl1 = new QVBoxLayout(this);
    emailLabel = new QLabel(this);
    emailLabel->setText("Email");
    Vl1->addWidget(emailLabel);
    passwLabel = new QLabel(this);
    passwLabel->setText("Password");
    Vl1->addWidget(passwLabel);
    HLayout->addLayout(Vl1);

    HLayout->addStretch();

    Vl2 = new QVBoxLayout(this);
    emailLineEdit = new QLineEdit(this);
    emailLineEdit->setPlaceholderText("inserire email");
    Vl2->addWidget(emailLineEdit);
    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setPlaceholderText("inserire password");
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    Vl2->addWidget(passwordLineEdit);
    HLayout->addLayout(Vl2);

    // Aggiungi pulsante di login
    loginButton = new QPushButton("Login", this);
    layout->addWidget(loginButton);

    // Connessione del pulsante di login allo slot onLoginButtonClicked()
    connect(loginButton,SIGNAL(clicked(bool)),this,SIGNAL(ButtonClicked()));
    connect(this,SIGNAL(ButtonClicked()),this,SLOT(onLoginButtonClicked()));

    // Aggiungi link per la registrazione
    registerLabel = new QLabel(this);
    registerLabel->setText("<a href='register'>Non sei registrato? Registrati</a>");
    registerLabel->setAlignment(Qt::AlignRight);
    registerLabel->setTextFormat(Qt::RichText);
    registerLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    registerLabel->setOpenExternalLinks(false);
    layout->addWidget(registerLabel);

    // Connessione del segnale linkActivated all'evento onRegisterClicked
    connect(registerLabel, SIGNAL(linkActivated(QString)), this, SIGNAL(Register_signal()));

    setLayout(layout) ;
}

void login_view::onLoginButtonClicked(){
    //controlli base, gli altri vanno fatti sul login_controller
    const QString email = emailLineEdit->text();
    const QString password = passwordLineEdit->text();

    if(email.isEmpty() || password.isEmpty()){
        static_cast<View*>(this)->showError("Inserimento errato", "Il valore inserito non è permesso");
    } else {
        emit Login_signal(email.toStdString(), password.toStdString());
    }
}

void login_view::closeEvent(QCloseEvent *event){
    if(QMessageBox::question(this,"Uscita","Vuoi uscire davvero?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes){
        event->accept();
        emit viewClosed();
    }
    else
        event->ignore();
}
