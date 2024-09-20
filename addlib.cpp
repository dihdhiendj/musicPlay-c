#include "addlib.h"

//判断为音乐文件
bool addLib::isMusic(QString suffix)
{
    QStringList table = {"mp3","flac"};
    for(int i=0;i<table.size();i++)
    {
        if(suffix == table[i])
        {
            return true;
        }
    }
    return false;
}

//标准化url
QString addLib::standardization(QString url)
{
    if(url.size()>3 && url[0] == '"')
    {
        for(int i=0;i<url.size()-2;i++)
        {
            url[i] = url[i+1];
        }
        url.remove(url.size()-2,2);
    }

    for(int i=0;i<url.size();i++)
    {
        if(url[0] == '\\')
        {
            url[0] = '/';
        }
    }
    return url;
}

//毫秒到时间
QString addLib::int64_into_string(qint64 time)
{
    QString string = QString::number(time/(1000*60)) + ":" + QString::number(time/1000%60);
    return string;
}

void addLib::setUp(QString txt)
{
    up* show = new up;
    show->setText(txt);
    show->show();

    log::write(txt);
}

//标准文件名字
QString addLib::normalizationFileName(QString name)
{
    name.replace("/",",");
    name.replace("<","(");
    name.replace(">",")");
    name.replace("\\",",");
    name.replace("*","");
    name.replace("|","");
    name.replace("\"","");
    name.replace("?","");
    name.replace(":","");

    return name;
}

//清空日志
void log::claer()
{
    QFile file(QDir::currentPath() +"/data/log.txt");
    if(file.open(QIODevice::WriteOnly |QIODevice::Text))
    {
        QTextStream out(&file);
        out<<QDateTime::currentDateTime().toString() <<"   " <<"exe is runing" << "\n";
        file.close();
    }
}

//写入日志
void log::write(QString txt)
{
    QFile file(QDir::currentPath() +"/data/log.txt");
    if(file.open(QIODevice::Append |QIODevice::Text))
    {
        QTextStream out(&file);
        out<<QDateTime::currentDateTime().toString() <<"   " << txt << "\n";
        file.close();
    }
}

