#include "data.h"

// Nimmt ein bereits erzeugtes Konto in die Verwaltung auf.
// Data übernimmt das Eigentum und gibt einen
// Beobachter-Pointer auf das gespeicherte Objekt zurück.
Konto* Data::hinzufuegen(std::unique_ptr<Konto> konto)
{
    Konto* rohPointer = konto.get();
    indexNachNummer[rohPointer->getKontoNr()] = rohPointer;
    konten.push_back(std::move(konto));
    return rohPointer;
}

// Liefert nullptr, falls keine passende Kontonummer existiert.
Konto* Data::getKontoMitNummer(unsigned int kontoNr) const
{
    auto treffer = indexNachNummer.find(kontoNr);
    if (treffer == indexNachNummer.end())
    {
        return nullptr;
    }
    return treffer->second;
}

// Liefert das Konto an einem bestimmten Index zurück, falls dieser gültig ist.
Konto* Data::getKontoAnIndex(std::size_t index) const
{
    if (index >= konten.size())
    {
        return nullptr;
    }
    return konten[index].get();
}

// Gibt die Anzahl der aktuell verwalteten Konten zurück.
std::size_t Data::getAnzahl() const
{
    return konten.size();
}

// Liefert den internen Container aller Konten zur weiteren Verarbeitung.
const std::vector<std::unique_ptr<Konto>>& Data::getAlleKonten() const
{
    return konten;
}

// Reserviert Speicher für die erwartete Anzahl an Konten, damit spätere Einfügungen effizienter sind.
void Data::reservieren(std::size_t anzahl)
{
    konten.reserve(anzahl);
    indexNachNummer.reserve(anzahl);
}
