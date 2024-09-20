#include "music.h"

#define  FFmpegUrl QDir::currentPath() + "/ffmpeg.exe"

music::music() {
    this->setWordWrap(1);
    this->installEventFilter(this);
}

//右键菜单
void music::contextMenuEvent(QContextMenuEvent* event)
{
    QMenu menu(this);

    QAction* edit = new QAction("编辑标签");
    menu.addAction(edit);
    connect(edit,&QAction::triggered,this,&music::editMetadata);

    QAction* move = new QAction("添加到列表");
    menu.addAction(move);
    connect(move,&QAction::triggered,this,[=]()
            {
                emit moveToTable(core->number);
            });

    QAction* remove = new QAction("从当前菜单移除");
    menu.addAction(remove);
    connect(remove,&QAction::triggered,this,&music::remove);

    menu.exec(QCursor::pos());
    event->accept();
}

//删除当前gui
void music::remove()
{
    core = new musicCore;
    this->hide();
}

//编辑文件标签
void music::editMetadata()
{
    AVFormatContext* fmt_ctx = nullptr;
    if(avformat_open_input(&fmt_ctx, core->url.toUtf8(), NULL, NULL) != 0) {
    }

    if(avformat_find_stream_info(fmt_ctx, nullptr) < 0) {
        avformat_close_input(&fmt_ctx);
    }

    // 遍历所有流并打印它们的元数据
    QMap <QString,QString> map;
    AVDictionaryEntry* tag = nullptr;
    while ((tag = av_dict_get(fmt_ctx->metadata, "", tag, AV_DICT_IGNORE_SUFFIX))) {
        // 将标签的键和值添加到QMap中
        QString key = QString::fromUtf8(tag->key);
        QString value = QString::fromUtf8(tag->value);
        map.insert(key,value);
    }

    // 清理
    avformat_close_input(&fmt_ctx);

    metadata* data = new metadata;
    data->fromMap(map);
    data->show();
    data->url = core->url;
}

//重写事件过滤器
bool music::eventFilter(QObject *target, QEvent *event)
{
    if (target == this && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if (mouseEvent->button() == Qt::LeftButton)
        {
            emit playMusic(number);
            return 1;
        }
    }
    return 0;
}

//根据core设置属性
void music::fromCore(musicCore* core)
{
    this->core = core;
    setText(core->baseName);
}

metadata::metadata()
{
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(tables);
    layout->addWidget(yes);

    this->setLayout(layout);
    this->setWindowTitle("编辑");
    this->setMinimumWidth(300);
    connect(yes,&QPushButton::pressed,this,&metadata::editFile);
}

void metadata::fromMap(QMap<QString,QString> map)
{
    QGridLayout* vbox = new QGridLayout;
    QStringList keys = map.keys();
    for(int i=0;i<keys.size();i++)
    {
        QLabel* label = new QLabel(keys[i]);
        label->setWordWrap(1);
        QLineEdit* edit = new QLineEdit(map[keys[i]]);
        vbox->addWidget(label,i,0);
        vbox->addWidget(edit,i,1);
    }
    tables->setLayout(vbox);
}

//确定修改
void metadata::editFile()
{
    QList <QLabel*> labels = this->findChildren<QLabel*>();
    QList <QLineEdit*> edits = this->findChildren<QLineEdit*>();
    QFileInfo info(url);
    QString run = FFmpegUrl + " -i \"" + url + "\"";
    for(int i=0;i<labels.size();i++)
    {
        run = run + " -metadata " + labels[i]->text() + "=\"" + edits[i]->text() + "\"";
    }
    run = run + " \"" + info.path() + "/" + info.fileName().split("." + info.suffix())[0] + "new." + info.suffix() + "\"";

    QProcess process;
    process.startCommand(run);
    process.waitForStarted();
    process.waitForFinished();

    QFile file(info.path() + "/" + info.fileName().split("." + info.suffix())[0] + "new." + info.suffix());
    QString aim = info.path() + "/" + info.fileName();
    QFile::remove(url);
    file.rename(aim);
}
