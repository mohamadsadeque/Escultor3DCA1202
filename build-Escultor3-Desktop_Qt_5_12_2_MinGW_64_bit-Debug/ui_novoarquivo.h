/********************************************************************************
** Form generated from reading UI file 'novoarquivo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOVOARQUIVO_H
#define UI_NOVOARQUIVO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_NovoArquivo
{
public:
    QDialogButtonBox *buttonBox;
    QSpinBox *spinBox_y;
    QLabel *label_3;
    QSpinBox *spinBox_x;
    QLabel *label;
    QSpinBox *spinBox_z;
    QLabel *label_2;

    void setupUi(QDialog *NovoArquivo)
    {
        if (NovoArquivo->objectName().isEmpty())
            NovoArquivo->setObjectName(QString::fromUtf8("NovoArquivo"));
        NovoArquivo->resize(400, 300);
        buttonBox = new QDialogButtonBox(NovoArquivo);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        spinBox_y = new QSpinBox(NovoArquivo);
        spinBox_y->setObjectName(QString::fromUtf8("spinBox_y"));
        spinBox_y->setGeometry(QRect(260, 100, 91, 31));
        QFont font;
        font.setPointSize(20);
        spinBox_y->setFont(font);
        label_3 = new QLabel(NovoArquivo);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 150, 191, 21));
        QFont font1;
        font1.setPointSize(16);
        label_3->setFont(font1);
        spinBox_x = new QSpinBox(NovoArquivo);
        spinBox_x->setObjectName(QString::fromUtf8("spinBox_x"));
        spinBox_x->setGeometry(QRect(260, 60, 91, 31));
        spinBox_x->setFont(font);
        label = new QLabel(NovoArquivo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 70, 191, 21));
        label->setFont(font1);
        spinBox_z = new QSpinBox(NovoArquivo);
        spinBox_z->setObjectName(QString::fromUtf8("spinBox_z"));
        spinBox_z->setGeometry(QRect(260, 140, 91, 31));
        spinBox_z->setFont(font);
        label_2 = new QLabel(NovoArquivo);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 110, 191, 21));
        label_2->setFont(font1);

        retranslateUi(NovoArquivo);
        QObject::connect(buttonBox, SIGNAL(accepted()), NovoArquivo, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NovoArquivo, SLOT(reject()));

        QMetaObject::connectSlotsByName(NovoArquivo);
    } // setupUi

    void retranslateUi(QDialog *NovoArquivo)
    {
        NovoArquivo->setWindowTitle(QApplication::translate("NovoArquivo", "Dialog", nullptr));
        label_3->setText(QApplication::translate("NovoArquivo", "Tamanho do Eixo Z:", nullptr));
        label->setText(QApplication::translate("NovoArquivo", "Tamanho do Eixo X:", nullptr));
        label_2->setText(QApplication::translate("NovoArquivo", "Tamanho do Eixo Y:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NovoArquivo: public Ui_NovoArquivo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOVOARQUIVO_H
