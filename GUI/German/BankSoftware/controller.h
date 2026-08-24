#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "data.h"

class Widget;

/*
 * Controller
 * ----------
 * Enthält die gesamte Anwendungslogik des Programms.
 * Die View kennt den Controller über einen Pointer und ruft
 * ausschließlich dessen öffentliche Methoden auf.
 */
class Controller
{
public:
    Controller();

    // Verknüpft den Controller mit der aktiven View.
    void setView(Widget* view);

    // --- Konten anlegen -----------------------------------------------
    unsigned int neuesGirokonto(double dispokredit);
    unsigned int neuesSparkonto(double willkommensgeschenk);

    // --- Kontoaktionen (Zugriff über Kontonummer) ----------------------
    // Geben bei Erfolg true zurück, sonst false + Fehlermeldung in fehlermeldung.
    bool einzahlen(unsigned int kontoNr, double betrag, std::string& fehlermeldung);
    bool abheben(unsigned int kontoNr, double betrag, std::string& fehlermeldung);
    bool dispokreditAendern(unsigned int kontoNr, double neuerDispokredit, std::string& fehlermeldung);

    // --- Abfragen für die Anzeige in der View ---------------------------
    bool kontoVorhanden(unsigned int kontoNr) const;
    std::string kontoInfo(unsigned int kontoNr) const;
    std::vector<std::string> kontenAlsText(std::size_t maxAnzahl) const;
    std::size_t getAnzahlKonten() const;

    void erzeugeTestkonten(std::size_t anzahl);

private:
  std::unique_ptr<Data> model;
  Widget *view;
};

#endif // CONTROLLER_H
