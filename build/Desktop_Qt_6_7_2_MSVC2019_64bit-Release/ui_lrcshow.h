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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <lrcshow.h>

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
    QPushButton *pushButton_alone;
    QPushButton *pushButton_hide;
    QPushButton *pushButton_unlock;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_level;
    QVBoxLayout *verticalLayout_3;
    lrc_line *labelNow;
    lrc_line *labelDown;

    void setupUi(QWidget *LrcShow)
    {
        if (LrcShow->objectName().isEmpty())
            LrcShow->setObjectName("LrcShow");
        LrcShow->resize(568, 110);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LrcShow->sizePolicy().hasHeightForWidth());
        LrcShow->setSizePolicy(sizePolicy);
        LrcShow->setStyleSheet(QString::fromUtf8("#show{\n"
"border-radius:15px;\n"
"}\n"
"#LrcShow{\n"
"background-color: rgba(0,0,0,128); \n"
"}\n"
"*{\n"
"border: 0px\357\274\233\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background-color: rgb(131, 197, 197);\n"
"border-radius:5px;\n"
"border:1px solid rgb(85, 255, 255);\n"
"}"));
        verticalLayout = new QVBoxLayout(LrcShow);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(90, 30, 90, 30);
        show = new QWidget(LrcShow);
        show->setObjectName("show");
        sizePolicy.setHeightForWidth(show->sizePolicy().hasHeightForWidth());
        show->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(show);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_tool = new QWidget(show);
        widget_tool->setObjectName("widget_tool");
        sizePolicy.setHeightForWidth(widget_tool->sizePolicy().hasHeightForWidth());
        widget_tool->setSizePolicy(sizePolicy);
        widget_tool->setStyleSheet(QString::fromUtf8("#widget_tool{\n"
"max-height:50px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget_tool);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget_lock = new QWidget(widget_tool);
        widget_lock->setObjectName("widget_lock");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_lock->sizePolicy().hasHeightForWidth());
        widget_lock->setSizePolicy(sizePolicy1);
        horizontalLayout_2 = new QHBoxLayout(widget_lock);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_up = new QPushButton(widget_lock);
        pushButton_up->setObjectName("pushButton_up");
        pushButton_up->setStyleSheet(QString::fromUtf8("image: url(:/left.png);"));

        horizontalLayout_2->addWidget(pushButton_up);

        pushButton_stop = new QPushButton(widget_lock);
        pushButton_stop->setObjectName("pushButton_stop");
        pushButton_stop->setStyleSheet(QString::fromUtf8("image: url(:/stop.png);"));

        horizontalLayout_2->addWidget(pushButton_stop);

        pushButton_play = new QPushButton(widget_lock);
        pushButton_play->setObjectName("pushButton_play");
        pushButton_play->setStyleSheet(QString::fromUtf8("image: url(:/play.png);"));

        horizontalLayout_2->addWidget(pushButton_play);

        pushButton_down = new QPushButton(widget_lock);
        pushButton_down->setObjectName("pushButton_down");
        pushButton_down->setStyleSheet(QString::fromUtf8("image: url(:/right.png);"));

        horizontalLayout_2->addWidget(pushButton_down);

        pushButton_lock = new QPushButton(widget_lock);
        pushButton_lock->setObjectName("pushButton_lock");
        pushButton_lock->setStyleSheet(QString::fromUtf8("image: url(:/lock.png);"));

        horizontalLayout_2->addWidget(pushButton_lock);

        pushButton_seit = new QPushButton(widget_lock);
        pushButton_seit->setObjectName("pushButton_seit");
        pushButton_seit->setStyleSheet(QString::fromUtf8("image: url(:/seit.png);"));

        horizontalLayout_2->addWidget(pushButton_seit);

        pushButton_alone = new QPushButton(widget_lock);
        pushButton_alone->setObjectName("pushButton_alone");
        pushButton_alone->setStyleSheet(QString::fromUtf8("image: url(:/alone.png);"));

        horizontalLayout_2->addWidget(pushButton_alone);

        pushButton_hide = new QPushButton(widget_lock);
        pushButton_hide->setObjectName("pushButton_hide");
        pushButton_hide->setStyleSheet(QString::fromUtf8("image: url(:/lrc.png);"));

        horizontalLayout_2->addWidget(pushButton_hide);


        horizontalLayout->addWidget(widget_lock);

        pushButton_unlock = new QPushButton(widget_tool);
        pushButton_unlock->setObjectName("pushButton_unlock");
        pushButton_unlock->setStyleSheet(QString::fromUtf8("image: url(:/lock.png);"));

        horizontalLayout->addWidget(pushButton_unlock);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widget_tool);


        verticalLayout->addWidget(show);

        widget_level = new QWidget(LrcShow);
        widget_level->setObjectName("widget_level");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_level->sizePolicy().hasHeightForWidth());
        widget_level->setSizePolicy(sizePolicy2);
        verticalLayout_3 = new QVBoxLayout(widget_level);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        labelNow = new lrc_line(widget_level);
        labelNow->setObjectName("labelNow");
        sizePolicy.setHeightForWidth(labelNow->sizePolicy().hasHeightForWidth());
        labelNow->setSizePolicy(sizePolicy);
        labelNow->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        labelNow->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(labelNow);

        labelDown = new lrc_line(widget_level);
        labelDown->setObjectName("labelDown");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelDown->sizePolicy().hasHeightForWidth());
        labelDown->setSizePolicy(sizePolicy3);
        labelDown->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 255);"));
        labelDown->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(labelDown);


        verticalLayout->addWidget(widget_level);


        retranslateUi(LrcShow);

        QMetaObject::connectSlotsByName(LrcShow);
    } // setupUi

    void retranslateUi(QWidget *LrcShow)
    {
        LrcShow->setWindowTitle(QCoreApplication::translate("LrcShow", "Form", nullptr));
        pushButton_up->setText(QString());
        pushButton_stop->setText(QString());
        pushButton_play->setText(QString());
        pushButton_down->setText(QString());
        pushButton_lock->setText(QString());
        pushButton_seit->setText(QString());
        pushButton_alone->setText(QString());
        pushButton_hide->setText(QString());
        pushButton_unlock->setText(QString());
        labelNow->setText(QCoreApplication::translate("LrcShow", "TextLabel", nullptr));
        labelDown->setText(QCoreApplication::translate("LrcShow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LrcShow: public Ui_LrcShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LRCSHOW_H
