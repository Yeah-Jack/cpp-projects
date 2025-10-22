#include "viewwidget.h"
#include "ui_viewwidget.h"

ViewWidget::ViewWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::ViewWidget), myLake(new ControllerLake) {
  ui->setupUi(this);
  connect(ui->btnCreateOneLouncherStandard, &QPushButton::clicked, this,
          &ViewWidget::createLoungerTypeStandard);
  connect(ui->btnCreateOneLouncherLuxurious, &QPushButton::clicked, this,
          &ViewWidget::createLoungerTypeLuxurious);
  connect(ui->btnShowListLoungers, &QPushButton::clicked, this,
          &ViewWidget::showListLoungers);
  connect(ui->btnClearLog, &QPushButton::clicked, this, &ViewWidget::clearLog);
}

ViewWidget::~ViewWidget() {
  delete ui;
  delete myLake;
}

void ViewWidget::createLoungerTypeStandard() {
  unsigned short days = ui->standardDays->value();
  myLake->createLoungerStandardType(days);
}

void ViewWidget::createLoungerTypeLuxurious() {
  unsigned short hours = ui->luxuriousHours->value();
  int pillows = ui->luxuriousPillows->value();
  QString coverColor = ui->luxuriousCoverColor->text();
  QString frameColor = ui->luxuriousFrameColor->text();
  myLake->createLoungerLuxury(hours, pillows, coverColor, frameColor);
}

void ViewWidget::showListLoungers() {
  QStringList loungerStrings;

  loungerStrings = myLake->getListLoungers();
  if (loungerStrings.size() > 0) {
    ui->edtListLoungers->clear();
    for (QString i : loungerStrings) {
      ui->edtListLoungers->appendPlainText(i);
    }
  }
}

void ViewWidget::clearLog() { ui->edtListLoungers->clear(); }
