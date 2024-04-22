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
    _register_w=new Register(this);
    //setCentralWidget(_register_w);
    //_register_w->show();

    _login_w->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    _register_w->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);



}

MainWindow::~MainWindow()
{
    delete ui;
/*
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

void MainWindow::slot_switch_register(){
    setCentralWidget(_register_w);
    _login_w->hide();
    _register_w->show();
}

