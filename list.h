#ifndef LIST_H
#define LIST_H

#include <addlib.h>
#include <lrcedit.h>
#include <table.h>

namespace Ui {
class list;
}

//列表界面
class list : public QWidget
{
    Q_OBJECT

public:
    explicit list(QWidget *parent = nullptr);
    ~list();

    //播放歌曲，播放列表
    int playMusicNumber = 0, playTableNumber = 0;
    //展示列表
    int showTable = 0;
    //歌词编辑界面
    lrcEdit* my_lrcEdit = new lrcEdit;

    QPoint my_pos;

    //重写事件过滤器
    bool eventFilter(QObject *target, QEvent *event) override;

    //读取元数据得到标签
    void get_muisc_tables(int number);

    //列表指针
    QList <table*> tables;
    //歌曲核心
    QList <musicCore*> cores;
    QList <music*> musics;
    QStringList dirs;

    //重载数据
    void reLoad_musicCore();
    //加载音乐核心
    void load_musicCore(QString dir);

    //设置背景
    void set_background_pic(QImage *img);

    //鼠标按下
    void mousePressEvent(QMouseEvent* event)override;
    //鼠标移动
    void mouseMoveEvent(QMouseEvent* event)override;

    //写数据
    void writer_data();
    //读数据
    void read_data();

    //上一首，下一首
    void next_music(bool forward,QString type);

    //播放音乐
    void play_music(int tableNumber,int musicNumber);

    //将图片内嵌到文件中
    void jpg_insert_fiel();

    //设置文件名格式
    void set_music_style(int type);

    //自定义api
    void rename(QString oldName,QString newName);
    void remove(QString url);

    //将歌曲添加到列表
    void table_add_music(int tableNumber, int core);

    //建立歌曲gui
    music* buildMusic(int core);

    //新建列表
    void add_table();
    //删除播放列表
    void delete_table(int aim);
    //切换列表
    void turn_table(int aim);

    void edit_table();

    //所有歌曲
    void build_all();

private:
    Ui::list *ui;

private slots:

    void on_pushButton_high_clicked();

    void on_pushButton_tables_clicked();

signals:
    //播放音乐
    void playMusic(musicCore*);

    //请求置空播放器，释放资源
    void askFreeMusic();

};

#endif // LIST_H
