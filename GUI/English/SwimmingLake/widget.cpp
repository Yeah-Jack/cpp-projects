#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget), gui(new GUI()) {
  ui->setupUi(this);

  // Connect buttons to slots
  connect(ui->rentLoungerButton, &QPushButton::clicked, this,
          &Widget::onRentLoungerClicked);
  connect(ui->parkBikeButton, &QPushButton::clicked, this,
          &Widget::onParkBikeClicked);
  connect(ui->refreshButton, &QPushButton::clicked, this,
          &Widget::onRefreshClicked);

  // Initial display update
  updateDisplay();
}

Widget::~Widget() {
  delete ui;
  delete gui;
}

void Widget::onRentLoungerClicked() {
  if (gui->rentLounger()) {
    ui->logTextEdit->append("Lounger rented successfully!");
  } else {
    ui->logTextEdit->append("No loungers available!");
  }
  updateDisplay();
}

void Widget::onParkBikeClicked() {
  gui->parkBike();
  ui->logTextEdit->append("Bike parked!");
  updateDisplay();
}

void Widget::onRefreshClicked() {
  updateDisplay();
  ui->logTextEdit->append("Information refreshed!");
}

void Widget::updateDisplay() {
  double temp = gui->viewCurrentWaterTemperature();
  ui->temperatureLabel->setText(QString("Water Temperature: %1 °C").arg(temp));

  unsigned short quality = gui->viewCurrentWaterQuality();
  ui->qualityLabel->setText(QString("Water Quality: %1/10").arg(quality));

  int visitors = gui->viewCurrentNumberOfVisitors();
  ui->visitorsLabel->setText(QString("Current Visitors: %1").arg(visitors));
}
