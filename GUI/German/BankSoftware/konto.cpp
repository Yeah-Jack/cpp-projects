#include "konto.h"
#include <sstream>

unsigned int Konto::nextKontoNr = 1;

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
    ausgabe << "Konto Nr. " << kontoNr << " | Kontostand: " << kontostand << " EUR";
    return ausgabe.str();
}
