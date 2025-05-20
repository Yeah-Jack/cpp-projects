#include "widget.h"
#include "ui_widget.h"
#include <cmath>

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget), calc(&dataStorage),
      newOperand(true) {
  ui->setupUi(this);
  updateDisplay("0");
}

Widget::~Widget() { delete ui; }

void Widget::updateDisplay(const QString &text) { ui->io->setText(text); }

void Widget::handleDigit(const QString &digit) {
  if (newOperand) {
    currentInput = digit;
    newOperand = false;
  } else {
    currentInput += digit;
  }
  updateDisplay(currentInput);
}

void Widget::handleOperation(const QString &op) {
  if (!currentInput.isEmpty()) {
    operandA_str = currentInput;
    currentInput.clear();
    operation = op;
    newOperand = true;
  }
}

void Widget::performCalculation() {
  if (operandA_str.isEmpty() || operation.isEmpty() || currentInput.isEmpty()) {
    if (operation != "sqrt" && operation != "pow" && operation != "formula") {
      updateDisplay("Fehler: Unvollständige Eingabe");
      return;
    }
  }

  operandB_str = currentInput;
  bool okA, okB;
  double valueA = operandA_str.toDouble(&okA);
  double valueB = operandB_str.toDouble(&okB);

  int intValueA = operandA_str.toInt(&okA);
  int intValueB = operandB_str.toInt(&okB);

  dataStorage.clearError();

  if (operation == "+") {
    if (okA && okB) {
      dataStorage.setOperandA(valueA);
      dataStorage.setOperandB(valueB);
      if (calc.add()) {
        updateDisplay(QString::number(dataStorage.getResult()));
      } else {
        updateDisplay("Fehler: Addieren");
      }
    }
  } else if (operation == "-") {
    if (okA && okB) {
      dataStorage.setOperandA(valueA);
      dataStorage.setOperandB(valueB);
      if (calc.sub()) {
        updateDisplay(QString::number(dataStorage.getResult()));
      } else {
        updateDisplay("Fehler: Subtrahieren");
      }
    }
  } else if (operation == "*") {
    if (okA && okB) {
      dataStorage.setOperandA(valueA);
      dataStorage.setOperandB(valueB);
      if (calc.mul()) {
        updateDisplay(QString::number(dataStorage.getResult()));
      } else {
        updateDisplay("Fehler: Multiplizieren");
      }
    }
  } else if (operation == "/") {
    if (okA && okB) {
      dataStorage.setOperandA(valueA);
      dataStorage.setOperandB(valueB);
      if (calc.div()) {
        updateDisplay(QString::number(dataStorage.getResult()));
      } else {
        updateDisplay(QString::fromStdString(dataStorage.getErrorMessage()));
      }
    }
  } else if (operation == "pow") {
    if (okA && okB) {
      dataStorage.setOperandA(valueA);
      dataStorage.setOperandB(valueB);
      if (calc.pow()) {
        updateDisplay(QString::number(dataStorage.getResult()));
      } else {
        updateDisplay(QString::fromStdString(dataStorage.getErrorMessage()));
      }
    }
  } else if (operation == "sqrt") {
    if (okA) {
      dataStorage.setOperandA(valueA);
      if (calc.sqrt()) {
        updateDisplay(QString::number(dataStorage.getResult()));
      } else {
        updateDisplay(QString::fromStdString(dataStorage.getErrorMessage()));
      }
    }
  } else if (operation == "AND") {
    if (okA && okB) {
      dataStorage.setIntOperandA(intValueA);
      dataStorage.setIntOperandB(intValueB);
      if (calc.binaryAnd()) {
        updateDisplay(QString::number(dataStorage.getIntResult()));
      } else {
        updateDisplay("Fehler: AND");
      }
    }
  } else if (operation == "OR") {
    if (okA && okB) {
      dataStorage.setIntOperandA(intValueA);
      dataStorage.setIntOperandB(intValueB);
      if (calc.binaryOr()) {
        updateDisplay(QString::number(dataStorage.getIntResult()));
      } else {
        updateDisplay("Error: OR");
      }
    }
  } else if (operation == "NAND") {
    if (okA && okB) {
      dataStorage.setIntOperandA(intValueA);
      dataStorage.setIntOperandB(intValueB);
      if (calc.binaryNand()) {
        updateDisplay(QString::number(dataStorage.getIntResult()));
      } else {
        updateDisplay("Fehler: NAND");
      }
    }
  } else if (operation == "formula") {
    if (!currentInput.isEmpty()) {
      if (calc.calculateFormula(currentInput.toStdString())) {
        updateDisplay(QString::number(dataStorage.getResult()));
      } else {
        updateDisplay(QString::fromStdString(dataStorage.getErrorMessage()));
      }
    }
  }

  if (dataStorage.getError()) {
    updateDisplay(QString::fromStdString(dataStorage.getErrorMessage()));
  }

  currentInput = ui->io->text();
  operandA_str.clear();
  operandB_str.clear();
  operation.clear();
  newOperand = true;
}

void Widget::on_number0_clicked() { handleDigit("0"); }
void Widget::on_number1_clicked() { handleDigit("1"); }
void Widget::on_number2_clicked() { handleDigit("2"); }
void Widget::on_number3_clicked() { handleDigit("3"); }
void Widget::on_number4_clicked() { handleDigit("4"); }
void Widget::on_number5_clicked() { handleDigit("5"); }
void Widget::on_number6_clicked() { handleDigit("6"); }
void Widget::on_number7_clicked() { handleDigit("7"); }
void Widget::on_number8_clicked() { handleDigit("8"); }
void Widget::on_number9_clicked() { handleDigit("9"); }

void Widget::on_add_clicked() { handleOperation("+"); }
void Widget::on_sub_clicked() { handleOperation("-"); }
void Widget::on_mul_clicked() { handleOperation("*"); }
void Widget::on_div_clicked() { handleOperation("/"); }
void Widget::on_pow_clicked() {
  if (!currentInput.isEmpty()) {
    operandA_str = currentInput;
    currentInput.clear();
  }
  operation = "pow";
  newOperand = true;
}

void Widget::on_sqrt_clicked() {
  if (!currentInput.isEmpty()) {
    operandA_str = currentInput;
    operation = "sqrt";
    performCalculation();
  } else {
    updateDisplay("Fehler: Eingabe für Wurzel");
  }
}

void Widget::on_binaryAnd_clicked() { handleOperation("AND"); }
void Widget::on_binaryOr_clicked() { handleOperation("OR"); }
void Widget::on_binaryNand_clicked() { handleOperation("NAND"); }

void Widget::on_equals_clicked() { performCalculation(); }
