#ifndef KONTO_H
#define KONTO_H

#include <string>

/*
 * Konto
 * -----
 * Fasst alle Gemeinsamkeiten von Girokonto und Sparkonto zusammen.
 *
 * - Jedes Konto erhält beim Anlegen automatisch eine fortlaufende Kontonummer
 *   aus der klasseneigenen Vorlage "nextKontoNr".
 * - Der Kontostand startet bei 0 EUR und wird ausschließlich über die Methoden
 *   einzahlen() und abheben() verändert.
 * - abheben() verhält sich je nach Kontoart unterschiedlich (Sparkonto darf
 *   nicht überzogen werden, Girokonto darf bis zum Dispokredit überzogen
 *   werden).
 */
class Konto
{
public:
    Konto();
    virtual ~Konto() = default;

    // Kontonummer: nach außen nur lesbar
    unsigned int getKontoNr() const;

    // Kontostand: nur lesbar; Änderung ausschließlich über einzahlen()/abheben()
    double getKontostand() const;

    // Für alle Kontoarten identisch
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
  static unsigned int nextKontoNr;
  const unsigned int kontoNr;
  double kontostand;
};

#endif // KONTO_H
