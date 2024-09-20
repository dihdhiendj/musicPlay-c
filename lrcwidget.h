#ifndef LRCWIDGET_H
#define LRCWIDGET_H

#include <hard.h>

class lrcWidget :public QLabel
{
public:
    lrcWidget();

    void mousePressEvent(QMouseEvent *event)override;
    void mouseMoveEvent(QMouseEvent *event)override;
    //重写事件过滤器
    bool eventFilter(QObject *target, QEvent *event) override;

    QPoint my_pos;
};

#endif // LRCWIDGET_H
