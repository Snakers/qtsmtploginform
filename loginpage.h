#ifndef LOGINPAGE_H
#define LOGINPAGE_H
#include <QtSql>
#include <QtDebug>
#include<QFileInfo>
#include <QMainWindow>

namespace Ui {
  class LoginPage;
}

class LoginPage : public QMainWindow
{
  Q_OBJECT

public:
  explicit LoginPage(QWidget *parent = 0);
  ~LoginPage();

private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

  void on_actionAbout_triggered();

private:
  Ui::LoginPage *ui;
  QSqlDatabase mydb;
};

#endif // LOGINPAGE_H
