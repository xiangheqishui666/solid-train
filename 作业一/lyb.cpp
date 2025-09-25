#include "lyb.h"
#include "ui_lyb.h"

lyb::lyb(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::lyb)
{
    ui->setupUi(this);
}

lyb::~lyb()
{
    delete ui;
}
