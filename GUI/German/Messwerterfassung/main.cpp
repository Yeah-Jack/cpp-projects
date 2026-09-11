#include "widget.h"
#include "messwertmodel.h"
#include "messwertcontroller.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  Widget view;
  MesswertModel model;
  MesswertController controller(&model, &view);

  view.show();
  return a.exec();
}
