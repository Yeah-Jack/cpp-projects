#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
}

Widget::~Widget() { delete ui; }

void Widget::on_calculate_clicked() {
  switch (ui->calculationType->currentIndex()) {
  case 0:
    ui->result->display(ui->number1->value() + ui->number2->value());
    break;
  case 1:
    ui->result->display(ui->number1->value() - ui->number2->value());
    break;
  case 2:
    ui->result->display(ui->number1->value() * ui->number2->value());
    break;
  case 3:
    ui->result->display(ui->number1->value() / ui->number2->value());
    break;
  }
}
