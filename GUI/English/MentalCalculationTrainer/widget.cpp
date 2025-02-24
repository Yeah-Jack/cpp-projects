#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget), tasksCounter(0), tasksCorrect(0),
      tasksIncorrect(0) {
  ui->setupUi(this);
}

Widget::~Widget() { delete ui; }

void Widget::on_input_clicked() {
  ui->number1->setValue(
      QInputDialog::getDouble(this, "Enter", "Enter your first number:"));

  QStringList items;
  items << "+" << "-" << "*" << "/";
  QString item = QInputDialog::getItem(this, "Select Calculation Type",
                                       "Calculation Type:", items);
  ui->calculationType->setCurrentIndex(items.indexOf(item));

  ui->number2->setValue(
      QInputDialog::getDouble(this, "Enter", "Enter your second number:"));
  ui->userResult->setValue(
      QInputDialog::getDouble(this, "Enter", "Enter your result:"));

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

  tasksCounter++;
  ui->tasksCounter->display(tasksCounter);

  if (ui->userResult->value() == ui->result->value()) {
    ui->user->setText("You're right");
    tasksCorrect++;
    ui->tasksCorrect->display(tasksCorrect);
  } else {
    ui->user->setText("You're wrong");
    tasksIncorrect++;
    ui->tasksIncorrect->display(tasksIncorrect);
  }
}
