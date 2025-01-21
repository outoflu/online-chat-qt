#include "login.h"
#include "clickedlabel.h"
#include "ui_login.h"
#include "HttpMgr.h"
#include "TcpMgr.h"

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
    connect(ui->LoginButton, &QPushButton::clicked, this, &Login::slot_login);
    
    connect(this, &Login::sig_connect_tcp, TcpMgr::getInstance().get(), &TcpMgr::slot_tcp_connect);
    connect(TcpMgr::getInstance().get(), &TcpMgr::sig_con_success, this, &Login::slot_tcp_connect_finish);
}

void Login::slot_login() {
    qDebug() << "login btn clicked";
    if (checkUserVaild() == false) {
        return;
    }
    if (checkPasswdVaild() == false) {
        return;
    }

    auto user = ui->UserEdit->text();
    auto pwd = ui->PasswdEdit->text();
    //发送http请求登录
    QJsonObject json_obj;
    json_obj["email"] = user;
    json_obj["password"] = pwd;
    HttpMgr::getInstance()->post_http_request(QUrl(GateUrlPrefix + "/user_login"),
        json_obj, ReqId::ID_LOGIN_USER, Modules::LOGINMOD);

}
void Login::slot_forget_pwd(){
    qDebug()<<"slot forget pwd";
    emit switch_reset();
}

void Login::slot_login_mod_finish(ReqId id, QString res, ErrorCodes errorCode)
{
    if (errorCode != ErrorCodes::SUCCESS) {
        show_tips(tr("网络请求错误"), false);
        return;
    }

    // 解析 JSON 字符串,res需转化为QByteArray
    QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());
    //json解析错误
    if (jsonDoc.isNull()) {
        show_tips(tr("json解析错误"), false);
        return;
    }

    //json解析错误
    if (!jsonDoc.isObject()) {
        show_tips(tr("json解析错误"), false);
        return;
    }


    //调用对应的逻辑,根据id回调。
    _handlers[id](jsonDoc.object());

    return;
}

void Login::slot_tcp_connect_finish(bool success)
{
    if (success) {
        show_tips(tr("聊天服务连接成功，正在登录..."), true);
        QJsonObject jsonObj;
        jsonObj["uid"] = _uid;
        jsonObj["token"] = _token;

        QJsonDocument doc(jsonObj);
        QString jsonString = doc.toJson(QJsonDocument::Indented);

        //发送tcp请求给chat server
        emit TcpMgr::getInstance()->sig_send_data(ReqId::ID_CHAT_LOGIN, jsonString);

    }
    else {
        show_tips(tr("网络异常"), false);
        enableBtn(true);
    }
}


Login::~Login()
{
    delete ui;
}

void Login::initHttphandlers()
{
    _handlers.insert(ReqId::ID_REG_USER, [this](QJsonObject jsonObj) {
        int error = jsonObj["error"].toInt();
        if (error != ErrorCodes::SUCCESS) {
            show_error_tips(tr("参数错误"));
            return;
        }
        auto user = jsonObj["user"].toString();

        ServerInfo si;
        si.Uid = jsonObj["uid"].toInt();
        si.Host = jsonObj["host"].toString();
        si.Port = jsonObj["port"].toString();
        si.Token = jsonObj["token"].toString();

        _uid = si.Uid;
        _token = si.Token;
        qDebug() << "user is " << user << " uid is " << si.Uid << " host is "
            << si.Host << " Port is " << si.Port << " Token is " << si.Token;
        emit sig_connect_tcp(si);
        show_tips(tr("登录成功"), true);
        qDebug() << "user is " << user;
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
    if (flag) {
        show_normal_tips(content);
    }
    else {
        show_error_tips(content);
    }
}

void Login::show_normal_tips(const QString& content)
{
    ui->ErrorTipsLabel->setText(content);
    ui->ErrorTipsLabel->setProperty("state", "normal");
    repolish(ui->ErrorTipsLabel);
}

void Login::show_error_tips(const QString& content)
{
    ui->ErrorTipsLabel->setText(content);
    ui->ErrorTipsLabel->setProperty("state", "error");
    repolish(ui->ErrorTipsLabel);
}

void Login::enableBtn(bool enabled)
{
    ui->LoginButton->setEnabled(enabled);
    ui->RegisterButton->setEnabled(enabled);
    return;
}
