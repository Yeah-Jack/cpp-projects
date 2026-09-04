#include "widget.h"
#include "ui_widget.h"

Widget::Widget(
    QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
  mySocket = new QTcpSocket(this);

  QObject::connect(mySocket, &QTcpSocket::readyRead, this, &Widget::readText);
  QObject::connect(mySocket, &QTcpSocket::connected, this, [this]() {
    ui->edtReceiveText->appendPlainText("[Client] Mit Server verbunden.");
  });
}

Widget::~Widget() { delete ui; }

void Widget::on_btnConnectServer_clicked() {
    if (mySocket->state() == QAbstractSocket::UnconnectedState) {
    mySocket->connectToHost("localhost", 4711);
    qDebug() << "Connecting to host";
  }
}

void Widget::on_btnSendText_clicked() {
  QString sendText = ui->edtSendText->text() + '\n';
  mySocket->write(sendText.toLatin1());
  qDebug() << sendText;
  ui->edtSendText->clear();
}

void Widget::readText() {
  while (mySocket->canReadLine()) {
    QString receivedText = mySocket->readLine().trimmed();
    ui->edtReceiveText->appendPlainText(receivedText);
  }
}
