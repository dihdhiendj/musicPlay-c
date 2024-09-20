#include "list.h"
#include "ui_list.h"

#define FFmpegUrl QDir::currentPath() + "/ffmpeg.exe"

list::list(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::list)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明
    this->setWindowFlags(Qt::FramelessWindowHint);   //设置无边框窗口
    ui->pushButton_tables->installEventFilter(this);
}

list::~list()
{
    delete ui;
}

//重写事件过滤器
bool list::eventFilter(QObject *target, QEvent *event)
{
    if(target == ui->pushButton_tables && event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if (mouseEvent->button() == Qt::RightButton)
        {
            edit_table();
            return true;
        }
    }

    return QWidget::eventFilter(target,event);
}

//读取元数据得到标签
void list::get_muisc_tables(int number)
{
    AVFormatContext* pFormatCtx = nullptr;
    // 打开音频文件
    if (avformat_open_input(&pFormatCtx, cores[number]->url.toUtf8(), nullptr, nullptr) != 0) {
        log::write(cores[number]->url + " Cannot open input file");
        return;
    }

    // 查找流信息
    if (avformat_find_stream_info(pFormatCtx, nullptr) < 0) {
        log::write(cores[number]->url + " Cannot find stream information");
        avformat_close_input(&pFormatCtx);
        return;
    }

    // 遍历全局元数据
    AVDictionaryEntry* tag = nullptr;
    while ((tag = av_dict_get(pFormatCtx->metadata, "", tag, AV_DICT_IGNORE_SUFFIX)))
    {
        QString key = QString::fromUtf8(tag->key);
        QString value = QString::fromUtf8(tag->value);
        if(key.toLower() == "title")
        {
            cores[number]->title = value;
        }
        else if(key.toLower() == "artist")
        {
            cores[number]->artist = value;
        }
        else if(key.toLower() == "album")
        {
            cores[number]->album = value;
        }
    }

    // 关闭文件
    avformat_close_input(&pFormatCtx);
}

//设置背景
void list::set_background_pic(QImage *img)
{
    *img = img->scaled(ui->pixmapshow->size(),Qt::KeepAspectRatioByExpanding);
    QPixmap *pixmap = new QPixmap;
    pixmap->convertFromImage(*img);
    ui->pixmapshow->pixmap = pixmap;
    ui->pixmapshow->update();
}

//设置字体
void list::set_font_type(QString f)
{
    ui->widget_show->setStyleSheet(
        "*{font:12pt \""+f
        +"\";border:0px;color: rgb(255, 255, 255);background-color: transparent;}"
          "*:hover{color: rgb(0, 170, 255);}"
          "#widget_show{background-color: rgba(0,0,0,128);}"
          "QLabel{border-bottom:1px solid rgb(198, 198, 198);min-height:40px;}"
          "QLineEdit{border-bottom:1px solid rgb(198, 198, 198);min-height:40px;}"
          "QComboBox{min-height:40px;}"
          "QComboBox QAbstractItemView {background-color: rgb(0, 0, 0);}"
          "QMenu{background-color: rgba(0,0,0,128);}");
}

