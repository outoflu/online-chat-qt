#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "global.h"
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
private:
    Ui::Login *ui;
    int _uid;
    QString _token;
    void initHttphandlers();
    bool checkUserVaild();
    bool checkPasswdVaild();
    QMap<ReqId, std::function<void(QJsonObject)>> _handlers;
    void show_tips(const QString&, bool);
    void show_normal_tips(const QString&);
    void show_error_tips(const QString&);
    void enableBtn(bool);
signals:
    void switch_register();
    void switch_reset();
    void sig_connect_tcp(ServerInfo);
public slots:
    void slot_login();
    void slot_forget_pwd();
    void slot_login_mod_finish(ReqId id,QString res,ErrorCodes errorCode);
    void slot_tcp_connect_finish(bool success);
};

#endif // LOGIN_H
