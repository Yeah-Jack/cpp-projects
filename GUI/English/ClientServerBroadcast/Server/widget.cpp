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
  connect(myClientSocket, &QTcpSocket::readyRead, this, &Widget::readMessage);
}

void Widget::readMessage() {}

void Widget::on_pushButton_clicked() {
  if (!myServerSocket->isListening()) {
    myServerSocket->listen(QHostAddress::Any, 4711);
  }
}
