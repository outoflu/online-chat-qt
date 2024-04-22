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

enum ReqId{
    ID_GET_VARIFY_CODE=1001,//获取验证码
    ID_REG_USER=1002,
};

enum Modules{
    REGISTERMOD=0,//注册用户
};

enum ErrorCodes{
    SUCCESS=0,
    ERR_JSON=1,//json 解析失败
    ERR_NETWORK=2,//网络错误
};

extern QString GateUrlPrefix;
#endif // GLOBAL_H
