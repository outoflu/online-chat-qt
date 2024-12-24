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

    //_register_w=new Register(this);
    //_reset_w = new ResetDialog(this);
    //setCentralWidget(_register_w);
    //_register_w->show();

    _login_w->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    //_register_w->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    //_reset_w->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    //_reset_w->hide();
    //_register_w->hide();

    //connect(_register_w,&Register::sigSwitchLogin,this,&MainWindow::slot_switch_login);

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
    connect(_reset_w, &ResetDialog::switch_login, this, &MainWindow::slot_switch_reset_login);
}

void MainWindow::slot_switch_reset_login()
{
    _login_w=new Login(this);
    _login_w->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    setCentralWidget(_login_w);

    _reset_w->hide();
    //_register_w->hide();

    _login_w->show();

    connect(_login_w, &Login::switch_register, this, &MainWindow::slot_switch_register);
    //连接登录界面忘记密码信号
    connect(_login_w, &Login::switch_reset, this, &MainWindow::slot_switch_reset);
}

void MainWindow::slot_switch_register_login()
{
    _login_w=new Login(this);
    _login_w->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    setCentralWidget(_login_w);

    //_reset_w->hide();
    _register_w->hide();

    _login_w->show();

    connect(_login_w, &Login::switch_register, this, &MainWindow::slot_switch_register);
    //连接登录界面忘记密码信号
    connect(_login_w, &Login::switch_reset, this, &MainWindow::slot_switch_reset);
}



void MainWindow::slot_switch_register(){
    _register_w = new Register(this);
    _register_w->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);

    setCentralWidget(_register_w);
    _login_w->hide();
    _register_w->show();

    connect(_register_w,&Register::sigSwitchLogin,this,&MainWindow::slot_switch_register_login);
}


