#ifndef TABLE_H
#define TABLE_H

#include <hard.h>
#include <music.h>

namespace Ui {
class table;
}

class table : public QWidget
{
    Q_OBJECT

public:
    explicit table(QWidget *parent = nullptr);
    ~table();

    //序号
    int number;
    //表名,类型
    QString name,type = "user";
    QList <music*> musics;

    void add_music(music* music);

    //生成保存数据
    QJsonObject jsonObject();
    //设置数据
    void fromJsonObject(QJsonObject obj);

    //设置名字
    void setName();

    void editShow();
    void editHide();

private:
    Ui::table *ui;
    int playNumber();

signals:
    //播放音乐
    void playMusic(int,int);

private slots:
    void sort_music(QString key,QString forward);
    void on_pushButton_search_clicked();
    void on_comboBox_key_currentTextChanged(const QString &arg1);
    void on_comboBox_forward_currentTextChanged(const QString &arg1);

    void on_pushButton_yes_clicked();
};

#endif // TABLE_H
