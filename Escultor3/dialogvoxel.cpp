#include "dialogvoxel.h"
#include "ui_dialogvoxel.h"

DialogVoxel::DialogVoxel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogVoxel)
{
    ui->setupUi(this);
}

DialogVoxel::~DialogVoxel()
{
    delete ui;
}
