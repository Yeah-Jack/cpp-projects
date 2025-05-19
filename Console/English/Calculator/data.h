#ifndef DATA_H
#define DATA_H

#include <iostream>

class data {
public:
  // data();

  double getOperandA() const;
  double getOperandB() const;
  double getResult() const;
  int getIntOperandA() const;
  int getIntOperandB() const;
  int getIntResult() const;
  bool getError() const;
  std::string getErrorMessage() const;

  void setOperandA(double value);
  void setOperandB(double value);
  void setResult(double value);
  void setIntOperandA(int value);
  void setIntOperandB(int value);
  void setIntResult(int value);
  void setError(bool flag);
  void setErrorMessage(const std::string message);

  void clearError();

private:
  double operandA = 0.0;
  double operandB = 0.0;
  double result = 0.0;
  int intOperandA = 0;
  int intOperandB = 0;
  int intResult = 0;
  bool error = false;
  std::string errorMessage;
};

#endif // DATA_H
