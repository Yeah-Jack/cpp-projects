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
  int viewNumberOfVisitors();

private slots:
  void on_waterTemperatureBtn_clicked();
  void on_waterQualityBtn_clicked();
  void on_addPersonBtn_clicked();
  void on_removePersonBtn_clicked();
  void on_rentLoungerBtn_clicked();
  void on_removeLoungerBtn_clicked();
  void on_viewVisitorsBtn_clicked();
  void on_parkBikeBtn_clicked();

private:
  Ui::GUI *ui;
  Lake *lake;
  void updateWaterTemperatureList();
  void updatePeopleList();
  void updateLoungerList();
};
#endif // GUI_H
