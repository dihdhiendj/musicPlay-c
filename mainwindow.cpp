#include "mainwindow.h"
#include "ui_mainwindow.h"

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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    build_dir();
    log::claer();

    //调整ui
    ui->setupUi(this);
    trayIcon->setToolTip("溪柄");
    trayIcon->setIcon(QIcon(":/exe.png"));
    this->setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明
    this->setWindowFlags(Qt::FramelessWindowHint);   //设置无边框窗口
    {
        ui->horizontalSlider_volume->setMaximum(100);

        my_seit->setMaximumHeight(this->height());
        my_list->setMaximumHeight(this->height());
    }

    buildTrayIconMenu();//预处理托盘菜单
    //关联
    {
        connect(my_seit,&seit::build_dir,my_list,[=](QString dir)
                {
                    my_list->dirs.append(dir);
                    my_list->load_musicCore(dir);
                });

        connect(my_list,&list::playMusic,this,&MainWindow::open_music);
        connect(my_list,&list::askFreeMusic,this,&MainWindow::set_void_play);

        connect(my_seit,&seit::giveLrcStyle,my_lrc,&LrcShow::set_lrcStyle);
        connect(my_seit,&seit::giveLrcStyle,this,&MainWindow::set_lrcStyle);

        connect(player,&QMediaPlayer::durationChanged,this,&MainWindow::insert_end_time);
        connect(player,&QMediaPlayer::positionChanged,this,&MainWindow::insert_now_time);
        connect(player,&QMediaPlayer::mediaStatusChanged,this,[=](QMediaPlayer::MediaStatus staus)
                {
                    if(staus == QMediaPlayer::EndOfMedia)
                    {
                        on_pushButton_down_clicked();
                    }
                });

        connect(my_lrc,&LrcShow::musicDown,this,&MainWindow::on_pushButton_down_clicked);
        connect(my_lrc,&LrcShow::musicStop,this,&MainWindow::on_pushButton_stop_clicked);
        connect(my_lrc,&LrcShow::musicUp,this,&MainWindow::on_pushButton_up_clicked);
        connect(my_lrc,&LrcShow::musicPlay,this,&MainWindow::on_pushButton_play_clicked);
        connect(my_lrc,&LrcShow::seitShow,this,&MainWindow::on_pushButton_seit_show_clicked);

        connect(this,&MainWindow::playNext,my_list,&list::next_music);

        connect(trayIcon,&QSystemTrayIcon::activated,this,&MainWindow::do_systemTrayIcon_active);
    }

    ui->scrollArea_lrc->installEventFilter(this);

    player->play();
    trayIcon->show();

    read_data();
}

MainWindow::~MainWindow()
{
    writer_data();

    delete ui;
}

