#ifndef LOUNGERSTANDARDTYPE_H
#define LOUNGERSTANDARDTYPE_H

#include <QString>

/**
 * @brief Basisklasse für Liege
 */
class LoungerStandardType {
public:
  LoungerStandardType(unsigned long newInventoryNr);

  unsigned long getInventoryNr();
  QString serialize();

private:
  unsigned long inventoryNr;
  unsigned short leaseTime;
};

#endif // LOUNGERSTANDARDTYPE_H
