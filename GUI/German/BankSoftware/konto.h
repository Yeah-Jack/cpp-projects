#ifndef KONTO_H
#define KONTO_H

#include <string>

/*
 * Konto
 * -----
 * Fasst alle Gemeinsamkeiten von Girokonto und Sparkonto zusammen.
 *
 * - Jedes Konto erhält beim Anlegen automatisch eine fortlaufende Kontonummer
 *   aus der klasseneigenen (statischen) Vorlage "nextKontoNr". Diese Vorlage
 *   ist privat und von außen weder lesbar noch veränderbar.
 * - Die Kontonummer selbst ist nach außen "readonly" (nur ein Getter, kein Setter).
 * - Der Kontostand startet bei 0 EUR und wird ausschließlich über die Methoden
 *   einzahlen() und abheben() verändert - es gibt daher bewusst keinen
 *   öffentlichen Setter für den Kontostand.
 * - abheben() verhält sich je nach Kontoart unterschiedlich (Sparkonto darf
 *   nicht überzogen werden, Girokonto darf bis zum Dispokredit überzogen
 *   werden) und ist daher rein virtuell. Dadurch ist Konto abstrakt und wird
 *   nie direkt angelegt, sondern nur über Girokonto/Sparkonto.
 */
class Konto
{
public:
    Konto();
    virtual ~Konto() = default;

    // Kontonummer: nach außen nur lesbar (readonly)
    unsigned int getKontoNr() const;

    // Kontostand: nur lesbar; Änderung ausschließlich über einzahlen()/abheben()
    double getKontostand() const;

    // Für alle Kontoarten identisch -> hier zentral implementiert
    virtual void einzahlen(double betrag);

    // Kontoartabhängig -> muss von Girokonto/Sparkonto implementiert werden
    virtual bool abheben(double betrag) = 0;

    // Liefert einen kurzen Bezeichner der Kontoart (z.B. "Girokonto").
    // Wird nur für Anzeigezwecke im Controller/View benötigt.
    virtual std::string getKontoArt() const = 0;

    // Gibt Kontonummer und aktuellen Kontostand als Text zurück.
    virtual std::string toString() const;

protected:
    // Erlaubt abgeleiteten Klassen (z.B. Sparkonto für das Willkommensgeschenk),
    // den Kontostand intern zu setzen, ohne dass dafür ein öffentlicher Setter
    // existieren muss.
    void setKontostandIntern(double betrag);

private:
    static unsigned int nextKontoNr; // Vorlage: privat, keine get-/set-Methode
    const unsigned int kontoNr;      // fortlaufende Nummer, nach außen readonly
    double kontostand;               // Änderung nur über einzahlen()/abheben()
};

#endif // KONTO_H
