#include "bird.h"
#include "ui_bird.h"

bird::bird(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bird)
{
    ui->setupUi(this);
}

bird::~bird()
{
    delete ui;
}
