/********************************************************************************
** Form generated from reading UI file 'dialogsphere.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSPHERE_H
#define UI_DIALOGSPHERE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DialogSphere
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label_2;
    QSpinBox *spinBox;

    void setupUi(QDialog *DialogSphere)
    {
        if (DialogSphere->objectName().isEmpty())
            DialogSphere->setObjectName(QString::fromUtf8("DialogSphere"));
        DialogSphere->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogSphere);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(DialogSphere);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 171, 31));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        radioButton = new QRadioButton(DialogSphere);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(50, 60, 121, 41));
        QFont font1;
        font1.setPointSize(12);
        radioButton->setFont(font1);
        radioButton_2 = new QRadioButton(DialogSphere);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(200, 60, 121, 41));
        radioButton_2->setFont(font1);
        label_2 = new QLabel(DialogSphere);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 120, 51, 41));
        label_2->setFont(font);
        spinBox = new QSpinBox(DialogSphere);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(110, 130, 61, 21));
        spinBox->setFont(font);

        retranslateUi(DialogSphere);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogSphere, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogSphere, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogSphere);
    } // setupUi

    void retranslateUi(QDialog *DialogSphere)
    {
        DialogSphere->setWindowTitle(QApplication::translate("DialogSphere", "Dialog", nullptr));
        label->setText(QApplication::translate("DialogSphere", "Forma: Esfera", nullptr));
        radioButton->setText(QApplication::translate("DialogSphere", "Inserir", nullptr));
        radioButton_2->setText(QApplication::translate("DialogSphere", "Remover", nullptr));
        label_2->setText(QApplication::translate("DialogSphere", "Raio:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSphere: public Ui_DialogSphere {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSPHERE_H
