#include "homepage.h"
#include "ui_homepage.h"
#include<Puzzle15.h>

HomePage::HomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);
}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::on_pushButton_clicked()
{
   MAINWINDOW = new MainWindow(this);
   MAINWINDOW->show();
}


void HomePage::on_pushButton_2_clicked()
{
    PUZZLE15 = new Puzzle15(this);
    PUZZLE15->show();
}


