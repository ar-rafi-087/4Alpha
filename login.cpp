#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <qsql.h>
#include <QSqlQuery>
#include <QDebug>

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}


void Login::on_pushButton_clicked()
{
        QString username = ui->lineEdit->text();
        QString password = ui->lineEdit_2->text();




        QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE","myconnect");
           db.setDatabaseName("D:/4alpha.sqlite");

           db.open();

           QSqlQuery query(QSqlDatabase::database("myconnect"));

           query.prepare("select * from USERNAME where USER=:user and PASS=:pass");
           query.bindValue(":user",username);
           query.bindValue(":pass",password);

           if ( !query.exec() )
          {

           qDebug()<<"Unsuccesfull";

           }

           else {

               if ( query.next() )
               {
                   QMessageBox::information(this, "Login", "Username & Password is correct");
                   hide();
                   homepage = new HomePage(this);
                   homepage->show();
               }
               else {
               QMessageBox::warning(this, "Login", "Username & Password is not correct");
           }
           }





        /*if(username == "admin" && password == "admin") {
          QMessageBox::information(this, "Login", "Username & Password is correct");
          hide();
          homepage = new HomePage(this);
          homepage->show();
        }
            else {
            QMessageBox::warning(this, "Login", "Username & Password is not correct");
        } */
}


void Login::on_pushButton_3_clicked()
{
    hide();
REGISTRATION = new registration(this);
    REGISTRATION->show();

}

