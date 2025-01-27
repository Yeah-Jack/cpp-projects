#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
}

Widget::~Widget() { delete ui; }

void Widget::on_berechnen_clicked() {
  double widerstand1 = 0;
  double widerstand2 = 0;
  double widerstand3 = 0;
  double ergebnis;

  if (ui->btnParallel2R->isChecked()) {
    widerstand1 = ui->widerstand1->value();
    widerstand2 = ui->widerstand2->value();
    ergebnis = (widerstand1 * widerstand2) / (widerstand1 + widerstand2);
  }
  if (ui->btnReihe2R->isChecked()) {
    widerstand1 = ui->widerstand1->value();
    widerstand2 = ui->widerstand2->value();
    ergebnis = widerstand1 + widerstand2;
  }
  if (ui->btnReihe3R->isChecked()) {
    widerstand1 = ui->widerstand1->value();
    widerstand2 = ui->widerstand2->value();
    widerstand3 = ui->widerstand3->value();
    ergebnis = widerstand1 + widerstand2 + widerstand3;
  }
  ui->ergebnis->display(ergebnis);
}
