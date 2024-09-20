#include "seit.h"
#include "ui_seit.h"

seit::seit(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::seit)
{
    this->setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明
    this->setWindowFlags(Qt::FramelessWindowHint);   //设置无边框窗口
    ui->setupUi(this);
}

seit::~seit()
{
    delete ui;
}

//鼠标按下
void seit::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        my_pos = event->pos();
        event->accept();
    }
    QWidget::mousePressEvent(event);
}
//鼠标移动
void seit::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        move(QCursor::pos() - my_pos);
        event->accept();
    }
    QWidget::mouseMoveEvent(event);
}

//设置背景
void seit::set_background_pic(QImage *img)
{
    *img = img->scaled(ui->pixmapshow->size(),Qt::KeepAspectRatioByExpanding);
    QPixmap *pixmap = new QPixmap;
    pixmap->convertFromImage(*img);
    ui->pixmapshow->pixmap = pixmap;
    ui->pixmapshow->update();
}

//保存数据
void seit::write_data()
{
    QSettings *ini = new QSettings(QDir::currentPath() + "/data/setting.ini", QSettings::IniFormat);
    ini->clear();
    ini->beginGroup("seit");

    ini->setValue("music_url",sourceList);
    ini->setValue("font_type",font_type);

    ini->setValue("lrc_fontType",lrc_fontType);
    ini->setValue("lrc_upColor",lrc_upColor);
    ini->setValue("lrc_downColor",lrc_downColor);
    ini->setValue("lrc_fontSize",lrc_fontSize);

    ini->endGroup();
    ini->sync();
    delete ini;
}
//读取数据
void seit::read_data()
{
    QSettings *ini = new QSettings(QDir::currentPath() + "/data/setting.ini", QSettings::IniFormat);
    ini->beginGroup("seit");

    sourceList = ini->value("music_url").toStringList();
    ui->comboBox_all_url->addItems(sourceList);
    for(int i=0;i<sourceList.size();i++)
    {
        emit build_dir(sourceList[i]);
    }

    font_type = ini->value("font_type").toString();
    if(font_type.isNull())
    {
        font_type = "华文仿宋";
    }
    ui->fontComboBox_seit->setCurrentText(font_type);
    set_font_type(font_type);

    lrc_fontType = ini->value("lrc_fontType").toString();
    ui->fontComboBox_lrc->setCurrentText(lrc_fontType);
    lrc_upColor = ini->value("lrc_upColor").toString();
    ui->pushButton_nowLrc->setStyleSheet("QPushButton { background-color: " + lrc_upColor + "; }");
    lrc_downColor = ini->value("lrc_downColor").toString();
    ui->pushButton_downLrc->setStyleSheet("QPushButton { background-color: " + lrc_downColor + "; }");
    lrc_fontSize = ini->value("lrc_fontSize").toInt();
    build_lrcStyle();

    ini->endGroup();
    noFirst = true;
}

void seit::on_pushButton_add_dir_clicked()
{
    QFileDialog fileDialog;
    QString aim_dir = fileDialog.getExistingDirectory(this, tr("选择保存路径"));
    if(aim_dir != "")
    {
        ui->comboBox_all_url->addItem(aim_dir);
        sourceList.append(aim_dir);
    }
    emit build_dir(aim_dir);
}

//设置字体
void seit::set_font_type(QString f)
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
    emit seit_type(f);
}

void seit::on_pushButton_nowLrc_clicked()
{
    QColor color = QColorDialog::getColor(Qt::red, this, "Choose a color");
    if (color.isValid()) {
        // 使用选择的颜色，例如，设置按钮的背景色
        ui->pushButton_nowLrc->setStyleSheet("QPushButton { background-color: " + color.name() + "; }");
    }
    lrc_upColor = color.name();
    build_lrcStyle();
}

void seit::on_pushButton_downLrc_clicked()
{
    QColor color = QColorDialog::getColor(Qt::red, this, "Choose a color");
    if (color.isValid()) {
        // 使用选择的颜色，例如，设置按钮的背景色
        ui->pushButton_downLrc->setStyleSheet("QPushButton { background-color: " + color.name() + "; }");
    }
    lrc_downColor = color.name();
    build_lrcStyle();
}

void seit::on_pushButton_sizeDown_clicked()
{
    lrc_fontSize--;
    build_lrcStyle();
}

void seit::on_pushButton_sizeUp_clicked()
{
    lrc_fontSize++;
    build_lrcStyle();
}

//执行数据
void seit::build_lrcStyle()
{
    QString now = "*{font:" + QString::number(lrc_fontSize) + "pt \"" + lrc_fontType + "\";color: "+ lrc_upColor +";}";
    QString down = "*{font:" + QString::number(lrc_fontSize) + "pt \"" + lrc_fontType + "\";color: "+ lrc_downColor +";}";
    emit giveLrcStyle(now,down);
}

void seit::on_pushButton_delete_dir_clicked()
{
    for(int i=0;i<sourceList.size();i++)
    {
        if(sourceList[i] == ui->comboBox_all_url->currentText())
        {
            sourceList.remove(i);
            break;
        }
    }
    ui->comboBox_all_url->removeItem(ui->comboBox_all_url->currentIndex());
}

void seit::on_fontComboBox_seit_currentTextChanged(const QString &arg1)
{
    if(noFirst)
    {
        font_type = arg1;
        set_font_type(arg1);
    }
}

void seit::on_fontComboBox_lrc_currentTextChanged(const QString &arg1)
{
    if(noFirst)
    {
        lrc_fontType = arg1;
        build_lrcStyle();
    }
}

