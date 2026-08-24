#ifndef GIROKONTO_H
#define GIROKONTO_H

#include "konto.h"

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
