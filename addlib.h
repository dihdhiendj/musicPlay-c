#ifndef ADDLIB_H
#define ADDLIB_H

#include <QColor>
#include <QColorDialog>
#include <QString>
#include <QMainWindow>
#include <QProcess>
#include <QDir>
#include <QFile>
#include <QThread>
#include <QWidget>
#include <QFileDialog>
#include <QLineEdit>
#include <QAudioOutput>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QSettings>
#include <QMouseEvent>
#include <QPainter>
#include <QMenu>
#include <QEvent>
#include <QCursor>
#include <QScrollArea>
#include <QScrollBar>
#include <QPushButton>
#include <QComboBox>
#include <QPainter>
#include <QWidget>
#include <QPalette>
#include <QRandomGenerator>
#include <QGraphicsBlurEffect>
#include <QCoreApplication>
#include <QSystemSemaphore>
#include <QAudioDevice>
#include <qpixmapshow.h>
#include <QMap>
#include <QSystemTrayIcon>
#include <QLine>
#include <QImageReader>
#include <QPainterPath>
#include <QTextCursor>
#include <QTextBlock>
#include <QTextDocument>

#include <QJsonDocument>
#include <QJsonObject>

#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QVariant>

extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
#include "libavdevice/avdevice.h"
#include "libavfilter/avfilter.h"
#include "libavutil/avutil.h"
}

struct musicCore
{
    //文件父目录，文件地址，文件名，文件全名，展示名字
    QString path = "",url = "",baseName = "",fileName = "",showName = "";
    //歌曲标题，歌曲专辑，歌曲作者
    QString title = "",album = "",artist = "";
    QDateTime lastTime;
    //播放次数，喜爱程度
    int play_number = 0,love_value = 0;
    //总序号
    int number = 0;

    void fromFileInfo(QFileInfo info)
    {
        path = info.path();
        url = info.filePath();
        baseName = info.fileName().split("." + info.suffix())[0];
        fileName = info.fileName();
        lastTime = info.lastModified();
    }

    void formJson(QJsonObject obj)
    {
        play_number = obj.value("play_number").toInt();
        love_value = obj.value("love_value").toInt();
    }
    QJsonObject buildJson()
    {
        QJsonObject obj;
        obj.insert("play_number",play_number);
        obj.insert("love_value",love_value);
        return obj;
    }

    bool isContains(QString aim)
    {
        return title.contains(aim) ||artist.contains(aim) ||album.contains(aim) ||baseName.contains(aim);
    }
};

class addLib
{
public:
    //判断为音乐文件
    static bool isMusic(QString suffix);

    //标准化url
    static QString standardization(QString url);

    //毫秒到时间
    static QString int64_into_string(qint64 time);

    //设置弹窗
    static void setUp(QString txt);

    //标准文件名字
    static QString normalizationFileName(QString name);

};

//日志
class log :public QObject
{
    Q_OBJECT

public:
    //清空日志
    static void claer();

    //写入日志
    static void write(QString txt);
};

//弹窗
class up :public QWidget
{
     Q_OBJECT

public:
    up()
    {
        QVBoxLayout* layout = new QVBoxLayout;
        layout->addWidget(label);
        layout->addWidget(know);
        this->setLayout(layout);

        label->setWordWrap(1);
        connect(know,&QPushButton::clicked,this,&up::close);
        this->setStyleSheet("*{font: 100 12pt \"华文仿宋\";min-height:30px;border:0px;color: rgb(255, 255, 255);background-color: rgb(0, 0, 0);}"
                            "*:hover{color:blue;}");
    }

    //ui
    QLabel* label = new QLabel;
    QPushButton* know = new QPushButton("我已知晓");

    void setText(QString txt)
    {
        label->setText(txt);
    }
};

class Menu :public QMenu
{
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    QGridLayout* layout = new QGridLayout;

    int buttons = 0;
    //插入按键
    void addPushButton(QPushButton* button,QString icon = NULL);

    //插入分割线
    void addSpacer();
};

#endif // ADDLIB_H
