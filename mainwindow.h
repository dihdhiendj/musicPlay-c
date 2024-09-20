#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <hard.h>
#include <seit.h>
#include <list.h>
#include <lrcshow.h>

QT_BEGIN_NAMESPACE

//歌词行
class lrc_line : public QLabel
{
    Q_OBJECT

public:
    lrc_line();
    bool isIn = false;
    //时间
    int time;
    //重写鼠标事件
    void mousePressEvent(QMouseEvent *event) override;
    //重写事件过滤器
    bool eventFilter(QObject *target, QEvent *event) override;

    //选中
    void selecing();
    //正在播放
    void playing();
    //恢复
    void back();

signals:
    //跳转时间
    void turn_time(int);
};

namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QPoint my_pos;

    //正在播放
    bool isFrist = true;
    //是否在歌词里
    bool posIsLrc = false;
    //播放进度
    int nowPlayPace = 0;
    //歌词
    QList <lrc_line*>lrc;

    //重写事件过滤器
    bool eventFilter(QObject *target, QEvent *event) override;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //获取歌词
    void open_getPy(QString song,QString sing,QString baseName,QString aimDir);
    //获取封面
    void open_get_coverPy(QString song,QString sing,QString baseName,QString aimDir);

    //设置
    seit *my_seit = new seit;
    //列表
    list *my_list = new list;
    //桌面歌词
    LrcShow *my_lrc = new LrcShow;

private slots:
    //暂停、继续
    void on_pushButton_stop_clicked();
    //设置
    void on_pushButton_seit_show_clicked();
    //下一首
    void on_pushButton_down_clicked();
    //上一首
    void on_pushButton_up_clicked();
    //列表显示
    void on_pushButton_table_clicked();
    void on_pushButton_close_clicked();
    void on_pushButton_lrc_show_clicked();
    void on_pushButton_play_clicked();
    //音量改变
    void on_horizontalSlider_volume_valueChanged(int value);

    //播放音乐
    void open_music(musicCore* parameter);

    //生成子文件夹
    void build_dir();

    //更新当前时间
    void insert_now_time(qint64 time);
    //更新结束时间
    void insert_end_time(qint64 time);
    //设置播放位置
    void seit_play_value(int pos);

    //生成歌词
    void build_lyric_show(QString url);
    //选中歌词
    void select_lrc(int time);
    //清空之前的歌词
    void clear_lyric_show();

    //写入播放数据
    void writer_data();
    //读取播放数据
    void read_data();

    //鼠标按下
    void mousePressEvent(QMouseEvent* event)override;
    //鼠标移动
    void mouseMoveEvent(QMouseEvent* event)override;

    //设置背景
    void set_bakcgroung_pic(QImage *img);

    void on_pushButton_value_clicked();

    //设置字体
    void set_font_type(QString f);

    void on_pushButton_min_clicked();

    //更新播放设备
    void updateAudioDevice();

    //置空播放
    void set_void_play();

private:
    Ui::MainWindow *ui;

    QMediaPlayer *player = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;

    //背景图片
    QPixmap back_pic;

signals:
    //下一首，上一首
    void playNext(bool forward,QString type);
};

#endif // MAINWINDOW_H
