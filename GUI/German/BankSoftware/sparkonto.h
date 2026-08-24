#ifndef SPARKONTO_H
#define SPARKONTO_H

#include "konto.h"

/*
 * Sparkonto
 * ---------
 * - Die Bank kann beim Anlegen optional ein Willkommensgeschenk als
 *   Startwert für den Kontostand vergeben. Das Geschenk ist kein
 *   dauerhaftes Attribut des Kontos, sondern legt lediglich den
 *   Anfangswert des Kontostands fest.
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
