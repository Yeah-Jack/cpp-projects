#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "data.h"

class Widget;

class Controller
{
public:
    Controller();

    void setView(Widget* view);

    unsigned int neuesGirokonto(double dispokredit);
    unsigned int neuesSparkonto(double willkommensgeschenk);

    bool einzahlen(unsigned int kontoNr, double betrag,
                   std::string &fehlermeldung);
    bool abheben(unsigned int kontoNr, double betrag, std::string& fehlermeldung);
    bool dispokreditAendern(unsigned int kontoNr, double neuerDispokredit, std::string& fehlermeldung);

    bool kontoVorhanden(unsigned int kontoNr) const;
    std::string kontoInfo(unsigned int kontoNr) const;
    std::vector<std::string> kontenAlsText(std::size_t maxAnzahl) const;
    std::size_t getAnzahlKonten() const;

    void erzeugeTestkonten(std::size_t anzahl);

private:
  std::unique_ptr<Data> model;
  Widget *view;
};

#endif // CONTROLLER_H
