#include "dialogsphere.h"
#include "ui_dialogsphere.h"

DialogSphere::DialogSphere(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSphere)
{
    ui->setupUi(this);
}

DialogSphere::~DialogSphere()
{
    delete ui;
}

bool DialogSphere::getPut()
{
    return ui->radioButtonPut->isChecked();
}

int DialogSphere::getRaio()
{
    return ui->spinBoxRaio->value();
}
