#ifndef MESSWERTMODEL_H
#define MESSWERTMODEL_H

#include <vector>

class MesswertModel {
public:
  MesswertModel();
  const std::vector<int> &getMesswerte() const;
  void addMesswerte();

private:
  std::vector<int> messwerte;
};

#endif // MESSWERTMODEL_H
