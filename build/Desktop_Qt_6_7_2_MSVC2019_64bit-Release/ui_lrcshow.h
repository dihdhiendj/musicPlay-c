/********************************************************************************
** Form generated from reading UI file 'lrcshow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LRCSHOW_H
#define UI_LRCSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LrcShow
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *show;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_tool;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_lock;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_up;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_play;
    QPushButton *pushButton_down;
    QPushButton *pushButton_lock;
    QPushButton *pushButton_seit;
    QPushButton *pushButton_dic;
    QPushButton *pushButton_alone;
    QPushButton *pushButton_hide;
    QPushButton *pushButton_unlock;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_main;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_level;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelNow;
    QLabel *labelDown;
    QWidget *widget_erect;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelNow_2;
    QLabel *labelDown_2;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *LrcShow)
    {
        if (LrcShow->objectName().isEmpty())
            LrcShow->setObjectName("LrcShow");
        LrcShow->resize(765, 196);
        LrcShow->setStyleSheet(QString::fromUtf8("#show{\n"
"border-radius:15px;\n"
"}\n"
"QLabel{\n"
"font: 40pt \"Microsoft YaHei UI\";\n"
"}\n"
"#LrcShow{\n"
"background-color: rgba(0,0,0,128); \n"
"}\n"
"*{\n"
"border: 0px\357\274\233\n"
"}"));
        verticalLayout = new QVBoxLayout(LrcShow);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        show = new QWidget(LrcShow);
        show->setObjectName("show");
        verticalLayout_2 = new QVBoxLayout(show);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_tool = new QWidget(show);
        widget_tool->setObjectName("widget_tool");
        widget_tool->setStyleSheet(QString::fromUtf8("#widget_tool{\n"
"max-height:50px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget_tool);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(310, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget_lock = new QWidget(widget_tool);
        widget_lock->setObjectName("widget_lock");
        horizontalLayout_2 = new QHBoxLayout(widget_lock);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_up = new QPushButton(widget_lock);
        pushButton_up->setObjectName("pushButton_up");

        horizontalLayout_2->addWidget(pushButton_up);

        pushButton_stop = new QPushButton(widget_lock);
        pushButton_stop->setObjectName("pushButton_stop");

        horizontalLayout_2->addWidget(pushButton_stop);

        pushButton_play = new QPushButton(widget_lock);
        pushButton_play->setObjectName("pushButton_play");

        horizontalLayout_2->addWidget(pushButton_play);

        pushButton_down = new QPushButton(widget_lock);
        pushButton_down->setObjectName("pushButton_down");

        horizontalLayout_2->addWidget(pushButton_down);

        pushButton_lock = new QPushButton(widget_lock);
        pushButton_lock->setObjectName("pushButton_lock");

        horizontalLayout_2->addWidget(pushButton_lock);

        pushButton_seit = new QPushButton(widget_lock);
        pushButton_seit->setObjectName("pushButton_seit");

        horizontalLayout_2->addWidget(pushButton_seit);

        pushButton_dic = new QPushButton(widget_lock);
        pushButton_dic->setObjectName("pushButton_dic");

        horizontalLayout_2->addWidget(pushButton_dic);

        pushButton_alone = new QPushButton(widget_lock);
        pushButton_alone->setObjectName("pushButton_alone");

        horizontalLayout_2->addWidget(pushButton_alone);

        pushButton_hide = new QPushButton(widget_lock);
        pushButton_hide->setObjectName("pushButton_hide");

        horizontalLayout_2->addWidget(pushButton_hide);


        horizontalLayout->addWidget(widget_lock);

        pushButton_unlock = new QPushButton(widget_tool);
        pushButton_unlock->setObjectName("pushButton_unlock");

        horizontalLayout->addWidget(pushButton_unlock);

        horizontalSpacer_2 = new QSpacerItem(310, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widget_tool);

        widget_main = new QWidget(show);
        widget_main->setObjectName("widget_main");
        horizontalLayout_3 = new QHBoxLayout(widget_main);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        widget_level = new QWidget(widget_main);
        widget_level->setObjectName("widget_level");
        verticalLayout_3 = new QVBoxLayout(widget_level);
        verticalLayout_3->setObjectName("verticalLayout_3");
        labelNow = new QLabel(widget_level);
        labelNow->setObjectName("labelNow");
        labelNow->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        labelNow->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(labelNow);

        labelDown = new QLabel(widget_level);
        labelDown->setObjectName("labelDown");
        labelDown->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 255);"));
        labelDown->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(labelDown);


        horizontalLayout_3->addWidget(widget_level);

        widget_erect = new QWidget(widget_main);
        widget_erect->setObjectName("widget_erect");
        horizontalLayout_4 = new QHBoxLayout(widget_erect);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        labelNow_2 = new QLabel(widget_erect);
        labelNow_2->setObjectName("labelNow_2");
        labelNow_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        labelNow_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(labelNow_2);

        labelDown_2 = new QLabel(widget_erect);
        labelDown_2->setObjectName("labelDown_2");
        labelDown_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 255);"));
        labelDown_2->setAlignment(Qt::AlignCenter);
        labelDown_2->setWordWrap(true);

        horizontalLayout_4->addWidget(labelDown_2);


        horizontalLayout_3->addWidget(widget_erect);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_2->addWidget(widget_main);


        verticalLayout->addWidget(show);


        retranslateUi(LrcShow);

        QMetaObject::connectSlotsByName(LrcShow);
    } // setupUi

    void retranslateUi(QWidget *LrcShow)
    {
        LrcShow->setWindowTitle(QCoreApplication::translate("LrcShow", "Form", nullptr));
        pushButton_up->setText(QCoreApplication::translate("LrcShow", "Up", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("LrcShow", "Stop", nullptr));
        pushButton_play->setText(QCoreApplication::translate("LrcShow", "Play", nullptr));
        pushButton_down->setText(QCoreApplication::translate("LrcShow", "Down", nullptr));
        pushButton_lock->setText(QCoreApplication::translate("LrcShow", "Lock", nullptr));
        pushButton_seit->setText(QCoreApplication::translate("LrcShow", "Seit", nullptr));
        pushButton_dic->setText(QCoreApplication::translate("LrcShow", "dic", nullptr));
        pushButton_alone->setText(QCoreApplication::translate("LrcShow", "alone", nullptr));
        pushButton_hide->setText(QCoreApplication::translate("LrcShow", "hide", nullptr));
        pushButton_unlock->setText(QCoreApplication::translate("LrcShow", "Unlock", nullptr));
        labelNow->setText(QCoreApplication::translate("LrcShow", "TextLabel", nullptr));
        labelDown->setText(QCoreApplication::translate("LrcShow", "TextLabel", nullptr));
        labelNow_2->setText(QCoreApplication::translate("LrcShow", "TextLabel", nullptr));
        labelDown_2->setText(QCoreApplication::translate("LrcShow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LrcShow: public Ui_LrcShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LRCSHOW_H
