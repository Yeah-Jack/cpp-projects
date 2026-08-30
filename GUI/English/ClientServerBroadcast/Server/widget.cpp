#include "widget.h"
#include "ui_widget.h"

Widget::Widget(
    QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);

  myServerSocket = new QTcpServer(this);
  myClientSocket = nullptr;

  QObject::connect(myServerSocket, &QTcpServer::newConnection, this,
                   &Widget::newConnection);
}

Widget::~Widget() { delete ui; }

void Widget::newConnection() {
  myClientSocket = myServerSocket->nextPendingConnection();
  connect(myClientSocket, &QTcpSocket::readyRead, this, &Widget::readText);
}

void Widget::on_btnConnectClient_clicked() {
  if (!myServerSocket->isListening()) {
    myServerSocket->listen(QHostAddress::Any, 4711);
  }
}

void Widget::on_btnSendText_clicked() {
  QString sendText;

  sendText = ui->edtSendText->text();

  myClientSocket->write(sendText.toLatin1());
  qDebug() << sendText;
}

void Widget::readText() {
  QString receivedText;

  receivedText = myClientSocket->readLine();
  ui->edtReceiveText->appendPlainText(receivedText);
}