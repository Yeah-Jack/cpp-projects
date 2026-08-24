#include "konto.h"
#include <sstream>

unsigned int Konto::nextKontoNr = 1;

/*
 * Konto
 * Fasst alle Gemeinsamkeiten von Girokonto und Sparkonto zusammen.
 * - Jedes Konto erhält beim Anlegen automatisch eine fortlaufende Kontonummer
 *   aus der klasseneigenen Vorlage "nextKontoNr".
 * - Der Kontostand startet bei 0 EUR und wird ausschließlich über die Methoden
 *   einzahlen() und abheben() verändert.
 * - abheben() verhält sich je nach Kontoart unterschiedlich (Sparkonto darf
 *   nicht überzogen werden, Girokonto darf bis zum Dispokredit überzogen
 *   werden).
 */
Konto::Konto()
    : kontoNr(nextKontoNr), kontostand(0.0)
{
    ++nextKontoNr;
}

unsigned int Konto::getKontoNr() const
{
    return kontoNr;
}

double Konto::getKontostand() const
{
    return kontostand;
}

// Zahlt einen positiven Betrag auf das Konto ein und erhöht damit den Kontostand.
void Konto::einzahlen(double betrag)
{
    if (betrag > 0.0)
    {
        kontostand += betrag;
    }
}

// Aktualisiert den Kontostand intern, z. B. nach einer erfolgreichen Abhebung oder einem Startguthaben.
void Konto::setKontostandIntern(double betrag)
{
    kontostand = betrag;
}

// Erstellt eine kompakte, lesbare Textdarstellung des Kontos für die Ausgabe.
std::string Konto::toString() const
{
    std::ostringstream ausgabe;
    ausgabe << "Konto Nr. " << kontoNr << " | Kontostand: " << kontostand << " EUR";
    return ausgabe.str();
}
