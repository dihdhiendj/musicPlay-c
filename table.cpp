#include "table.h"
#include "ui_table.h"

table::table(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::table)
{
    ui->setupUi(this);
    ui->widget_edit->hide();
}

table::~table()
{
    delete ui;
}

void table::add_music(music* music)
{
    ui->verticalLayout_music->insertWidget(0,music);
    music->number = musics.size();
    musics.append(music);

    connect(music,&music::playMusic,this,[this](int music){
        emit playMusic(number,music);
    });
}

void table::sort_music(QString key,QString forward)
{
    QList <musicCore*> sort;
    for(int i=0;i<musics.size();i++)
    {
        sort.append(musics[i]->core);
    }

    if(key == "标题")
    {
        std::sort(sort.begin(), sort.end(), [](musicCore* a, musicCore* b)
                  {return a->title < b->title;});
        for(int i=0;i<sort.size();i++)
        {
            sort[i]->showName = sort[i]->title + " : " + sort[i]->baseName;
        }
    }
    else if(key == "作者")
    {
        std::sort(sort.begin(), sort.end(), [](musicCore* a, musicCore* b)
                  { return a->artist < b->artist;});
        for(int i=0;i<sort.size();i++)
        {
            sort[i]->showName = sort[i]->artist + " : " + sort[i]->baseName;
        }
    }
    else if(key == "专辑")
    {
        std::sort(sort.begin(), sort.end(), [](musicCore* a, musicCore* b)
                  {return a->album < b->album;});
        for(int i=0;i<sort.size();i++)
        {
            sort[i]->showName = sort[i]->album + " : " + sort[i]->baseName;
        }
    }
    else if(key == "播放次数")
    {
        std::sort(sort.begin(), sort.end(), [](musicCore* a, musicCore* b)
                  {return a->play_number < b->play_number;});
        for(int i=0;i<sort.size();i++)
        {
            sort[i]->showName = QString::number(sort[i]->play_number) + " : " + sort[i]->baseName;
        }
    }
    else if(key == "喜爱程度")
    {
        std::sort(sort.begin(), sort.end(), [](musicCore* a, musicCore* b)
                  {return a->love_value < b->love_value;});
        for(int i=0;i<sort.size();i++)
        {
            sort[i]->showName = QString::number(sort[i]->love_value) + " : " + sort[i]->baseName;
        }
    }
    else if(key == "编辑日期")
    {
        std::sort(sort.begin(), sort.end(), [](musicCore* a, musicCore* b)
                  {return a->lastTime.toMSecsSinceEpoch() < b->lastTime.toMSecsSinceEpoch();});
        for(int i=0;i<sort.size();i++)
        {
            sort[i]->showName = sort[i]->lastTime.toString() + " : " + sort[i]->baseName;
        }
    }

    if(forward == "降序")
    {
        for(int i=0;i<musics.size();i++)
        {
            musics[i]->core = sort[i];
            musics[i]->setText(sort[i]->showName);
        }
    }
    else
    {
        for(int i=0;i<musics.size();i++)
        {
            musics[i]->core = sort[musics.size()-1-i];
            musics[i]->setText(sort[musics.size()-1-i]->showName);
        }
    }
    ui->scrollArea->verticalScrollBar()->setValue(0);
}

void table::on_pushButton_search_clicked()
{
    QString aim = ui->lineEdit->text();
    for(int i=0;i<musics.size();i++)
    {
        if(musics[i]->core->isContains(aim))
        {
            musics[i]->show();
        }
        else
        {
            musics[i]->hide();
        }
    }
}

void table::on_comboBox_key_currentTextChanged(const QString &arg1)
{
    sort_music(arg1,ui->comboBox_forward->currentText());
}

void table::on_comboBox_forward_currentTextChanged(const QString &arg1)
{
    sort_music(ui->comboBox_key->currentText(),arg1);
}

//生成保存数据
QJsonObject table::jsonObject()
{
    QJsonObject obj;
    obj.insert("name",name);
    obj.insert("order",ui->comboBox_forward->currentText());
    obj.insert("key",ui->comboBox_key->currentText());
    obj.insert("type",type);
    if(type == "user")
    {
        QJsonObject data;
        for(int i=0;i<musics.size();i++)
        {
            data.insert("music-" + QString::number(i),musics[i]->core->fileName);
        }
        obj.insert("data",data);
    }
    return obj;
}

//设置数据
void table::fromJsonObject(QJsonObject obj)
{
    name = obj.value("name").toString();
    ui->comboBox_key->setCurrentText(obj.value("key").toString());
    ui->comboBox_forward->setCurrentText(obj.value("order").toString());
}

void table::on_pushButton_yes_clicked()
{
    name = ui->lineEdit_name->text();
    editHide();
}

void table::editShow()
{
    ui->widget_edit->show();
}
void table::editHide()
{
    ui->widget_edit->hide();
}

void table::on_pushButton_no_clicked()
{
    ui->widget_edit->hide();
}

void table::on_lineEdit_returnPressed()
{
    on_pushButton_search_clicked();
}

