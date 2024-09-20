#ifndef LRCSHOW_H
#define LRCSHOW_H

#include <hard.h>

namespace Ui {
class LrcShow;
}

class LrcShow : public QWidget
{
    Q_OBJECT

public:
    explicit LrcShow(QWidget *parent = nullptr);
    ~LrcShow();

    QPoint my_pos;
    int fontSize = 10;
    QString lrcNow,lrcDown;
    QPoint center;

    //反向
    bool dic = false;
    //单双
    bool alone = false;
    //锁
    bool lock = false;

    //设置歌词样式
    void set_lrcStyle(QString now,QString down);
    //设置歌词
    void setLrc(QString now,QString down);

    //重写事件过滤器
    bool eventFilter(QObject *target, QEvent *event) override;

    //鼠标按下
    void mousePressEvent(QMouseEvent* event)override;
    //鼠标移动
    void mouseMoveEvent(QMouseEvent* event)override;

    void play();
    void stop();

    //写数据
    void writer_data();
    //读数据
    void read_data();

private slots:
    void on_pushButton_lock_clicked();

    void on_pushButton_unlock_clicked();

    void on_pushButton_play_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_up_clicked();

    void on_pushButton_down_clicked();

    void on_pushButton_seit_clicked();

    void on_pushButton_dic_clicked();

    void on_pushButton_alone_clicked();

    void on_pushButton_hide_clicked();

signals:
    void musicUp();
    void musicDown();
    void musicPlay();
    void musicStop();
    void seitShow();

private:
    Ui::LrcShow *ui;
};

#endif // LRCSHOW_H
