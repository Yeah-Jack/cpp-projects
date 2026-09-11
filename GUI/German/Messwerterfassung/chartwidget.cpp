#include "chartwidget.h"
#include <QPainter>
#include <QPainterPath>

ChartWidget::ChartWidget(QWidget *parent) : QWidget(parent) {
  setAutoFillBackground(true);
  QPalette pal = palette();
  pal.setColor(QPalette::Window, Qt::white);
  setPalette(pal);
}

void ChartWidget::setData(const std::vector<int> &values) {
  m_values = values;
  update();
}

void ChartWidget::paintEvent(QPaintEvent *) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  const QRect plotArea(kMarginLeft, kMarginTop,
                        width() - kMarginLeft - kMarginRight,
                        height() - kMarginTop - kMarginBottom);

  painter.setPen(QPen(Qt::black, 1));
  painter.drawRect(plotArea);

  if (m_values.empty()) {
    painter.drawText(plotArea, Qt::AlignCenter, tr("Keine Daten"));
    return;
  }

  const int minVal = *std::min_element(m_values.begin(), m_values.end());
  const int maxVal = *std::max_element(m_values.begin(), m_values.end());
  const int valueRange = std::max(1, maxVal - minVal);
  const size_t countMinus1 = std::max<size_t>(1, m_values.size() - 1);

  auto toPoint = [&](size_t index, int value) -> QPointF {
    const double x =
        plotArea.left() + (double(index) / countMinus1) * plotArea.width();
    const double y = plotArea.bottom() -
                      (double(value - minVal) / valueRange) * plotArea.height();
    return QPointF(x, y);
  };

  const QFontMetrics fm(painter.font());

  // Horizontale Gitterlinien + Y-Achsenbeschriftung
  const int ySteps = 5;
  for (int i = 0; i <= ySteps; ++i) {
    const int value = minVal + valueRange * i / ySteps;
    const double y = plotArea.bottom() -
                      (double(value - minVal) / valueRange) * plotArea.height();

    painter.setPen(QPen(QColor(220, 220, 220), 1, Qt::DashLine));
    painter.drawLine(QPointF(plotArea.left(), y), QPointF(plotArea.right(), y));

    painter.setPen(QPen(Qt::black, 1));
    painter.drawText(QRect(0, int(y) - fm.height() / 2, kMarginLeft - 5,
                            fm.height()),
                      Qt::AlignRight | Qt::AlignVCenter,
                      QString::number(value));
  }

  // X-Achsenbeschriftung (Index), maximal 10 Beschriftungen
  const int xTicks = std::min<int>(10, int(m_values.size()) - 1);
  if (xTicks > 0) {
    for (int i = 0; i <= xTicks; ++i) {
      const size_t index = size_t(std::round(double(i) / xTicks * countMinus1));
      const QPointF p = toPoint(index, m_values[index]);
      painter.drawText(
          QRect(int(p.x()) - 15, plotArea.bottom() + 4, 30, kMarginBottom - 4),
          Qt::AlignHCenter | Qt::AlignTop, QString::number(index));
    }
  }

  // Linienzug der Messwerte
  QPainterPath path;
  path.moveTo(toPoint(0, m_values[0]));
  for (size_t i = 1; i < m_values.size(); ++i) {
    path.lineTo(toPoint(i, m_values[i]));
  }
  painter.setPen(QPen(QColor(30, 110, 200), 2));
  painter.drawPath(path);
}
