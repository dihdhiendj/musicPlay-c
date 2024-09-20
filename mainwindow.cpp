#include "mainwindow.h"
#include "ui_mainwindow.h"

lrc_line::lrc_line()
{
    this->setWordWrap(true);
    this->setAlignment(Qt::AlignCenter);
    this->installEventFilter(this);
    back();
}

// 高斯模糊函数
QImage applyGaussianBlur(const QImage &oldimage, int radius)
{
    QImage image(oldimage);
    if (image.isNull() || radius <= 0)
        return QImage();

    QImage resultImage = image;
    const int size = radius * 2 + 1;
    const int sigma = radius / 2;
    const double sigmaSq = sigma * sigma;
    QVector<double> kernel(size);

    // 构建高斯核
    double sum = 0.0;
    for (int i = -radius; i <= radius; ++i)
    {
        double value = exp(-(i * i) / (2 * sigmaSq)) / (sqrt(2 * M_PI) * sigma);
        kernel[i + radius] = value;
        sum += value;
    }

    // 归一化
    for (int i = 0; i < size; ++i)
    {
        kernel[i] /= sum;
    }

    // 水平方向模糊
    for (int y = 0; y < image.height(); ++y)
    {
        for (int x = 0; x < image.width(); ++x)
        {
            double red = 0, green = 0, blue = 0;
            for (int i = -radius; i <= radius; ++i)
            {
                if(x+i>0 && x+i<image.width())
                {
                    QRgb pixel = image.pixel(x + i, y);
                    red += qRed(pixel) * kernel[i + radius];
                    green += qGreen(pixel) * kernel[i + radius];
                    blue += qBlue(pixel) * kernel[i + radius];
                }
            }
            resultImage.setPixel(x, y, qRgb(red, green, blue));
        }
    }

    // 垂直方向模糊
    for (int x = 0; x < image.width(); ++x)
    {
        for (int y = 0; y < image.height(); ++y)
        {
            double red = 0, green = 0, blue = 0;
            for (int i = -radius; i <= radius; ++i)
            {
                if(y+i>0 && y+i<image.height())
                {
                    QRgb pixel = resultImage.pixel(x, y + i);
                    red += qRed(pixel) * kernel[i + radius];
                    green += qGreen(pixel) * kernel[i + radius];
                    blue += qBlue(pixel) * kernel[i + radius];
                }
            }
            image.setPixel(x, y, qRgb(red, green, blue));
        }
    }
    return image;
}

//重写事件过滤器
bool lrc_line::eventFilter(QObject *target, QEvent *event)
{
    if(target == this && event->type() == QEvent::Leave)
    {
        back();
        return true;
    }
    else if(target == this && event->type() == QEvent::Enter)
    {
        selecing();
        return true;
    }
    return QLabel::eventFilter(target,event);
}

//重写鼠标事件
void lrc_line::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit turn_time(time);
    }
}

//选中
void lrc_line::selecing()
{
    isIn = true;
    this->setStyleSheet("QLabel{font: 14pt \"仿宋\";color: rgb(0, 147, 221);min-height:50px;}");
}
//正在播放
void lrc_line::playing()
{
    this->setStyleSheet("QLabel{font: 14pt \"仿宋\";color: rgb(226, 0, 0);min-height:50px;}");
}
//恢复
void lrc_line::back()
{
    isIn = false;
    this->setStyleSheet("QLabel{font: 12pt \"仿宋\";min-height:50px;}");
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    build_dir();
    log::claer();

    //调整ui
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明
    this->setWindowFlags(Qt::FramelessWindowHint);   //设置无边框窗口
    {
        ui->pushButton_close->setIcon(QIcon(":/close.png"));
        ui->pushButton_seit_show->setIcon(QIcon(":/seit.png"));
        ui->pushButton_play->setIcon(QIcon(":/play.png"));
        ui->pushButton_table->setIcon(QIcon(":/list.png"));
        ui->pushButton_stop->setIcon(QIcon(":/stop.png"));
        ui->pushButton_value->setIcon(QIcon(":/value.png"));
        ui->pushButton_lrc_show->setIcon(QIcon(":/lrc.png"));

        my_lrc->setMaximumSize(this->width(),100);
        ui->horizontalSlider_volume->setMaximum(100);

        my_seit->setMaximumHeight(this->height());
        my_list->setMaximumHeight(this->height());
    }
    //关联
    {
        connect(my_seit,&seit::seit_type,my_list,&list::set_font_type);
        connect(my_seit,&seit::build_dir,my_list,&list::load_musicCore);

        connect(my_seit,&seit::seit_type,this,&MainWindow::set_font_type);

        connect(my_list,&list::playMusic,this,&MainWindow::open_music);
        connect(my_list,&list::askFreeMusic,this,&MainWindow::set_void_play);

        connect(my_seit,&seit::giveLrcStyle,my_lrc,&LrcShow::set_lrcStyle);

        connect(player,&QMediaPlayer::durationChanged,this,&MainWindow::insert_end_time);
        connect(player,&QMediaPlayer::positionChanged,this,&MainWindow::insert_now_time);

        connect(my_lrc,&LrcShow::musicDown,this,&MainWindow::on_pushButton_down_clicked);
        connect(my_lrc,&LrcShow::musicStop,this,&MainWindow::on_pushButton_stop_clicked);
        connect(my_lrc,&LrcShow::musicUp,this,&MainWindow::on_pushButton_up_clicked);
        connect(my_lrc,&LrcShow::musicPlay,this,&MainWindow::on_pushButton_play_clicked);
        connect(my_lrc,&LrcShow::seitShow,this,&MainWindow::on_pushButton_seit_show_clicked);

        connect(this,&MainWindow::playNext,my_list,&list::next_music);
    }

    ui->scrollArea_lrc->installEventFilter(this);

    player->play();

    my_seit->read_data();
    my_list->read_data();
    my_lrc->read_data();
    read_data();
}

