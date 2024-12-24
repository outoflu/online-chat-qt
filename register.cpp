#include "register.h"
#include "qlineedit.h"
#include "qregularexpression.h"
#include "ui_register.h"
#include "global.h"
#include <QRegularExpression>
#include <QPushButton>
#include "HttpMgr.h"
#include "clickedlabel.h"
#include "register.h"
//this Regex is used to check email valid or not

const QString Register::emailRegexString=R"((\w+)(\.|\_)?(\w*)@(\w+)(\.(\w+))+)";
const QRegularExpression Register::emailRegex=QRegularExpression(Register::emailRegexString);


Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    
    

    ui->PasswdEdit->setEchoMode(QLineEdit::Password);
    ui->ConfirmPasswdEdit->setEchoMode(QLineEdit::Password);
    ui->ErrorTipsLabel->setProperty("state","normal");
    repolish(ui->ErrorTipsLabel);

    connect (ui->UserEdit,&QLineEdit::editingFinished,this,&Register::slot_check_user_valid);
    connect (ui->MailEdit,&QLineEdit::editingFinished,this,&Register::slot_check_mail_valid);
    connect (ui->PasswdEdit,&QLineEdit::editingFinished,this,&Register::slot_check_passwd_valid);
    connect (ui->ConfirmPasswdEdit,&QLineEdit::editingFinished,this,&Register::slot_check_confirmpasswd_valid);
    connect (ui->CodeEdit,&QLineEdit::editingFinished,this,&Register::slot_check_verifycode_valid);


    connect(ui->GetCodeButton,&QPushButton::clicked,this,&Register::slot_on_get_code_clicked);
    connect(ui->ConfirmBtn,&QPushButton::clicked,this,&Register::slot_on_confirmbtn_clicked);
    //repolish(this);
    connect(HttpMgr::getInstance().get(),&HttpMgr::sig_reg_mod_finish,this,&Register::slot_reg_mod_finish);
    initHttpHandlers();

    ui->PasswdVisible->setCursor(Qt::PointingHandCursor);
    ui->ConfirmPasswdVisible->setCursor(Qt::PointingHandCursor);

    ui->PasswdVisible->SetState("unvisible", "unvisible_hover", "", "visible",
        "visible_hover", "");

    ui->ConfirmPasswdVisible->SetState("unvisible", "unvisible_hover", "", "visible",
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

    connect(ui->ConfirmPasswdVisible, &ClickedLabel::clicked, this, [this]() {
        auto state = ui->ConfirmPasswdVisible->GetCurState();
        if (state == ClickLbState::Normal) {
            ui->ConfirmPasswdEdit->setEchoMode(QLineEdit::Password);
        }
        else {
            ui->ConfirmPasswdEdit->setEchoMode(QLineEdit::Normal);
        }
        qDebug() << "Label was clicked!";
        });

    _countdown_timer = new QTimer(this);
    // 连接信号和槽
    _countdown = 5;
    connect(_countdown_timer, &QTimer::timeout, [this]() {
        if (_countdown == 0) {
            _countdown_timer->stop();
            emit sigSwitchLogin();
            return;
        }
        _countdown--;
        auto str = QString("注册成功，%1 s后返回登录").arg(_countdown);
        ui->tip_lb->setText(str);
        });

    connect(ui->CancelBtn,&QPushButton::clicked,this,&Register::slot_switch_login);
    connect(ui->return_btn,&QPushButton::clicked,this,&Register::slot_switch_login);
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
            chang_tip_page();
            qDebug()<< "email is " << email ;
        }
    });
}

void Register::slot_on_get_code_clicked(){
    auto email=ui->MailEdit->text();
    //QRegularExpression regex(R"((\w+)(\.|\_)?(\w*)@(\w+)(\.(\w+))+)");
    //static QRegularExpression emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4})");
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
        //json_obj["live"] = QString("live");
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

void Register::add_tip_err(TipErr te, const QString& tips)
{
    _tip_errs[te] = tips;
    show_error_tips(tips);
}

void Register::del_tip_err(TipErr te)
{
    _tip_errs.remove(te); //QMap::remove在Key不存在时只会返回0
    if (_tip_errs.empty()) {
        ui->ErrorTipsLabel->clear();
        return;
    }
    show_error_tips(_tip_errs.first());
}

bool Register::check_user_valid()
{
    if (ui->UserEdit->text() == "") {
        add_tip_err(TipErr::TIP_USER_ERR, tr("用户名不能为空"));
        return false;
    }
    del_tip_err(TipErr::TIP_USER_ERR);
    return true;
}

bool Register::check_email_valid()
{
    //验证邮箱的地址正则表达式
    auto email = ui->MailEdit->text();
    // 邮箱地址的正则表达式
    bool match = this->emailRegex.match(email).hasMatch(); // 执行正则表达式匹配
    if (!match) {
        //提示邮箱不正确
        add_tip_err(TipErr::TIP_EMAIL_ERR, tr("邮箱地址不正确"));
        return false;
    }

    del_tip_err(TipErr::TIP_EMAIL_ERR);
    return true;
}

bool Register::check_passwd_valid()
{
    auto pass = ui->PasswdEdit->text();

    if (pass.length() < 6 || pass.length() > 15) {
        //提示长度不准确
        add_tip_err(TipErr::TIP_PWD_ERR, tr("密码长度应为6~15"));
        return false;
    }

    // 创建一个正则表达式对象，按照上述密码要求
    // 这个正则表达式解释：
    // ^[a-zA-Z0-9!@#$%^&*]{6,15}$ 密码长度至少6，可以是字母、数字和特定的特殊字符
    static QRegularExpression regExp("^[a-zA-Z0-9!@#$%^&*]{6,15}$");
    bool match = regExp.match(pass).hasMatch();
    if (!match) {
        //提示字符非法
        add_tip_err(TipErr::TIP_PWD_ERR, tr("不能包含非法字符"));
        return false;;
    }

    del_tip_err(TipErr::TIP_PWD_ERR);

    return true;
}

bool Register::check_confirmpasswd_valid()
{
    auto passwd = ui->PasswdEdit->text();
    auto passwd2 = ui->ConfirmPasswdEdit->text();
    if (passwd == passwd2) {
        del_tip_err(TipErr::TIP_CONFIRM_ERR);
        return true;
    }
    else {
        add_tip_err(TipErr::TIP_CONFIRM_ERR,tr("前后密码不一致"));
        return false;
    }

}

bool Register::check_verifycode_valid()
{
    auto pass = ui->CodeEdit->text();
    if (pass.isEmpty()) {
        add_tip_err(TipErr::TIP_VARIFY_ERR, tr("验证码不能为空"));
        return false;
    }

    del_tip_err(TipErr::TIP_VARIFY_ERR);
    return true;
}
void Register::chang_tip_page()
{
    _countdown_timer->stop();
    ui->stackedWidget->setCurrentWidget(ui->page_2);

    _countdown_timer->start(1000);
    // 启动定时器，设置间隔为1000毫秒（1秒）
    
}

void Register::slot_check_user_valid(){
    check_user_valid();
}
void Register::slot_check_mail_valid(){
    check_email_valid();
}
void Register::slot_check_passwd_valid(){
    check_passwd_valid();
}
void Register::slot_check_confirmpasswd_valid(){
    check_confirmpasswd_valid();
}
void Register::slot_check_verifycode_valid(){
    check_verifycode_valid();
}

void Register::slot_switch_login()
{
    _countdown_timer->stop();
    emit sigSwitchLogin();
}


