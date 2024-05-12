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
    connect(ui->GetCodeButton,&QPushButton::clicked,this,&Register::slot_on_get_code_clicked);
    connect(ui->ConfirmBtn,&QPushButton::clicked,this,&Register::slot_on_confirmbtn_clicked);
    repolish(this);
    connect(HttpMgr::getInstance().get(),&HttpMgr::sig_reg_mod_finish,this,&Register::slot_reg_mod_finish);
    initHttpHandlers();
}

Register::~Register()
{
    delete ui;
}

void Register::initHttpHandlers()
{
    _handlers.insert(ReqId::ID_GET_VARIFY_CODE,[this](QJsonObject jsonObj){
        int error=jsonObj["error"].toInt();
        if (error!=ErrorCodes::SUCCESS){
            show_error_tips(tr("参数错误"));
            return ;
        }
        //auto email=jsonObj["email"].toString();
        show_normal_tips(tr("验证码已经发送，注意接收"));
        return ;

    });
    _handlers.insert(ReqId::ID_REG_USER,[this](QJsonObject jsonObj){
        int error=jsonObj["error"].toInt();
        if (error!=ErrorCodes::SUCCESS){
            show_error_tips(tr("参数错误"));
            return ;
        }else {
            auto email = jsonObj["email"].toString();
            show_normal_tips(tr("用户注册成功"));
            qDebug()<< "email is " << email ;
        }
    });
}

void Register::slot_on_get_code_clicked(){
    auto email=ui->MailEdit->text();
    //QRegularExpression regex(R"((\w+)(\.|\_)?(\w*)@(\w+)(\.(\w+))+)");
    static QRegularExpression emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4})");
    auto match=emailRegex.match(email).hasMatch();
    if (match) {
        //发送HTTP请求验证码
        QJsonObject json_obj;
        json_obj["email"]=email;
        HttpMgr::getInstance()->post_http_request(QUrl(GateUrlPrefix+"/get_varifycode"),
                                            json_obj,ReqId::ID_GET_VARIFY_CODE,Modules::REGISTERMOD);
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
    if (jsonDoc.isNull()){
        show_error_tips(tr("Json解析失败"));
        return ;
    }
    if (!jsonDoc.isObject()){
        show_error_tips(tr("Json解析对象失败"));
    }

    //jsonDoc.object();
    try {
        _handlers[id](jsonDoc.object());
    }catch(std::exception& e ){
        std::cout<<e.what()<<std::endl;
    }

    return ;
}

void Register::slot_on_confirmbtn_clicked(){
    if (ui->UserEdit->text()==""){
        show_error_tips(tr("用户名不能为空"));
        return ;
    }
    else if (ui->MailEdit->text()==""){
        show_error_tips(tr("邮箱不能为空"));
        return ;
    }else if (ui->PasswdEdit->text()==""){
        show_error_tips(tr("密码不能为空"));
        return ;
    }else if (ui->ConfirmPasswdEdit->text()!=ui->PasswdEdit->text()){
        show_error_tips(tr("前后输入的密码不一致"));
        return ;
    }else if (ui->CodeEdit->text()=="")  {
        show_error_tips(tr("验证码不能为空"));
        return ;
    }else {
        QJsonObject json_obj;
        json_obj["user"]=ui->UserEdit->text();
        json_obj["email"]=ui->MailEdit->text();
        json_obj["password"]=ui->PasswdEdit->text();
        json_obj["varifycode"]=ui->CodeEdit->text();
        HttpMgr::getInstance()->post_http_request(
            QUrl(GateUrlPrefix+"/user_register"),json_obj,ReqId::ID_REG_USER,Modules::REGISTERMOD);
    }
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


