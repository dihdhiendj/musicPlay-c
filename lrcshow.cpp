#include "lrcshow.h"
#include "ui_lrcshow.h"

LrcShow::LrcShow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LrcShow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setAutoFillBackground(false);//设置自动填充
    setAttribute(Qt::WA_TranslucentBackground, true);//设置窗口背景透明
    repaint();

    {
        ui->pushButton_stop->setIcon(QIcon(":/stop.png"));
        ui->pushButton_unlock->setIcon(QIcon(":/lock.png"));
        ui->pushButton_up->setIcon(QIcon(":/left.png"));
        ui->pushButton_down->setIcon(QIcon(":/right.png"));
        ui->pushButton_play->setIcon(QIcon(":/play.png"));
        ui->pushButton_lock->setIcon(QIcon(":/lock.png"));
        ui->pushButton_seit->setIcon(QIcon(":/seit.png"));
        ui->pushButton_alone->setIcon(QIcon(":/alone.png"));
        ui->pushButton_dic->setIcon(QIcon(":/dic.png"));
        ui->pushButton_hide->setIcon(QIcon(":/close.png"));

        ui->pushButton_stop->setText("");
        ui->pushButton_unlock->setText("");
        ui->pushButton_up->setText("");
        ui->pushButton_down->setText("");
        ui->pushButton_play->setText("");
        ui->pushButton_lock->setText("");
        ui->pushButton_seit->setText("");
        ui->pushButton_alone->setText("");
        ui->pushButton_dic->setText("");
        ui->pushButton_hide->setText("");
    }

    this->installEventFilter(this);
    ui->widget_tool->hide();
    ui->pushButton_unlock->hide();
}

LrcShow::~LrcShow()
{
    delete ui;
}

//重写事件过滤器
bool LrcShow::eventFilter(QObject *target, QEvent *event)
{
    if(target == this && event->type() == QEvent::Enter)
    {
        setAttribute(Qt::WA_NoSystemBackground, false);
        setAttribute(Qt::WA_TranslucentBackground, false);//设置窗口背景透明
        repaint();

        ui->widget_tool->show();
        return true;
    }
    else if(target == this && event->type() == QEvent::Leave)
    {
        setAutoFillBackground(false);
        setAttribute(Qt::WA_TranslucentBackground, true);//设置窗口背景透明
        repaint();

        ui->widget_tool->hide();
        return true;
    }
    return QWidget::eventFilter(target,event);
}

//设置歌词样式
void LrcShow::set_lrcStyle(QString now,QString down)
{
    ui->labelNow->setStyleSheet(now);
    ui->labelDown->setStyleSheet(down);
    ui->labelNow_2->setStyleSheet(now);
    ui->labelDown_2->setStyleSheet(down);
}
void LrcShow::setLrc(QString now,QString down)
{
    ui->labelNow->setText(now);
    ui->labelDown->setText(down);
    ui->labelNow_2->setText(now.replace("","\n"));
    ui->labelDown_2->setText(down.replace("","\n"));

    QPoint aim(center.x()-width()/2,center.y()-height()/2);
    move(aim);
}

//鼠标按下
void LrcShow::mousePressEvent(QMouseEvent* event)
{
    if (!lock && event->button() == Qt::LeftButton) {
        my_pos = event->pos();
        event->accept();
    }
    QWidget::mousePressEvent(event);
}
//鼠标移动
void LrcShow::mouseMoveEvent(QMouseEvent* event)
{
    if (!lock && event->buttons() & Qt::LeftButton)
    {
        move(QCursor::pos() - my_pos);
        event->accept();

        center = this->geometry().center();
    }

    QWidget::mouseMoveEvent(event);
}

void LrcShow::on_pushButton_lock_clicked()
{
    lock = true;
    ui->widget_lock->hide();
    ui->pushButton_unlock->show();
}

void LrcShow::on_pushButton_unlock_clicked()
{
    lock = false;
    ui->widget_lock->show();
    ui->pushButton_unlock->hide();
}

void LrcShow::play()
{
    ui->pushButton_play->hide();
    ui->pushButton_stop->show();
}
void LrcShow::stop()
{
    ui->pushButton_play->show();
    ui->pushButton_stop->hide();
}

void LrcShow::on_pushButton_play_clicked()
{
    emit musicPlay();
    play();
}

void LrcShow::on_pushButton_stop_clicked()
{
    emit musicStop();
    stop();
}

void LrcShow::on_pushButton_up_clicked()
{
    emit musicUp();
}

void LrcShow::on_pushButton_down_clicked()
{
    emit musicDown();
}

void LrcShow::on_pushButton_seit_clicked()
{
    emit seitShow();
}

void LrcShow::on_pushButton_dic_clicked()
{
    if(dic)
    {
        dic = false;
        ui->widget_level->hide();
        ui->widget_erect->show();
    }
    else
    {
        dic = true;
        ui->widget_level->show();
        ui->widget_erect->hide();
    }
}

void LrcShow::on_pushButton_alone_clicked()
{
    if(alone)
    {
        alone = false;
        ui->labelDown->hide();
        ui->labelDown_2->hide();
    }
    else
    {
        alone = true;
        ui->labelDown->show();
        ui->labelDown_2->show();
    }
}

//写数据
void LrcShow::writer_data()
{
    QSettings *ini = new QSettings(QDir::currentPath() + "/data/lrc.ini", QSettings::IniFormat);
    ini->beginGroup("lrc");

    ini->setValue("dic",dic);
    ini->setValue("alone",alone);
    ini->setValue("lock",lock);

    ini->endGroup();
    ini->sync();
    delete ini;
}
//读数据
void LrcShow::read_data()
{
    QSettings *ini = new QSettings(QDir::currentPath() + "/data/lrc.ini", QSettings::IniFormat);
    ini->beginGroup("lrc");

    dic = ini->value("dic").toBool();
    on_pushButton_dic_clicked();
    on_pushButton_dic_clicked();

    alone = ini->value("alone").toBool();
    on_pushButton_alone_clicked();
    on_pushButton_alone_clicked();

    lock = ini->value("lock").toBool();
    if(lock)
    {on_pushButton_lock_clicked();}
    else
    {on_pushButton_unlock_clicked();}

    ini->endGroup();
    ini->sync();
    delete ini;
}

void LrcShow::on_pushButton_hide_clicked()
{
    this->hide();
}

