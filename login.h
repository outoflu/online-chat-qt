#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

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
signals:
    void switch_register();
    void switch_reset();
public slots:
    void slot_forget_pwd();
};

#endif // LOGIN_H
