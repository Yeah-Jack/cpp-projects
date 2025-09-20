#include "gui.h"
#include "ui_gui.h"

GUI::GUI(QWidget *parent) : QWidget(parent), ui(new Ui::GUI) {
  ui->setupUi(this);
  lake = new Lake;
  person = new Person;
}

GUI::~GUI() { delete ui; }

void GUI::on_currentWaterTemperatureBtn_clicked() {
  double currentWaterTemperature = lake->getCurrentWaterTemperature();
  QString temp = "The current water temperature is " +
                 QString::number(currentWaterTemperature) + "°C.";
  ui->log->appendPlainText(temp);
}

void GUI::on_currentWaterQualityBtn_clicked() {
  double currentWaterQuality = lake->getCurrentWaterQuality();
  QString temp = "The current water quality is " +
                 QString::number(currentWaterQuality) + '.';
  ui->log->appendPlainText(temp);
}

void GUI::on_getFirstNameBtn_clicked() {
  QString firstName = person->getFirstName();
  QString temp = "The first name " + firstName + '.';
  ui->log->appendPlainText(temp);
}

void GUI::on_getLastNameBtn_clicked() {
  QString lastName = person->getLastName();
  QString temp = "The first name " + lastName + '.';
  ui->log->appendPlainText(temp);
}
