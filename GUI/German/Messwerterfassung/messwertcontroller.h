#ifndef MESSWERTCONTROLLER_H
#define MESSWERTCONTROLLER_H

#include "messwertmodel.h"
#include "widget.h"

class MesswertController {
public:
  MesswertController(MesswertModel *model, Widget *view);

  void getDatenAnfordern();

private:
  MesswertModel *model;
  Widget *view;
};

#endif // MESSWERTCONTROLLER_H
