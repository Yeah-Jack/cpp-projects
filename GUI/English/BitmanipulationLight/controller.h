#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QtTypes>

class Controller {
public:
  Controller();

  void setBit(int bit);
  void clearBit(int bit);
  bool checkBit(int bit) const;
  bool isLightOn(int room) const;

private:
  quint8 lights = 0;
  const int centralBit = 0;
};

#endif // CONTROLLER_H