//事件过滤器
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
    if (event->button() == Qt::LeftButton)
    {
        updateRegion(event);
        my_pos = event->pos();
        isMove = true;
        event->accept();
    }
    QWidget::mousePressEvent(event);
}
//鼠标移动
void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton && isMove)
    {
        resizeRegion(event);
        event->accept();
    }
    QWidget::mouseMoveEvent(event);
}
void MainWindow::updateRegion(QMouseEvent *event)
{
    QRect rect = this->rect();

    int marginTop =  event->pos().y() - rect.y();
    int marginBottom = rect.y() + height() - event->pos().y();
    int marginLeft = event->pos().x() - rect.x();
    int marginRight = rect.x() + width() - event->pos().x();

    if(marginRight < 10 && marginRight >0
        && marginBottom < 10 && marginBottom >0)
    {
        setCursor(Qt::SizeFDiagCursor);
        dic = "right:bottom";
    }
    else if(marginRight < 10 && marginRight >0
             && marginTop < 10 && marginTop >0)
    {
        setCursor(Qt::SizeBDiagCursor);
        dic = "right:top";
    }
    else if(marginLeft < 10 && marginLeft >0
             && marginBottom < 10 && marginBottom >0)
    {
        setCursor(Qt::SizeBDiagCursor);
        dic = "left:bottom";
    }
    else if(marginLeft < 10 && marginLeft >0
             && marginTop < 10 && marginTop >0)
    {
        setCursor(Qt::SizeFDiagCursor);
        dic = "left:top";
    }
    else if(marginRight < 10 && marginRight >0)
    {
        setCursor(Qt::SizeHorCursor);
        dic = "right";
    }
    else if(marginLeft < 10 && marginLeft >0)
    {
        setCursor(Qt::SizeHorCursor);
        dic = "left";
    }
    else if(marginBottom < 10 && marginBottom >0)
    {
        setCursor(Qt::SizeVerCursor);
        dic = "bottom";
    }
    else if(marginTop < 10 && marginTop >0)
    {
        setCursor(Qt::SizeVerCursor);
        dic = "top";
    }
    else
    {
        setCursor(Qt::OpenHandCursor);
        dic = "move";
    }
}
void MainWindow::resizeRegion(QMouseEvent *event)
{
    QPoint move_pos = event->pos() - my_pos;
    QRect rect = geometry();
    QStringList stringList ={"right:bottom","right:top","left:bottom","left:top"
                              ,"right","left","bottom","top","move"};

    switch (stringList.indexOf(dic))
    {
    case 0:
        my_pos = event->pos();
        rect.setBottomRight(rect.bottomRight() + move_pos);
        setGeometry(rect);
        break;
    case 1:
        my_pos.setX(event->pos().x());
        rect.setTopRight(rect.topRight() + move_pos);
        setGeometry(rect);
        break;
    case 2:
        my_pos.setY(event->pos().y());
        rect.setBottomLeft(rect.bottomLeft() + move_pos);
        setGeometry(rect);
        break;
    case 3:
        rect.setTopLeft(rect.topLeft() + move_pos);
        setGeometry(rect);
        break;
    case 4:
        my_pos.setX(event->pos().x());
        rect.setRight(rect.right() + move_pos.x());
        setGeometry(rect);
        break;
    case 5:
        rect.setLeft(rect.left() + move_pos.x());
        setGeometry(rect);
        break;
    case 6:
        my_pos.setY(event->pos().y());
        rect.setBottom(rect.bottom() + move_pos.y());
        setGeometry(rect);
        break;
    case 7:
        rect.setTop(rect.top() + move_pos.y());
        setGeometry(rect);
        break;
    case 8:
        move(QCursor::pos() - my_pos);
        //移动seit
        my_seit->resize(my_seit->width(),this->height());
        my_seit->move(this->x()-my_seit->width(),this->y());
        //移动list
        my_list->resize(my_list->width(),this->height());
        my_list->move(this->x()+this->width(),this->y());
        break;
    }
}
//鼠标释放
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        setCursor(Qt::ArrowCursor);

        isMove = false;
        event->accept();
    }
    QWidget::mousePressEvent(event);
}

//重写关闭事件
void MainWindow::closeEvent(QCloseEvent *event)
{
    my_list->close();
    my_lrc->close();
    my_seit->close();

    QWidget::closeEvent(event);
}

//重写隐藏事件
void MainWindow::hideEvent(QHideEvent *event)
{
    my_list->hide();
    my_seit->hide();

    QWidget::hideEvent(event);
}

//写入数据
void MainWindow::writer_data()
{
    my_seit->write_data();
    my_list->writer_data();
    my_lrc->writer_data();

    QSettings *ini = new QSettings(QDir::currentPath() + "/data/main.ini", QSettings::IniFormat);
    ini->clear();
    ini->beginGroup("main");

    ini->setValue("y",y());
    ini->setValue("x",x());
    ini->setValue("h",height());
    ini->setValue("w",width());

    ini->setValue("play",ui->horizontalSlider_play_value->value());
    ini->setValue("volume",ui->horizontalSlider_volume->value());

    ini->endGroup();
    ini->sync();
    delete ini;
}
//读取数据
void MainWindow::read_data()
{
    my_seit->read_data();
    my_list->read_data();
    my_lrc->read_data();

    QSettings *ini = new QSettings(QDir::currentPath() + "/data/main.ini", QSettings::IniFormat);
    ini->beginGroup("main");

    QRect show;
    show.setRect(ini->value("x").toInt(),ini->value("y").toInt()
                 ,ini->value("w").toInt(),ini->value("h").toInt());
    this->setGeometry(show);

    ui->horizontalSlider_play_value->setValue(ini->value("play").toInt());
    ui->horizontalSlider_volume->setValue(ini->value("volume").toInt());

    ini->endGroup();
    ini->sync();
    delete ini;
}

//得到歌词
void MainWindow::open_getPy(QString song,QString sing,QString baseName,QString aimDir)
{
    if(*isOnlineLrc)
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
}

//获取封面
void MainWindow::open_get_coverPy(QString song,QString sing,QString baseName,QString aimDir)
{
    if(*isOnlineCover)
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
}

