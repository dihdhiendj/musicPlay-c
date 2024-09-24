#include "lrcedit.h"
#include "ui_lrcedit.h"

QString qint64_to_time(qint64 time)
{
    int ms = time%1000;
    time = (time-ms)/1000;
    int s = time%60;
    time = (time-s)/60;
    int m = time;
    QString M = m>=10?QString::number(m):QString::number(0)+QString::number(m);
    QString S = s>=10?QString::number(s):QString::number(0)+QString::number(s);
    QString MS;
    if(ms >=100)
    {
        MS = QString::number(ms);
    }
    else if(ms >=10)
    {
        MS = QString::number(0)+QString::number(ms);
    }
    else
    {
        MS = QString::number(0)+QString::number(0)+QString::number(ms);
    }
    QString string = "["+M+":"+S+"."+MS+"]";
    return string;
}

QString addTime(qint64 time,QString txt)
{
    return qint64_to_time(time) + txt;
}
QString deletaTime(QString txt)
{
    if(txt.contains("]"))
    {
        QStringList  strs = txt.split("]");
        QString newText = strs[1];

        for(int i=2;i<strs.size();i++)
        {
            newText = newText +"]"+strs[i];
        }
        return newText;
    }
    return txt;
}

lrcEdit::lrcEdit(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::lrcEdit)
{
    ui->setupUi(this);
}

lrcEdit::~lrcEdit()
{
    delete ui;
}

//读取lrc文件
void lrcEdit::read_lrc(QString url)
{
    this->url = url;
    QFile file(url);
    if(file.open(QIODevice::ReadOnly| QIODevice::Text))
    {
        QTextStream in(&file);
        ui->plainTextEdit_lrcs->setPlainText(in.readAll());
        file.close();
    }

    this->show();
}

void lrcEdit::on_pushButton_addTime_clicked()
{
    QString old = ui->plainTextEdit_lrcs->document()->findBlockByLineNumber(select_line).text();
    QString finish = addTime(runTime,old);
    replace_textBlock(select_line,finish);
}

void lrcEdit::on_pushButton_deleteTime_clicked()
{
    QString old = ui->plainTextEdit_lrcs->document()->findBlockByLineNumber(select_line).text();
    QString finish = deletaTime(old);
    replace_textBlock(select_line,finish);
}

void lrcEdit::on_pushButton_yes_clicked()
{
    QFile file(url);
    if(file.open(QIODevice::WriteOnly| QIODevice::Text))
    {
        QTextStream out(&file);
        out<<ui->plainTextEdit_lrcs->toPlainText();
        file.close();
    }
    this->hide();
}

void lrcEdit::on_pushButton_no_clicked()
{
    this->hide();
}

void lrcEdit::on_pushButton_down_clicked()
{
    on_pushButton_deleteTime_clicked();
    on_pushButton_addTime_clicked();
    if(select_line < ui->plainTextEdit_lrcs->blockCount())
    {
        select_line++;
        QTextCursor cursor = ui->plainTextEdit_lrcs->textCursor();
        cursor.movePosition(QTextCursor::Down);
        ui->plainTextEdit_lrcs->setTextCursor(cursor);
    }
    highlight_textBlock();
}

//光标变化
void lrcEdit::on_plainTextEdit_lrcs_cursorPositionChanged()
{
    select_line = ui->plainTextEdit_lrcs->textCursor().blockNumber();
    highlight_textBlock();
}

void lrcEdit::replace_textBlock(int lineNumber, const QString newContent)
{
    if (lineNumber < 0 || lineNumber >= ui->plainTextEdit_lrcs->blockCount())
        return; // 确保行号在有效范围内

    QTextCursor cursor(ui->plainTextEdit_lrcs->textCursor());
    cursor.beginEditBlock(); // 开始一个编辑块

    // 移动到指定行的开始
    QTextBlock block = ui->plainTextEdit_lrcs->document()->findBlockByNumber(lineNumber);
    if (block.isValid())
    {
        cursor.setPosition(block.position());

        // 删除当前行的内容（包括换行符）
        cursor.movePosition(QTextCursor::EndOfBlock, QTextCursor::KeepAnchor);
        cursor.deleteChar();

        // 插入新内容
        cursor.insertText(newContent);
    }

    cursor.endEditBlock(); // 结束编辑块
}

void lrcEdit::highlight_textBlock()
{
    //提供一种方式显示选择的文本
    QList<QTextEdit::ExtraSelection> extraSelections;

    QTextEdit::ExtraSelection selection;
    selection.format.setBackground(Qt::blue);
    selection.format.setProperty(QTextFormat::FullWidthSelection, true);
    selection.cursor = ui->plainTextEdit_lrcs->textCursor();
    extraSelections.append(selection);
    //设置高亮
    ui->plainTextEdit_lrcs->setExtraSelections(extraSelections);
}

