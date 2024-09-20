#ifndef ADDLIB_H
#define ADDLIB_H

#include <hard.h>

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
public:
    up()
    {
        QVBoxLayout* layout = new QVBoxLayout;
        layout->addWidget(label);
        layout->addWidget(know);
        this->setLayout(layout);

        label->setWordWrap(1);
        connect(know,&QPushButton::pressed,this,&up::close);
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

#endif // ADDLIB_H
