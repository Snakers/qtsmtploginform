#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>
#include <QtSql>
#include "activatoncodeclass.h"
#include "smtp.h"

namespace Ui {
  class SignUpDialog;
}

class SignUpDialog : public QDialog
{
  Q_OBJECT

public:
  explicit SignUpDialog(QWidget *parent = 0);
  ~SignUpDialog();
unsigned int getRan() const;
void sendMail();
private slots:
void on_pushButton_clicked();

void mailSent(QString);
private:
  Ui::SignUpDialog *ui;
  QSqlDatabase mydb;
 unsigned int ran;
Smtp* smtp ;
 QString msg;
 ActivatonCodeClass *act;
};

#endif // SIGNUPDIALOG_H
