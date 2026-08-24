#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Controller;

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

    Ui::Widget *ui;
    Controller *controller;

    static const std::size_t MAX_ANGEZEIGTE_KONTEN = 500;
};

#endif // WIDGET_H
