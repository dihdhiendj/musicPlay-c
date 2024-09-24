#ifndef MUSIC_H
#define MUSIC_H

#include <addlib.h>

class music : public QLabel
{
    Q_OBJECT

public:
    music();

    musicCore* core = NULL;
    int number = 0;

    //重写事件过滤器
    bool eventFilter(QObject *target, QEvent *event) override;
    //右键菜单
    void contextMenuEvent(QContextMenuEvent* event) override;

    //编辑文件标签
    void editMetadata();

    //根据core设置属性
    void fromCore(musicCore* core);

    //删除当前gui
    void remove();

signals:
    void askPlay(int);
    //播放音乐
    void playMusic(int);
    //添加到列表
    void moveToTable(int);
    //编辑歌词
    void editLrc(QString);
};

class metadata : public QWidget
{
    Q_OBJECT

public:
    QWidget* tables = new QWidget;
    QPushButton* yes = new QPushButton("确认修改");
    //文件地址
    QString url;

    metadata();

    void fromMap(QMap<QString,QString> map);
    //确定修改
    void editFile();
};

#endif // MUSIC_H
