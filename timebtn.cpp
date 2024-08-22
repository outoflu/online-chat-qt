#include "timebtn.h"
#include "qevent.h"

TimeBtn::TimeBtn(QWidget *widget):QPushButton(widget),_counter(10){
    _timer=new QTimer(this);
    connect(_timer,&QTimer::timeout,[this](){
        _counter--;
        if (_counter<=0){
            _timer->stop();
            _counter=10;
            this->setText("获取");
            this->setEnabled(true);
            return ;
        }
        this->setText(QString::number(_counter));
    });
}

TimeBtn::~TimeBtn(){
    delete _timer;
}

void TimeBtn::mouseReleaseEvent(QMouseEvent* e){
    if (e->button() == Qt::LeftButton) {
        // 在这里处理鼠标左键释放事件
        qDebug() << "MyButton was released!";
        this->setEnabled(false);
        this->setText(QString::number(_counter));
        _timer->start(1000);
        emit clicked();
    }
    // 调用基类的mouseReleaseEvent以确保正常的事件处理（如点击效果）
    QPushButton::mouseReleaseEvent(e);
}
