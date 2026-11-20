#ifndef WIDGET_H
#define WIDGET_H

#include "morsecode.h"
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
  void LedOn();
  void LedOff();

private slots:
  void on_listPorts_clicked();
  void on_openPort_clicked();
  void on_setLedOn_clicked();
  void on_setLedOff_clicked();
  void on_readData_clicked();
  void on_clearData_clicked();
  void on_clearLog_clicked();
  void on_translate_clicked();

private:
  Ui::Widget *ui;

  QSerialPort serial;
  QList<QSerialPortInfo> portList;

  MorseCode morse;

  void onSerialReadyRead();
};
#endif // WIDGET_H
