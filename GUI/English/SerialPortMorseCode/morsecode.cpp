#include "morsecode.h"
#include "widget.h"

MorseCode::MorseCode(Widget *myWidget) { this->myWidget = myWidget; }

void MorseCode::translate(QString text) {
  for (int i = 0; i < text.length(); i++) {
    text = text.toUpper();
    QChar currentChar = text[i];

    switch (currentChar.toLatin1()) {
    case 'A':
      myWidget->LedOn();
      break;
    case 'B':
      myWidget->LedOff();
    default:
      break;
    }
  }
}
