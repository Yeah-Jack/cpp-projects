#include "chartwidget.h"
#include <QPainter>

// Rechnet einen Messwert an einer bestimmten Stelle (index) in einen
// Punkt auf dem Bildschirm um. "nenner" ist die Anzahl der Werte minus 1
// (mindestens 1), damit man nicht durch 0 teilt.
static QPointF berechnePunkt(int index, int wert, int minWert, int wertBereich,
                             int nenner, const QRect &zeichenbereich) {
  double x =
      zeichenbereich.left() + (double)index / nenner * zeichenbereich.width();
  double y = zeichenbereich.bottom() -
             (double)(wert - minWert) / wertBereich * zeichenbereich.height();
  return QPointF(x, y);
}

ChartWidget::ChartWidget(QWidget *parent) : QWidget(parent) {
  setAutoFillBackground(true);
  QPalette pal = palette();
  pal.setColor(QPalette::Window, Qt::white);
  setPalette(pal);
}

void ChartWidget::setData(const std::vector<int> &values) {
  messwerte = values;
  update();
}

void ChartWidget::paintEvent(QPaintEvent *) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);
  int anzahlWerte = (int)messwerte.size();

  // Abstaende zwischen Widget-Rand und eigentlicher Zeichenflaeche,
  // damit Platz fuer die Achsenbeschriftung bleibt.
  int randLinks = 45;
  int randRechts = 15;
  int randOben = 35;
  int randUnten = 30;

  QRect zeichenbereich(randLinks, randOben,
                        width() - randLinks - randRechts,
                        height() - randOben - randUnten);

  // Rahmen um die Zeichenflaeche
  painter.setPen(QPen(Qt::black, 1));
  painter.drawRect(zeichenbereich);

  // Wenn keine Messwerte vorhanden sind, nur einen Hinweis anzeigen
  if (anzahlWerte == 0) {
    painter.drawText(zeichenbereich, Qt::AlignCenter, tr("Keine Daten"));
    return;
  }

  // Kleinsten und groessten Messwert suchen
  int minWert = messwerte[0];
  int maxWert = messwerte[0];
  for (int i = 1; i < anzahlWerte; i++) {
    if (messwerte[i] < minWert) {
      minWert = messwerte[i];
    }
    if (messwerte[i] > maxWert) {
      maxWert = messwerte[i];
    }
  }

  int wertBereich = maxWert - minWert;
  if (wertBereich == 0) {
    wertBereich = 1; // Division durch 0 vermeiden, falls alle Werte gleich sind
  }

  int nenner = anzahlWerte - 1;
  if (nenner == 0) {
    nenner = 1; // Division durch 0 vermeiden, falls es nur einen Wert gibt
  }

  QFontMetrics schriftMasse(painter.font());

  // Y-Achse beschriften
  int anzahlSchritte = 5;
  for (int i = 0; i <= anzahlSchritte; i++) {
    int wert = minWert + wertBereich * i / anzahlSchritte;
    double y = zeichenbereich.bottom() -
               (double)(wert - minWert) / wertBereich * zeichenbereich.height();

    painter.drawText(QRect(0, (int)y - schriftMasse.height() / 2, randLinks - 5,
                           schriftMasse.height()),
                     Qt::AlignRight | Qt::AlignVCenter, QString::number(wert));
  }

  // X-Achse beschriften
  int anzahlBeschriftungen = anzahlWerte - 1;
  if (anzahlBeschriftungen > 10) {
    anzahlBeschriftungen = 10;
  }
  if (anzahlBeschriftungen > 0) {
    for (int i = 0; i <= anzahlBeschriftungen; i++) {
      int index = i * (anzahlWerte - 1) / anzahlBeschriftungen;
      QPointF punkt = berechnePunkt(index, messwerte[index], minWert,
                                     wertBereich, nenner, zeichenbereich);
      painter.drawText(QRect((int)punkt.x() - 15, zeichenbereich.bottom() + 4,
                              30, randUnten - 4),
                        Qt::AlignHCenter | Qt::AlignTop, QString::number(index));
    }
  }

  // Messwerte als Linie zeichnen: jeden Punkt mit dem naechsten verbinden
  painter.setPen(QPen(QColor(30, 110, 200), 2));
  for (int i = 0; i + 1 < anzahlWerte; i++) {
    QPointF punkt1 = berechnePunkt(i, messwerte[i], minWert, wertBereich,
                                   nenner, zeichenbereich);
    QPointF punkt2 = berechnePunkt(i + 1, messwerte[i + 1], minWert,
                                   wertBereich, nenner, zeichenbereich);
    painter.drawLine(punkt1, punkt2);
  }
}
