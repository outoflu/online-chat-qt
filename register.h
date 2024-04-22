#ifndef REGISTER_H
#define REGISTER_H
#include <global.h>
#include <HttpMgr.h>
#include <QDialog>
#include <QMap>
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
public slots:
    void on_get_code_clicked();
    void slot_reg_mod_finish(ReqId id,QString res,ErrorCodes err_code);
private:
    void show_tips(const QString&,bool);
    void show_normal_tips(const QString&);
    void show_error_tips(const QString&);
    QMap<ReqId,std::function<void(QJsonObject)>> _handlers;

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
