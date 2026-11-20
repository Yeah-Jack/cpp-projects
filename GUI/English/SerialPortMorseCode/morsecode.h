#ifndef MORSECODE_H
#define MORSECODE_H

#include <QString>

class Widget;
class MorseCode {
public:
  MorseCode(Widget *myWidget);
  void translate(QString text);

private:
  const int unit = 200;
  const int unitThree = unit * 3;
  const int unitSeven = unit * 7;
  Widget *myWidget;
};

#endif // MORSECODE_H
