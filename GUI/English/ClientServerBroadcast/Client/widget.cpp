#include "widget.h"
#include "ui_widget.h"

Widget::Widget(
    QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
  mySocket = new QTcpSocket(this);
}

Widget::~Widget() { delete ui; }

void Widget::on_btnConnectServer_clicked() {
  mySocket->connectToHost("localhost", 4711);
  QObject::connect(mySocket, &QTcpSocket::readyRead, this, &Widget::readText);
}

void Widget::on_btnSendText_clicked() {
  QString sendText;

  sendText = ui->edtSendText->text() + "\n";

  mySocket->write(sendText.toLatin1());
  qDebug() << sendText;
}

void Widget::readText() {
  while (mySocket->canReadLine()) {
    QString receivedText = mySocket->readLine();
    ui->edtReceiveText->appendPlainText(receivedText);
  }
}
