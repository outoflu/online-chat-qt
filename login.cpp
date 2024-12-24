#include "login.h"
#include "clickedlabel.h"
#include "ui_login.h"
#include "HttpMgr.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    connect(ui->RegisterButton,&QPushButton::clicked,this,&Login::switch_register);
    //connect(ui->ForgetPasswdLabel,&ClickedLabel::clicked,this,&Login::slot_forget_pwd);
    ui->ForgetPasswdLabel->SetState("normal", "hover", "", "selected", "selected_hover", "");
    ui->ForgetPasswdLabel->setCursor(Qt::PointingHandCursor);


    ui->PasswdEdit->setEchoMode(QLineEdit::Password);
    ui->ErrorTipsLabel->setProperty("state", "normal");
    ui->PasswdVisible->SetState("unvisible", "unvisible_hover", "", "visible",
                                       "visible_hover", "");
    //连接点击事件

    connect(ui->PasswdVisible, &ClickedLabel::clicked, this, [this]() {
        auto state = ui->PasswdVisible->GetCurState();
        if (state == ClickLbState::Normal) {
            ui->PasswdEdit->setEchoMode(QLineEdit::Password);
        }
        else {
            ui->PasswdEdit->setEchoMode(QLineEdit::Normal);
        }
        qDebug() << "Label was clicked!";
    });
    repolish(ui->ErrorTipsLabel);

    connect(ui->ForgetPasswdLabel, &ClickedLabel::clicked, this, &Login::slot_forget_pwd);
    initHttphandlers();

    connect(HttpMgr::getInstance().get(), &HttpMgr::sig_login_mod_finish, this, &Login::slot_login_mod_finish);

    
}

void Login::slot_forget_pwd(){
    qDebug()<<"slot forget pwd";
    emit switch_reset();
}

void Login::slot_login_mod_finish() {

}

Login::~Login()
{
    delete ui;
}

void Login::initHttphandlers()
{
    _handlers.insert(ReqId::ID_REG_USER, [](QJsonObject jsonObj) {
        int error = jsonObj["error"].toInt();
        if (error != ErrorCodes::SUCCESS) {
            
        }
        });

}

bool Login::checkUserVaild()
{
    auto user = ui->UserEdit->text();
    if (user.isEmpty()) {
        qDebug() << "User empty ";
        return false;
    }

    return true;
}

bool Login::checkPasswdVaild()
{
    auto passwd = ui->PasswdEdit->text();
    if (passwd.length() < 6 || passwd.length() > 15) {
        qDebug() << "Pass length invalid";
        return false;
    }

    return true;
}

void Login::show_tips(const QString& content, bool flag)
{
}

void Login::show_normal_tips(const QString& content)
{
    
}

void Login::show_error_tips(const QString& content)
{
}
