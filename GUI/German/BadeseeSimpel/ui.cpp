#include "ui.h"

#include <QComboBox>
#include <QLabel>
#include <QPushButton>

#include "ui_ui.h"

namespace {
QString liegeTypAlsText(
    LiegeTyp typ) {
  if (typ == LiegeTyp::Standard) {
    return QString("Standard-Liege");
  }
  return QString("Premium-Liege");
}
} // namespace

UI::UI(
    QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::UI),
      listeLabel(nullptr),
      statusLabel(nullptr),
      typAuswahl(nullptr) {
  ui->setupUi(this);

  typAuswahl = ui->comboBoxTyp;
  listeLabel = ui->labelListe;
  statusLabel = ui->labelStatus;

  connect(ui->buttonListe, &QPushButton::clicked, this, &UI::listeAnzeigen);
  connect(ui->buttonBuchen, &QPushButton::clicked, this, &UI::liegeBuchen);
  connect(ui->buttonStornieren, &QPushButton::clicked, this, &UI::buchungStornieren);

  setWindowTitle(QString("Badesee Liegenverwaltung"));

  listeAnzeigen();
  zeigeStatus(QString("Willkommen! Wählen Sie eine Aktion."));
}

UI::~UI() {
  delete ui;
}

void UI::listeAnzeigen() {
  const QString liste = controller.listeAbrufen();
  listeLabel->setText(liste);
}

void UI::liegeBuchen() {
  const LiegeTyp typ = ausgewaehlterTyp();
  const bool erfolg = controller.liegeBuchen(typ);
  listeAnzeigen();
  if (erfolg) {
    zeigeStatus(liegeTypAlsText(typ) + QString(" wurde gebucht."));
  } else {
    zeigeStatus(liegeTypAlsText(typ) + QString(" ist leider nicht verfügbar."));
  }
}

void UI::buchungStornieren() {
  const LiegeTyp typ = ausgewaehlterTyp();
  const bool erfolg = controller.buchungStornieren(typ);
  listeAnzeigen();
  if (erfolg) {
    zeigeStatus(liegeTypAlsText(typ) + QString(" wurde freigegeben."));
  } else {
    zeigeStatus(QString("Keine gebuchte ") + liegeTypAlsText(typ) + QString(" vorhanden."));
  }
}

LiegeTyp UI::ausgewaehlterTyp() const {
  const int index = typAuswahl->currentIndex();
  if (index == 0) {
    return LiegeTyp::Standard;
  }
  return LiegeTyp::Premium;
}

void UI::zeigeStatus(
    const QString &text) {
  statusLabel->setText(text);
}
