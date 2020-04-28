#include "loginpage.h"
#include "ui_loginpage.h"
#include <QMessageBox>
#include <QFont>
#include <QPainter>
#include <QPalette>
#include "signupdialog.h"
LoginPage::LoginPage(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::LoginPage)
{
  setFixedSize(500,250);
  ui->setupUi(this);

  QPixmap pix("/home/blocker/Downloads/ship.jpg");
  QPixmap newPixmap = pix.scaled(QSize(200,200),  Qt::KeepAspectRatio);
  ui->imglbl->setPixmap(newPixmap);
  auto func=[](int x){
      qDebug()<<"Hello World + "<<x;
    };

  mydb = QSqlDatabase::addDatabase("QSQLITE");
  mydb.setDatabaseName("/home/blocker/QtProject/QSqlLoginPage/mydb.db");
  //  QPainter pp(this);
  //  QPen pen;
  QColor color(0,255,0);
  //  pen.setColor(color);
  //  pp.setPen(pen);
  //  pp.save();
  QPalette pal;
  pal.setColor(QPalette::WindowText,"#fdf5e6");
  pal.setColor(QPalette::Window,"#fada5e");

  if(mydb.open()){
      ui->statusBar->showMessage("Connected");

      QFont serifFont("Times", 14, QFont::Bold);

      ui->statusBar->setFont(serifFont);
      ui->statusBar->setPalette(pal);
      ui->centralWidget->setPalette(pal);
      setAutoFillBackground(true);
      this->setPalette(pal);
      this->setObjectName("sysinfogui");
    }else{
      ui->statusBar->showMessage("An error",5000);
    }
  setWindowTitle("{ Dark Hole Image Launcher }");

}

LoginPage::~LoginPage()
{
  delete ui;
}

void LoginPage::on_pushButton_clicked()
{
  QString username,password;
  username=ui->lineEdit_username->text();
  password=ui->lineEdit_password->text();
  if(mydb.open()){
      qDebug()<<"Connected";

    }else{
      qDebug()<<"Failed to connect to database";;
    }
  QSqlQuery query;
  if(query.exec("select * from emp where name='"+username+"'and pass='"+password+"'")){
      int count;

      while (query.next()){
          count++;
        }
      if(count==1){
          QMessageBox::information(this,"Logging info","Logged IN Successfully", QMessageBox::Ok);

        }else{

          QMessageBox::critical(this,"Logging info","Please Enter A Valid User", QMessageBox::Ok);


        }
      qDebug()<<count;
    }
}

void LoginPage::on_pushButton_2_clicked()
{
  SignUpDialog *sign=new SignUpDialog(this);
  if(!sign->exec());

}

void LoginPage::on_actionAbout_triggered()
{
  QMessageBox::about(this,"About us","Designed and Created by Louay Hesham click <a href=\"https://www.facebook.com/louay.hesham\">here</a> for more information");

}
