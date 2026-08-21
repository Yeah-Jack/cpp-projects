#include "konto.h"
#include <sstream>
#include <iomanip>

// Vorlage für die fortlaufende Kontonummer. Startwert frei wählbar,
// z.B. beginnen echte Banken auch nicht bei 0.
unsigned int Konto::nextKontoNr = 1000;

Konto::Konto()
    : kontoNr(nextKontoNr), kontostand(0.0)
{
    // Erst wird die aktuelle Nummer aus der Vorlage vergeben (s.o. in der
    // Initialisierungsliste), anschließend wird die Vorlage um eins erhöht.
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

void Konto::einzahlen(double betrag)
{
    if (betrag > 0.0)
    {
        kontostand += betrag;
    }
}

void Konto::setKontostandIntern(double betrag)
{
    kontostand = betrag;
}

std::string Konto::toString() const
{
    std::ostringstream ausgabe;
    ausgabe << "Konto Nr. " << kontoNr << " | Kontostand: "
            << std::fixed << std::setprecision(2) << kontostand << " EUR";
    return ausgabe.str();
}
