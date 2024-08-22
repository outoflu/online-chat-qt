#ifndef REGISTER_H
#define REGISTER_H
#include "global.h"
#include <HttpMgr.h>
#include <QDialog>
#include <QMap>
#include <QRegularExpression>
#include <QTimer>
namespace Ui {
class Register;
}


class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();
    void initHttpHandlers();
    static const QString emailRegexString;
    static const QRegularExpression emailRegex;
signals:
    void sigSwitchLogin();
public slots:
    void slot_on_get_code_clicked();
    void slot_reg_mod_finish(ReqId id,QString res,ErrorCodes err_code);
    void slot_on_confirmbtn_clicked();
    void slot_check_user_valid();
    void slot_check_mail_valid();
    void slot_check_passwd_valid();
    void slot_check_confirmpasswd_valid();
    void slot_check_verifycode_valid();
private:
    void show_tips(const QString&,bool);
    void show_normal_tips(const QString&);
    void show_error_tips(const QString&);
    QMap<ReqId,std::function<void(QJsonObject)>> _handlers;
    QMap<TipErr,QString> _tip_errs;

private:
    Ui::Register* ui;
    QTimer* _countdown_timer;
};

#endif // REGISTER_H
