#ifndef WIDGET_H
#define WIDGET_H

#include "lake.h"
#include "person.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
  Q_OBJECT

public:
  Widget(QWidget *parent = nullptr);
  ~Widget();

private slots:
  void on_currentWaterTemperatureBtn_clicked();
  void on_currentWaterQualityBtn_clicked();
  void on_getFirstNameBtn_clicked();
  void on_getLastNameBtn_clicked();

private:
  Ui::Widget *ui;
  Lake *lake;
  Person *person;
};
#endif // WIDGET_H
