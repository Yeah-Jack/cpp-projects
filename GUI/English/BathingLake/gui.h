#ifndef GUI_H
#define GUI_H

#include "lake.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class GUI : public QWidget {
  Q_OBJECT

public:
  GUI(QWidget *parent = nullptr);
  ~GUI();
  bool rentLounger();
  void parkBike();
  double viewCurrentWaterTemperature();
  unsigned short viewCurrentWaterQuality();
  int viewCurrentNumberOfVisitors();

private slots:
  void on_currentWaterTemperatureBtn_clicked();
  void on_currentWaterQualityBtn_clicked();
  void on_getFirstNameBtn_clicked();
  void on_getLastNameBtn_clicked();

private:
  Ui::GUI *ui;
  Lake *lake;
  Person *person;
};
#endif // GUI_H
