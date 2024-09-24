/********************************************************************************
** Form generated from reading UI file 'seit.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEIT_H
#define UI_SEIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qpixmapshow.h>

QT_BEGIN_NAMESPACE

class Ui_seit
{
public:
    QVBoxLayout *verticalLayout_4;
    QWidget *widget;
    QVBoxLayout *verticalLayout_6;
    QPixmapShow *pixmapshow;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_show;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_source;
    QGridLayout *gridLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_sizeUp;
    QPushButton *pushButton_sizeDown;
    QLabel *label_3;
    QPushButton *pushButton_lrc_sizeAdd;
    QLabel *label;
    QLabel *label_8;
    QPushButton *pushButton_delete_dir;
    QCheckBox *checkBox_downLrc;
    QComboBox *comboBox_all_url;
    QLabel *label_lrcShow_fontSize;
    QPushButton *pushButton_downLrc;
    QFontComboBox *fontComboBox_lrc;
    QLabel *label_2;
    QPushButton *pushButton_add_dir;
    QPushButton *pushButton_nowLrc;
    QLabel *label_4;
    QPushButton *pushButton_lrc_sizeDecrease;
    QLabel *label_6;
    QCheckBox *checkBox_downCover;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *seit)
    {
        if (seit->objectName().isEmpty())
            seit->setObjectName("seit");
        seit->resize(508, 805);
        seit->setMinimumSize(QSize(0, 600));
        seit->setMaximumSize(QSize(16777215, 16777215));
        seit->setStyleSheet(QString::fromUtf8("*:hover{\n"
"color: rgb(0, 170, 255);\n"
"}\n"
"#widget{\n"
"border-radius:15px;\n"
"background-color: rgb(0, 0, 0);\n"
"}\n"
"#widget_show\n"
"{\n"
"background-color: rgba(0,0,0,128); \n"
"}\n"
"*{\n"
"font: 100 12pt \"\345\215\216\346\226\207\344\273\277\345\256\213\";\n"
"color: rgb(255, 255, 255);\n"
"border:0px;\n"
"background-color: transparent;\n"
"}\n"
"QComboBox QAbstractItemView \n"
"{\n"
"background-color:rgba(0,0,0,128);\n"
"}\n"
"QMenu\n"
"{\n"
"background-color: rgba(0,0,0,128);\n"
"}\n"
""));
        verticalLayout_4 = new QVBoxLayout(seit);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(seit);
        widget->setObjectName("widget");
        verticalLayout_6 = new QVBoxLayout(widget);
        verticalLayout_6->setObjectName("verticalLayout_6");
        pixmapshow = new QPixmapShow(widget);
        pixmapshow->setObjectName("pixmapshow");
        verticalLayout_5 = new QVBoxLayout(pixmapshow);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget_show = new QWidget(pixmapshow);
        widget_show->setObjectName("widget_show");
        widget_show->setMinimumSize(QSize(361, 600));
        widget_show->setMaximumSize(QSize(16777215, 16777215));
        widget_show->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(widget_show);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        scrollArea = new QScrollArea(widget_show);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 472, 769));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_source = new QWidget(scrollAreaWidgetContents);
        widget_source->setObjectName("widget_source");
        gridLayout = new QGridLayout(widget_source);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(20);
        gridLayout->setContentsMargins(-1, -1, -1, 20);
        widget_2 = new QWidget(widget_source);
        widget_2->setObjectName("widget_2");
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_sizeUp = new QPushButton(widget_2);
        pushButton_sizeUp->setObjectName("pushButton_sizeUp");
        pushButton_sizeUp->setStyleSheet(QString::fromUtf8("image: url(:/move.png);"));

        horizontalLayout->addWidget(pushButton_sizeUp);

        pushButton_sizeDown = new QPushButton(widget_2);
        pushButton_sizeDown->setObjectName("pushButton_sizeDown");
        pushButton_sizeDown->setStyleSheet(QString::fromUtf8("image: url(:/min.png);"));

        horizontalLayout->addWidget(pushButton_sizeDown);


        gridLayout->addWidget(widget_2, 11, 3, 1, 2);

        label_3 = new QLabel(widget_source);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 7, 0, 1, 1);

        pushButton_lrc_sizeAdd = new QPushButton(widget_source);
        pushButton_lrc_sizeAdd->setObjectName("pushButton_lrc_sizeAdd");
        pushButton_lrc_sizeAdd->setStyleSheet(QString::fromUtf8("image: url(:/move.png);"));

        gridLayout->addWidget(pushButton_lrc_sizeAdd, 3, 3, 1, 1);

        label = new QLabel(widget_source);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_8 = new QLabel(widget_source);
        label_8->setObjectName("label_8");

        gridLayout->addWidget(label_8, 3, 1, 1, 2);

        pushButton_delete_dir = new QPushButton(widget_source);
        pushButton_delete_dir->setObjectName("pushButton_delete_dir");

        gridLayout->addWidget(pushButton_delete_dir, 2, 1, 1, 3);

        checkBox_downLrc = new QCheckBox(widget_source);
        checkBox_downLrc->setObjectName("checkBox_downLrc");

        gridLayout->addWidget(checkBox_downLrc, 12, 1, 1, 2);

        comboBox_all_url = new QComboBox(widget_source);
        comboBox_all_url->setObjectName("comboBox_all_url");

        gridLayout->addWidget(comboBox_all_url, 0, 1, 1, 4);

        label_lrcShow_fontSize = new QLabel(widget_source);
        label_lrcShow_fontSize->setObjectName("label_lrcShow_fontSize");

        gridLayout->addWidget(label_lrcShow_fontSize, 11, 2, 1, 1);

        pushButton_downLrc = new QPushButton(widget_source);
        pushButton_downLrc->setObjectName("pushButton_downLrc");

        gridLayout->addWidget(pushButton_downLrc, 7, 3, 1, 2);

        fontComboBox_lrc = new QFontComboBox(widget_source);
        fontComboBox_lrc->setObjectName("fontComboBox_lrc");

        gridLayout->addWidget(fontComboBox_lrc, 9, 1, 1, 4);

        label_2 = new QLabel(widget_source);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 11, 1, 1, 1);

        pushButton_add_dir = new QPushButton(widget_source);
        pushButton_add_dir->setObjectName("pushButton_add_dir");

        gridLayout->addWidget(pushButton_add_dir, 2, 4, 1, 1);

        pushButton_nowLrc = new QPushButton(widget_source);
        pushButton_nowLrc->setObjectName("pushButton_nowLrc");

        gridLayout->addWidget(pushButton_nowLrc, 7, 1, 1, 2);

        label_4 = new QLabel(widget_source);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        pushButton_lrc_sizeDecrease = new QPushButton(widget_source);
        pushButton_lrc_sizeDecrease->setObjectName("pushButton_lrc_sizeDecrease");
        pushButton_lrc_sizeDecrease->setStyleSheet(QString::fromUtf8("image: url(:/min.png);"));

        gridLayout->addWidget(pushButton_lrc_sizeDecrease, 3, 4, 1, 1);

        label_6 = new QLabel(widget_source);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 12, 0, 1, 1);

        checkBox_downCover = new QCheckBox(widget_source);
        checkBox_downCover->setObjectName("checkBox_downCover");

        gridLayout->addWidget(checkBox_downCover, 12, 3, 1, 2);


        verticalLayout_2->addWidget(widget_source);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        verticalLayout_5->addWidget(widget_show);


        verticalLayout_6->addWidget(pixmapshow);


        verticalLayout_4->addWidget(widget);


        retranslateUi(seit);

        QMetaObject::connectSlotsByName(seit);
    } // setupUi

    void retranslateUi(QWidget *seit)
    {
        seit->setWindowTitle(QCoreApplication::translate("seit", "\350\256\276\347\275\256", nullptr));
        pushButton_sizeUp->setText(QString());
        pushButton_sizeDown->setText(QString());
        label_3->setText(QCoreApplication::translate("seit", "\346\241\214\351\235\242\346\255\214\350\257\215", nullptr));
        pushButton_lrc_sizeAdd->setText(QString());
        label->setText(QCoreApplication::translate("seit", "\351\237\263\344\271\220\345\255\230\346\224\276\344\275\215\347\275\256", nullptr));
        label_8->setText(QCoreApplication::translate("seit", "\346\273\232\345\212\250\346\255\214\350\257\215\345\255\227\344\275\223\345\244\247\345\260\217", nullptr));
        pushButton_delete_dir->setText(QCoreApplication::translate("seit", "\345\210\240\351\231\244\345\234\260\345\235\200", nullptr));
        checkBox_downLrc->setText(QCoreApplication::translate("seit", "\344\270\213\350\275\275\346\255\214\350\257\215\357\274\210\347\275\221\346\230\223\344\272\221\357\274\211", nullptr));
        label_lrcShow_fontSize->setText(QCoreApplication::translate("seit", "20", nullptr));
        pushButton_downLrc->setText(QCoreApplication::translate("seit", "\344\270\213\344\270\200\345\217\245\346\255\214\350\257\215\351\242\234\350\211\262", nullptr));
        label_2->setText(QCoreApplication::translate("seit", "\345\255\227\344\275\223\345\244\247\345\260\217\357\274\232", nullptr));
        pushButton_add_dir->setText(QCoreApplication::translate("seit", "\346\226\260\345\212\240\345\234\260\345\235\200", nullptr));
        pushButton_nowLrc->setText(QCoreApplication::translate("seit", "\345\275\223\345\211\215\346\255\214\350\257\215\351\242\234\350\211\262", nullptr));
        label_4->setText(QCoreApplication::translate("seit", "\344\270\273\347\225\214\351\235\242\350\256\276\347\275\256", nullptr));
        pushButton_lrc_sizeDecrease->setText(QString());
        label_6->setText(QCoreApplication::translate("seit", "\345\234\250\347\272\277\346\234\215\345\212\241", nullptr));
        checkBox_downCover->setText(QCoreApplication::translate("seit", "\344\270\213\350\275\275\345\260\201\351\235\242\357\274\210\347\275\221\346\230\223\344\272\221\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class seit: public Ui_seit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEIT_H
