#include "girokonto.h"

/*
 * Girokonto
 * Startet wie jedes Konto bei 0 EUR (kein Willkommensgeschenk).
 * Besitzt zusätzlich einen Dispokredit.
 */
Girokonto::Girokonto(double dispokredit)
    : Konto(), dispokredit(dispokredit >= 0.0 ? dispokredit : 0.0)
{
}

double Girokonto::getDispokredit() const
{
    return dispokredit;
}

void Girokonto::setDispokredit(double neuerDispokredit)
{
    if (neuerDispokredit >= 0.0)
    {
        dispokredit = neuerDispokredit;
    }
}

// Hebt einen Betrag ab, sofern der Kontostand mit dem Dispokredit noch gedeckt ist.
bool Girokonto::abheben(double betrag)
{
    if (betrag <= 0.0)
    {
        return false;
    }

    // Ein Girokonto darf bis zur Höhe des Dispokredits ins Minus rutschen.
    if (getKontostand() - betrag < -dispokredit)
    {
        return false;
    }

    setKontostandIntern(getKontostand() - betrag);
    return true;
}

// Gibt die konkrete Kontenart als Text für die Darstellung zurück.
std::string Girokonto::getKontoArt() const
{
    return "Girokonto";
}
