#include "tictactoe.h"
#include "ui_tictactoe.h"



tictactoe::tictactoe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tictactoe)
{
    ui->setupUi(this);
}

tictactoe::~tictactoe()
{
    delete ui;
}



