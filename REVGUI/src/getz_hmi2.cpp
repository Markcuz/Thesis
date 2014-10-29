#include "getz_hmi2.h"
#include "ui_getz_hmi2.h"

Getz_HMI2::Getz_HMI2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Getz_HMI2)
{
    ui->setupUi(this);
}

Getz_HMI2::~Getz_HMI2()
{
    delete ui;
}