//写数据
void list::writer_data()
{
    QSettings *ini = new QSettings(QDir::currentPath() + "/data/list.ini", QSettings::IniFormat);
    ini->beginGroup("list");

    ini->setValue("playMusicNumber",playMusicNumber);
    ini->setValue("playTableNumber",playTableNumber);

    ini->endGroup();
    ini->sync();
    delete ini;

    //歌曲信息
    {
        QFile file(QDir::currentPath() + "/data/musics.json");
        if(file.open(QIODevice::WriteOnly |QIODevice::Text))
        {
            QJsonObject all;
            for(int i=0;i<cores.size();i++)
            {
                all.insert(cores[i]->baseName,cores[i]->buildJson());
            }
            QJsonDocument doc;
            doc.setObject(all);

            QTextStream out(&file);
            out << doc.toJson();
            file.close();
        }
    }

    //列表信息
    {
        QFile file(QDir::currentPath() + "/data/tables.json");
        if(file.open(QIODevice::WriteOnly |QIODevice::Text))
        {
            QJsonObject all;
            for(int i=0;i<tables.size();i++)
            {
                all.insert(tables[i]->name,tables[i]->jsonObject());
            }
            QJsonDocument doc;
            doc.setObject(all);

            QTextStream out(&file);
            out << doc.toJson();
            file.close();
        }
    }
}
//读数据
void list::read_data()
{
    //歌曲信息
    {
        QFile file(QDir::currentPath() + "/data/musics.json");
        if(file.open(QIODevice::ReadOnly |QIODevice::Text))
        {
            QTextStream in(&file);
            QJsonDocument doc = QJsonDocument::fromJson(in.readAll().toUtf8());

            QJsonObject all = doc.object();

            for(int i=0;i<cores.size();i++)
            {
                cores[i]->formJson(all.value(cores[i]->baseName).toObject());
            }
            file.close();
        }
    }

    //列表信息
    {
        QFile file(QDir::currentPath() + "/data/tables.json");
        if(file.open(QIODevice::ReadOnly |QIODevice::Text))
        {
            QTextStream in(&file);
            QJsonDocument doc = QJsonDocument::fromJson(in.readAll().toUtf8());

            QJsonObject all = doc.object();

            auto key = all.begin();
            while(key != all.end())
            {
                log::write(key.key());
                //本地文件夹读取附加参数
                for(int i=0;i<tables.size();i++)
                {
                    if(tables[i]->name == key.key())
                    {
                        tables[i]->fromJsonObject(key.value().toObject());
                        break;
                    }
                }

                //自建立列表读取参数
                if(key.value().toObject().value("type").toString() == "user")
                {
                    add_table();
                    tables[tables.size()-1]->fromJsonObject(key.value().toObject());
                    QJsonObject data = key.value().toObject().value("data").toObject();

                    auto gate = data.begin();
                    while(gate != data.end())
                    {
                        for(int i=0;i<cores.size();i++)
                        {
                            if(gate.value().toString() == cores[i]->fileName)
                            {
                                table_add_music(tables.size()-1,i);
                                break;
                            }
                        }
                        gate++;
                    }
                }
                key++;
            }
            file.close();
        }
    }

    //读取正在播放信息
    QSettings *ini = new QSettings(QDir::currentPath() + "/data/list.ini", QSettings::IniFormat);
    ini->beginGroup("list");

    playMusicNumber = ini->value("playMusicNumber").toInt();
    playTableNumber = ini->value("playTableNumber").toInt();
    play_music(playTableNumber,playMusicNumber);
    turn_table(playTableNumber);

    ini->endGroup();
    ini->sync();
    delete ini;
}

//鼠标按下
void list::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        my_pos = event->pos();
        event->accept();
    }
    QWidget::mousePressEvent(event);
}
//鼠标移动
void list::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        move(QCursor::pos() - my_pos);
        event->accept();
    }
    QWidget::mouseMoveEvent(event);
}

//加载音乐核心
void list::load_musicCore(QString dir)
{
    log::write("START, go through all the songs in the folder. dir: " + dir);
    QDir Dir(dir);
    if(!Dir.exists())
    {
        return;
    }
    Dir.setFilter(QDir::NoDotAndDotDot |QDir::Files);
    QFileInfoList list = Dir.entryInfoList();

    bool isBuild = true;
    for(int i=0;i<list.size();i++)
    {
        if(addLib::isMusic(list[i].suffix()))
        {
            if(isBuild)
            {
                add_table();
                tables[tables.size()-1]->name = Dir.dirName();
                tables[tables.size()-1]->type = "master";
                isBuild = false;
            }
            musicCore* core = new musicCore;
            core->fromFileInfo(list[i]);
            core->number = cores.size();
            cores.append(core);
            get_muisc_tables(cores.size()-1);

            //插入列表
            table_add_music(tables.size()-1,cores.size()-1);
        }
    }

    Dir.setFilter(QDir::Dirs |QDir::NoDotAndDotDot);
    list = Dir.entryInfoList();
    for(int i=0;i<list.size();i++)
    {
        load_musicCore(list[i].filePath());
    }

    log::write("OK, go through all the songs in the folder. dir: " + dir);
}

