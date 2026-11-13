#include "widget.h"
#include "ui_widget.h"

Widget::Widget(
    QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
  connect(&serial, &QSerialPort::readyRead, this, &Widget::onSerialReadyRead);
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

  ui->selectPort->setMaximum(portList.size() - 1);
}

void Widget::on_openPort_clicked() {
  if (!portList.isEmpty()) {
    serial.setPort(portList[ui->selectPort->value()]);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    serial.setParity(QSerialPort::NoParity);

    serial.open(QIODevice::ReadWrite);
    if (serial.isOpen()) {
      serial.setDataTerminalReady(true);
      int index = ui->selectPort->value();
      ui->log->appendPlainText("Opened Port " + QString::number(index) + " (" +
                               portList[index].portName() + ")");
    } else
      ui->log->appendPlainText("Port error");
  }
}

void Widget::on_setLedOn_clicked() {
  char sendChar;
  QDataStream dataStream(&serial);

  sendChar = 0x05;
  dataStream << (quint8)sendChar;
}

void Widget::on_setLedOff_clicked() {
  char sendChar;
  QDataStream dataStream(&serial);

  sendChar = 0x06;
  dataStream << (quint8)sendChar;
}

void Widget::on_readData_clicked() {
  char sendChar;
  QDataStream dataStream(&serial);

  sendChar = 0x07;
  dataStream << (quint8)sendChar;
}

void Widget::onSerialReadyRead() {
  QByteArray recByteArray = serial.readAll();
  QString outString;

  for (int i = 0; i < recByteArray.size(); i++) {
    quint8 byte = (quint8)recByteArray[i];
    outString.append(QString::number(byte, 16) + " ");
  }

  ui->log->appendPlainText(outString);
}

void Widget::on_clearData_clicked() {
  char sendChar;
  QDataStream dataStream(&serial);

  sendChar = 0x08;
  dataStream << (quint8)sendChar;
}

void Widget::on_clearLog_clicked() { ui->log->clear(); }