//设置背景
void MainWindow::set_bakcgroung_pic(QImage *img)
{
    *cover = img->scaled(300,300,Qt::KeepAspectRatioByExpanding);
    ui->label_back->setPixmap(QPixmap::fromImage(*cover));

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

    //提前歌曲图片
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
            //使用QImage读取完整图片数据
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
        QString url;
        //下载封面
        if(!dir.exists(parameter->baseName + ".jpg"))
        {
            open_get_coverPy(parameter->title,parameter->artist,parameter->baseName,parameter->path);
        }
        if(dir.exists(parameter->baseName + ".jpg"))
        {
            url = parameter->path + "/" + parameter->baseName + ".jpg";
        }
        else
        {
            url = QDir::currentPath()+"/ui/dault.jpg";
        }
        QImageReader reader;
        reader.setFileName(url);
        QSize aim = reader.size();
        aim.scale(300,300,Qt::KeepAspectRatioByExpanding);
        reader.setScaledSize(aim);
        QImage use = reader.read();
        img = &use;
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
            line = in.readLine();//读取歌词
            //判断为有效行
            if(line.contains("]"))
            {
                lrc_line *Lrc = new lrc_line;
                lrc.append(Lrc);
                connect(Lrc,&lrc_line::turn_time,this,&MainWindow::seit_play_value);
                QString text = line.split("]")[1];
                QString date = line.split("[")[1].split("]")[0];

                if(line.contains(":") && line.contains("."))
                {
                    Lrc->start = (date.split(":")[0].toInt() * 60
                                  + date.split(":")[1].split(".")[0].toInt()) *1000
                                 + date.split(":")[1].split(".")[1].toInt();
                }
                Lrc->setText(text);
                ui->verticalLayout_lrc->addWidget(Lrc);
            }
        }
        while(!in.atEnd());
    }

    for(int i=1;i<lrc.size();i++)//设置持续时间
    {
        lrc[i-1]->last = lrc[i]->start - lrc[i-1]->start;
    }
    set_lrcStyle(play_color,next_color,lrc_font);

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
//设置歌词样式
void MainWindow::set_lrcStyle(QColor play,QColor next ,QFont f)
{
    play_color = play;
    next_color = next;
    f.setPointSize(*font_size);
    lrc_font = f;
    for(int i=0;i<lrc.size();i++)
    {
        lrc[i]->set_runStyle(play,next,f,Qt::white);
    }
}

//选中歌词
void MainWindow::select_lrc(qint64 time)
{
    transform_cover();
    //同步桌面歌词
    my_lrc->upDate_palyValue(time);
    //同步编辑器
    my_list->my_lrcEdit->runTime = time;

    int aim = 0;
    if(lrc.size() < 1)
    {
        return;
    }
    for(int i=0;i<lrc.size();i++)
    {
        if(lrc[i]->start <= time && (i+1 == lrc.size() || lrc[i+1]->start > time))
        {
            aim = i;
            lrc[i]->playing(time);
            lrc[i]->font.setPointSize(20);
        }
        else
        {
            lrc[i]->back();
            lrc[i]->font.setPointSize(18);
        }
    }

    if(aim + 1 >= lrc.size())
    {
        my_lrc->setLrc(lrc[aim]->text(),"##end##",lrc[aim]);
    }
    else
    {
        my_lrc->setLrc(lrc[aim]->text(),lrc[aim+1]->text(),lrc[aim]);
    }

    if(!posIsLrc)
    {
        ui->scrollArea_lrc->ensureWidgetVisible(lrc[lrc.size()-1],0,ui->scrollArea_lrc->height()/2);
        ui->scrollArea_lrc->ensureWidgetVisible(lrc[aim],0,ui->scrollArea_lrc->height()/2);
    }
}
//更新播放时间
void MainWindow::insert_now_time(qint64 time)
{
    //选中歌词
    select_lrc(time);

    updateAudioDevice();
    //断开槽
    ui->label_now->setText(addLib::int64_into_string(time));
    disconnect(ui->horizontalSlider_play_value,&QSlider::valueChanged,
               this,&MainWindow::seit_play_value);
    ui->horizontalSlider_play_value->setValue(time);
    if(isFrist)
    {
        isFrist = false;
        ui->horizontalSlider_play_value->setValue(nowPlayPace);
        ui->label_now->setText(addLib::int64_into_string(nowPlayPace));
        on_pushButton_stop_clicked();
    }
    //链接槽
    connect(ui->horizontalSlider_play_value,&QSlider::valueChanged,
            this,&MainWindow::seit_play_value);
}
//更新结束时间
void MainWindow::insert_end_time(qint64 time)
{
    ui->horizontalSlider_play_value->setMinimum(0);
    ui->horizontalSlider_play_value->setMaximum(time);
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

//设置播放位置
void MainWindow::seit_play_value(qint64 pos)
{
    player->setPosition(pos);
}

//置空播放
void MainWindow::set_void_play()
{
    player->setSource(QUrl());
}

//预处理托盘菜单
void MainWindow::buildTrayIconMenu()
{
    QPushButton* up = new QPushButton("上一首");
    trayIconMenu->addPushButton(up,":/left.png");
    connect(up,&QPushButton::clicked,this,&MainWindow::on_pushButton_up_clicked);

    QPushButton* play = new QPushButton("播放");
    trayIconMenu->addPushButton(play,":/play.png");
    connect(play,&QPushButton::clicked,this,&MainWindow::on_pushButton_play_clicked);

    QPushButton* stop = new QPushButton("暂停");
    trayIconMenu->addPushButton(stop,":/stop.png");
    connect(stop,&QPushButton::clicked,this,&MainWindow::on_pushButton_stop_clicked);

    QPushButton* down = new QPushButton("下一首");
    trayIconMenu->addPushButton(down,":/right.png");
    connect(down,&QPushButton::clicked,this,&MainWindow::on_pushButton_down_clicked);

    trayIconMenu->addSpacer();

    QPushButton* lrc = new QPushButton("显示桌面歌词");
    trayIconMenu->addPushButton(lrc,":/lrc.png");
    connect(lrc,&QPushButton::clicked,this,&MainWindow::on_pushButton_lrc_show_clicked);

    trayIconMenu->addSpacer();

    QPushButton* seit = new QPushButton("设置");
    trayIconMenu->addPushButton(seit,":/seit.png");
    connect(seit,&QPushButton::clicked,this,&MainWindow::on_pushButton_seit_show_clicked);

    trayIconMenu->addSpacer();

    QPushButton* show = new QPushButton("显示");
    trayIconMenu->addPushButton(show);
    connect(show,&QPushButton::clicked,this,&MainWindow::show);

    QPushButton* close = new QPushButton("退出");
    trayIconMenu->addPushButton(close,":/close.png");
    connect(close,&QPushButton::clicked,this,[=](){this->show();this->close();});
}
//处理托盘事件
void MainWindow::do_systemTrayIcon_active(QSystemTrayIcon::ActivationReason reason)
{
    if(reason == QSystemTrayIcon::Context)
    {
        QPoint now = QCursor::pos();
        trayIconMenu->show();
        trayIconMenu->move(QPoint(now.x(),now.y()-trayIconMenu->height()));
    }
    else if(reason == QSystemTrayIcon::Trigger)
    {
        this->show();
    }
}


void MainWindow::on_pushButton_min_clicked()
{
    my_list->hide();
    my_seit->hide();
    this->showMinimized();
}

void MainWindow::on_pushButton_max_clicked()
{
    my_list->hide();
    my_seit->hide();

    if(this->isFullScreen())
    {
        this->showNormal();
    }
    else
    {
        this->showMaximized();
    }
}

void MainWindow::on_pushButton_play_clicked()
{
    player->setPosition(ui->horizontalSlider_play_value->value());
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
        if(this->isFullScreen())
        {
            my_list->show();
        }
        else
        {
            my_list->resize(my_list->width(),this->height());
            my_list->move(this->x()+this->width(),this->y());
            my_list->show();
        }
    }
    else{
        my_list->hide();
    }
}

