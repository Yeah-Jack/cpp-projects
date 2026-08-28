#ifndef WIDGET_H
#define WIDGET_H

#include <QDebug>
#include <QTcpSocket>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
  Q_OBJECT

public:
  Widget(QWidget *parent = nullptr);
  ~Widget();

private slots:
  void on_btnConnectServer_clicked();
  void on_btnSendText_clicked();

private:
  Ui::Widget *ui;
  QTcpSocket *mySocket;
  void readData();
};
#endif // WIDGET_H
