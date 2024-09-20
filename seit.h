#ifndef SEIT_H
#define SEIT_H

#include <hard.h>

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
    //ui字体类型
    QString font_type;

    //资源文件地址
    QStringList sourceList;

    //桌面歌词参数
    QString lrc_fontType = "华文仿宋";
    int lrc_fontSize = 0;
    QString lrc_upColor = "red",lrc_downColor = "blue";

    //保存数据
    void write_data();
    //读取数据
    void read_data();

    //设置背景
    void set_background_pic(QImage *img);

    //鼠标按下
    void mousePressEvent(QMouseEvent* event)override;
    //鼠标移动
    void mouseMoveEvent(QMouseEvent* event)override;

private slots:

    void on_pushButton_add_dir_clicked();

    //设置字体
    void set_font_type(QString f);

    void on_pushButton_nowLrc_clicked();

    void on_pushButton_downLrc_clicked();

    void on_pushButton_sizeDown_clicked();

    void on_pushButton_sizeUp_clicked();

    void on_pushButton_delete_dir_clicked();

    void on_fontComboBox_seit_currentTextChanged(const QString &arg1);

    void on_fontComboBox_lrc_currentTextChanged(const QString &arg1);

private:
    Ui::seit *ui;

    //执行数据
    void build_lrcStyle();

signals:
    //生成文件夹
    void build_dir(QString);
    //设置type
    void seit_type(QString);
    //发送lrc样式表
    void giveLrcStyle(QString,QString);
};

#endif // SEIT_H