MainWindow::~MainWindow()
{
    my_seit->write_data();
    my_list->writer_data();
    my_lrc->writer_data();
    writer_data();

    delete ui;
}

bool MainWindow::eventFilter(QObject *target, QEvent *event)
{
    if(target == ui->scrollArea_lrc && event->type() == QEvent::Enter)
    {
        posIsLrc = true;
        return true;
    }
    else if(target == ui->scrollArea_lrc && event->type() == QEvent::Leave)
    {
        posIsLrc = false;
        return true;
    }
    return false;
}

//鼠标按下
void MainWindow::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        my_pos = event->pos();
        event->accept();
    }
    QWidget::mousePressEvent(event);
}
//鼠标移动
void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        move(QCursor::pos() - my_pos);
        //移动seit
        my_seit->resize(my_seit->width(),this->height());
        my_seit->move(this->x()-my_seit->width(),this->y());
        //移动list
        my_list->resize(my_list->width(),this->height());
        my_list->move(this->x()+this->width(),this->y());
        event->accept();
    }
    QWidget::mouseMoveEvent(event);
}

//写入播放数据
void MainWindow::writer_data()
{
    QSettings *ini = new QSettings(QDir::currentPath() + "/data/main.ini", QSettings::IniFormat);
    ini->clear();
    ini->beginGroup("main");

    ini->setValue("play",ui->horizontalSlider_play_value->value());
    ini->setValue("volume",ui->horizontalSlider_volume->value());

    ini->endGroup();
    ini->sync();
    delete ini;
}

//读取播放数据
void MainWindow::read_data()
{
    QSettings *ini = new QSettings(QDir::currentPath() + "/data/main.ini", QSettings::IniFormat);
    ini->beginGroup("main");

    ui->horizontalSlider_play_value->setValue(ini->value("play").toInt());
    ui->horizontalSlider_volume->setValue(ini->value("volume").toInt());

    ini->endGroup();
    ini->sync();
    delete ini;
}

//得到歌词
void MainWindow::open_getPy(QString song,QString sing,QString baseName,QString aimDir)
{
    QProcess process;
    QStringList argv;
    argv.append(song);
    argv.append(sing);
    argv.append(baseName);
    argv.append(aimDir);
    process.start(QDir::currentPath() + "/get.exe",argv);
    process.waitForStarted();
    process.waitForFinished();
}

//获取封面
void MainWindow::open_get_coverPy(QString song,QString sing,QString baseName,QString aimDir)
{
    QProcess process;
    QStringList argv;
    argv.append(song);
    argv.append(sing);
    argv.append(baseName);
    argv.append(aimDir);
    process.start(QDir::currentPath() + "/get_cover.exe",argv);
    process.waitForStarted();
    process.waitForFinished();
}

//设置背景
void MainWindow::set_bakcgroung_pic(QImage *img)
{
    *img = img->scaled(300,300,Qt::KeepAspectRatioByExpanding);
    ui->label_back->setPixmap(QPixmap::fromImage(*img));

    *img = applyGaussianBlur(*img,10);

    QPixmap *pixmap = new QPixmap;
    pixmap->convertFromImage(*img);
    ui->pixmapshow->pixmap = pixmap;
    ui->pixmapshow->update();

    my_seit->set_background_pic(img);
    my_list->set_background_pic(img);
}

