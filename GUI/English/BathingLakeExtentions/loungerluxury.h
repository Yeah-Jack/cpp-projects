#ifndef LOUNGERLUXURY_H
#define LOUNGERLUXURY_H

#include "loungerstandardtype.h"
#include <QString>

/**
 * @brief Luxus-Klasse für Liege, erbt von LoungerStandardType
 */
class LoungerLuxury : public LoungerStandardType {
public:
  LoungerLuxury(unsigned long newInventoryNr, int pillows, QString coverColor,
                QString frameColor);

  int getNumPillows() const;
  QString getCoverColor() const;
  QString getFrameColor() const;

  void setNumPillows(int pillows);
  void setCoverColor(const QString &color);
  void setFrameColor(const QString &color);

  QString serialize();

private:
  int numPillows;
  QString coverColor;
  QString frameColor;
};

#endif // LOUNGERLUXURY_H
