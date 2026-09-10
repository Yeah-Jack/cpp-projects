#ifndef WIDGET_H
#define WIDGET_H
#include <QLineSeries>
#include <QWidget>
#include <QtCharts>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
  Q_OBJECT

public:
  Widget(QWidget *parent = nullptr);
  ~Widget();

private slots:
  void on_btnGetData_clicked();

private:
  Ui::Widget *ui;
  void addMesswert();
  void createChart();
  void addDatatoChart();
};
#endif // WIDGET_H