//新建播放列表
void list::add_table()
{
    table* one = new table();
    one->name = "表"+QString::number(tables.size());
    tables.append(one);
    one->number = tables.size()-1;
    ui->stackedWidget_tables->addWidget(one);

    connect(one,&table::playMusic,this,&list::play_music);
}

//上一首，下一首
void list::next_music(bool forward,QString type)
{
    int aim = playMusicNumber;
    if(type == "顺序循环")
    {
        if(forward)
        {
            aim = playMusicNumber+1;
        }
        else
        {
            aim = playMusicNumber-1;
        }
    }
    else if(type == "随机循环")
    {
        aim =  QRandomGenerator::global()->bounded(tables[playTableNumber]->musics.size()-1);
    }
    else if(type == "单曲循环")
    {
        aim =  playMusicNumber;
    }
    else if(type == "反序循环")
    {
        if(forward)
        {
            aim =  playMusicNumber-1;
        }
        else
        {
            aim =  playMusicNumber+1;
        }
    }

    if(aim >= tables[playTableNumber]->musics.size()-1)
    {
        aim = 0;
    }
    else if(aim < 0)
    {
        aim = tables[playTableNumber]->musics.size()-1-1;
    }
    play_music(playTableNumber,aim);
}

//播放音乐
void list::play_music(int tableNumber,int musicNumber)
{
    if(tables.size() > tableNumber && tables[tableNumber]->musics.size() > musicNumber)
    {
        playTableNumber = tableNumber;
        playMusicNumber = musicNumber;

        tables[tableNumber]->musics[musicNumber]->core->play_number++;

        emit playMusic(tables[tableNumber]->musics[musicNumber]->core);
    }
}

void list::on_pushButton_high_clicked()
{
    QMenu menu(this);

    QAction* insert = new QAction("把图片内嵌到文件当中");
    menu.addAction(insert);
    connect(insert,&QAction::triggered,this,&list::jpg_insert_fiel);

    QAction* style1 = new QAction("作者 - 标题");
    menu.addAction(style1);
    connect(style1,&QAction::triggered,this,[this]()
            {
                set_music_style(1);
            });

    QAction* style2 = new QAction("标题 - 作者");
    menu.addAction(style2);
    connect(style2,&QAction::triggered,this,[this]()
            {
                set_music_style(2);
            });

    menu.exec(QCursor::pos());
}

//将图片内嵌到文件中
void list::jpg_insert_fiel()
{
    log::write("START embedding image");
    emit askFreeMusic();

    for(int i=0;i<cores.size();i++)
    {
        if(QFile::exists(cores[i]->path + "/" + cores[i]->baseName + ".jpg"))
        {
            QFileInfo info(cores[i]->url);
            QString run = "";
            if(info.suffix() == "mp3")
            {
                run ="\""+ FFmpegUrl +"\""
                              " -i \"" + cores[i]->url +
                              "\" -i \"" +  cores[i]->path + "/" + cores[i]->baseName + ".jpg\"" +
                              " -map 0:a -map 1:v -map_metadata 0 -id3v2_version 3 -c:a copy -c:v copy "
                              +"\""+cores[i]->path + "/new.mp3\"";;
            }
            else if(info.suffix() == "flac")
            {
                run ="\""+ FFmpegUrl +"\""
                              " -i \"" + cores[i]->url +
                              "\" -i \"" +  cores[i]->path + "/" + cores[i]->baseName + ".jpg\"" +
                              " -map 0:a -map 1:v -c:v copy -disposition:v attached_pic -codec:a copy "
                              +"\""+cores[i]->path + "/new.flac\"";;
            }
            else
            {
                continue;
            }

            log::write(run);
            log::write("START, embedding image. url: " + cores[i]->url);

            QProcess process;
            process.startCommand(run);
            process.waitForStarted();
            process.waitForFinished();

            remove(cores[i]->path + "/" + cores[i]->baseName + ".jpg");
            remove(cores[i]->url);

            rename(cores[i]->path +"/new."+info.suffix(),cores[i]->url);

            log::write("OK, embedding image. url: " + cores[i]->url);
        }

    }

    //申请弹窗
    addLib::setUp("OK, All song images have been successfully embedded.");

    //继续播放
    play_music(playTableNumber,playMusicNumber);
}

