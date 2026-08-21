#include "data.h"

Konto* Data::hinzufuegen(std::unique_ptr<Konto> konto)
{
    Konto* rohPointer = konto.get();
    indexNachNummer[rohPointer->getKontoNr()] = rohPointer;
    konten.push_back(std::move(konto));
    return rohPointer;
}

Konto* Data::getKontoMitNummer(unsigned int kontoNr) const
{
    auto treffer = indexNachNummer.find(kontoNr);
    if (treffer == indexNachNummer.end())
    {
        return nullptr;
    }
    return treffer->second;
}

Konto* Data::getKontoAnIndex(std::size_t index) const
{
    if (index >= konten.size())
    {
        return nullptr;
    }
    return konten[index].get();
}

std::size_t Data::getAnzahl() const
{
    return konten.size();
}

const std::vector<std::unique_ptr<Konto>>& Data::getAlleKonten() const
{
    return konten;
}

void Data::reservieren(std::size_t anzahl)
{
    konten.reserve(anzahl);
    indexNachNummer.reserve(anzahl);
}
