#include "dialogbox.h"
#include "ui_dialogbox.h"

DialogBox::DialogBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogBox)
{
    ui->setupUi(this);
}

DialogBox::~DialogBox()
{
    delete ui;
}

bool DialogBox::getPut()
{
    return ui->radioButtonPut->isChecked();
}

int DialogBox::getAltura()
{
    return ui->spinAltura->value();
}

int DialogBox::getLargura()
{
    return ui->spinLargura->value();
}

int DialogBox::getProfundidade()
{
    return ui->spinProfundidade->value();
}
