#ifndef SPARKONTO_H
#define SPARKONTO_H

#include "konto.h"

/*
 * Sparkonto
 * ---------
 * - Startet grundsätzlich bei 0 EUR (wie jedes Konto).
 * - Die Bank kann beim Anlegen optional ein Willkommensgeschenk als
 *   Startwert für den Kontostand vergeben. Das Geschenk ist kein
 *   dauerhaftes Attribut des Kontos, sondern legt lediglich den
 *   Anfangswert des Kontostands fest - es gibt daher bewusst keine
 *   eigene get-/set-Methode dafür (Kontostand ist ja bereits abrufbar).
 * - Darf nicht überzogen werden.
 */
class Sparkonto : public Konto
{
public:
    explicit Sparkonto(double willkommensgeschenk = 0.0);

    bool abheben(double betrag) override;
    std::string getKontoArt() const override;
};

#endif // SPARKONTO_H
