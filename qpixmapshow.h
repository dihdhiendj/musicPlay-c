#ifndef QPIXMAPSHOW_H
#define QPIXMAPSHOW_H

#include <QPainter>
#include <QWidget>

namespace Ui {
class QPixmapShow;
}

class QPixmapShow : public QWidget
{
    Q_OBJECT

public:
    explicit QPixmapShow(QWidget *parent = nullptr);
    ~QPixmapShow();

    QPixmap* pixmap = NULL;
    void paintEvent(QPaintEvent *event) override
    {
        if(pixmap != NULL)
        {
            QPainter painter(this);
            int h = 0,w = 0;
            if(rect().height() * pixmap->width() > rect().width() * pixmap->rect().height())
            {
                h = rect().height();
                w = pixmap->rect().width() * rect().height() / pixmap->rect().height();
            }
            else
            {
                h = pixmap->rect().height() * rect().width() / pixmap->rect().width();
                w = rect().width();
            }
            painter.drawPixmap(QRect(0,0,w,h), *pixmap);
        }
        QWidget::paintEvent(event);
    }

private:
    Ui::QPixmapShow *ui;
};

#endif // QPIXMAPSHOW_H

