#include "controller.h"

Controller::Controller() {}

QString Controller::listeAbrufen() const { return listeStringGenerieren(); }

bool Controller::liegeBuchen(LiegeTyp typ) { return data.bucheLiege(typ); }

bool Controller::buchungStornieren(LiegeTyp typ) {
  return data.storniereLiege(typ);
}

QString Controller::listeStringGenerieren() const {
  QString text;

  const std::vector<LiegeStandard *> &standard = data.standardLiegen();
  text += QString("Standard-Liegen (");
  text += QString::number(static_cast<int>(standard.size()));
  text += QString(" gesamt):\n");
  for (int i = 0; i < static_cast<int>(standard.size()); ++i) {
    LiegeStandard *liege = standard[static_cast<size_t>(i)];
    text += QString("  #");
    text += QString::number(i + 1);
    text += QString(" - ");
    if (liege->istBelegt()) {
      text += QString("belegt");
    } else {
      text += QString("frei");
    }
    text += QString(" (Zustand: ");
    text += QString::number(liege->zustand());
    text += QString(")\n");
  }

  const std::vector<LiegePremium *> &premium = data.premiumLiegen();
  text += QString("Premium-Liegen (");
  text += QString::number(static_cast<int>(premium.size()));
  text += QString(" gesamt):\n");
  for (int i = 0; i < static_cast<int>(premium.size()); ++i) {
    LiegePremium *liege = premium[static_cast<size_t>(i)];
    text += QString("  #");
    text += QString::number(i + 1);
    text += QString(" - ");
    if (liege->istBelegt()) {
      text += QString("belegt");
    } else {
      text += QString("frei");
    }
    text += QString(" (Zustand: ");
    text += QString::number(liege->zustand());
    text += QString(", Kissen: ");
    text += QString::number(liege->anzahlKissen());
    text += QString(")\n");
  }

  return text;
}
