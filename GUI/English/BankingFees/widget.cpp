#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
}

Widget::~Widget() { delete ui; }

void Widget::on_calculate_clicked() {
  int bookings = ui->bookings->value();

  if (bookings <= 10) {
    ui->fees->setValue(0);
  } else if (bookings > 10 && bookings <= 20) {
    bookings -= 10;
    ui->fees->setValue(0.15);
  } else {
    bookings -= 10;
    ui->fees->setValue(0.1);
  }

  ui->fees->setValue(bookings * ui->fees->value());
}
