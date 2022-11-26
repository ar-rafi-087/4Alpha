#include "chess.h"
#include "ui_chess.h"

chess::chess(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chess)
{
    ui->setupUi(this);
}

chess::~chess()
{
    delete ui;
}
