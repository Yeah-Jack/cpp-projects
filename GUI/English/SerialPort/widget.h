#ifndef WIDGET_H
#define WIDGET_H

#include <QSerialPort>
#include <QSerialPortInfo>
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
  void on_listPorts_clicked();

  void on_openPort_clicked();

  void on_setLedOn_clicked();

  void on_setLedOff_clicked();

private:
  Ui::Widget *ui;

  QSerialPort serial;
  QList<QSerialPortInfo> portList;
  QByteArray byteArray;

  void btnToggleLed();
};
#endif // WIDGET_H
