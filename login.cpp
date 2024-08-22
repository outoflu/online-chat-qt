#include "login.h"
#include "qpushbutton.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    connect(ui->RegisterButton,&QPushButton::clicked,this,&Login::switch_register);
    //connect(ui->ForgetPasswdLabel,&QLabel::clicked,this,&Login::slot_forget_pwd);
}

void Login::slot_forget_pwd(){
    qDebug()<<"slot forget pwd";
    emit switch_reset();
}

Login::~Login()
{
    delete ui;
}
