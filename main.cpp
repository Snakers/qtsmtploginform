#include "loginpage.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
QString readTextFile(QString path){
  QFile file(path);
  if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
      QTextStream in(&file);
      return in.readAll();
    }
  return "";

}
int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  LoginPage w;
  QString css=readTextFile("://css/style.css");
  w.setStyleSheet(css);
  w.show();

  return a.exec();
}
