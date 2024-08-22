#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _login_w=new Login(this);
    setCentralWidget(_login_w);
    _login_w->show();

    connect(_login_w,&Login::switch_register,this,&MainWindow::slot_switch_register);
    connect(_login_w,&Login::switch_reset,this,&MainWindow::slot_switch_reset);

    _register_w=new Register(this);
    //setCentralWidget(_register_w);
    //_register_w->show();

    _login_w->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    _register_w->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);



}

MainWindow::~MainWindow()
{
    delete ui;
/* 这里不用手动删除是因为设置了_login_w和_register_w为mainWindow的子窗口，
 * Qt的父子窗口机制会管理这些窗口的生命周期
    if (_login_w!=nullptr){
        delete _login_w;
        _login_w=nullptr;
    }
    if (_register_w!=nullptr){
        delete _register_w;
        _register_w=nullptr;
    }
*/
}

void MainWindow::slot_switch_reset()
{
    _reset_w = new ResetDialog(this);
    _reset_w->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    setCentralWidget(_reset_w);
    _login_w->hide();
    _reset_w->show();
    //注册返回登录信号和槽函数
    connect(_reset_w, &ResetDialog::switch_login, this, &MainWindow::slot_swicth_login2);
}

void MainWindow::slot_swicth_login2()
{

}

void MainWindow::slot_switch_register(){
    setCentralWidget(_register_w);
    _login_w->hide();
    _register_w->show();
}

