#include "messwertcontroller.h"

MesswertController::MesswertController(MesswertModel *model, Widget *view)
    : model(model), view(view) {
  view->setController(this);
}

void MesswertController::getDatenAnfordern() {
  view->leereAnzeige();
  model->addMesswerte();
  view->zeigeMesswerte(model->getMesswerte());
}
