#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "data.h"

#include <QString>

class Controller {
public:
  Controller();

  QString listeAbrufen() const;
  bool liegeBuchen(LiegeTyp typ);
  bool buchungStornieren(LiegeTyp typ);

private:
  QString listeStringGenerieren() const;

  Data data;
};

#endif // CONTROLLER_H
