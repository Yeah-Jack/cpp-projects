#ifndef CHARTWIDGET_H
#define CHARTWIDGET_H

#include <QWidget>
#include <vector>

class ChartWidget : public QWidget {
  Q_OBJECT

public:
  explicit ChartWidget(QWidget *parent = nullptr);

  void setData(const std::vector<int> &values);

protected:
  void paintEvent(QPaintEvent *event) override;

private:
  QString m_title;
  std::vector<int> m_values;

  static constexpr int kMarginLeft = 45;
  static constexpr int kMarginRight = 15;
  static constexpr int kMarginTop = 35;
  static constexpr int kMarginBottom = 30;
};

#endif // CHARTWIDGET_H
