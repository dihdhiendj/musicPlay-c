#include "lrcshow.h"
#include "ui_lrcshow.h"

lrc_line::lrc_line(QWidget *parent)
    :QLabel(parent)
{
    this->installEventFilter(this);
    this->setWordWrap(1);
    this->setObjectName("lrc");
    this->setAlignment(Qt::AlignCenter);
    this->setStyleSheet("*{min-height:50px;}");
    back();
}
//重写事件过滤器
bool lrc_line::eventFilter(QObject *target, QEvent *event)
{
    if(isUse)
    {
        if(target == this && event->type() == QEvent::Leave)
        {
            finish_color = Qt::white;
            font.setPointSize(font.pointSize()-2);
            return true;
        }
        else if(target == this && event->type() == QEvent::Enter)
        {
            finish_color = next_color;
            font.setPointSize(font.pointSize()+2);
            return true;
        }
    }
    return QLabel::eventFilter(target,event);
}

//重写鼠标事件
void lrc_line::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && isUse)
    {
        emit turn_time(start);
    }
    else
    {
        event->ignore();
    }
}

//重写绘图事件
void lrc_line::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);   //防锯齿

    QPainterPath path;
    painter.setFont(font);

    QFontMetrics fm(font);
    int textWidth = fm.horizontalAdvance(text());
    this->setMinimumWidth(textWidth);
    int textHeight = fm.height();
    this->setMinimumHeight(textHeight+10);

    //起始百分比
    float openWidth = (width()/2-textWidth/2)/float(width());
    //长度百分比
    float endWidth = (openWidth + textWidth)/float(width());

    path.addText(width()/2-textWidth/2 , height()/2+textHeight/2 , font , this->text());
    QLinearGradient linearGridient(0,height(),width(),height());
    if(isplay)
    {
        auto play = (stop - 0.0001)*endWidth + openWidth > 0
                        ?(stop - 0.0001)*endWidth + openWidth : 0;
        play = play < 1?play : 1;
        auto end = stop*endWidth + openWidth < 1
                       ?stop*endWidth + openWidth : 1;
        end = end > 0?end:0;

        linearGridient.setColorAt(play , play_color);
        linearGridient.setColorAt(end , next_color);
        painter.setBrush(linearGridient);
        painter.setBrush(linearGridient);
    }
    else
    {
        linearGridient.setColorAt(0,finish_color);;
        painter.setBrush(linearGridient);
    }
    painter.setPen(Qt::NoPen);
    painter.drawPath(path);
}

//复制播放数据
void lrc_line::copy(lrc_line* one)
{
    last = one->last;
    start = one->start;
}

//设置播放样式
void lrc_line::set_runStyle(QColor play,QColor next ,QFont f,QColor finish)
{
    play_color = play;
    next_color = next;
    font = f;
    finish_color = finish;
}
//正在播放
void lrc_line::playing(qint64 time)
{
    stop = (time-start)/last;
    isplay = true;
    update();
}
//恢复
void lrc_line::back()
{
    isplay = false;
    update();
}


LrcShow::LrcShow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LrcShow)
{
    ui->setupUi(this);
    this->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setAutoFillBackground(false);//设置自动填充
    setAttribute(Qt::WA_TranslucentBackground, true);//设置窗口背景透明
    repaint();

    //调整策略
    {
        ui->labelNow->isUse = false;
        ui->labelDown->isUse = false;
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
void LrcShow::set_lrcStyle(QColor play,QColor next ,QFont font)
{
    font.setBold(1);
    ui->labelDown->set_runStyle(play,next,font,next);
    ui->labelNow->set_runStyle(play,next,font,next);
}

void LrcShow::setLrc(QString now,QString down,lrc_line* one)
{
    ui->labelNow->copy(one);
    ui->labelNow->setText(now);
    ui->labelDown->setText(down);

    if(this->isVisible())
    {
        int max = ui->labelNow->minimumWidth()>ui->labelDown->minimumWidth()
                      ?ui->labelNow->minimumWidth():ui->labelDown->minimumWidth();
        this->setMaximumWidth(max+50);

        this->move(QPoint(center.x()-width()/2,center.y()-height()/2));
    }
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

void LrcShow::on_pushButton_alone_clicked()
{
    if(alone)
    {
        alone = false;
        ui->labelDown->hide();
    }
    else
    {
        alone = true;
        ui->labelDown->show();
    }
}

//更新播放进度
void LrcShow::upDate_palyValue(qint64 time)
{
    ui->labelNow->playing(time);
    ui->labelDown->back();
}

//写数据
void LrcShow::writer_data()
{
    QSettings *ini = new QSettings(QDir::currentPath() + "/data/lrc.ini", QSettings::IniFormat);
    ini->beginGroup("lrc");

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

