/********************************************************************************
** Form generated from reading UI file 'dialogvoxel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGVOXEL_H
#define UI_DIALOGVOXEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_DialogVoxel
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;

    void setupUi(QDialog *DialogVoxel)
    {
        if (DialogVoxel->objectName().isEmpty())
            DialogVoxel->setObjectName(QString::fromUtf8("DialogVoxel"));
        DialogVoxel->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogVoxel);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(DialogVoxel);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 221, 31));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        radioButton_2 = new QRadioButton(DialogVoxel);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(220, 110, 121, 41));
        QFont font1;
        font1.setPointSize(12);
        radioButton_2->setFont(font1);
        radioButton = new QRadioButton(DialogVoxel);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(70, 110, 121, 41));
        radioButton->setFont(font1);

        retranslateUi(DialogVoxel);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogVoxel, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogVoxel, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogVoxel);
    } // setupUi

    void retranslateUi(QDialog *DialogVoxel)
    {
        DialogVoxel->setWindowTitle(QApplication::translate("DialogVoxel", "Dialog", nullptr));
        label->setText(QApplication::translate("DialogVoxel", "Forma: Voxel", nullptr));
        radioButton_2->setText(QApplication::translate("DialogVoxel", "Remover", nullptr));
        radioButton->setText(QApplication::translate("DialogVoxel", "Inserir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogVoxel: public Ui_DialogVoxel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGVOXEL_H
