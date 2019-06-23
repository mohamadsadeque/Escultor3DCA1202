/********************************************************************************
** Form generated from reading UI file 'dialogellipsoid.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGELLIPSOID_H
#define UI_DIALOGELLIPSOID_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DialogEllipsoid
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QRadioButton *radioButtonCut;
    QRadioButton *radioButtonPut;
    QLabel *label_2;
    QSpinBox *spinBoxRaioX;
    QLabel *label_3;
    QSpinBox *spinBoxRaioY;
    QLabel *label_4;
    QSpinBox *spinBoxRaioZ;

    void setupUi(QDialog *DialogEllipsoid)
    {
        if (DialogEllipsoid->objectName().isEmpty())
            DialogEllipsoid->setObjectName(QString::fromUtf8("DialogEllipsoid"));
        DialogEllipsoid->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogEllipsoid);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(DialogEllipsoid);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 221, 31));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        radioButtonCut = new QRadioButton(DialogEllipsoid);
        radioButtonCut->setObjectName(QString::fromUtf8("radioButtonCut"));
        radioButtonCut->setGeometry(QRect(210, 60, 121, 41));
        QFont font1;
        font1.setPointSize(12);
        radioButtonCut->setFont(font1);
        radioButtonPut = new QRadioButton(DialogEllipsoid);
        radioButtonPut->setObjectName(QString::fromUtf8("radioButtonPut"));
        radioButtonPut->setGeometry(QRect(60, 60, 121, 41));
        radioButtonPut->setFont(font1);
        label_2 = new QLabel(DialogEllipsoid);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 100, 121, 41));
        label_2->setFont(font);
        spinBoxRaioX = new QSpinBox(DialogEllipsoid);
        spinBoxRaioX->setObjectName(QString::fromUtf8("spinBoxRaioX"));
        spinBoxRaioX->setGeometry(QRect(190, 110, 61, 21));
        spinBoxRaioX->setFont(font);
        label_3 = new QLabel(DialogEllipsoid);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 140, 121, 41));
        label_3->setFont(font);
        spinBoxRaioY = new QSpinBox(DialogEllipsoid);
        spinBoxRaioY->setObjectName(QString::fromUtf8("spinBoxRaioY"));
        spinBoxRaioY->setGeometry(QRect(190, 150, 61, 21));
        spinBoxRaioY->setFont(font);
        label_4 = new QLabel(DialogEllipsoid);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 180, 121, 41));
        label_4->setFont(font);
        spinBoxRaioZ = new QSpinBox(DialogEllipsoid);
        spinBoxRaioZ->setObjectName(QString::fromUtf8("spinBoxRaioZ"));
        spinBoxRaioZ->setGeometry(QRect(190, 190, 61, 21));
        spinBoxRaioZ->setFont(font);

        retranslateUi(DialogEllipsoid);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogEllipsoid, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogEllipsoid, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogEllipsoid);
    } // setupUi

    void retranslateUi(QDialog *DialogEllipsoid)
    {
        DialogEllipsoid->setWindowTitle(QApplication::translate("DialogEllipsoid", "Dialog", nullptr));
        label->setText(QApplication::translate("DialogEllipsoid", "Forma: Elips\303\263ide", nullptr));
        radioButtonCut->setText(QApplication::translate("DialogEllipsoid", "Remover", nullptr));
        radioButtonPut->setText(QApplication::translate("DialogEllipsoid", "Inserir", nullptr));
        label_2->setText(QApplication::translate("DialogEllipsoid", "Raio em X:", nullptr));
        label_3->setText(QApplication::translate("DialogEllipsoid", "Raio em Y:", nullptr));
        label_4->setText(QApplication::translate("DialogEllipsoid", "Raio em Z:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogEllipsoid: public Ui_DialogEllipsoid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGELLIPSOID_H
