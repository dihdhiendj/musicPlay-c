#include "seit.h"
#include "ui_seit.h"

seit::seit(QWidget *parent)
    : QWidget(parent, Qt::WindowStaysOnTopHint)
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

    ini->setValue("lrc_font_family",lrc_font.family());
    ini->setValue("lrc_font_pointSize",lrc_font.pointSize());
    ini->setValue("mainLrc_font_pointSize",mainLrc_font_size);

    ini->setValue("playLrc_red",playLrc_color.red());
    ini->setValue("playLrc_green",playLrc_color.green());
    ini->setValue("playLrc_blue",playLrc_color.blue());

    ini->setValue("nextLrc_red",nextLrc_color.red());
    ini->setValue("nextLrc_green",nextLrc_color.green());
    ini->setValue("nextLrc_blue",nextLrc_color.blue());

    ini->setValue("isOnlineCover",isOnlineCover);
    ini->setValue("isOnlineLrc",isOnlineLrc);

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

    lrc_font.setFamily(ini->value("lrc_font_family").toString());
    lrc_font.setPointSize(ini->value("lrc_font_pointSize").toInt());
    ui->fontComboBox_lrc->setCurrentFont(lrc_font);

    mainLrc_font_size = ini->value("mainLrc_font_pointSize").toInt();

    playLrc_color.setRed(ini->value("playLrc_red").toInt());
    playLrc_color.setGreen(ini->value("playLrc_green").toInt());
    playLrc_color.setBlue(ini->value("playLrc_blue").toInt());


    nextLrc_color.setRed(ini->value("nextLrc_red").toInt());
    nextLrc_color.setGreen(ini->value("nextLrc_green").toInt());
    nextLrc_color.setBlue(ini->value("nextLrc_blue").toInt());
    build_lrcStyle();

    isOnlineCover = ini->value("isOnlineCover").toBool();
    ui->checkBox_downCover->setChecked(isOnlineCover);
    isOnlineLrc = ini->value("isOnlineLrc").toBool();
    ui->checkBox_downLrc->setChecked(isOnlineLrc);

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

void seit::on_pushButton_nowLrc_clicked()
{
    QColor color = QColorDialog::getColor(Qt::red, this, "Choose a color");
    if(color.isValid())
    {
        // 使用选择的颜色，例如，设置按钮的背景色
        ui->pushButton_nowLrc->setStyleSheet("QPushButton { background-color: " + color.name() + "; }");
    }
    playLrc_color = color;
    build_lrcStyle();
}

void seit::on_pushButton_downLrc_clicked()
{
    QColor color = QColorDialog::getColor(Qt::red, this, "Choose a color");
    if(color.isValid())
    {
        // 使用选择的颜色，例如，设置按钮的背景色
        ui->pushButton_downLrc->setStyleSheet("QPushButton { background-color: " + color.name() + "; }");
    }
    nextLrc_color = color.name();
    build_lrcStyle();
}

//设置lrcShow font
void seit::next_Font_size(int isAdd)
{
    int i = lrc_font.pointSize() + isAdd;
    if(i > 0)
    {
        ui->label_lrcShow_fontSize->setText(QString::number(i));
        lrc_font.setPointSize(i);
        build_lrcStyle();
    }
}

void seit::on_pushButton_sizeDown_clicked()
{
    next_Font_size(-1);
}


void seit::on_pushButton_sizeUp_clicked()
{
    next_Font_size(1);
}


//执行数据
void seit::build_lrcStyle()
{
    emit giveLrcStyle(playLrc_color,nextLrc_color,lrc_font);
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


void seit::on_fontComboBox_lrc_currentFontChanged(const QFont &f)
{
    lrc_font.setFamily(f.family());
    build_lrcStyle();
}


void seit::on_pushButton_lrc_sizeAdd_clicked()
{
    mainLrc_font_size++;
    build_lrcStyle();
}


void seit::on_pushButton_lrc_sizeDecrease_clicked()
{
    mainLrc_font_size--;
    build_lrcStyle();
}


void seit::on_checkBox_downLrc_stateChanged(int arg1)
{
    isOnlineLrc = arg1;
}


void seit::on_checkBox_downCover_stateChanged(int arg1)
{
    isOnlineCover = arg1;
}

