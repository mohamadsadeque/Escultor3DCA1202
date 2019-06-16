#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <novoarquivo.h>
#include <plotter.h>
#include <QMessageBox>
#include <QColorDialog>
#include <QColor>
#include <dialogsphere.h>
#include <dialogellipsoid.h>
#include <dialogvoxel.h>
#include <dialogbox.h>
#include <qfiledialog.h>

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

    connect(ui->actionEsfera,
            SIGNAL(triggered(bool)),
            this,
            SLOT(configuraEsfera()));

    connect(ui->actionElipsoide,
            SIGNAL(triggered(bool)),
            this,
            SLOT(configuraElipsoide()));

    connect(ui->actionVoxel,
            SIGNAL(triggered(bool)),
            this,
            SLOT(configuraVoxel()));
    connect(ui->actionCaixa,
            SIGNAL(triggered(bool)),
            this,
            SLOT(configuraBox()));
    connect(ui->actionOpen,
            SIGNAL(triggered(bool)),
            this,
            SLOT(abrirArquivo()));

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
QColor color = QColorDialog::getColor();
if(color.isValid()){

}


}

void MainWindow::configuraEsfera()
{
    DialogSphere s;
    s.exec();
}

void MainWindow::configuraElipsoide()
{
    DialogEllipsoid e;
    e.exec();
}

void MainWindow::configuraVoxel()
{
    DialogVoxel v;
    v.exec();
}

void MainWindow::configuraBox()
{
    DialogBox b;
    b.exec();
}

void MainWindow::abrirArquivo()
{
    QString filename=QFileDialog::getOpenFileName(this,tr("Abrir Arquivo"),"C://","Todos Arquivos (*.*);;OFF (*.off);; VECT (*.vect)");
    QMessageBox::information(this,tr("Nome do Arquivo"),filename);
}

