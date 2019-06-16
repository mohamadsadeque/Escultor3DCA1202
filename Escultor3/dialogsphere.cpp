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
