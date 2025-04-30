#include "ui.h"
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);

  ui myUI;
  myUI.main();

  return 0;
}