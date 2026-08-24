#ifndef DATA_H
#define DATA_H

#include <vector>
#include <memory>
#include <unordered_map>
#include "konto.h"

/*
 * Data (Model)
 * ------------
 * Verwaltet ausschließlich die Sammlung aller Konten. Die Klasse enthält
 * bewusst keine Geschäftslogik.
 */
class Data
{
public:
    Data() = default;

    // Nimmt ein bereits erzeugtes Konto in die Verwaltung auf.
    // Data übernimmt das Eigentum und gibt einen
    // Beobachter-Pointer auf das gespeicherte Objekt zurück.
    Konto* hinzufuegen(std::unique_ptr<Konto> konto);

    // Liefert nullptr, falls keine passende Kontonummer existiert.
    Konto* getKontoMitNummer(unsigned int kontoNr) const;

    Konto* getKontoAnIndex(std::size_t index) const;

    std::size_t getAnzahl() const;

    const std::vector<std::unique_ptr<Konto>>& getAlleKonten() const;

    void reservieren(std::size_t anzahl);

private:
    std::vector<std::unique_ptr<Konto>> konten;
    std::unordered_map<unsigned int, Konto*> indexNachNummer;
};

#endif // DATA_H
