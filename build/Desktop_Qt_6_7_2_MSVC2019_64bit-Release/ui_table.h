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
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_search;
    QComboBox *comboBox_key;
    QLineEdit *lineEdit;
    QComboBox *comboBox_forward;
    QWidget *widget_edit;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_yes;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_name;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_music;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *table)
    {
        if (table->objectName().isEmpty())
            table->setObjectName("table");
        table->resize(358, 475);
        table->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"min-height:50px;\n"
"}"));
        verticalLayout = new QVBoxLayout(table);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(9, 9, 9, 9);
        widget = new QWidget(table);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, -1);
        pushButton_search = new QPushButton(widget);
        pushButton_search->setObjectName("pushButton_search");

        gridLayout->addWidget(pushButton_search, 1, 1, 1, 2);

        comboBox_key = new QComboBox(widget);
        comboBox_key->addItem(QString());
        comboBox_key->addItem(QString());
        comboBox_key->addItem(QString());
        comboBox_key->addItem(QString());
        comboBox_key->addItem(QString());
        comboBox_key->addItem(QString());
        comboBox_key->setObjectName("comboBox_key");

        gridLayout->addWidget(comboBox_key, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        comboBox_forward = new QComboBox(widget);
        comboBox_forward->addItem(QString());
        comboBox_forward->addItem(QString());
        comboBox_forward->setObjectName("comboBox_forward");
        comboBox_forward->setStyleSheet(QString::fromUtf8("*{\n"
"min-width:100px;\n"
"}"));

        gridLayout->addWidget(comboBox_forward, 0, 1, 1, 2);

        widget_edit = new QWidget(widget);
        widget_edit->setObjectName("widget_edit");
        widget_edit->setMinimumSize(QSize(0, 100));
        gridLayout_2 = new QGridLayout(widget_edit);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        pushButton_yes = new QPushButton(widget_edit);
        pushButton_yes->setObjectName("pushButton_yes");

        gridLayout_2->addWidget(pushButton_yes, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        lineEdit_name = new QLineEdit(widget_edit);
        lineEdit_name->setObjectName("lineEdit_name");

        gridLayout_2->addWidget(lineEdit_name, 0, 0, 1, 3);


        gridLayout->addWidget(widget_edit, 2, 0, 1, 3);


        verticalLayout->addWidget(widget);

        scrollArea = new QScrollArea(table);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setMaximumSize(QSize(16777215, 16777215));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 338, 264));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 0));
        scrollAreaWidgetContents->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_music = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_music->setSpacing(6);
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
        pushButton_search->setText(QCoreApplication::translate("table", "\346\220\234\347\264\242", nullptr));
        comboBox_key->setItemText(0, QCoreApplication::translate("table", "\344\275\234\350\200\205", nullptr));
        comboBox_key->setItemText(1, QCoreApplication::translate("table", "\346\240\207\351\242\230", nullptr));
        comboBox_key->setItemText(2, QCoreApplication::translate("table", "\344\270\223\350\276\221", nullptr));
        comboBox_key->setItemText(3, QCoreApplication::translate("table", "\346\222\255\346\224\276\346\254\241\346\225\260", nullptr));
        comboBox_key->setItemText(4, QCoreApplication::translate("table", "\345\226\234\347\210\261\347\250\213\345\272\246", nullptr));
        comboBox_key->setItemText(5, QCoreApplication::translate("table", "\347\274\226\350\276\221\346\227\245\346\234\237", nullptr));

        comboBox_forward->setItemText(0, QCoreApplication::translate("table", "\351\231\215\345\272\217", nullptr));
        comboBox_forward->setItemText(1, QCoreApplication::translate("table", "\345\215\207\345\272\217", nullptr));

        pushButton_yes->setText(QCoreApplication::translate("table", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class table: public Ui_table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_H
