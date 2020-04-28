#include "activatoncodeclass.h"
#include "ui_activatoncodeclass.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QToolTip>
#include <QSettings>
#include <QTimer>
#include <QDebug>
#include <QVariant>
static int attempt= 3;
ActivatonCodeClass::ActivatonCodeClass(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::ActivatonCodeClass)
{
  timer = nullptr;
  ui->setupUi(this);
  connect(ui->pushButton,&QPushButton::clicked,this,&ActivatonCodeClass::checkCode);
  QSettings settings("Comp","time");
  settings.beginGroup("Time");
//          settings.setValue("MyTime",QDateTime::currentDateTime());
  QDateTime dd=settings.value("mytime",0).toDateTime();
  settings.endGroup();
  qDebug()<<"GG"<<dd;
  connect(this,&ActivatonCodeClass::rejected,this,[=](){

      qDebug()<<"REJECT";
    if(timer!=nullptr){
      timer->stop();
    delete timer;
      }
    });

}

ActivatonCodeClass::~ActivatonCodeClass()
{
  delete ui;
}

void ActivatonCodeClass::checkCode()
{
  int checker=ui->le_code->text().toInt();
  if(checker==getCode()){
      QSqlQuery query;
      if(query.exec("insert into emp(name,pass,email) values('"+getUname()+"','"+getPass()+"','"+getEmail()+"')")){

          QMessageBox::information(this,"System Message!","User Created Succesfully!",QMessageBox::Ok);
          setResult(QDialog::Accepted);
          done(QDialog::Accepted);
          setResult(QDialog::Accepted);
          close();
          //accept();
        }

    }else{
      if(attempt!=0){
          QPoint point = QPoint(geometry().left() + ui->le_code->geometry().left(),
                                geometry().top() + ui->le_code->geometry().bottom());
          ui->le_code->clear();   // Reset previous text..
          QToolTip::showText(point,"Error Wrong Number Maximum Tries :"+ QString::number(attempt));
          attempt--;

        }else{
          qDebug() << "start timer code";
          ui->pushButton->setEnabled(false);
          current = QDateTime::currentDateTime();
          QSettings settings("Comp","time");
          settings.beginGroup("Time");
//          settings.setValue("MyTime",QDateTime::currentDateTime());
          expire = current.addSecs(120);
          settings.setValue("mytime",expire.currentDateTime().addSecs(300));
          settings.endGroup();

          timer = new QTimer(this);
          connect(timer, &QTimer::timeout, this, [&](){
              qDebug()<<"expire : "<<expire;
              qDebug()<<"current : "<<current;
              current = QDateTime::currentDateTime();
              if(expire <= current){
              timer->stop();
              delete timer;
              timer=0;
              attempt=3;
              ui->pushButton->setEnabled(true);
              }
            });
          if(timer!=0)
          timer->start(1000);
        }

    }
}

void ActivatonCodeClass::update()
{
  qDebug()<<"LOL";
}

QString ActivatonCodeClass::getEmail() const
{
  return email;
}

void ActivatonCodeClass::setEmail(const QString &value)
{
  email = value;
}

QString ActivatonCodeClass::getUname() const
{
  return uname;
}

void ActivatonCodeClass::setUname(QString value)
{
  uname = value;
}

QString ActivatonCodeClass::getPass() const
{
  return pass;
}

void ActivatonCodeClass::setPass(QString value)
{
  pass = value;
}

int ActivatonCodeClass::getCode() const
{
  return code;
}

void ActivatonCodeClass::setCode(int value)
{
  code = value;
}
