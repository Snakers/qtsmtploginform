  #ifndef ACTIVATONCODECLASS_H
  #define ACTIVATONCODECLASS_H

  #include <QDialog>
  #include <QTimer>
  #include <QDateTime>
  namespace Ui {
    class ActivatonCodeClass;
  }

  class ActivatonCodeClass : public QDialog
  {
    Q_OBJECT

  public:
    explicit ActivatonCodeClass(QWidget *parent = 0);
    ~ActivatonCodeClass();
    int getCode() const;
    void setCode(int value);
    QString getPass() const;
    void setPass( QString value);

    QString getUname() const;
    void setUname( QString value);

    QString getEmail() const;
    void setEmail(const QString &value);

  public  slots:
    void checkCode();
    void update();

  private:
    Ui::ActivatonCodeClass *ui;
    int code;
    QString uname;
    QString pass;
    QString email;
    QDateTime current,expire;
    QTimer *timer;

  };

  #endif // ACTIVATONCODECLASS_H
