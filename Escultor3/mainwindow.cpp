#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <novoarquivo.h>
#include <plotter.h>
#include <dialogrgb.h>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->horizontalSliderPlano,
            SIGNAL(valueChanged(int)),
            ui->widgetPlotter,
            SLOT(olhaPlano(int)));

    connect(ui->widgetPlotter,
            SIGNAL(clickXY(int,int)),
            ui->widgetPlotter,
            SLOT(clicou(int,int)));


    connect(ui->actionNovoArquivo,
            SIGNAL(triggered(bool)),
            this,
            SLOT( abreNovoArquivo() ));

    connect(ui->actionRGB,
            SIGNAL(triggered(bool)),
            this,
            SLOT(selecionaCor()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::abreNovoArquivo()
{
   NovoArquivo d;
   if( d.exec() == QDialog::Accepted){
     ui->widgetPlotter->mudaLinhas(d.getX());
     ui->widgetPlotter->mudaColunas(d.getY());
     ui->widgetPlotter->mudaPlanos(d.getZ());

   }

}

void MainWindow::fecha()
{
    exit(0);
}


void MainWindow::selecionaCor()
{

//  QMessageBox box;
//  QString msg;
//  DialogRgb dialog;

//  if(dialog.exec() == QDialog::Accepted){
//    msg = "r = <b>"+QString::number(dialog.getR())+
//        "</b> <br>"+
//        "g = <b>"+QString::number(dialog.getG())+
//        "</b> <br>"+
//        "b = <b>"+QString::number(dialog.getB())+
//        "</b>";
//    box.setText(msg);
//    box.exec();
//  }
}

