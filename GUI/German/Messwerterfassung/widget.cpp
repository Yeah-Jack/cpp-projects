#include "widget.h"
#include "ui_widget.h"

Widget::Widget(
    QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
}

Widget::~Widget() { delete ui; }

void Widget::addMesswert() {
  std::vector<int> messwerte = {10, 11, 13, 15, 9, 8, 3, 0, -1,
                                -4, -5, -3, -2, 0, 0, 2, 3};
  // ToDo: Auf 100 Werte erweitern

  for (size_t i = 0; i < messwerte.size(); i++) {
    ui->edtMesswerte->appendPlainText(QString::number(messwerte[i]));
  }
}

void Widget::on_btnGetData_clicked() { addMesswert(); }

void Widget::createChart() {}

void Widget::addDatatoChart() {}
