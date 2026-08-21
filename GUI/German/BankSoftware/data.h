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
 * bewusst KEINE Geschäftslogik (kein Prüfen von Beträgen, keine Regeln zum
 * Überziehen etc.) - das ist Aufgabe der Konto-Klassen (fachliche Regeln
 * je Kontoart) bzw. des Controllers (Ablauf-/Anwendungslogik).
 *
 * Zugriff auf die Konten erfolgt ausschließlich über Pointer:
 * - Eigentum an den Objekten liegt bei std::unique_ptr in "konten".
 * - Nach außen werden nur rohe Konto* zurückgegeben (Data bleibt Eigentümer).
 *
 * Die Kontonummer dient zusätzlich als Schlüssel in einer Hashtabelle, damit
 * auch bei sehr vielen Konten (Anforderung: mind. 50.000) ein einzelnes Konto
 * performant gefunden werden kann.
 */
class Data
{
public:
    Data() = default;

    // Nimmt ein bereits erzeugtes Konto in die Verwaltung auf.
    // Data übernimmt das Eigentum (unique_ptr) und gibt einen
    // Beobachter-Pointer auf das gespeicherte Objekt zurück.
    Konto* hinzufuegen(std::unique_ptr<Konto> konto);

    // Liefert nullptr, falls keine passende Kontonummer existiert.
    Konto* getKontoMitNummer(unsigned int kontoNr) const;

    Konto* getKontoAnIndex(std::size_t index) const;

    std::size_t getAnzahl() const;

    // Direkter, lesender Zugriff auf alle Konten (z.B. für Listenanzeige).
    const std::vector<std::unique_ptr<Konto>>& getAlleKonten() const;

    // Reserviert im Voraus Speicher, sinnvoll vor dem Anlegen sehr vieler Konten.
    void reservieren(std::size_t anzahl);

private:
    std::vector<std::unique_ptr<Konto>> konten;
    std::unordered_map<unsigned int, Konto*> indexNachNummer;
};

#endif // DATA_H
