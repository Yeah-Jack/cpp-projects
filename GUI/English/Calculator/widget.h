#ifndef WIDGET_H
#define WIDGET_H

#include "calculator.h"
#include "data.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
  Q_OBJECT

public:
  Widget(QWidget *parent = nullptr);
  ~Widget();

private slots:
  void on_number0_clicked();
  void on_number1_clicked();
  void on_number2_clicked();
  void on_number3_clicked();
  void on_number4_clicked();
  void on_number5_clicked();
  void on_number6_clicked();
  void on_number7_clicked();
  void on_number8_clicked();
  void on_number9_clicked();
  void on_add_clicked();
  void on_sub_clicked();
  void on_mul_clicked();
  void on_div_clicked();
  void on_equals_clicked();
  void on_sqrt_clicked();
  void on_pow_clicked();
  void on_binaryAnd_clicked();
  void on_binaryOr_clicked();
  void on_binaryNand_clicked();

private:
  Ui::Widget *ui;
  class data dataStorage;
  calculator calc;
  QString currentInput;
  QString operandA_str;
  QString operandB_str;
  QString operation;
  bool newOperand;

  void handleDigit(const QString &digit);
  void handleOperation(const QString &op);
  void updateDisplay(const QString &text);
  void performCalculation();
};
#endif // WIDGET_H
