#include "qpixmapshow.h"
#include "ui_qpixmapshow.h"

QPixmapShow::QPixmapShow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QPixmapShow)
{
    ui->setupUi(this);
}

QPixmapShow::~QPixmapShow()
{
    delete ui;
}
