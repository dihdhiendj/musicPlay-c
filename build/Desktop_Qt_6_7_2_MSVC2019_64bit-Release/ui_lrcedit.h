/********************************************************************************
** Form generated from reading UI file 'lrcedit.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LRCEDIT_H
#define UI_LRCEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lrcEdit
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_show;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_tool;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_down;
    QPushButton *pushButton_addTime;
    QPushButton *pushButton_deleteTime;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_yes;
    QPushButton *pushButton_no;
    QScrollArea *scrollArea_lrcs;
    QWidget *scrollAreaWidgetContents_lrcs;
    QVBoxLayout *verticalLayout_lines;
    QPlainTextEdit *plainTextEdit_lrcs;

    void setupUi(QWidget *lrcEdit)
    {
        if (lrcEdit->objectName().isEmpty())
            lrcEdit->setObjectName("lrcEdit");
        lrcEdit->resize(636, 510);
        lrcEdit->setStyleSheet(QString::fromUtf8("#widget{\n"
"background-color: rgb(0, 0, 0);\n"
"border-radius:15px;\n"
"}\n"
"QScrollBar {width:0px;}\n"
"QScrollBar {height:0px;}\n"
"#widget_show{\n"
"background-color: rgba(0,0,0,128); \n"
"}\n"
"QMenu\n"
"{\n"
"background-color: rgba(0,0,0,128);\n"
"}\n"
"*{\n"
"font: 18pt \"\345\215\216\346\226\207\344\273\277\345\256\213\";\n"
"border:none;\n"
"color: rgb(255, 255, 255);\n"
"background-color: transparent;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background-color: rgb(131, 197, 197);\n"
"border-radius:5px;\n"
"border:1px solid rgb(85, 255, 255);\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(lrcEdit);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_show = new QWidget(lrcEdit);
        widget_show->setObjectName("widget_show");
        verticalLayout_4 = new QVBoxLayout(widget_show);
        verticalLayout_4->setObjectName("verticalLayout_4");
        widget_tool = new QWidget(widget_show);
        widget_tool->setObjectName("widget_tool");
        horizontalLayout = new QHBoxLayout(widget_tool);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_down = new QPushButton(widget_tool);
        pushButton_down->setObjectName("pushButton_down");
        pushButton_down->setStyleSheet(QString::fromUtf8("image: url(:/down_y.png);"));

        horizontalLayout->addWidget(pushButton_down);

        pushButton_addTime = new QPushButton(widget_tool);
        pushButton_addTime->setObjectName("pushButton_addTime");
        pushButton_addTime->setStyleSheet(QString::fromUtf8("image: url(:/move.png);"));

        horizontalLayout->addWidget(pushButton_addTime);

        pushButton_deleteTime = new QPushButton(widget_tool);
        pushButton_deleteTime->setObjectName("pushButton_deleteTime");
        pushButton_deleteTime->setStyleSheet(QString::fromUtf8("image: url(:/min.png);"));

        horizontalLayout->addWidget(pushButton_deleteTime);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_yes = new QPushButton(widget_tool);
        pushButton_yes->setObjectName("pushButton_yes");
        pushButton_yes->setStyleSheet(QString::fromUtf8("image: url(:/yes_red.png);"));

        horizontalLayout->addWidget(pushButton_yes);

        pushButton_no = new QPushButton(widget_tool);
        pushButton_no->setObjectName("pushButton_no");
        pushButton_no->setStyleSheet(QString::fromUtf8("image: url(:/close.png);"));

        horizontalLayout->addWidget(pushButton_no);


        verticalLayout_4->addWidget(widget_tool);

        scrollArea_lrcs = new QScrollArea(widget_show);
        scrollArea_lrcs->setObjectName("scrollArea_lrcs");
        scrollArea_lrcs->setWidgetResizable(true);
        scrollAreaWidgetContents_lrcs = new QWidget();
        scrollAreaWidgetContents_lrcs->setObjectName("scrollAreaWidgetContents_lrcs");
        scrollAreaWidgetContents_lrcs->setGeometry(QRect(0, 0, 618, 441));
        verticalLayout_lines = new QVBoxLayout(scrollAreaWidgetContents_lrcs);
        verticalLayout_lines->setObjectName("verticalLayout_lines");
        plainTextEdit_lrcs = new QPlainTextEdit(scrollAreaWidgetContents_lrcs);
        plainTextEdit_lrcs->setObjectName("plainTextEdit_lrcs");

        verticalLayout_lines->addWidget(plainTextEdit_lrcs);

        scrollArea_lrcs->setWidget(scrollAreaWidgetContents_lrcs);

        verticalLayout_4->addWidget(scrollArea_lrcs);


        verticalLayout->addWidget(widget_show);


        retranslateUi(lrcEdit);

        QMetaObject::connectSlotsByName(lrcEdit);
    } // setupUi

    void retranslateUi(QWidget *lrcEdit)
    {
        lrcEdit->setWindowTitle(QCoreApplication::translate("lrcEdit", "\346\255\214\350\257\215\347\274\226\350\276\221\345\231\250", nullptr));
        pushButton_down->setText(QString());
        pushButton_addTime->setText(QString());
        pushButton_deleteTime->setText(QString());
        pushButton_yes->setText(QString());
        pushButton_no->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class lrcEdit: public Ui_lrcEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LRCEDIT_H
