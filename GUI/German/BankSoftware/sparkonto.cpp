#include "sparkonto.h"

/*
 * Sparkonto
 * - Die Bank kann beim Anlegen optional ein Willkommensgeschenk als
 *   Startwert für den Kontostand vergeben. Das Geschenk ist kein
 *   dauerhaftes Attribut des Kontos, sondern legt lediglich den
 *   Anfangswert des Kontostands fest.
 * - Darf nicht überzogen werden.
 */
Sparkonto::Sparkonto(double willkommensgeschenk)
    : Konto()
{
    if (willkommensgeschenk > 0.0)
    {
        setKontostandIntern(willkommensgeschenk);
    }
}

// Hebt einen Betrag nur dann ab, wenn das Sparkonto dadurch nicht ins Minus fällt.
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

// Gibt den Namen der Kontoart für die Anzeige zurück.
std::string Sparkonto::getKontoArt() const
{
    return "Sparkonto";
}
