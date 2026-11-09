#include "widget.h"
#include "ui_widget.h"

Widget::Widget(
    QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
}

Widget::~Widget() { delete ui; }

void Widget::on_listPorts_clicked() {
  portList = QSerialPortInfo::availablePorts();

  ui->listPortsResult->clear();
  for (int i = 0; i < portList.size(); i++) {
    ui->listPortsResult
        ->appendPlainText(QString::number(i) + " " + portList[i].portName() +
                          " " + portList[i].description());
  }
}

void Widget::on_openPort_clicked() {}

void Widget::on_setLedOn_clicked() {}

void Widget::on_setLedOff_clicked() {}
