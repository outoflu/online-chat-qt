#ifndef GLOBAL_H
#define GLOBAL_H

#include <QWidget>
#include <functional>
#include <QStyle>
#include <QByteArray>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QDir>
#include <QSettings>

extern std::function<void(QWidget*)> repolish;

enum ReqId {
    ID_GET_VARIFY_CODE = 1001,//获取验证码
    ID_REG_USER = 1002,
    ID_LOGIN_USER = 1003,
    ID_RESET_PWD=1004,
    ID_RESET_USER = 1005
};

enum Modules{
    REGISTERMOD=0,//注册用户
    RESETMOD=1,//
    LOGINMOD=2,
};

enum ErrorCodes{
    SUCCESS=0,
    ERR_JSON=1,//json 解析失败
    ERR_NETWORK=2,//网络错误
};

enum TipErr{
    TIP_SUCCESS = 0,
    TIP_EMAIL_ERR = 1,
    TIP_PWD_ERR = 2,
    TIP_CONFIRM_ERR = 3,
    TIP_PWD_CONFIRM = 4,
    TIP_VARIFY_ERR = 5,
    TIP_USER_ERR = 6
};

enum ClickLbState{
    Normal = 0,
    Selected = 1
};

extern QString GateUrlPrefix;
#endif // GLOBAL_H
