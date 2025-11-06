#include "data.h"

Data::Data() {
  for (int i = 0; i < 6; ++i) {
    LiegeStandard *neu = new LiegeStandard(1 + i * 2);
    listeLiegenStandard.push_back(neu);
  }

  for (int i = 0; i < 6; ++i) {
    LiegePremium *neu = new LiegePremium(2 + i * 2, 2 + i);
    listeLiegenPremium.push_back(neu);
  }
}

Data::~Data() {
  for (LiegeStandard *liege : listeLiegenStandard) {
    delete liege;
  }
  for (LiegePremium *liege : listeLiegenPremium) {
    delete liege;
  }
}

const std::vector<LiegeStandard *> &Data::standardLiegen() const {
  return listeLiegenStandard;
}

const std::vector<LiegePremium *> &Data::premiumLiegen() const {
  return listeLiegenPremium;
}

bool Data::bucheLiege(LiegeTyp typ) {
  if (typ == LiegeTyp::Standard) {
    for (LiegeStandard *liege : listeLiegenStandard) {
      if (!liege->istBelegt()) {
        return liege->buchen();
      }
    }
  } else {
    for (LiegePremium *liege : listeLiegenPremium) {
      if (!liege->istBelegt()) {
        return liege->buchen();
      }
    }
  }
  return false;
}

bool Data::storniereLiege(LiegeTyp typ) {
  if (typ == LiegeTyp::Standard) {
    for (LiegeStandard *liege : listeLiegenStandard) {
      if (liege->istBelegt()) {
        return liege->stornieren();
      }
    }
  } else {
    for (LiegePremium *liege : listeLiegenPremium) {
      if (liege->istBelegt()) {
        return liege->stornieren();
      }
    }
  }
  return false;
}
