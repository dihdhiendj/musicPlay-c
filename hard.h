#ifndef HARD_H
#define HARD_H

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
#include <QAction>
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

#endif // HARD_H
