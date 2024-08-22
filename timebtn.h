#ifndef TIMEBTN_H
#define TIMEBTN_H

#include <QPushButton>
#include <QTimer>

class TimeBtn: public QPushButton
{
    Q_OBJECT;
public:
   TimeBtn(QWidget* widget=nullptr);
    ~TimeBtn();
    // 重写mouseReleaseEvent
    virtual void mouseReleaseEvent(QMouseEvent *e) override;
private:
    QTimer  *_timer;
    int _counter;
};

#endif // TIMEBTN_H
