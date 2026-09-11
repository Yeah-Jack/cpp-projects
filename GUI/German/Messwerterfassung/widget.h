#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <vector>
#include "chartwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class MesswertController;

class Widget : public QWidget {
  Q_OBJECT

public:
  Widget(QWidget *parent = nullptr);
  ~Widget();

  void setController(MesswertController *controller);

  void zeigeMesswerte(const std::vector<int> &werte);
  void leereAnzeige();

private slots:
  void on_btnGetData_clicked();

private:
  Ui::Widget *ui;
  ChartWidget *chartView;
  MesswertController *controller;
  void createChart();
};
#endif // WIDGET_H
