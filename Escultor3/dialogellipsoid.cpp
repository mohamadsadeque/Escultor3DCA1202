#include "dialogellipsoid.h"
#include "ui_dialogellipsoid.h"

DialogEllipsoid::DialogEllipsoid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEllipsoid)
{
    ui->setupUi(this);
}

DialogEllipsoid::~DialogEllipsoid()
{
    delete ui;
}

bool DialogEllipsoid::getPut()
{
    return ui->radioButtonPut->isChecked();

}

int DialogEllipsoid::getRaioX()
{
    return ui->spinBoxRaioX->value();

}

int DialogEllipsoid::getRaioY()
{
    return ui->spinBoxRaioY->value();

}

int DialogEllipsoid::getRaioZ()
{
    return ui->spinBoxRaioZ->value();

}
