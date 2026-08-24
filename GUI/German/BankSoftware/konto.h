#ifndef KONTO_H
#define KONTO_H

#include <string>

class Konto
{
public:
    Konto();
    virtual ~Konto() = default;

    unsigned int getKontoNr() const;
    double getKontostand() const;

    virtual void einzahlen(double betrag);
    virtual bool abheben(double betrag) = 0;

    virtual std::string getKontoArt() const = 0;

    virtual std::string toString() const;

  protected:
    void setKontostandIntern(double betrag);

  private:
    static unsigned int nextKontoNr;
    const unsigned int kontoNr;
    double kontostand;
};

#endif // KONTO_H
