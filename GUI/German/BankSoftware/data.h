#ifndef DATA_H
#define DATA_H

#include "konto.h"
#include <memory>
#include <unordered_map>
#include <vector>

/*
 * Data (Model)
 * Verwaltet ausschließlich die Sammlung aller Konten.
 */
class Data
{
public:
    Data() = default;

    Konto* hinzufuegen(std::unique_ptr<Konto> konto);

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
