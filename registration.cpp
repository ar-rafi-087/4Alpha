#include "ui_registration.h"
#include <QMessageBox>
#include <qsql.h>
#include <QSqlQuery>
#include <QDebug>
#include<registration.h>
#include<login.h>
registration::registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);
}

registration::~registration()
{
    delete ui;
}

void registration::on_pushButton_clicked()
{
    QString username = ui->Username->text();
    QString password = ui->Password->text();
    QString email = ui->Email->text();





    QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE","myconnect");
       db.setDatabaseName("D:/4alpha.sqlite");

       db.open();

       QSqlQuery query(QSqlDatabase::database("myconnect"));

       query.prepare("insert into USERNAME(USER,PASS,EMAIL)""values(:user,:pass,:email)");
       query.bindValue(":user",username);
       query.bindValue(":pass",password);
       query.bindValue(":email",email);

      if (username=="" || password=="" || email=="")
      {

          QMessageBox::warning(this, "Registration", "Register Unsuccessful !! Please Enter Text");


      }
       else if ( !query.exec() )
      {

       QMessageBox::warning(this, "Registration", "Register Unsuccessful");

       }

       else {


               QMessageBox::information(this, "Registration", "Register Successful");


       }
}


void registration::on_pushButton_2_clicked()
{
    hide();

    Login * LOGIN = nullptr;
    LOGIN = new Login(this);

    LOGIN->show();


}

