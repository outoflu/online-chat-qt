#include "register.h"
#include "ui_register.h"
#include "global.h"
#include <QRegularExpression>
#include <QPushButton>
#include "HttpMgr.h"
Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->PasswdEdit->setEchoMode(QLineEdit::Password);
    ui->ConfirmPasswdEdit->setEchoMode(QLineEdit::Password);
    ui->ErrorTipsLabel->setProperty("state","normal");
    connect(ui->GetCodeButton,&QPushButton::clicked,this,&Register::on_get_code_clicked);
    repolish(this);
    connect(HttpMgr::getInstance().get(),&HttpMgr::sig_reg_mod_finish,this,&Register::slot_reg_mod_finish);
}

Register::~Register()
{
    delete ui;
}

void Register::initHttpHandlers()
{
    _handlers.insert(ReqId::ID_GET_VARIFY_CODE,[this](const QJsonObject& jsonObj){
        int error=jsonObj["error"].toInt();
        if (error!=ErrorCodes::SUCCESS){
            show_error_tips(tr("参数错误"));
            return ;
        }
        auto email=jsonObj["email"].toString();
        show_normal_tips(tr("验证码已经发送，注意接收"));

    });
}

void Register::on_get_code_clicked(){
    auto email=ui->MailEdit->text();
    //QRegularExpression regex(R"((\w+)(\.|\_)?(\w*)@(\w+)(\.(\w+))+)");
    static QRegularExpression emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4})");
    auto match=emailRegex.match(email).hasMatch();
    if (match) {
        //发送HTTP请求验证码
    }else {
        show_error_tips(tr("非法的邮箱号"));
    }
}

void Register::slot_reg_mod_finish(ReqId id, QString res, ErrorCodes err_code)
{
    if (err_code!=ErrorCodes::SUCCESS){
        show_error_tips(tr("网络请求错误"));
        return ;
    }
    QJsonDocument jsonDoc=QJsonDocument::fromJson(res.toUtf8());
    if (jsonDoc.isEmpty()){
        show_error_tips(tr("Json解析失败"));
        return ;
    }
    if (!jsonDoc.isObject()){
        show_error_tips(tr("Json解析对象失败"));
    }

    //jsonDoc.object();
    _handlers[id](jsonDoc.object());
    return ;
}

void Register::show_tips(const QString& tips,bool type){
    if (type){
        show_normal_tips(tips);
    }else {
        show_error_tips(tips);
    }
}

void Register::show_normal_tips(const QString& normal_tips){
    ui->ErrorTipsLabel->setText(normal_tips);
    ui->ErrorTipsLabel->setProperty("state","normal");
    repolish(ui->ErrorTipsLabel);
}
void Register::show_error_tips(const QString& error_tips){
    ui->ErrorTipsLabel->setText(error_tips);
    ui->ErrorTipsLabel->setProperty("state","error");
    repolish(ui->ErrorTipsLabel);
}
