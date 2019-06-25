/********************************************************************************
** Form generated from reading UI file 'dialogbox.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGBOX_H
#define UI_DIALOGBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DialogBox
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QRadioButton *radioButtonCut;
    QRadioButton *radioButtonPut;
    QSpinBox *spinLargura;
    QSpinBox *spinProfundidade;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *spinAltura;

    void setupUi(QDialog *DialogBox)
    {
        if (DialogBox->objectName().isEmpty())
            DialogBox->setObjectName(QString::fromUtf8("DialogBox"));
        DialogBox->resize(400, 379);
        buttonBox = new QDialogButtonBox(DialogBox);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 300, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(DialogBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 221, 31));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        radioButtonCut = new QRadioButton(DialogBox);
        radioButtonCut->setObjectName(QString::fromUtf8("radioButtonCut"));
        radioButtonCut->setGeometry(QRect(190, 60, 121, 41));
        QFont font1;
        font1.setPointSize(12);
        radioButtonCut->setFont(font1);
        radioButtonPut = new QRadioButton(DialogBox);
        radioButtonPut->setObjectName(QString::fromUtf8("radioButtonPut"));
        radioButtonPut->setGeometry(QRect(30, 70, 121, 41));
        radioButtonPut->setFont(font1);
        spinLargura = new QSpinBox(DialogBox);
        spinLargura->setObjectName(QString::fromUtf8("spinLargura"));
        spinLargura->setGeometry(QRect(180, 120, 141, 29));
        spinProfundidade = new QSpinBox(DialogBox);
        spinProfundidade->setObjectName(QString::fromUtf8("spinProfundidade"));
        spinProfundidade->setGeometry(QRect(180, 170, 141, 29));
        label_2 = new QLabel(DialogBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 120, 221, 31));
        label_2->setFont(font);
        label_3 = new QLabel(DialogBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 170, 221, 31));
        label_3->setFont(font);
        label_4 = new QLabel(DialogBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 220, 221, 31));
        label_4->setFont(font);
        spinAltura = new QSpinBox(DialogBox);
        spinAltura->setObjectName(QString::fromUtf8("spinAltura"));
        spinAltura->setGeometry(QRect(180, 220, 141, 29));

        retranslateUi(DialogBox);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogBox, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogBox, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogBox);
    } // setupUi

    void retranslateUi(QDialog *DialogBox)
    {
        DialogBox->setWindowTitle(QApplication::translate("DialogBox", "Dialog", nullptr));
        label->setText(QApplication::translate("DialogBox", "Forma: Caixa", nullptr));
        radioButtonCut->setText(QApplication::translate("DialogBox", "Remover", nullptr));
        radioButtonPut->setText(QApplication::translate("DialogBox", "Inserir", nullptr));
        label_2->setText(QApplication::translate("DialogBox", "Largura:", nullptr));
        label_3->setText(QApplication::translate("DialogBox", "Profundidade:", nullptr));
        label_4->setText(QApplication::translate("DialogBox", "Altura", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogBox: public Ui_DialogBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGBOX_H
