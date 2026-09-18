#ifndef MESSWERTMODEL_H
#define MESSWERTMODEL_H

#include <vector>

class MesswertModel {
public:
  MesswertModel();
  void addMesswerte();
  std::vector<int> getMesswerte();

private:
  std::vector<int> messwerte;
};

#endif // MESSWERTMODEL_H
