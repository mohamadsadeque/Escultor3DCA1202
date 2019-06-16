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
