/********************************************************************************
** Form generated from reading UI file 'qpixmapshow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QPIXMAPSHOW_H
#define UI_QPIXMAPSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QPixmapShow
{
public:

    void setupUi(QWidget *QPixmapShow)
    {
        if (QPixmapShow->objectName().isEmpty())
            QPixmapShow->setObjectName("QPixmapShow");
        QPixmapShow->resize(400, 300);
        QPixmapShow->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(QPixmapShow);

        QMetaObject::connectSlotsByName(QPixmapShow);
    } // setupUi

    void retranslateUi(QWidget *QPixmapShow)
    {
        QPixmapShow->setWindowTitle(QCoreApplication::translate("QPixmapShow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QPixmapShow: public Ui_QPixmapShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QPIXMAPSHOW_H
