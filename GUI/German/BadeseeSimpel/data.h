#ifndef DATA_H
#define DATA_H

#include "liege.h"

#include <vector>

class Data {
public:
  Data();
  ~Data();

  const std::vector<LiegeStandard *> &standardLiegen() const;
  const std::vector<LiegePremium *> &premiumLiegen() const;

  bool bucheLiege(LiegeTyp typ);
  bool storniereLiege(LiegeTyp typ);

private:
  std::vector<LiegeStandard *> listeLiegenStandard;
  std::vector<LiegePremium *> listeLiegenPremium;
};

#endif // DATA_H
