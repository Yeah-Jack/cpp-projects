#include "data.h"

double data::getOperandA() const { return operandA; }
double data::getOperandB() const { return operandB; }
double data::getResult() const { return result; }
int data::getIntOperandA() const { return intOperandA; }
int data::getIntOperandB() const { return intOperandB; }
int data::getIntResult() const { return intResult; }
bool data::getError() const { return error; }
std::string data::getErrorMessage() const { return errorMessage; }

void data::setOperandA(double value) { operandA = value; }
void data::setOperandB(double value) { operandB = value; }
void data::setResult(double value) { result = value; }
void data::setIntOperandA(int value) { intOperandA = value; }
void data::setIntOperandB(int value) { intOperandB = value; }
void data::setIntResult(int value) { intResult = value; }
void data::setError(bool flag) { error = flag; }
void data::setErrorMessage(const std::string message) {
  errorMessage = message;
}

void data::clearError() {
  errorMessage = "";
  error = false;
}