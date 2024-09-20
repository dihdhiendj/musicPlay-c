/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qpixmapshow.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QPixmapShow *pixmapshow;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_show;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_title;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_min;
    QPushButton *pushButton_close;
    QWidget *widget_lrcAcover;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_cover;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label_back;
    QLabel *label_baseName;
    QSpacerItem *verticalSpacer_2;
    QScrollArea *scrollArea_lrc;
    QWidget *scrollAreaWidgetContents_lrc;
    QVBoxLayout *verticalLayout_lrc;
    QWidget *widget_others;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_lrc_show;
    QComboBox *comboBox_loop;
    QPushButton *pushButton_value;
    QSlider *horizontalSlider_volume;
    QPushButton *pushButton_table;
    QPushButton *pushButton_seit_show;
    QWidget *widget_play_number;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_now;
    QSlider *horizontalSlider_play_value;
    QLabel *label_end;
    QWidget *widget_play;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_up;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_play;
    QPushButton *pushButton_down;
    QSpacerItem *horizontalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1051, 709);
        MainWindow->setStyleSheet(QString::fromUtf8("#widget{\n"
"background-color: rgb(0, 0, 0);\n"
"border-radius:15px;\n"
"}\n"
"QScrollBar {width:0px;}\n"
"QScrollBar {height:0px;}\n"
"*:hover{\n"
"color: rgb(0, 170, 255);\n"
"}\n"
"#widget_show{\n"
"background-color: rgba(0,0,0,128); \n"
"}\n"
"QMenu\n"
"{\n"
"background-color: rgba(0,0,0,128);\n"
"}\n"
"*{\n"
"font: 100 12pt \"\345\215\216\346\226\207\344\273\277\345\256\213\";\n"
"border:0px;\n"
"min-height:30px;\n"
"color: rgb(255, 255, 255);\n"
"background-color: transparent;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        pixmapshow = new QPixmapShow(widget);
        pixmapshow->setObjectName("pixmapshow");
        verticalLayout_4 = new QVBoxLayout(pixmapshow);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_show = new QWidget(pixmapshow);
        widget_show->setObjectName("widget_show");
        widget_show->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(widget_show);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_title = new QWidget(widget_show);
        widget_title->setObjectName("widget_title");
        horizontalLayout_5 = new QHBoxLayout(widget_title);
        horizontalLayout_5->setSpacing(30);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 10, 50, 10);
        horizontalSpacer_3 = new QSpacerItem(858, 27, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        pushButton_min = new QPushButton(widget_title);
        pushButton_min->setObjectName("pushButton_min");

        horizontalLayout_5->addWidget(pushButton_min);

        pushButton_close = new QPushButton(widget_title);
        pushButton_close->setObjectName("pushButton_close");

        horizontalLayout_5->addWidget(pushButton_close);


        verticalLayout_2->addWidget(widget_title);

        widget_lrcAcover = new QWidget(widget_show);
        widget_lrcAcover->setObjectName("widget_lrcAcover");
        horizontalLayout_4 = new QHBoxLayout(widget_lrcAcover);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        widget_cover = new QWidget(widget_lrcAcover);
        widget_cover->setObjectName("widget_cover");
        widget_cover->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(widget_cover);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(40, -1, -1, -1);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_back = new QLabel(widget_cover);
        label_back->setObjectName("label_back");
        label_back->setStyleSheet(QString::fromUtf8("*{\n"
"min-width:300px;\n"
"min-height:300px;\n"
"}"));

        verticalLayout->addWidget(label_back);

        label_baseName = new QLabel(widget_cover);
        label_baseName->setObjectName("label_baseName");
        label_baseName->setStyleSheet(QString::fromUtf8("*{\n"
"min-width:300px;\n"
"font: 14pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"}\n"
""));

        verticalLayout->addWidget(label_baseName);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout_4->addWidget(widget_cover);

        scrollArea_lrc = new QScrollArea(widget_lrcAcover);
        scrollArea_lrc->setObjectName("scrollArea_lrc");
        scrollArea_lrc->setMaximumSize(QSize(666, 16777215));
        scrollArea_lrc->setStyleSheet(QString::fromUtf8(""));
        scrollArea_lrc->setWidgetResizable(true);
        scrollAreaWidgetContents_lrc = new QWidget();
        scrollAreaWidgetContents_lrc->setObjectName("scrollAreaWidgetContents_lrc");
        scrollAreaWidgetContents_lrc->setGeometry(QRect(0, 0, 666, 495));
        scrollAreaWidgetContents_lrc->setMaximumSize(QSize(666, 16777215));
        verticalLayout_lrc = new QVBoxLayout(scrollAreaWidgetContents_lrc);
        verticalLayout_lrc->setSpacing(0);
        verticalLayout_lrc->setObjectName("verticalLayout_lrc");
        scrollArea_lrc->setWidget(scrollAreaWidgetContents_lrc);

        horizontalLayout_4->addWidget(scrollArea_lrc);


        verticalLayout_2->addWidget(widget_lrcAcover);

        widget_others = new QWidget(widget_show);
        widget_others->setObjectName("widget_others");
        widget_others->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_2 = new QHBoxLayout(widget_others);
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(40, 0, 40, 0);
        pushButton_lrc_show = new QPushButton(widget_others);
        pushButton_lrc_show->setObjectName("pushButton_lrc_show");

        horizontalLayout_2->addWidget(pushButton_lrc_show);

        comboBox_loop = new QComboBox(widget_others);
        comboBox_loop->addItem(QString());
        comboBox_loop->addItem(QString());
        comboBox_loop->addItem(QString());
        comboBox_loop->addItem(QString());
        comboBox_loop->setObjectName("comboBox_loop");
        comboBox_loop->setStyleSheet(QString::fromUtf8("*{\n"
"min-width:100px;\n"
"}\n"
"QComboBox\n"
"{\n"
"border:1px red solid;\n"
"}\n"
"QComboBox::drop-down \n"
"{\n"
"width:0px;border:1px red solid;\n"
"}"));

        horizontalLayout_2->addWidget(comboBox_loop);

        pushButton_value = new QPushButton(widget_others);
        pushButton_value->setObjectName("pushButton_value");

        horizontalLayout_2->addWidget(pushButton_value);

        horizontalSlider_volume = new QSlider(widget_others);
        horizontalSlider_volume->setObjectName("horizontalSlider_volume");
        horizontalSlider_volume->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider_volume);

        pushButton_table = new QPushButton(widget_others);
        pushButton_table->setObjectName("pushButton_table");

        horizontalLayout_2->addWidget(pushButton_table);

        pushButton_seit_show = new QPushButton(widget_others);
        pushButton_seit_show->setObjectName("pushButton_seit_show");

        horizontalLayout_2->addWidget(pushButton_seit_show);


        verticalLayout_2->addWidget(widget_others);

        widget_play_number = new QWidget(widget_show);
        widget_play_number->setObjectName("widget_play_number");
        horizontalLayout_3 = new QHBoxLayout(widget_play_number);
        horizontalLayout_3->setSpacing(20);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(40, -1, 40, -1);
        label_now = new QLabel(widget_play_number);
        label_now->setObjectName("label_now");

        horizontalLayout_3->addWidget(label_now);

        horizontalSlider_play_value = new QSlider(widget_play_number);
        horizontalSlider_play_value->setObjectName("horizontalSlider_play_value");
        horizontalSlider_play_value->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider_play_value);

        label_end = new QLabel(widget_play_number);
        label_end->setObjectName("label_end");

        horizontalLayout_3->addWidget(label_end);


        verticalLayout_2->addWidget(widget_play_number);

        widget_play = new QWidget(widget_show);
        widget_play->setObjectName("widget_play");
        widget_play->setStyleSheet(QString::fromUtf8("*{min-height:50px}"));
        horizontalLayout = new QHBoxLayout(widget_play);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_up = new QPushButton(widget_play);
        pushButton_up->setObjectName("pushButton_up");

        horizontalLayout->addWidget(pushButton_up);

        pushButton_stop = new QPushButton(widget_play);
        pushButton_stop->setObjectName("pushButton_stop");

        horizontalLayout->addWidget(pushButton_stop);

        pushButton_play = new QPushButton(widget_play);
        pushButton_play->setObjectName("pushButton_play");

        horizontalLayout->addWidget(pushButton_play);

        pushButton_down = new QPushButton(widget_play);
        pushButton_down->setObjectName("pushButton_down");

        horizontalLayout->addWidget(pushButton_down);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(widget_play);


        verticalLayout_4->addWidget(widget_show);


        verticalLayout_5->addWidget(pixmapshow);


        verticalLayout_3->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\270\214\344\270\241", nullptr));
        pushButton_min->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\260\217\345\214\226", nullptr));
        pushButton_close->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(whatsthis)
        label_back->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\346\255\214\346\233\262\345\260\201\351\235\242</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_back->setText(QCoreApplication::translate("MainWindow", "\345\260\201\351\235\242", nullptr));
        label_baseName->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_lrc_show->setText(QCoreApplication::translate("MainWindow", "\350\257\215", nullptr));
        comboBox_loop->setItemText(0, QCoreApplication::translate("MainWindow", "\351\241\272\345\272\217\345\276\252\347\216\257", nullptr));
        comboBox_loop->setItemText(1, QCoreApplication::translate("MainWindow", "\351\232\217\346\234\272\345\276\252\347\216\257", nullptr));
        comboBox_loop->setItemText(2, QCoreApplication::translate("MainWindow", "\345\215\225\346\233\262\345\276\252\347\216\257", nullptr));
        comboBox_loop->setItemText(3, QCoreApplication::translate("MainWindow", "\345\217\215\345\272\217\345\276\252\347\216\257", nullptr));

#if QT_CONFIG(whatsthis)
        comboBox_loop->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\345\210\207\346\215\242\345\276\252\347\216\257\346\250\241\345\274\217</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_value->setText(QCoreApplication::translate("MainWindow", "\351\237\263\351\207\217", nullptr));
        pushButton_table->setText(QCoreApplication::translate("MainWindow", "\346\255\214\346\233\262\345\210\227\350\241\250", nullptr));
        pushButton_seit_show->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        label_now->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215", nullptr));
        label_end->setText(QCoreApplication::translate("MainWindow", "\347\273\223\346\235\237", nullptr));
        pushButton_up->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\351\246\226", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        pushButton_play->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276", nullptr));
        pushButton_down->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\351\246\226", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