//播放音乐
void MainWindow::open_music(musicCore* parameter)
{
    QFile file(parameter->url);
    if(!file.exists())
    {
        addLib::setUp("WARNING, file is no found. url: " + parameter->url);
        return;
    }
    file.close();

    log::write("START, play music. url: " + parameter->url);
    ui->label_baseName->setText(parameter->baseName);
    ui->label_baseName->setWordWrap(1);

    //播放进度的信号提示
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile(parameter->url));
    //调整ui
    on_pushButton_play_clicked();

    //处理标签
    AVFormatContext *fmt_ctx = NULL;
    if (avformat_open_input(&fmt_ctx, parameter->url.toUtf8(), NULL, NULL)){
        char errbuf[1024];
        av_strerror(AVERROR_UNKNOWN, errbuf, sizeof(errbuf));
        log::write(parameter->url +"Failed to open input: "+errbuf);
        return;
    }
    QImage *img = NULL;
    for (unsigned int i = 0; i < fmt_ctx->nb_streams; i++){
        if (fmt_ctx->streams[i]->disposition & AV_DISPOSITION_ATTACHED_PIC) {
            AVPacket pkt = fmt_ctx->streams[i]->attached_pic;
            //使用QImage读取完整图片数据（注意，图片数据是为解析的文件数据，需要用QImage::fromdata来解析读取）
            img = new QImage;
            *img = QImage::fromData((uchar*)pkt.data, pkt.size);

            set_bakcgroung_pic(img);
            break;
        }
    }
    // 清理
    avformat_close_input(&fmt_ctx);

    QDir dir(parameter->path);
    log::write(parameter->url +" finish tables-building");

    if(img == NULL)
    {
        //下载封面
        if(!dir.exists(parameter->baseName + ".jpg"))
        {
            open_get_coverPy(parameter->title,parameter->artist,parameter->baseName,parameter->path);
        }
        img = new QImage(parameter->path + "/" + parameter->baseName + ".jpg");
        set_bakcgroung_pic(img);
    }
    //下载歌词
    if(!dir.exists(parameter->baseName + ".lrc"))
    {
        open_getPy(parameter->title,parameter->artist,parameter->baseName,parameter->path);
    }
    //生成歌词
    build_lyric_show(dir.path() + "/" + parameter->baseName + ".lrc");

    log::write("OK, play music. url: " + parameter->url);
}

//生成歌词
void MainWindow::build_lyric_show(QString url)
{
    //清空之前的歌词
    clear_lyric_show();

    log::write("START, insert music lrc lines. url: " +url);
    QFile lrc_F(url);
    if(lrc_F.open(QIODevice::ReadOnly| QIODevice::Text))
    {
        QTextStream in(&lrc_F);
        QString line;
        do{
            line = in.readLine();
            if(lrc_F.pos() != 0 && !line.isEmpty() && line.contains("]") && line.split("]")[1] != "")
            {
                lrc_line *Lrc = new lrc_line;
                lrc.append(Lrc);
                connect(Lrc,&lrc_line::turn_time,this,&MainWindow::seit_play_value);
                QString text = line.split("]")[1];
                QString date = line.split("[")[1].split("]")[0];
                Lrc->time = date.split(":")[0].toInt() * 60 + date.split(":")[1].split(".")[0].toInt();
                Lrc->setText(text);
                ui->verticalLayout_lrc->addWidget(Lrc);
            }
        }
        while(!line.isNull());
    }
    log::write("OK, insert music lrc lines. url: " +url);
}
//清空之前的歌词
void MainWindow::clear_lyric_show()
{
    for(int i=0;i<lrc.size();i++)
    {
        lrc[i]->setParent(NULL);
        delete lrc[i];
    }
    lrc = QList <lrc_line*>();

    ui->scrollArea_lrc->verticalScrollBar()->setMaximum(ui->scrollAreaWidgetContents_lrc->height());
}

//选中歌词
void MainWindow::select_lrc(int time)
{
    int aim = 0;
    if(lrc.size() < 1)
    {
        return;
    }
    for(int i=0;i<lrc.size();i++)
    {
        if(lrc[i]->time <= time && (i+1 == lrc.size() || lrc[i+1]->time > time))
        {
            aim = i;
            lrc[i]->playing();
        }
        else if(!lrc[i]->isIn)
        {
            lrc[i]->back();
        }
    }

    if(aim + 1 >= lrc.size())
    {
        my_lrc->setLrc(lrc[aim]->text(),"##end##");
    }
    else
    {
        my_lrc->setLrc(lrc[aim]->text(),lrc[aim+1]->text());
    }

    if(!posIsLrc && aim > 2)
    {
        ui->scrollArea_lrc->verticalScrollBar()->setValue(aim * 50 - 100);
    }
}
//更新播放时间
void MainWindow::insert_now_time(qint64 time)
{
    updateAudioDevice();
    int value = static_cast<qint64>(time/1000);
    if(value >= ui->horizontalSlider_play_value->maximum())
    {
        on_pushButton_down_clicked();
    }
    //断开槽
    ui->label_now->setText(addLib::int64_into_string(time));
    disconnect(ui->horizontalSlider_play_value,&QSlider::valueChanged,
               this,&MainWindow::seit_play_value);
    ui->horizontalSlider_play_value->setValue(value);
    if(isFrist)
    {
        isFrist = false;
        ui->horizontalSlider_play_value->setValue(nowPlayPace);
        ui->label_now->setText(addLib::int64_into_string(nowPlayPace * 1000));
        on_pushButton_stop_clicked();
    }
    //链接槽
    connect(ui->horizontalSlider_play_value,&QSlider::valueChanged,
            this,&MainWindow::seit_play_value);
    //选中歌词
    select_lrc(value);
}
//更新结束时间
void MainWindow::insert_end_time(qint64 time)
{
    int value = static_cast<qint64>(time/1000);
    ui->horizontalSlider_play_value->setMinimum(0);
    ui->horizontalSlider_play_value->setMaximum(value);
    ui->label_end->setText(addLib::int64_into_string(time));
}

