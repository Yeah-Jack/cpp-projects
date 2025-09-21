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
  ui->log->appendPlainText("The current water temperature is " +
                           QString::number(currentWaterTemperature) + "°C.");
}

void GUI::on_currentWaterQualityBtn_clicked() {
  double currentWaterQuality = lake->getCurrentWaterQuality();
  ui->log->appendPlainText("The current water quality is " +
                           QString::number(currentWaterQuality) + '.');
}

void GUI::on_getFirstNameBtn_clicked() {
  QString firstName = person->getFirstName();
  ui->log->appendPlainText("The first name " + firstName + '.');
}

void GUI::on_getLastNameBtn_clicked() {
  QString lastName = person->getLastName();
  ui->log->appendPlainText("The first name " + lastName + '.');
}
