#include "widget.h"
#include "ui_widget.h"

Widget::Widget(
    QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);

  myServerSocket = new QTcpServer(this);

  QObject::connect(myServerSocket, &QTcpServer::newConnection, this,
                   &Widget::newConnection);
}

Widget::~Widget() { delete ui; }

void Widget::newConnection() {
  QTcpSocket *clientSocket = myServerSocket->nextPendingConnection();
  myClientSockets.push_back(clientSocket);

  connect(clientSocket, &QTcpSocket::readyRead, this, &Widget::readText);

  ui->edtReceiveText->appendPlainText(QString(
      "[Server] Neuer Client verbunden: " + clientLabel(clientSocket) +
      " (aktuell " + QString::number(myClientSockets.size()) + " Client(s))"));
  qDebug() << "Established new connection to" << clientSocket;
}

void Widget::on_btnConnectClient_clicked() {
  if (!myServerSocket->isListening()) {
    if (myServerSocket->listen(QHostAddress::Any, 4711)) {
      qDebug() << "Listening";
      ui->edtReceiveText->appendPlainText(
          "[Server] Warte auf Client-Verbindungen ...");
    }
  }
}

void Widget::on_btnSendText_clicked() {
  QString sendText = ui->edtSendText->text() + '\n';

  for (QTcpSocket *iterator : myClientSockets) {
    iterator->write(sendText.toLatin1());
  }

  qDebug() << sendText;
  ui->edtSendText->clear();
}

void Widget::readText() {
  QTcpSocket *clientSocket = qobject_cast<QTcpSocket *>(sender());

  while (clientSocket->canReadLine()) {
    QString receivedText = clientSocket->readLine().trimmed();
    ui->edtReceiveText->appendPlainText(
        QString(clientLabel(clientSocket) + ": " + receivedText));

    QString sendText = receivedText + '\n';
    for (QTcpSocket *iterator : myClientSockets) {
      if (iterator != clientSocket) {
        iterator->write(sendText.toLatin1());
      }
    }
  }
}

QString Widget::clientLabel(QTcpSocket *socket) const {
  return QString("%1:%2")
      .arg(socket->peerAddress().toString())
      .arg(socket->peerPort());
}
