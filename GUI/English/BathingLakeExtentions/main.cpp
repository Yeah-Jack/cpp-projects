#include "viewwidget.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  ViewWidget w;
  w.show();
  return a.exec();
}
