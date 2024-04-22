#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    connect(ui->RegisterButton,&QPushButton::clicked,this,&Login::switch_register);
    ui->PasswdEdit->setEchoMode(QLineEdit::Password);
}

Login::~Login()
{
    delete ui;
}