//设置文件名格式
void list::set_music_style(int type)
{
    //预处理
    log::write("START, unify file name formats :" + QString::number(type));
    emit askFreeMusic();

    for(int i=0;i<cores.size();i++)
    {
        log::write("START, unify file name formats. url: " + cores[i]->url);
        QString aim;
        switch (type) {
        case 1:
            aim = cores[i]->artist +" - "+ cores[i]->title;
            break;
        case 2:
            aim = cores[i]->title +" - "+ cores[i]->artist;
            break;
        default:
            break;
        }
        aim = addLib::normalizationFileName(aim);

        if(cores[i]->baseName != aim)
        {
            cores[i]->baseName = aim;
            QFileInfo info(cores[i]->url);
            cores[i]->fileName = aim +"."+ info.suffix();
            //重命名本体
            rename(cores[i]->url,
                   cores[i]->path +"/"+ aim +"."+ info.suffix());
            //重命名歌词
            rename(cores[i]->path +"/"+ info.baseName() +".lrc",
                   cores[i]->path +"/"+ aim +".lrc");
            //重命名封面
            rename(cores[i]->path +"/"+ info.baseName() +".jpg",
                   cores[i]->path +"/"+ aim +".jpg");
        }
        log::write("OK, unify file name formats. url: " + cores[i]->url);
    }


    //申请弹窗
    addLib::setUp("OK, All song file names have been set.");
    //继续播放
    play_music(playTableNumber,playMusicNumber);
}

//自定义api
void list::rename(QString oldName,QString newName)
{
    QFile file(oldName);
    if(file.exists())
    {
        if(!file.rename(newName))
        {
            log::write("ERROR, rename :" + file.errorString());
            log::write(oldName);
            log::write(newName);
        }
    }
    else
    {
        log::write("ERROR, exists :" + file.errorString());
        log::write(oldName);
        log::write(newName);
    }
    file.close();
}
void list::remove(QString url)
{
    QFile file(url);
    if(file.exists())
    {
        if(!file.remove())
        {
            log::write("ERROR, remove :" + file.errorString());
            log::write(url);
        }
    }
    else
    {
        log::write("ERROR, exists :" + file.errorString());
        log::write(url);
    }
    file.close();
}

//将歌曲添加到列表
void list::table_add_music(int tableNumber, int core)
{
    tables[tableNumber]->add_music(buildMusic(core));
}

//建立歌曲gui
music* list::buildMusic(int core)
{
    music* one = new music;
    one->fromCore(cores[core]);
    musics.append(one);

    connect(one,&music::moveToTable,this,[=](int musicNumber)
            {
                QMenu menu(this);

                for(int i=0;i<tables.size();i++)
                {
                    QAction* act = new QAction(tables[i]->name);
                    menu.addAction(act);
                    connect(act,&QAction::triggered,this,[=]()
                            {
                                if(tables[i]->type == "user")
                                {table_add_music(i,musicNumber);}
                            });
                }
                menu.exec(QCursor::pos());
            });

    return one;
}

void list::on_pushButton_tables_clicked()
{
    QMenu menu(this);
    for(int i=0;i<tables.size();i++)
    {
        QAction* table = new QAction(tables[i]->name);
        menu.addAction(table);
        connect(table,&QAction::triggered,this,[=](){turn_table(i);});
    }
    menu.exec(QCursor::pos());
}

//切换列表
void list::turn_table(int aim)
{
    ui->pushButton_tables->setText(tables[aim]->name);
    ui->stackedWidget_tables->setCurrentIndex(aim);
    showTable = aim;
}

void list::edit_table()
{
    QMenu* menu = new QMenu(this);

    QAction* act = new QAction("编辑");
    menu->addAction(act);
    connect(act,&QAction::triggered,this,[=]()
            {
                ui->pushButton_tables->setText(tables[showTable]->name);
                tables[showTable]->editShow();
            });

    QAction* add = new QAction("新建列表");
    menu->addAction(add);
    connect(add,&QAction::triggered,this,&list::add_table);

    menu->exec(QCursor::pos());
}
