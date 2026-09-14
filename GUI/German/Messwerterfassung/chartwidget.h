#ifndef CHARTWIDGET_H
#define CHARTWIDGET_H

#include <QWidget>
#include <vector>

class ChartWidget : public QWidget {
  Q_OBJECT

public:
  ChartWidget(QWidget *parent = nullptr);

  void setData(const std::vector<int> &values);

protected:
  void paintEvent(QPaintEvent *event) override;

private:
  std::vector<int> messwerte;
};

#endif // CHARTWIDGET_H
