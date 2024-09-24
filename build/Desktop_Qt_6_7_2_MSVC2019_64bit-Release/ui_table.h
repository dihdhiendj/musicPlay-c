/********************************************************************************
** Form generated from reading UI file 'table.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_H
#define UI_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_table
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_main;
    QGridLayout *gridLayout;
    QWidget *widget_edit;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_name;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_yes;
    QPushButton *pushButton_no;
    QWidget *widget_search;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_search;
    QLineEdit *lineEdit;
    QComboBox *comboBox_forward;
    QComboBox *comboBox_key;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_music;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *table)
    {
        if (table->objectName().isEmpty())
            table->setObjectName("table");
        table->resize(358, 475);
        table->setStyleSheet(QString::fromUtf8("\n"
"QComboBox QAbstractItemView {\n"
"	background-color: rgb(0, 0, 0);\n"
"}\n"
"#widget_search{\n"
"border:1px solid white;\n"
"}\n"
"*:hover{\n"
"color: rgb(0, 170, 255);\n"
"}\n"
"*{\n"
"font: 12pt \"\345\215\216\346\226\207\344\273\277\345\256\213\";\n"
"border:none;\n"
"color: rgb(255, 255, 255);\n"
"background-color: transparent;\n"
"min-height:30px;\n"
"}"));
        verticalLayout = new QVBoxLayout(table);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(9, 9, 9, 9);
        widget_main = new QWidget(table);
        widget_main->setObjectName("widget_main");
        gridLayout = new QGridLayout(widget_main);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, -1);
        widget_edit = new QWidget(widget_main);
        widget_edit->setObjectName("widget_edit");
        widget_edit->setMinimumSize(QSize(0, 30));
        gridLayout_2 = new QGridLayout(widget_edit);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        lineEdit_name = new QLineEdit(widget_edit);
        lineEdit_name->setObjectName("lineEdit_name");

        gridLayout_2->addWidget(lineEdit_name, 0, 0, 1, 4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        pushButton_yes = new QPushButton(widget_edit);
        pushButton_yes->setObjectName("pushButton_yes");

        gridLayout_2->addWidget(pushButton_yes, 1, 1, 1, 1);

        pushButton_no = new QPushButton(widget_edit);
        pushButton_no->setObjectName("pushButton_no");

        gridLayout_2->addWidget(pushButton_no, 1, 2, 1, 1);


        gridLayout->addWidget(widget_edit, 2, 0, 1, 3);

        widget_search = new QWidget(widget_main);
        widget_search->setObjectName("widget_search");
        horizontalLayout = new QHBoxLayout(widget_search);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_search = new QPushButton(widget_search);
        pushButton_search->setObjectName("pushButton_search");

        horizontalLayout->addWidget(pushButton_search);

        lineEdit = new QLineEdit(widget_search);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);


        gridLayout->addWidget(widget_search, 1, 0, 1, 3);

        comboBox_forward = new QComboBox(widget_main);
        comboBox_forward->addItem(QString());
        comboBox_forward->addItem(QString());
        comboBox_forward->setObjectName("comboBox_forward");
        comboBox_forward->setStyleSheet(QString::fromUtf8("*{\n"
"min-width:100px;\n"
"}"));

        gridLayout->addWidget(comboBox_forward, 0, 2, 1, 1);

        comboBox_key = new QComboBox(widget_main);
        comboBox_key->addItem(QString());
        comboBox_key->addItem(QString());
        comboBox_key->addItem(QString());
        comboBox_key->addItem(QString());
        comboBox_key->addItem(QString());
        comboBox_key->addItem(QString());
        comboBox_key->setObjectName("comboBox_key");

        gridLayout->addWidget(comboBox_key, 0, 0, 1, 2);


        verticalLayout->addWidget(widget_main);

        scrollArea = new QScrollArea(table);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setMaximumSize(QSize(16777215, 16777215));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 340, 286));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 30));
        scrollAreaWidgetContents->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_music = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_music->setSpacing(10);
        verticalLayout_music->setObjectName("verticalLayout_music");
        verticalLayout_music->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_music->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(table);

        QMetaObject::connectSlotsByName(table);
    } // setupUi

    void retranslateUi(QWidget *table)
    {
        table->setWindowTitle(QCoreApplication::translate("table", "Form", nullptr));
        pushButton_yes->setText(QCoreApplication::translate("table", "\347\241\256\345\256\232", nullptr));
        pushButton_no->setText(QCoreApplication::translate("table", "\345\217\226\346\266\210", nullptr));
        pushButton_search->setText(QCoreApplication::translate("table", "\346\220\234\347\264\242\357\274\232", nullptr));
        comboBox_forward->setItemText(0, QCoreApplication::translate("table", "\351\231\215\345\272\217", nullptr));
        comboBox_forward->setItemText(1, QCoreApplication::translate("table", "\345\215\207\345\272\217", nullptr));

        comboBox_key->setItemText(0, QCoreApplication::translate("table", "\344\275\234\350\200\205", nullptr));
        comboBox_key->setItemText(1, QCoreApplication::translate("table", "\346\240\207\351\242\230", nullptr));
        comboBox_key->setItemText(2, QCoreApplication::translate("table", "\344\270\223\350\276\221", nullptr));
        comboBox_key->setItemText(3, QCoreApplication::translate("table", "\346\222\255\346\224\276\346\254\241\346\225\260", nullptr));
        comboBox_key->setItemText(4, QCoreApplication::translate("table", "\345\226\234\347\210\261\347\250\213\345\272\246", nullptr));
        comboBox_key->setItemText(5, QCoreApplication::translate("table", "\347\274\226\350\276\221\346\227\245\346\234\237", nullptr));

    } // retranslateUi

};

namespace Ui {
    class table: public Ui_table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_H
