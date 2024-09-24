#ifndef LRCSHOW_H
#define LRCSHOW_H

#include <addlib.h>
//歌词行
class lrc_line : public QLabel
{
    Q_OBJECT

public:
    lrc_line(QWidget *parent = nullptr);
    //正在播放,可被跳转
    bool isplay = false,isUse = true;
    //开始时间，持续时间
    qint64 start = 0;
    double last = 3000 ,stop  = 0.0001;

    //歌词播放颜色,字体
    QColor play_color = Qt::red,next_color = Qt::blue, finish_color = Qt::white;
    QFont font;

    //重写鼠标事件
    void mousePressEvent(QMouseEvent *event) override;
    //重写事件过滤器
    bool eventFilter(QObject *target, QEvent *event) override;
    //重写绘图事件
    void paintEvent(QPaintEvent *event) override;

    //设置播放样式
    void set_runStyle(QColor play,QColor next ,QFont f,QColor finish = Qt::white);
    //正在播放
    void playing(qint64 time);
    //恢复
    void back();

    //复制播放数据
    void copy(lrc_line* one);

signals:
    //跳转时间
    void turn_time(int);
};

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
    //单双
    bool alone = false;
    //锁,可见
    bool lock = false;

    //设置歌词样式
    void set_lrcStyle(QColor play,QColor next ,QFont font);
    //设置歌词
    void setLrc(QString now,QString down,lrc_line* one);

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

    //更新播放进度
    void upDate_palyValue(qint64 time);


private slots:
    void on_pushButton_lock_clicked();

    void on_pushButton_unlock_clicked();

    void on_pushButton_play_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_up_clicked();

    void on_pushButton_down_clicked();

    void on_pushButton_seit_clicked();

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
