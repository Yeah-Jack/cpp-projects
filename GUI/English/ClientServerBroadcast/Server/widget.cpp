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
  qDebug() << "Established new connection to" << myClientSocket;
}

void Widget::on_btnConnectClient_clicked() {
  if (!myServerSocket->isListening()) {
    if (myServerSocket->listen(QHostAddress::Any, 4711)) {
      qDebug() << "Listening";
    }
  }
}

void Widget::on_btnSendText_clicked() {
  QString sendText = ui->edtSendText->text() + '\n';
  myClientSocket->write(sendText.toLatin1());
  qDebug() << sendText;
}

void Widget::readText() {
  while (myClientSocket->canReadLine()) {
    QString receivedText = myClientSocket->readLine();
    ui->edtReceiveText->appendPlainText(receivedText);
  }
}
