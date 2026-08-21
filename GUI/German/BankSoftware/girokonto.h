#ifndef GIROKONTO_H
#define GIROKONTO_H

#include "konto.h"

/*
 * Girokonto
 * ---------
 * - Startet wie jedes Konto bei 0 EUR (kein Willkommensgeschenk).
 * - Besitzt zusätzlich einen Dispokredit (get-/set-Methode vorhanden,
 *   da es sich um ein "normales" Attribut handelt).
 * - Darf bis zur Höhe des Dispokredits überzogen werden.
 */
class Girokonto : public Konto
{
public:
    explicit Girokonto(double dispokredit = 0.0);

    double getDispokredit() const;
    void setDispokredit(double dispokredit);

    bool abheben(double betrag) override;
    std::string getKontoArt() const override;

private:
    double dispokredit;
};

#endif // GIROKONTO_H
