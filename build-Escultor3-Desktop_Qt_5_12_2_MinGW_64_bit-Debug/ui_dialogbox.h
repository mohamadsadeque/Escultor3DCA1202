/********************************************************************************
** Form generated from reading UI file 'dialogbox.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
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

QT_BEGIN_NAMESPACE

class Ui_DialogBox
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QRadioButton *radioButtonCut;
    QRadioButton *radioButtonPut;

    void setupUi(QDialog *DialogBox)
    {
        if (DialogBox->objectName().isEmpty())
            DialogBox->setObjectName(QString::fromUtf8("DialogBox"));
        DialogBox->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogBox);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
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
        radioButtonPut->setGeometry(QRect(40, 60, 121, 41));
        radioButtonPut->setFont(font1);

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
    } // retranslateUi

};

namespace Ui {
    class DialogBox: public Ui_DialogBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGBOX_H
