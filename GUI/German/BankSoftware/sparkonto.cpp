#include "sparkonto.h"

Sparkonto::Sparkonto(double willkommensgeschenk)
    : Konto()
{
    if (willkommensgeschenk > 0.0)
    {
        setKontostandIntern(willkommensgeschenk);
    }
}

bool Sparkonto::abheben(double betrag)
{
    if (betrag <= 0.0)
    {
        return false;
    }

    // Ein Sparkonto darf nicht überzogen werden.
    if (getKontostand() - betrag < 0.0)
    {
        return false;
    }

    setKontostandIntern(getKontostand() - betrag);
    return true;
}

std::string Sparkonto::getKontoArt() const
{
    return "Sparkonto";
}
