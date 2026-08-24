#include "widget.h"
#include "ui_widget.h"
#include "controller.h"

#include <string>
#include <vector>

Widget::Widget(Controller* controller, QWidget* parent)
    : QWidget(parent), ui(new Ui::Widget), controller(controller)
{
    ui->setupUi(this);

    ui->editKontoNr->setValidator(new QIntValidator(0, 2000000000, ui->editKontoNr));

    ui->labelHinweisAnzeige->setText(
        QString("Anzeige der ersten %1 Konten:")
            .arg(MAX_ANGEZEIGTE_KONTEN));

    verbindeSignaleUndSlots();
    aktualisiereAnzahlAnzeige();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::verbindeSignaleUndSlots()
{
    connect(ui->comboKontoart, &QComboBox::currentIndexChanged, this, &Widget::onKontoartGeaendert);
    connect(ui->buttonKontoAnlegen, &QPushButton::clicked, this, &Widget::onKontoAnlegenGeklickt);
    connect(ui->buttonEinzahlen, &QPushButton::clicked, this, &Widget::onEinzahlenGeklickt);
    connect(ui->buttonAbheben, &QPushButton::clicked, this, &Widget::onAbhebenGeklickt);
    connect(ui->buttonDispoAendern, &QPushButton::clicked, this, &Widget::onDispoAendernGeklickt);
    connect(ui->buttonKontoSuchen, &QPushButton::clicked, this, &Widget::onKontoSuchenGeklickt);
    connect(ui->buttonTestkontenErzeugen, &QPushButton::clicked, this, &Widget::onTestkontenErzeugenGeklickt);
}

void Widget::onKontoartGeaendert(int index)
{
    // 0 = Girokonto, 1 = Sparkonto - passt nur die Beschriftung an,
    // enthält keine fachliche Logik.
    if (index == 0)
    {
        ui->labelStartwert->setText("Dispokredit (EUR):");
    }
    else
    {
        ui->labelStartwert->setText("Willkommensgeschenk (EUR):");
    }
}

void Widget::onKontoAnlegenGeklickt()
{
    unsigned int neueNummer;
    QString meldung;

    if (ui->comboKontoart->currentIndex() == 0)
    {
        neueNummer = controller->neuesGirokonto(ui->spinStartwert->value());
        meldung = QString("Girokonto Nr. %1 angelegt (Dispokredit: %2 EUR).")
                      .arg(neueNummer)
                      .arg(ui->spinStartwert->value(), 0, 'f', 2);
    }
    else
    {
        neueNummer = controller->neuesSparkonto(ui->spinStartwert->value());
        meldung = QString("Sparkonto Nr. %1 angelegt (Willkommensgeschenk: %2 EUR).")
                      .arg(neueNummer)
                      .arg(ui->spinStartwert->value(), 0, 'f', 2);
    }

    ui->editKontoNr->setText(QString::number(neueNummer));
    zeigeStatus(meldung, false);
    zeigeKontoInfo(QString::fromStdString(controller->kontoInfo(neueNummer)));
    aktualisiereKontenliste();
    aktualisiereAnzahlAnzeige();
}

bool Widget::leseKontoNrEingabe(unsigned int& ergebnis)
{
    bool ok = false;
    unsigned int wert = ui->editKontoNr->text().toUInt(&ok);
    if (!ok)
    {
        zeigeStatus("Bitte eine gültige Kontonummer eingeben.", true);
        return false;
    }
    ergebnis = wert;
    return true;
}

void Widget::onEinzahlenGeklickt()
{
    unsigned int kontoNr;
    if (!leseKontoNrEingabe(kontoNr))
    {
        return;
    }

    std::string fehler;
    if (controller->einzahlen(kontoNr, ui->spinBetrag->value(), fehler))
    {
        zeigeStatus("Einzahlung erfolgreich durchgeführt.", false);
    }
    else
    {
        zeigeStatus(QString::fromStdString(fehler), true);
    }

    zeigeKontoInfo(QString::fromStdString(controller->kontoInfo(kontoNr)));
    aktualisiereKontenliste();
}

void Widget::onAbhebenGeklickt()
{
    unsigned int kontoNr;
    if (!leseKontoNrEingabe(kontoNr))
    {
        return;
    }

    std::string fehler;
    if (controller->abheben(kontoNr, ui->spinBetrag->value(), fehler))
    {
        zeigeStatus("Abhebung erfolgreich durchgeführt.", false);
    }
    else
    {
        zeigeStatus(QString::fromStdString(fehler), true);
    }

    zeigeKontoInfo(QString::fromStdString(controller->kontoInfo(kontoNr)));
    aktualisiereKontenliste();
}

void Widget::onDispoAendernGeklickt()
{
    unsigned int kontoNr;
    if (!leseKontoNrEingabe(kontoNr))
    {
        return;
    }

    std::string fehler;
    if (controller->dispokreditAendern(kontoNr, ui->spinNeuerDispo->value(), fehler))
    {
        zeigeStatus("Dispokredit erfolgreich geändert.", false);
    }
    else
    {
        zeigeStatus(QString::fromStdString(fehler), true);
    }

    zeigeKontoInfo(QString::fromStdString(controller->kontoInfo(kontoNr)));
    aktualisiereKontenliste();
}

void Widget::onKontoSuchenGeklickt()
{
    unsigned int kontoNr;
    if (!leseKontoNrEingabe(kontoNr))
    {
        return;
    }

    zeigeKontoInfo(QString::fromStdString(controller->kontoInfo(kontoNr)));

    if (controller->kontoVorhanden(kontoNr))
    {
        zeigeStatus("Konto gefunden.", false);
    }
    else
    {
        zeigeStatus("Konto nicht gefunden.", true);
    }
}

void Widget::onTestkontenErzeugenGeklickt()
{
    std::size_t anzahl = static_cast<std::size_t>(ui->spinTestkontenAnzahl->value());
    controller->erzeugeTestkonten(anzahl);

    zeigeStatus(QString("%1 Testkonten erzeugt.").arg(anzahl), false);
    aktualisiereKontenliste();
    aktualisiereAnzahlAnzeige();
}

void Widget::zeigeStatus(const QString& text, bool istFehler)
{
    ui->labelStatus->setText((istFehler ? "Fehler: " : "") + text);
    ui->labelStatus->setStyleSheet(istFehler ? "color: darkred;" : "color: darkgreen;");
}

void Widget::zeigeKontoInfo(const QString& text)
{
    ui->labelKontoInfo->setText(text);
}

void Widget::aktualisiereKontenliste()
{
    ui->listeKonten->setUpdatesEnabled(false);
    ui->listeKonten->clear();

    std::vector<std::string> zeilen = controller->kontenAlsText(MAX_ANGEZEIGTE_KONTEN);
    for (const auto& zeile : zeilen)
    {
        ui->listeKonten->addItem(QString::fromStdString(zeile));
    }

    ui->listeKonten->setUpdatesEnabled(true);
}

void Widget::aktualisiereAnzahlAnzeige()
{
    ui->labelAnzahlKonten->setText(
        QString("Aktuell verwaltete Konten insgesamt: %1").arg(controller->getAnzahlKonten()));
}
