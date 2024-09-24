#ifndef SEIT_H
#define SEIT_H

#include <addlib.h>

namespace Ui {
class seit;
}

class seit : public QWidget
{
    Q_OBJECT

public:
    explicit seit(QWidget *parent = nullptr);
    ~seit();

    bool noFirst = false;
    QPoint my_pos;

    //资源文件地址
    QStringList sourceList;

    //桌面歌词参数
    QFont lrc_font;
    int mainLrc_font_size = 18;
    //播放颜色，接下来颜色
    QColor playLrc_color = Qt::red, nextLrc_color = Qt::blue;
    //在线服务
    bool isOnlineLrc = true,isOnlineCover = true;

    //保存数据
    void write_data();
    //读取数据
    void read_data();

    //设置背景
    void set_background_pic(QImage *img);

    //设置lrcShow font
    void next_Font_size(int isAdd);

    //鼠标按下
    void mousePressEvent(QMouseEvent* event)override;
    //鼠标移动
    void mouseMoveEvent(QMouseEvent* event)override;

private slots:

    void on_pushButton_add_dir_clicked();

    void on_pushButton_nowLrc_clicked();

    void on_pushButton_downLrc_clicked();

    void on_pushButton_sizeDown_clicked();

    void on_pushButton_sizeUp_clicked();

    void on_pushButton_delete_dir_clicked();

    void on_fontComboBox_lrc_currentFontChanged(const QFont &f);

    void on_pushButton_lrc_sizeAdd_clicked();

    void on_pushButton_lrc_sizeDecrease_clicked();

    void on_checkBox_downLrc_stateChanged(int arg1);

    void on_checkBox_downCover_stateChanged(int arg1);

private:
    Ui::seit *ui;

    //执行数据
    void build_lrcStyle();

signals:
    //生成文件夹
    void build_dir(QString);
    //发送lrc样式表
    void giveLrcStyle(QColor,QColor,QFont);
};

#endif // SEIT_H
