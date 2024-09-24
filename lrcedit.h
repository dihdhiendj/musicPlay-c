#ifndef LRCEDIT_H
#define LRCEDIT_H

#include <addlib.h>

namespace Ui {
class lrcEdit;
}

class lrcEdit : public QWidget
{
    Q_OBJECT

public:
    explicit lrcEdit(QWidget *parent = nullptr);
    ~lrcEdit();

    int select_line = 0;
    //当前时间
    qint64 runTime = 0;
    //歌词文件地址
    QString url;

    //读取lrc文件
    void read_lrc(QString url);
    //选中lrcline
    void select_lrc();



private slots:
    //替换块内容
    void replace_textBlock(int lineNumber, const QString newContent);
    void highlight_textBlock();

    void on_pushButton_addTime_clicked();

    void on_pushButton_deleteTime_clicked();

    void on_pushButton_yes_clicked();

    void on_pushButton_no_clicked();

    void on_pushButton_down_clicked();

    void on_plainTextEdit_lrcs_cursorPositionChanged();

private:
    Ui::lrcEdit *ui;
};

#endif // LRCEDIT_H
