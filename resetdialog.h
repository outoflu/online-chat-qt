#ifndef RESETDIALOG_H
#define RESETDIALOG_H
#include <global.h>
#include <HttpMgr.h>
#include <QDialog>
#include <QMap>
#include <QRegularExpression>

namespace Ui {
class ResetDialog;
}


class ResetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ResetDialog(QWidget *parent = nullptr);
    ~ResetDialog();
    void initHttpHandlers();
    static const QString emailRegexString;
    static const QRegularExpression emailRegex;
public slots:
    void slot_on_get_code_clicked();
    void slot_reset_mod_finish(ReqId id,QString res,ErrorCodes err_code);
    void slot_on_confirmbtn_clicked();
    void slot_check_user_valid();
    void slot_check_mail_valid();
    void slot_check_passwd_valid();
    void slot_check_verifycode_valid();
private:
    void show_tips(const QString&,bool);
    void show_normal_tips(const QString&);
    void show_error_tips(const QString&);
    void add_tip_err(TipErr te,const QString&);
    void del_tip_err(TipErr te);
    bool check_user_valid();
    bool check_email_valid();
    bool check_passwd_valid();
    bool check_verifycode_valid();
    QMap<ReqId,std::function<void(QJsonObject)>> _handlers;
    QMap<TipErr,QString> _tip_errs;
    void change_tip_page();
    QTimer* _countdown_timer;
    int _countdown;
private:
    Ui::ResetDialog *ui;
signals:
    void switch_login();
};

#endif // RESETDIALOG_H
