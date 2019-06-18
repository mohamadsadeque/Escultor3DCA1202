/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <plotter.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNovoArquivo;
    QAction *actionRGB;
    QAction *actionEsfera;
    QAction *actionElipsoide;
    QAction *actionVoxel;
    QAction *actionCaixa;
    QAction *actionSave;
    QAction *actionOpen;
    QWidget *centralWidget;
    QSlider *horizontalSliderPlano;
    Plotter *widgetPlotter;
    QLabel *label;
    QPushButton *pushButtonRefX;
    QPushButton *pushButtonRefY;
    QPushButton *pushButtonRefZ;
    QLCDNumber *lcdNumberX;
    QLabel *label_2;
    QLCDNumber *lcdNumberY;
    QLabel *label_3;
    QLCDNumber *lcdNumber_4;
    QLabel *label_4;
    QLCDNumber *lcdNumber;
    QMenuBar *menuBar;
    QMenu *menuArquivos;
    QMenu *menuEdi_o;
    QMenu *menuFormas;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1578, 997);
        actionNovoArquivo = new QAction(MainWindow);
        actionNovoArquivo->setObjectName(QString::fromUtf8("actionNovoArquivo"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icones/recursos/NovoArquivoIMG.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNovoArquivo->setIcon(icon);
        actionRGB = new QAction(MainWindow);
        actionRGB->setObjectName(QString::fromUtf8("actionRGB"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icones/recursos/RGBIMG.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRGB->setIcon(icon1);
        actionEsfera = new QAction(MainWindow);
        actionEsfera->setObjectName(QString::fromUtf8("actionEsfera"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icones/recursos/sphere.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEsfera->setIcon(icon2);
        actionElipsoide = new QAction(MainWindow);
        actionElipsoide->setObjectName(QString::fromUtf8("actionElipsoide"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icones/recursos/ellipse.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionElipsoide->setIcon(icon3);
        actionVoxel = new QAction(MainWindow);
        actionVoxel->setObjectName(QString::fromUtf8("actionVoxel"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icones/recursos/voxel.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionVoxel->setIcon(icon4);
        actionCaixa = new QAction(MainWindow);
        actionCaixa->setObjectName(QString::fromUtf8("actionCaixa"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icones/recursos/cubo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCaixa->setIcon(icon5);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icones/recursos/save-icon-31.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon6);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icones/recursos/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon7);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalSliderPlano = new QSlider(centralWidget);
        horizontalSliderPlano->setObjectName(QString::fromUtf8("horizontalSliderPlano"));
        horizontalSliderPlano->setGeometry(QRect(20, 70, 131, 41));
        horizontalSliderPlano->setOrientation(Qt::Horizontal);
        widgetPlotter = new Plotter(centralWidget);
        widgetPlotter->setObjectName(QString::fromUtf8("widgetPlotter"));
        widgetPlotter->setGeometry(QRect(360, 80, 1081, 671));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 221, 41));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        pushButtonRefX = new QPushButton(centralWidget);
        pushButtonRefX->setObjectName(QString::fromUtf8("pushButtonRefX"));
        pushButtonRefX->setGeometry(QRect(130, 30, 31, 23));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        pushButtonRefX->setFont(font1);
        pushButtonRefY = new QPushButton(centralWidget);
        pushButtonRefY->setObjectName(QString::fromUtf8("pushButtonRefY"));
        pushButtonRefY->setGeometry(QRect(170, 30, 31, 23));
        pushButtonRefY->setFont(font1);
        pushButtonRefZ = new QPushButton(centralWidget);
        pushButtonRefZ->setObjectName(QString::fromUtf8("pushButtonRefZ"));
        pushButtonRefZ->setGeometry(QRect(210, 30, 31, 23));
        pushButtonRefZ->setFont(font1);
        lcdNumberX = new QLCDNumber(centralWidget);
        lcdNumberX->setObjectName(QString::fromUtf8("lcdNumberX"));
        lcdNumberX->setGeometry(QRect(430, 20, 111, 51));
        QFont font2;
        font2.setPointSize(16);
        lcdNumberX->setFont(font2);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(380, 20, 31, 41));
        label_2->setFont(font);
        lcdNumberY = new QLCDNumber(centralWidget);
        lcdNumberY->setObjectName(QString::fromUtf8("lcdNumberY"));
        lcdNumberY->setGeometry(QRect(720, 20, 111, 51));
        lcdNumberY->setFont(font2);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(670, 20, 31, 41));
        label_3->setFont(font);
        lcdNumber_4 = new QLCDNumber(centralWidget);
        lcdNumber_4->setObjectName(QString::fromUtf8("lcdNumber_4"));
        lcdNumber_4->setGeometry(QRect(1020, 20, 111, 51));
        lcdNumber_4->setFont(font2);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(970, 20, 31, 41));
        label_4->setFont(font);
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(180, 70, 141, 51));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1578, 21));
        menuArquivos = new QMenu(menuBar);
        menuArquivos->setObjectName(QString::fromUtf8("menuArquivos"));
        menuEdi_o = new QMenu(menuBar);
        menuEdi_o->setObjectName(QString::fromUtf8("menuEdi_o"));
        menuFormas = new QMenu(menuEdi_o);
        menuFormas->setObjectName(QString::fromUtf8("menuFormas"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArquivos->menuAction());
        menuBar->addAction(menuEdi_o->menuAction());
        menuArquivos->addAction(actionNovoArquivo);
        menuArquivos->addAction(actionOpen);
        menuArquivos->addAction(actionSave);
        menuEdi_o->addAction(menuFormas->menuAction());
        menuEdi_o->addAction(actionRGB);
        menuFormas->addAction(actionEsfera);
        menuFormas->addAction(actionElipsoide);
        menuFormas->addAction(actionVoxel);
        menuFormas->addAction(actionCaixa);
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionNovoArquivo);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionRGB);
        mainToolBar->addAction(actionEsfera);
        mainToolBar->addAction(actionElipsoide);
        mainToolBar->addAction(actionVoxel);
        mainToolBar->addAction(actionCaixa);

        retranslateUi(MainWindow);
        QObject::connect(widgetPlotter, SIGNAL(moveX(int)), lcdNumberX, SLOT(display(int)));
        QObject::connect(widgetPlotter, SIGNAL(moveY(int)), lcdNumberY, SLOT(display(int)));
        QObject::connect(widgetPlotter, SIGNAL(moveZ(int)), lcdNumber_4, SLOT(display(int)));
        QObject::connect(horizontalSliderPlano, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNovoArquivo->setText(QApplication::translate("MainWindow", "NovoArquivo", nullptr));
        actionRGB->setText(QApplication::translate("MainWindow", "Cor", nullptr));
        actionEsfera->setText(QApplication::translate("MainWindow", "Esfera", nullptr));
        actionElipsoide->setText(QApplication::translate("MainWindow", "Elipsoide\n"
"", nullptr));
        actionVoxel->setText(QApplication::translate("MainWindow", "Voxel", nullptr));
        actionCaixa->setText(QApplication::translate("MainWindow", "Caixa", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
        label->setText(QApplication::translate("MainWindow", "Plano:", nullptr));
        pushButtonRefX->setText(QApplication::translate("MainWindow", "X", nullptr));
        pushButtonRefY->setText(QApplication::translate("MainWindow", "Y", nullptr));
        pushButtonRefZ->setText(QApplication::translate("MainWindow", "Z", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "X", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Y", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Z", nullptr));
        menuArquivos->setTitle(QApplication::translate("MainWindow", "Arquivos", nullptr));
        menuEdi_o->setTitle(QApplication::translate("MainWindow", "Edi\303\247\303\243o", nullptr));
        menuFormas->setTitle(QApplication::translate("MainWindow", "Formas", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
