#include "guiauthenticated.h"
#include "ui_guiauthenticated.h"

GuiAuthenticated::GuiAuthenticated(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GuiAuthenticated)
{
    ui->setupUi(this);

    connect(ui->submitButton,SIGNAL(clicked()),this,SLOT(submit()));
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(cancel()));
}

GuiAuthenticated::~GuiAuthenticated()
{
    delete ui;
}

void GuiAuthenticated::submit(){

    QStringList _auth;

    _auth << ui->login->text();
    _auth << ui->password->text();

    qDebug()<< _auth;

    emit setAuth(_auth);

}

void GuiAuthenticated::error(const QString &cod){

    ui->label->setStyleSheet(" background-color:red");
    ui->label_2->setStyleSheet(" background-color: red");
   }

void GuiAuthenticated::cancel(){
    ui->login->clear();
    ui->password->clear();
}

