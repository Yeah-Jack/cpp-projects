#include "view.h"
#include "ui_view.h"

#include <QDebug>

View::View(
    QWidget *parent)
    : QWidget(parent), ui(new Ui::View) {
  ui->setupUi(this);
}

View::~View() { delete ui; }

void View::on_lightOn_clicked() {
  qDebug() << "Turning on light for room:" << ui->roomSelection->currentIndex();

  myController.setBit(ui->roomSelection->currentIndex());
}

void View::on_lightOff_clicked() {
  qDebug() << "Turning off light for room:"
           << ui->roomSelection->currentIndex();

  myController.deleteBit(ui->roomSelection->currentIndex());
}
