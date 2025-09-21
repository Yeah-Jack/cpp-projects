#include "gui.h"
#include "ui_gui.h"

GUI::GUI(QWidget *parent) : QWidget(parent), ui(new Ui::GUI) {
  ui->setupUi(this);
  lake = new Lake;
  person = new Person;
}

GUI::~GUI() {
  delete ui;
  delete lake;
  delete person;
}

void GUI::on_getWaterTemperatureBtn_clicked() {
  double waterTemperature = lake->getWaterTemperature();
  ui->log->appendPlainText("The water temperature is " +
                           QString::number(waterTemperature) + "°C.");
}

void GUI::on_getWaterQualityBtn_clicked() {
  double waterQuality = lake->getWaterQuality();
  ui->log->appendPlainText("The water quality is " +
                           QString::number(waterQuality) + '.');
}

void GUI::on_getFirstNameBtn_clicked() {
  QString firstName = person->getFirstName();
  ui->log->appendPlainText("The first name " + firstName + '.');
}

void GUI::on_getLastNameBtn_clicked() {
  QString lastName = person->getLastName();
  ui->log->appendPlainText("The last name is " + lastName + '.');
}

void GUI::on_setFirstNameBtn_clicked() {
  QString firstName = ui->setFirstNameEdit->text();
  person->setFirstName(firstName);
  ui->log->appendPlainText("The first name has been set to " + firstName + '.');
}

void GUI::on_setLastNameBtn_clicked() {
  QString lastName = ui->setLastNameEdit->text();
  person->setLastName(lastName);
  ui->log->appendPlainText("The last name has been set to " + lastName + '.');
}
