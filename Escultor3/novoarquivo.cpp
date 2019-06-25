#include "novoarquivo.h"
#include "ui_novoarquivo.h"

NovoArquivo::NovoArquivo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NovoArquivo)
{
    ui->setupUi(this);
}

NovoArquivo::~NovoArquivo()
{
    delete ui;
}

int NovoArquivo::getX()
{
    return ui->spinBox_x->value();
}

int NovoArquivo::getY()
{
    return ui->spinBox_y->value();
}

int NovoArquivo::getZ()
{
    return ui->spinBox_z->value();
}