//生成子文件夹
void MainWindow::build_dir()
{
    QDir *dir = new QDir(QDir::currentPath());
    if(!dir->exists("data"))
    {
        dir->mkdir("data");
    }
}

//设置播放位置
void MainWindow::seit_play_value(int pos)
{
    player->setPosition(pos * 1000);
}

void MainWindow::on_pushButton_play_clicked()
{
    player->setPosition(ui->horizontalSlider_play_value->value() * 1000);
    on_horizontalSlider_volume_valueChanged(ui->horizontalSlider_volume->value());
    player->play();

    ui->pushButton_play->hide();
    ui->pushButton_stop->show();

    my_lrc->play();
}

void MainWindow::on_pushButton_stop_clicked()
{
    player->pause();

    ui->pushButton_stop->hide();
    ui->pushButton_play->show();

    my_lrc->stop();
}

void MainWindow::on_pushButton_table_clicked()
{
    if(my_list->isHidden())
    {
        my_list->resize(my_list->width(),this->height());
        my_list->move(this->x()+this->width(),this->y());
        my_list->show();
    }
    else{
        my_list->hide();
    }
}

void MainWindow::on_pushButton_seit_show_clicked()
{
    if(my_seit->isHidden())
    {
        my_seit->resize(my_seit->width(),this->height());
        my_seit->move(this->x()-my_seit->width(),this->y());
        my_seit->show();
    }
    else {
        my_seit->hide();
    }
}

void MainWindow::on_horizontalSlider_volume_valueChanged(int value)
{
    float volume = static_cast<float>(value);
    volume = volume/100;
    audioOutput->setVolume(volume);
}

//下一首
void MainWindow::on_pushButton_down_clicked()
{
    emit playNext(0,ui->comboBox_loop->currentText());
}

//上一首
void MainWindow::on_pushButton_up_clicked()
{
    emit playNext(1,ui->comboBox_loop->currentText());
}

void MainWindow::on_pushButton_close_clicked()
{
    my_list->close();
    my_seit->close();
    my_lrc->close();
    this->close();
}

void MainWindow::on_pushButton_lrc_show_clicked()
{
    if(my_lrc->isHidden())
    {
        my_lrc->resize(this->width(),my_lrc->height());
        my_lrc->move(this->x(),this->y() + this->height() + 5);
        my_lrc->show();
        my_lrc->center = my_lrc->geometry().center();
    }
    else {
        my_lrc->hide();
    }
}

void MainWindow::on_pushButton_value_clicked()
{
    if(!ui->horizontalSlider_volume->value())
    {
        ui->horizontalSlider_volume->setValue(100);
    }
    else
    {
        ui->horizontalSlider_volume->setValue(0);
    }
}

//设置字体
void MainWindow::set_font_type(QString f)
{
    ui->widget_show->setStyleSheet(
        "*{font:12pt \""+f+"\";"
                               "border:0px;"
                               "min-height:30px;"
                               "color: rgb(255, 255, 255);"
                               "background-color: transparent;}"
                               "*:hover"
                               "{color: rgb(0, 170, 255);}"
                               "#widget_show{background-color: rgba(0,0,0,128);}");
}

void MainWindow::on_pushButton_min_clicked()
{
    my_list->hide();
    my_seit->hide();
    this->showMinimized();
}

//更新播放设备
void MainWindow::updateAudioDevice()
{
    QAudioOutput* newOut = new QAudioOutput;
    if(audioOutput->device().id() != newOut->device().id())
    {
        newOut->setVolume(audioOutput->volume());
        audioOutput = new QAudioOutput;
        audioOutput->setVolume(newOut->volume());

        log::write("播放器更新");
        player->setAudioOutput(audioOutput);
    }
}

//置空播放
void MainWindow::set_void_play()
{
    player->setSource(QUrl());
}