void MainWindow::on_pushButton_seit_show_clicked()
{
    if(my_seit->isHidden())
    {
        if(this->isFullScreen())
        {
            my_seit->show();
        }
        else
        {
            my_seit->resize(my_seit->width(),this->height());
            my_seit->move(this->x()-my_seit->width(),this->y());
            my_seit->show();
        }
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
    this->hide();
}

void MainWindow::on_pushButton_lrc_show_clicked()
{
    if(my_lrc->isHidden())
    {
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

QPixmap makeImageCircular(const QImage &image) {
    // 确保图像不为空
    if (image.isNull())
        return QPixmap();

    // 创建一个与原图大小相同的QPixmap
    QPixmap pixmap(image.size());
    pixmap.fill(Qt::transparent); // 填充为透明，以避免在圆形外显示背景色

    // 使用QPainter在QPixmap上绘制
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing); // 抗锯齿

    // 创建一个圆形的QPainterPath
    QRect rect(0, 0, image.width(), image.height());
    QPainterPath path;
    path.addEllipse(rect);

    // 设置裁剪路径
    painter.setClipPath(path);

    // 在裁剪区域内绘制图像
    painter.drawImage(rect, image);

    // 完成绘制
    painter.end();

    return pixmap;
}

//旋转封面
void MainWindow::transform_cover()
{
    QTransform rotateTransform;
    rotateTransform.translate(ui->label_back->width()/2,ui->label_back->height()/2);
    rotateTransform.rotate(r);
    r = r+0.5;
    if(r==360)
        r=0.5;

    QImage img = cover->transformed(rotateTransform);
    img = img.copy(QRect((img.width()-cover->width())/2,(img.height()-cover->height())/2
                         ,cover->width(),cover->height()));

    QPixmap pixmap = makeImageCircular(img);

    ui->label_back->setPixmap(pixmap);
}

void MainWindow::on_pushButton_mainShow_clicked()
{

}

