#include "lrcwidget.h"

lrcWidget::lrcWidget()
{
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setAutoFillBackground(false);//设置自动填充
    setAttribute(Qt::WA_TranslucentBackground, true);//设置窗口背景透明
    repaint();

    this->setStyleSheet("QLabel{font:30pt \"华文仿宋\";"
                        "color: red;"
                        "border-radius:25px;"
                        "background-color:rgba(0,0,0,128);}");
    this->installEventFilter(this);
    this->setAlignment(Qt::AlignCenter);
}

//重写事件过滤器
bool lrcWidget::eventFilter(QObject *target, QEvent *event)
{
    if(target == this && event->type() == QEvent::Enter)
    {
        setAttribute(Qt::WA_NoSystemBackground, false);
        setAttribute(Qt::WA_TranslucentBackground, false);//设置窗口背景透明
        repaint();
        return true;
    }
    else if(target == this && event->type() == QEvent::Leave)
    {
        setAutoFillBackground(false);
        setAttribute(Qt::WA_TranslucentBackground, true);//设置窗口背景透明
        repaint();
        return true;
    }
    return false;
}

void lrcWidget::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        my_pos = event->pos();
        event->accept();
    }
    QLabel::mousePressEvent(event);
}
//鼠标移动
void lrcWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton) {
        move(QCursor::pos() - my_pos);
        event->accept();
    }
    QLabel::mouseMoveEvent(event);
}

