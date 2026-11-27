#include "view.h"
#include "ui_view.h"

View::View(QWidget *parent) : QWidget(parent), ui(new Ui::View) {
  ui->setupUi(this);
  updateDisplay();
}

View::~View() { delete ui; }

void View::on_lightOn_clicked() {
  int bit = ui->roomSelection->currentIndex();
  myController.setBit(bit);
  updateDisplay();
}

void View::on_lightOff_clicked() {
  int bit = ui->roomSelection->currentIndex();
  myController.clearBit(bit);
  updateDisplay();
}

void View::updateDisplay() {
  colorFrame(ui->livingRoomFrame, myController.isLightOn(1));
  colorFrame(ui->bedroomFrame, myController.isLightOn(2));
  colorFrame(ui->childrensRoom1Frame, myController.isLightOn(3));
  colorFrame(ui->childrensRoom2Frame, myController.isLightOn(4));
  colorFrame(ui->kitchenFrame, myController.isLightOn(5));
  colorFrame(ui->hallwayFrame, myController.isLightOn(6));
  colorFrame(ui->bathroomFrame, myController.isLightOn(7));
}

void View::colorFrame(QFrame *frame, bool lightOn) {
  if (lightOn) {
    frame->setStyleSheet("background-color: yellow;");
  } else {
    frame->setStyleSheet("background-color: gray;");
  }
}
