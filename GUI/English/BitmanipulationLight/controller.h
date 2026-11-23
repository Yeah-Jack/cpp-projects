#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QtTypes>

class Controller {
public:
  Controller();

private:
  quint8 currentState = 0;
};

#endif // CONTROLLER_H
