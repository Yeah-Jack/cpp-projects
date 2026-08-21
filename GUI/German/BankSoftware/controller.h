#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>
#include <string>
#include <vector>
#include <cstddef>
#include "data.h"

class Widget; // Vorwärtsdeklaration der View (siehe widget.h)

/*
 * Controller
 * ----------
 * Enthält die gesamte Ablauf- und Anwendungslogik des Programms und bildet
 * das Bindeglied zwischen Model (Data) und View (Widget):
 * - nimmt Benutzeraktionen von der View entgegen (z.B. "Konto anlegen"),
 * - prüft Eingaben / wendet fachliche Regeln an bzw. delegiert diese an die
 *   Konto-Objekte selbst (einzahlen()/abheben()),
 * - liest/schreibt Daten über das Model (Data),
 * - bereitet Ergebnisse für die Anzeige in der View auf.
 *
 * Die View kennt den Controller nur über einen klassischen Pointer und ruft
 * ausschließlich dessen öffentliche Methoden auf - sie enthält selbst keine
 * fachliche Logik.
 */
class Controller
{
public:
    Controller();

    // Verknüpft den Controller mit der aktiven View (klassischer Pointer,
    // der Controller übernimmt hier bewusst kein Eigentum an der View).
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

    // Erzeugt "anzahl" zufällige Testkonten (Anforderung: mind. 50.000 Konten
    // müssen verwaltbar sein).
    void erzeugeTestkonten(std::size_t anzahl);

private:
    std::unique_ptr<Data> model; // Controller besitzt und verwaltet das Model
    Widget* view;                // klassischer Pointer, kein Besitz
};

#endif // CONTROLLER_H
