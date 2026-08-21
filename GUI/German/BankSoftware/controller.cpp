#include "controller.h"
#include "girokonto.h"
#include "sparkonto.h"
#include <random>
#include <sstream>
#include <iomanip>

Controller::Controller()
    : model(std::make_unique<Data>()), view(nullptr)
{
}

void Controller::setView(Widget* v)
{
    view = v;
}

unsigned int Controller::neuesGirokonto(double dispokredit)
{
    auto neuesKonto = std::make_unique<Girokonto>(dispokredit);
    unsigned int nummer = neuesKonto->getKontoNr();
    model->hinzufuegen(std::move(neuesKonto));
    return nummer;
}

unsigned int Controller::neuesSparkonto(double willkommensgeschenk)
{
    auto neuesKonto = std::make_unique<Sparkonto>(willkommensgeschenk);
    unsigned int nummer = neuesKonto->getKontoNr();
    model->hinzufuegen(std::move(neuesKonto));
    return nummer;
}

bool Controller::einzahlen(unsigned int kontoNr, double betrag, std::string& fehlermeldung)
{
    Konto* konto = model->getKontoMitNummer(kontoNr);
    if (konto == nullptr)
    {
        fehlermeldung = "Konto Nr. " + std::to_string(kontoNr) + " existiert nicht.";
        return false;
    }
    if (betrag <= 0.0)
    {
        fehlermeldung = "Der Betrag muss größer als 0 sein.";
        return false;
    }

    konto->einzahlen(betrag);
    return true;
}

bool Controller::abheben(unsigned int kontoNr, double betrag, std::string& fehlermeldung)
{
    Konto* konto = model->getKontoMitNummer(kontoNr);
    if (konto == nullptr)
    {
        fehlermeldung = "Konto Nr. " + std::to_string(kontoNr) + " existiert nicht.";
        return false;
    }
    if (betrag <= 0.0)
    {
        fehlermeldung = "Der Betrag muss größer als 0 sein.";
        return false;
    }

    if (!konto->abheben(betrag))
    {
        fehlermeldung = "Abhebung nicht möglich: Deckung reicht nicht aus.";
        return false;
    }
    return true;
}

bool Controller::dispokreditAendern(unsigned int kontoNr, double neuerDispokredit, std::string& fehlermeldung)
{
    Konto* konto = model->getKontoMitNummer(kontoNr);
    if (konto == nullptr)
    {
        fehlermeldung = "Konto Nr. " + std::to_string(kontoNr) + " existiert nicht.";
        return false;
    }

    Girokonto* girokonto = dynamic_cast<Girokonto*>(konto);
    if (girokonto == nullptr)
    {
        fehlermeldung = "Ein Dispokredit kann nur bei einem Girokonto geändert werden.";
        return false;
    }
    if (neuerDispokredit < 0.0)
    {
        fehlermeldung = "Der Dispokredit darf nicht negativ sein.";
        return false;
    }

    girokonto->setDispokredit(neuerDispokredit);
    return true;
}

bool Controller::kontoVorhanden(unsigned int kontoNr) const
{
    return model->getKontoMitNummer(kontoNr) != nullptr;
}

std::string Controller::kontoInfo(unsigned int kontoNr) const
{
    Konto* konto = model->getKontoMitNummer(kontoNr);
    if (konto == nullptr)
    {
        return "Konto Nr. " + std::to_string(kontoNr) + " existiert nicht.";
    }

    std::string info = "[" + konto->getKontoArt() + "] " + konto->toString();

    if (auto* girokonto = dynamic_cast<Girokonto*>(konto))
    {
        std::ostringstream dispoText;
        dispoText << " | Dispokredit: " << std::fixed << std::setprecision(2)
                   << girokonto->getDispokredit() << " EUR";
        info += dispoText.str();
    }
    return info;
}

std::vector<std::string> Controller::kontenAlsText(std::size_t maxAnzahl) const
{
    std::vector<std::string> ergebnis;
    std::size_t anzahl = model->getAnzahl();
    std::size_t grenze = (maxAnzahl == 0 || maxAnzahl > anzahl) ? anzahl : maxAnzahl;
    ergebnis.reserve(grenze);

    for (std::size_t i = 0; i < grenze; ++i)
    {
        const Konto* konto = model->getKontoAnIndex(i);
        ergebnis.push_back("[" + konto->getKontoArt() + "] " + konto->toString());
    }
    return ergebnis;
}

std::size_t Controller::getAnzahlKonten() const
{
    return model->getAnzahl();
}

void Controller::erzeugeTestkonten(std::size_t anzahl)
{
    model->reservieren(model->getAnzahl() + anzahl);

    // Feste Seed für reproduzierbare Testdaten.
    std::mt19937 zufallsgenerator(42);
    std::uniform_int_distribution<int> kontoartVerteilung(0, 1);
    std::uniform_real_distribution<double> betragVerteilung(0.0, 500.0);

    for (std::size_t i = 0; i < anzahl; ++i)
    {
        if (kontoartVerteilung(zufallsgenerator) == 0)
        {
            model->hinzufuegen(std::make_unique<Girokonto>(betragVerteilung(zufallsgenerator)));
        }
        else
        {
            model->hinzufuegen(std::make_unique<Sparkonto>(betragVerteilung(zufallsgenerator)));
        }
    }
}
