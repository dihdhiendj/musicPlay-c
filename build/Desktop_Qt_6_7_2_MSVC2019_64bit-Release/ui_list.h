/********************************************************************************
** Form generated from reading UI file 'list.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIST_H
#define UI_LIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qpixmapshow.h>

QT_BEGIN_NAMESPACE

class Ui_list
{
public:
    QVBoxLayout *verticalLayout_6;
    QWidget *widget;
    QVBoxLayout *verticalLayout_7;
    QPixmapShow *pixmapshow;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_show;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_tables;
    QPushButton *pushButton_high;
    QStackedWidget *stackedWidget_tables;

    void setupUi(QWidget *list)
    {
        if (list->objectName().isEmpty())
            list->setObjectName("list");
        list->resize(406, 652);
        list->setStyleSheet(QString::fromUtf8("#widget{\n"
"background-color: rgb(0, 0, 0);\n"
"border-radius:15px;\n"
"}\n"
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
"font: 12pt \"\345\215\216\346\226\207\344\273\277\345\256\213\";\n"
"border:none;\n"
"color: rgb(255, 255, 255);\n"
"background-color: transparent;\n"
"}"));
        verticalLayout_6 = new QVBoxLayout(list);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(list);
        widget->setObjectName("widget");
        verticalLayout_7 = new QVBoxLayout(widget);
        verticalLayout_7->setObjectName("verticalLayout_7");
        pixmapshow = new QPixmapShow(widget);
        pixmapshow->setObjectName("pixmapshow");
        verticalLayout_5 = new QVBoxLayout(pixmapshow);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget_show = new QWidget(pixmapshow);
        widget_show->setObjectName("widget_show");
        widget_show->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(widget_show);
        verticalLayout->setObjectName("verticalLayout");
        widget_2 = new QWidget(widget_show);
        widget_2->setObjectName("widget_2");
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_tables = new QPushButton(widget_2);
        pushButton_tables->setObjectName("pushButton_tables");

        horizontalLayout->addWidget(pushButton_tables);

        pushButton_high = new QPushButton(widget_2);
        pushButton_high->setObjectName("pushButton_high");

        horizontalLayout->addWidget(pushButton_high);


        verticalLayout->addWidget(widget_2);

        stackedWidget_tables = new QStackedWidget(widget_show);
        stackedWidget_tables->setObjectName("stackedWidget_tables");

        verticalLayout->addWidget(stackedWidget_tables);


        verticalLayout_5->addWidget(widget_show);


        verticalLayout_7->addWidget(pixmapshow);


        verticalLayout_6->addWidget(widget);


        retranslateUi(list);

        stackedWidget_tables->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(list);
    } // setupUi

    void retranslateUi(QWidget *list)
    {
        list->setWindowTitle(QCoreApplication::translate("list", "\346\222\255\346\224\276\345\210\227\350\241\250", nullptr));
        pushButton_tables->setText(QCoreApplication::translate("list", "\345\210\227\350\241\250\345\220\215", nullptr));
        pushButton_high->setText(QCoreApplication::translate("list", "\351\253\230\347\272\247\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class list: public Ui_list {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIST_H
