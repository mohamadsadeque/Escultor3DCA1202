/********************************************************************************
** Form generated from reading UI file 'dialogrgb.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGRGB_H
#define UI_DIALOGRGB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_DialogRGB
{
public:
    QDialogButtonBox *buttonBox;
    QLCDNumber *lcdNumber;
    QLabel *label_3;
    QSlider *horizontalSliderB;
    QLabel *label_2;
    QLabel *label;
    QSlider *horizontalSliderG;
    QLCDNumber *lcdNumber_2;
    QSlider *horizontalSliderR;
    QLCDNumber *lcdNumber_3;

    void setupUi(QDialog *DialogRGB)
    {
        if (DialogRGB->objectName().isEmpty())
            DialogRGB->setObjectName(QString::fromUtf8("DialogRGB"));
        DialogRGB->resize(371, 242);
        buttonBox = new QDialogButtonBox(DialogRGB);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 190, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lcdNumber = new QLCDNumber(DialogRGB);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(230, 52, 64, 23));
        label_3 = new QLabel(DialogRGB);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(45, 148, 7, 23));
        horizontalSliderB = new QSlider(DialogRGB);
        horizontalSliderB->setObjectName(QString::fromUtf8("horizontalSliderB"));
        horizontalSliderB->setGeometry(QRect(58, 148, 166, 22));
        horizontalSliderB->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(DialogRGB);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(45, 100, 7, 23));
        label = new QLabel(DialogRGB);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(45, 52, 7, 23));
        horizontalSliderG = new QSlider(DialogRGB);
        horizontalSliderG->setObjectName(QString::fromUtf8("horizontalSliderG"));
        horizontalSliderG->setGeometry(QRect(58, 100, 166, 22));
        horizontalSliderG->setOrientation(Qt::Horizontal);
        lcdNumber_2 = new QLCDNumber(DialogRGB);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(230, 100, 64, 23));
        horizontalSliderR = new QSlider(DialogRGB);
        horizontalSliderR->setObjectName(QString::fromUtf8("horizontalSliderR"));
        horizontalSliderR->setGeometry(QRect(58, 52, 166, 22));
        horizontalSliderR->setOrientation(Qt::Horizontal);
        lcdNumber_3 = new QLCDNumber(DialogRGB);
        lcdNumber_3->setObjectName(QString::fromUtf8("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(230, 148, 64, 23));

        retranslateUi(DialogRGB);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogRGB, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogRGB, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogRGB);
    } // setupUi

    void retranslateUi(QDialog *DialogRGB)
    {
        DialogRGB->setWindowTitle(QApplication::translate("DialogRGB", "Dialog", nullptr));
        label_3->setText(QApplication::translate("DialogRGB", "B", nullptr));
        label_2->setText(QApplication::translate("DialogRGB", "G", nullptr));
        label->setText(QApplication::translate("DialogRGB", "R", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogRGB: public Ui_DialogRGB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGRGB_H
