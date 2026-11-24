#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QtTypes>

class Controller {
public:
  Controller();

  void setBit(int bit);
  void deleteBit(int bit);
  bool checkBit(int bit);

private:
  quint8 lights = 0;
};

#endif // CONTROLLER_H
