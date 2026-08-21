#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <cstddef>

class Controller;
class QComboBox;
class QLineEdit;
class QDoubleSpinBox;
class QSpinBox;
class QPushButton;
class QListWidget;
class QLabel;

/*
 * Widget (View)
 * -------------
 * Übernimmt ausschließlich die Kommunikation mit dem Anwender (Eingabe
 * entgegennehmen, Ergebnisse anzeigen). Enthält bewusst KEINE fachliche
 * Logik: jede Benutzeraktion wird 1:1 an den Controller weitergereicht,
 * die Antwort des Controllers wird lediglich angezeigt.
 *
 * Der Zugriff auf den Controller erfolgt über einen klassischen Pointer;
 * die View besitzt den Controller nicht (kein Lifetime-Management hier).
 */
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(Controller* controller, QWidget* parent = nullptr);
    ~Widget() override = default;

private slots:
    void onKontoartGeaendert(int index);
    void onKontoAnlegenGeklickt();
    void onEinzahlenGeklickt();
    void onAbhebenGeklickt();
    void onDispoAendernGeklickt();
    void onKontoSuchenGeklickt();
    void onTestkontenErzeugenGeklickt();

private:
    void baueOberflaeche();
    void zeigeStatus(const QString& text, bool istFehler);
    void zeigeKontoInfo(const QString& text);
    void aktualisiereKontenliste();
    void aktualisiereAnzahlAnzeige();
    bool leseKontoNrEingabe(unsigned int& ergebnis);

    Controller* controller; // klassischer Pointer, keine Besitzverhältnisse

    // -- Bereich: Konto anlegen --
    QComboBox* comboKontoart;
    QLabel* labelStartwert;
    QDoubleSpinBox* spinStartwert;
    QPushButton* buttonKontoAnlegen;

    // -- Bereich: Ein-/Auszahlung --
    QLineEdit* editKontoNr;
    QDoubleSpinBox* spinBetrag;
    QPushButton* buttonEinzahlen;
    QPushButton* buttonAbheben;

    // -- Bereich: Dispokredit ändern --
    QDoubleSpinBox* spinNeuerDispo;
    QPushButton* buttonDispoAendern;

    // -- Bereich: Konto suchen / Info --
    QPushButton* buttonKontoSuchen;
    QLabel* labelKontoInfo;

    // -- Bereich: Testkonten erzeugen --
    QSpinBox* spinTestkontenAnzahl;
    QPushButton* buttonTestkontenErzeugen;
    QLabel* labelAnzahlKonten;

    // -- Bereich: Kontenliste + Status --
    QListWidget* listeKonten;
    QLabel* labelStatus;

    static const std::size_t MAX_ANGEZEIGTE_KONTEN = 500;
};

#endif // WIDGET_H
