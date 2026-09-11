#include "widget.h"
#include "ui_widget.h"
#include "messwertcontroller.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget), controller(nullptr) {
  ui->setupUi(this);
  createChart();
}

Widget::~Widget() { delete ui; }

void Widget::createChart() {
  chartView = new ChartWidget(this);
  chartView->setGeometry(350, 20, 400, 450);
}

void Widget::setController(MesswertController *controller) {
  this->controller = controller;
}

// Zeigt die uebergebenen Messwerte in der Liste und im Chart an.
void Widget::zeigeMesswerte(const std::vector<int> &werte) {
  for (size_t i = 0; i < werte.size(); i++) {
    ui->edtMesswerte->appendPlainText(QString::number(werte[i]));
  }
  chartView->setData(werte);
}

void Widget::leereAnzeige() {
  ui->edtMesswerte->clear();
}

// Reagiert auf den Klick und ruft den Controller direkt auf.
void Widget::on_btnGetData_clicked() {
  if (controller) {
    controller->getDatenAnfordern();
  }
}
