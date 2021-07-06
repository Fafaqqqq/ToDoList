#include "error.h"
#include "ui_error.h"

Error::Error(QString str, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Error)
{
    ui->setupUi(this);
    ui->label->setText(str);
}

Error::~Error()
{
    delete ui;
}
