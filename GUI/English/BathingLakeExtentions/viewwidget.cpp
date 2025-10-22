#include "viewwidget.h"
#include "ui_viewwidget.h"

ViewWidget::ViewWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::ViewWidget), myLake1(new ControllerLake) {
  ui->setupUi(this);
  connect(ui->btnCreateOneLouncherStandard, &QPushButton::clicked, this,
          &ViewWidget::createLoungerTypeStandard);
  // connect(ui->btnCreateOneLouncherLuxurious, &QPushButton::clicked, this,
  // &ViewWidget::createLoungerTypeLuxuious);
  connect(ui->btnShowListLoungers, &QPushButton::clicked, this,
          &ViewWidget::showListLoungers);
  connect(ui->btnClearLog, &QPushButton::clicked, this, &ViewWidget::clearLog);
}

ViewWidget::~ViewWidget() {
  delete ui;
  delete myLake1;
}

void ViewWidget::createLoungerTypeStandard() {
  myLake1->createLoungerStandardType();
}

void ViewWidget::showListLoungers() {
  QStringList loungerStrings;

  loungerStrings = myLake1->getListLoungers();
  if (loungerStrings.size() > 0) {
    ui->edtListLoungers->clear();
    for (QString i : loungerStrings) {
      ui->edtListLoungers->appendPlainText(i);
    }
  }
}

void ViewWidget::clearLog() { ui->edtListLoungers->clear(); }
