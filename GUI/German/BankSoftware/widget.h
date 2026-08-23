#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <cstddef>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Controller;

/*
 * Widget (View)
 * -------------
 * Übernimmt ausschließlich die Kommunikation mit dem Anwender. Das eigentliche
 * Layout/Aussehen stammt vollständig aus widget.ui (Qt Designer) und wird
 * über die generierte Klasse Ui::Widget bereitgestellt (ui->...).
 *
 * Die Klasse enthält bewusst KEINE fachliche Logik: jede Benutzeraktion wird
 * 1:1 an den Controller weitergereicht, dessen Antwort lediglich angezeigt
 * wird.
 *
 * Der Zugriff auf den Controller erfolgt über einen klassischen Pointer;
 * die View besitzt den Controller nicht (kein Lifetime-Management hier).
 */
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(Controller* controller, QWidget* parent = nullptr);
    ~Widget() override;

private slots:
    void onKontoartGeaendert(int index);
    void onKontoAnlegenGeklickt();
    void onEinzahlenGeklickt();
    void onAbhebenGeklickt();
    void onDispoAendernGeklickt();
    void onKontoSuchenGeklickt();
    void onTestkontenErzeugenGeklickt();

private:
    void verbindeSignaleUndSlots();
    void zeigeStatus(const QString& text, bool istFehler);
    void zeigeKontoInfo(const QString& text);
    void aktualisiereKontenliste();
    void aktualisiereAnzahlAnzeige();
    bool leseKontoNrEingabe(unsigned int& ergebnis);

    Ui::Widget* ui;          // von Qt Designer generierte Oberfläche (widget.ui)
    Controller* controller;  // klassischer Pointer, keine Besitzverhältnisse

    static const std::size_t MAX_ANGEZEIGTE_KONTEN = 500;
};

#endif // WIDGET_H
