#include "girokonto.h"

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

std::string Girokonto::getKontoArt() const
{
    return "Girokonto";
}
