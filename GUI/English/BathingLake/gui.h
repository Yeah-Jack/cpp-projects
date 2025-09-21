#ifndef GUI_H
#define GUI_H

#include "lake.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class GUI;
}
QT_END_NAMESPACE

class GUI : public QWidget {
  Q_OBJECT

public:
  GUI(QWidget *parent = nullptr);
  ~GUI();
  bool rentLounger();
  void parkBike();
  double viewWaterTemperature();
  unsigned short viewWaterQuality();
  int viewNumberOfVisitors();

private slots:
  void on_getWaterTemperatureBtn_clicked();
  void on_getWaterQualityBtn_clicked();
  void on_getFirstNameBtn_clicked();
  void on_getLastNameBtn_clicked();
  void on_setFirstNameBtn_clicked();
  void on_setLastNameBtn_clicked();

private:
  Ui::GUI *ui;
  Lake *lake;
  Person *person;
};
#endif // GUI_H
