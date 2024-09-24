#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <addlib.h>
#include <seit.h>
#include <list.h>
#include <lrcshow.h>

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //重要控件
    //设置
    seit *my_seit = new seit;
    //列表
    list *my_list = new list;
    //桌面歌词
    LrcShow *my_lrc = new LrcShow;
    //后台小程序
    QSystemTrayIcon *trayIcon = new QSystemTrayIcon(this);
    QImage* cover = new QImage;
    double r = 0.5;

    //移动，拉伸
    QPoint my_pos;
    bool isMove = false;
    QString dic = "";

    //正在播放,加载歌曲
    bool isFrist = true;
    //聚焦歌词
    bool posIsLrc = false;
    //播放进度
    int nowPlayPace = 0;
    //歌词列表
    QList <lrc_line*>lrc;

    //para
    QColor play_color ,next_color;

    QFont lrc_font;
    int* font_size = &my_seit->mainLrc_font_size;

    //在线服务
    bool *isOnlineLrc = &my_seit->isOnlineLrc,*isOnlineCover = &my_seit->isOnlineCover;

    //托盘菜单
    Menu* trayIconMenu = new Menu;


    //重写事件过滤器
    bool eventFilter(QObject *target, QEvent *event) override;

    //鼠标按下
    void mousePressEvent(QMouseEvent* event)override;
    //鼠标移动
    void mouseMoveEvent(QMouseEvent* event)override;
    //鼠标释放
    void mouseReleaseEvent(QMouseEvent *event) override;
    void updateRegion(QMouseEvent *event);
    void resizeRegion(QMouseEvent *event);

    //重写关闭事件
    void closeEvent(QCloseEvent *event) override;
    //重写隐藏事件
    void hideEvent(QHideEvent *event) override;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //获取歌词
    void open_getPy(QString song,QString sing,QString baseName,QString aimDir);
    //获取封面
    void open_get_coverPy(QString song,QString sing,QString baseName,QString aimDir);

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
    //禁音
    void on_pushButton_value_clicked();

    void on_pushButton_max_clicked();
    void on_pushButton_min_clicked();

    void on_pushButton_mainShow_clicked();

private:
    //播放音乐
    void open_music(musicCore* parameter);

    //生成子文件夹
    void build_dir();

    //更新当前时间
    void insert_now_time(qint64 time);
    //更新结束时间
    void insert_end_time(qint64 time);
    //设置播放位置
    void seit_play_value(qint64 pos);

    //生成歌词
    void build_lyric_show(QString url);
    //选中歌词
    void select_lrc(qint64 time);
    //清空之前的歌词
    void clear_lyric_show();
    //设置歌词样式
    void set_lrcStyle(QColor play,QColor next ,QFont f);

    //写入播放数据
    void writer_data();
    //读取播放数据
    void read_data();

    //设置背景
    void set_bakcgroung_pic(QImage *img);

    //更新播放设备
    void updateAudioDevice();

    //置空播放
    void set_void_play();

    //处理托盘事件
    void do_systemTrayIcon_active(QSystemTrayIcon::ActivationReason reason);
    //预处理托盘菜单
    void buildTrayIconMenu();

    //旋转封面
    void transform_cover();

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
