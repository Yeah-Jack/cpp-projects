#ifndef SPARKONTO_H
#define SPARKONTO_H

#include "konto.h"

class Sparkonto : public Konto
{
public:
    explicit Sparkonto(double willkommensgeschenk = 0.0);

    bool abheben(double betrag) override;
    std::string getKontoArt() const override;
};

#endif // SPARKONTO_H
