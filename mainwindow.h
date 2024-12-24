#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "register.h"
#include "resetdialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void slot_switch_register();
    void slot_switch_reset();
    void slot_switch_reset_login();
    void slot_switch_register_login();
private:
    Ui::MainWindow *ui;
    Login *_login_w;
    Register *_register_w;
    ResetDialog* _reset_w;
};
#endif // MAINWINDOW_H
