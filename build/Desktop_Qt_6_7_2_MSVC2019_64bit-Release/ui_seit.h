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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
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
    QPushButton *pushButton_sizeUp;
    QComboBox *comboBox_all_url;
    QPushButton *pushButton_add_dir;
    QPushButton *pushButton_sizeDown;
    QFontComboBox *fontComboBox_lrc;
    QFontComboBox *fontComboBox_seit;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label;
    QPushButton *pushButton_delete_dir;
    QPushButton *pushButton_nowLrc;
    QPushButton *pushButton_downLrc;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *seit)
    {
        if (seit->objectName().isEmpty())
            seit->setObjectName("seit");
        seit->resize(477, 805);
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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 441, 769));
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
        pushButton_sizeUp = new QPushButton(widget_source);
        pushButton_sizeUp->setObjectName("pushButton_sizeUp");

        gridLayout->addWidget(pushButton_sizeUp, 8, 1, 1, 1);

        comboBox_all_url = new QComboBox(widget_source);
        comboBox_all_url->setObjectName("comboBox_all_url");

        gridLayout->addWidget(comboBox_all_url, 0, 1, 1, 2);

        pushButton_add_dir = new QPushButton(widget_source);
        pushButton_add_dir->setObjectName("pushButton_add_dir");

        gridLayout->addWidget(pushButton_add_dir, 2, 2, 1, 1);

        pushButton_sizeDown = new QPushButton(widget_source);
        pushButton_sizeDown->setObjectName("pushButton_sizeDown");

        gridLayout->addWidget(pushButton_sizeDown, 8, 2, 1, 1);

        fontComboBox_lrc = new QFontComboBox(widget_source);
        fontComboBox_lrc->setObjectName("fontComboBox_lrc");

        gridLayout->addWidget(fontComboBox_lrc, 6, 1, 1, 2);

        fontComboBox_seit = new QFontComboBox(widget_source);
        fontComboBox_seit->setObjectName("fontComboBox_seit");

        gridLayout->addWidget(fontComboBox_seit, 3, 1, 1, 2);

        label_4 = new QLabel(widget_source);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_3 = new QLabel(widget_source);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        label = new QLabel(widget_source);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton_delete_dir = new QPushButton(widget_source);
        pushButton_delete_dir->setObjectName("pushButton_delete_dir");

        gridLayout->addWidget(pushButton_delete_dir, 2, 1, 1, 1);

        pushButton_nowLrc = new QPushButton(widget_source);
        pushButton_nowLrc->setObjectName("pushButton_nowLrc");

        gridLayout->addWidget(pushButton_nowLrc, 4, 1, 1, 1);

        pushButton_downLrc = new QPushButton(widget_source);
        pushButton_downLrc->setObjectName("pushButton_downLrc");

        gridLayout->addWidget(pushButton_downLrc, 4, 2, 1, 1);


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
        pushButton_sizeUp->setText(QCoreApplication::translate("seit", "<", nullptr));
        pushButton_add_dir->setText(QCoreApplication::translate("seit", "\346\226\260\345\212\240\345\234\260\345\235\200", nullptr));
        pushButton_sizeDown->setText(QCoreApplication::translate("seit", ">", nullptr));
        label_4->setText(QCoreApplication::translate("seit", "\345\255\227\344\275\223", nullptr));
        label_3->setText(QCoreApplication::translate("seit", "\346\241\214\351\235\242\346\255\214\350\257\215", nullptr));
        label->setText(QCoreApplication::translate("seit", "\351\237\263\344\271\220\345\255\230\346\224\276\344\275\215\347\275\256", nullptr));
        pushButton_delete_dir->setText(QCoreApplication::translate("seit", "\345\210\240\351\231\244\345\234\260\345\235\200", nullptr));
        pushButton_nowLrc->setText(QCoreApplication::translate("seit", "\345\275\223\345\211\215\346\255\214\350\257\215\351\242\234\350\211\262", nullptr));
        pushButton_downLrc->setText(QCoreApplication::translate("seit", "\344\270\213\344\270\200\345\217\245\346\255\214\350\257\215\351\242\234\350\211\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class seit: public Ui_seit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEIT_H
