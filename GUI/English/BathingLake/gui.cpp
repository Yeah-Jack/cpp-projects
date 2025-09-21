#include "gui.h"
#include "ui_gui.h"

GUI::GUI(QWidget *parent) : QWidget(parent), ui(new Ui::GUI) {
  ui->setupUi(this);
  lake = new Lake;
  updateWaterTemperatureList();
  updatePeopleList();
  updateLoungerList();
}

GUI::~GUI() {
  delete ui;
  delete lake;
}

void GUI::on_waterTemperatureBtn_clicked() {
  double waterTemperature = lake->getWaterTemperature();
  ui->log->appendPlainText("The water temperature is " +
                           QString::number(waterTemperature) + "°C.");
}

void GUI::on_waterQualityBtn_clicked() {
  double waterQuality = lake->getWaterQuality();
  ui->log->appendPlainText("The water quality is " +
                           QString::number(waterQuality) + '.');
}

void GUI::on_parkBikeBtn_clicked() {
  ui->log->appendPlainText("You have parked your bike.");
}

void GUI::on_rentLoungerBtn_clicked() {
  if (lake->canRentLounger()) {
    Lounger *newLounger = new Lounger();
    unsigned int id = lake->getNextLoungerId();
    short type = ui->typeSelect->currentIndex();
    short condition = ui->conditionSelect->currentIndex();
    newLounger->setId(id);
    newLounger->setType(type);
    newLounger->setCondition(condition);
    lake->addLounger(newLounger);
    updateLoungerList();
    ui->log->appendPlainText("You have rented the lounger number " +
                             QString::number(id) + " of the type \"" +
                             Lounger::getTypeName(type) +
                             "\" with the condition \"" +
                             Lounger::getConditionName(condition) + "\".");
  } else {
    ui->log->appendPlainText(
        "Maximum number of loungers (200) already rented.");
  }
}

void GUI::on_viewVisitorsBtn_clicked() {
  ui->log->appendPlainText(
      "Number of visitors: " + QString::number(lake->getPeopleCount()) + '.');
}

void GUI::updatePeopleList() {
  ui->peopleList->clear();
  for (auto p : lake->getPeople()) {
    ui->peopleList->addItem("ID: " + QString::number(p->getId()) + ", Name: " +
                            p->getFirstName() + " " + p->getLastName());
  }
}

void GUI::updateLoungerList() {
  ui->loungerList->clear();
  for (auto l : lake->getLoungers()) {
    ui->loungerList->addItem(
        "ID: " + QString::number(l->getId()) +
        ", Type: " + Lounger::getTypeName(l->getType()) +
        ", Condition: " + Lounger::getConditionName(l->getCondition()));
  }
}

void GUI::updateWaterTemperatureList() {
  ui->waterTemperatureList->clear();
  for (int i = 0; i < 200; i++) {
    ui->waterTemperatureList->addItem(
        QString::number(lake->getWaterTemperature()) + "°C");
  }
}

void GUI::on_addPersonBtn_clicked() {
  QString firstName = ui->firstNameEdit->text();
  QString lastName = ui->lastNameEdit->text();
  if (!firstName.isEmpty() && !lastName.isEmpty()) {
    Person *newPerson = new Person();
    newPerson->setId(lake->getNextPersonId());
    newPerson->setFirstName(firstName);
    newPerson->setLastName(lastName);
    lake->addPerson(newPerson);
    updatePeopleList();
    ui->log->appendPlainText(
        "You added the person number " + QString::number(newPerson->getId()) +
        " with the name of " + firstName + " " + lastName + '.');
  } else {
    ui->log->appendPlainText("Please enter both first and last name.");
  }
}

void GUI::on_removePersonBtn_clicked() {
  int row = ui->peopleList->currentRow();
  if (row >= 0) {
    lake->removePerson(row);
    updatePeopleList();
    ui->log->appendPlainText("Removed person.");
  } else {
    ui->log->appendPlainText("Please select a person to remove.");
  }
}

void GUI::on_removeLoungerBtn_clicked() {
  int row = ui->loungerList->currentRow();
  if (row >= 0) {
    lake->removeLounger(row);
    updateLoungerList();
    ui->log->appendPlainText("Removed lounger.");
  } else {
    ui->log->appendPlainText("Please select a lounger to remove.");
  }
}
