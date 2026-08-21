#include "widget.h"
#include "controller.h"

#include <QComboBox>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QPushButton>
#include <QListWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QElapsedTimer>
#include <QIntValidator>

Widget::Widget(Controller* controller, QWidget* parent)
    : QWidget(parent), controller(controller)
{
    baueOberflaeche();
    aktualisiereAnzahlAnzeige();
}

void Widget::baueOberflaeche()
{
    setWindowTitle("Bankhaus - Kontenverwaltung");
    resize(760, 640);

    // ---------- Gruppe: Konto anlegen ----------
    auto* gruppeAnlegen = new QGroupBox("Neues Konto anlegen", this);
    comboKontoart = new QComboBox(gruppeAnlegen);
    comboKontoart->addItem("Girokonto");
    comboKontoart->addItem("Sparkonto");

    labelStartwert = new QLabel("Dispokredit (EUR):", gruppeAnlegen);
    spinStartwert = new QDoubleSpinBox(gruppeAnlegen);
    spinStartwert->setRange(0.0, 1000000.0);
    spinStartwert->setDecimals(2);

    buttonKontoAnlegen = new QPushButton("Konto anlegen", gruppeAnlegen);

    auto* layoutAnlegen = new QFormLayout;
    layoutAnlegen->addRow("Kontoart:", comboKontoart);
    layoutAnlegen->addRow(labelStartwert, spinStartwert);
    layoutAnlegen->addRow(buttonKontoAnlegen);
    gruppeAnlegen->setLayout(layoutAnlegen);

    // ---------- Gruppe: Ein-/Auszahlung & Dispokredit ----------
    auto* gruppeAktionen = new QGroupBox("Ein-/Auszahlung und Dispokredit", this);

    editKontoNr = new QLineEdit(gruppeAktionen);
    editKontoNr->setValidator(new QIntValidator(0, 2000000000, editKontoNr));
    editKontoNr->setPlaceholderText("z.B. 1000");

    spinBetrag = new QDoubleSpinBox(gruppeAktionen);
    spinBetrag->setRange(0.0, 1000000.0);
    spinBetrag->setDecimals(2);

    buttonEinzahlen = new QPushButton("Einzahlen", gruppeAktionen);
    buttonAbheben = new QPushButton("Abheben", gruppeAktionen);

    spinNeuerDispo = new QDoubleSpinBox(gruppeAktionen);
    spinNeuerDispo->setRange(0.0, 1000000.0);
    spinNeuerDispo->setDecimals(2);
    buttonDispoAendern = new QPushButton("Dispokredit ändern (nur Girokonto)", gruppeAktionen);

    buttonKontoSuchen = new QPushButton("Konto anzeigen", gruppeAktionen);
    labelKontoInfo = new QLabel("Noch kein Konto ausgewählt.", gruppeAktionen);
    labelKontoInfo->setWordWrap(true);

    auto* layoutAktionen = new QFormLayout;
    layoutAktionen->addRow("Kontonummer:", editKontoNr);
    layoutAktionen->addRow("Betrag (EUR):", spinBetrag);

    auto* zeileEinAus = new QHBoxLayout;
    zeileEinAus->addWidget(buttonEinzahlen);
    zeileEinAus->addWidget(buttonAbheben);
    layoutAktionen->addRow(zeileEinAus);

    auto* zeileDispo = new QHBoxLayout;
    zeileDispo->addWidget(spinNeuerDispo);
    zeileDispo->addWidget(buttonDispoAendern);
    layoutAktionen->addRow("Neuer Dispokredit:", zeileDispo);

    layoutAktionen->addRow(buttonKontoSuchen);
    layoutAktionen->addRow("Kontoinfo:", labelKontoInfo);

    gruppeAktionen->setLayout(layoutAktionen);

    // ---------- Gruppe: Testkonten & Übersicht ----------
    auto* gruppeUebersicht = new QGroupBox("Testkonten & Übersicht (Anforderung: min. 50.000 Konten)", this);

    spinTestkontenAnzahl = new QSpinBox(gruppeUebersicht);
    spinTestkontenAnzahl->setRange(1, 1000000);
    spinTestkontenAnzahl->setValue(50000);
    spinTestkontenAnzahl->setGroupSeparatorShown(true);

    buttonTestkontenErzeugen = new QPushButton("Testkonten erzeugen", gruppeUebersicht);
    labelAnzahlKonten = new QLabel(gruppeUebersicht);

    listeKonten = new QListWidget(gruppeUebersicht);

    auto* zeileTest = new QHBoxLayout;
    zeileTest->addWidget(new QLabel("Anzahl:", gruppeUebersicht));
    zeileTest->addWidget(spinTestkontenAnzahl);
    zeileTest->addWidget(buttonTestkontenErzeugen);
    zeileTest->addStretch();

    auto* layoutUebersicht = new QVBoxLayout;
    layoutUebersicht->addLayout(zeileTest);
    layoutUebersicht->addWidget(labelAnzahlKonten);
    layoutUebersicht->addWidget(new QLabel(
        QString("Anzeige der ersten %1 Konten (aus Performance-Gründen; intern werden alle Konten verwaltet):")
            .arg(MAX_ANGEZEIGTE_KONTEN), gruppeUebersicht));
    layoutUebersicht->addWidget(listeKonten);

    gruppeUebersicht->setLayout(layoutUebersicht);

    // ---------- Statuszeile ----------
    labelStatus = new QLabel("Bereit.", this);
    labelStatus->setWordWrap(true);

    // ---------- Gesamtlayout ----------
    auto* hauptlayout = new QVBoxLayout(this);
    hauptlayout->addWidget(gruppeAnlegen);
    hauptlayout->addWidget(gruppeAktionen);
    hauptlayout->addWidget(gruppeUebersicht, 1);
    hauptlayout->addWidget(labelStatus);

    // ---------- Signal/Slot-Verbindungen ----------
    connect(comboKontoart, &QComboBox::currentIndexChanged, this, &Widget::onKontoartGeaendert);
    connect(buttonKontoAnlegen, &QPushButton::clicked, this, &Widget::onKontoAnlegenGeklickt);
    connect(buttonEinzahlen, &QPushButton::clicked, this, &Widget::onEinzahlenGeklickt);
    connect(buttonAbheben, &QPushButton::clicked, this, &Widget::onAbhebenGeklickt);
    connect(buttonDispoAendern, &QPushButton::clicked, this, &Widget::onDispoAendernGeklickt);
    connect(buttonKontoSuchen, &QPushButton::clicked, this, &Widget::onKontoSuchenGeklickt);
    connect(buttonTestkontenErzeugen, &QPushButton::clicked, this, &Widget::onTestkontenErzeugenGeklickt);
}

void Widget::onKontoartGeaendert(int index)
{
    // 0 = Girokonto, 1 = Sparkonto - passt nur die Beschriftung an,
    // enthält keine fachliche Logik.
    if (index == 0)
    {
        labelStartwert->setText("Dispokredit (EUR):");
    }
    else
    {
        labelStartwert->setText("Willkommensgeschenk (EUR):");
    }
}

void Widget::onKontoAnlegenGeklickt()
{
    unsigned int neueNummer;
    QString meldung;

    if (comboKontoart->currentIndex() == 0)
    {
        neueNummer = controller->neuesGirokonto(spinStartwert->value());
        meldung = QString("Girokonto Nr. %1 angelegt (Dispokredit: %2 EUR).")
                      .arg(neueNummer)
                      .arg(spinStartwert->value(), 0, 'f', 2);
    }
    else
    {
        neueNummer = controller->neuesSparkonto(spinStartwert->value());
        meldung = QString("Sparkonto Nr. %1 angelegt (Willkommensgeschenk: %2 EUR).")
                      .arg(neueNummer)
                      .arg(spinStartwert->value(), 0, 'f', 2);
    }

    editKontoNr->setText(QString::number(neueNummer));
    zeigeStatus(meldung, false);
    zeigeKontoInfo(QString::fromStdString(controller->kontoInfo(neueNummer)));
    aktualisiereKontenliste();
    aktualisiereAnzahlAnzeige();
}

bool Widget::leseKontoNrEingabe(unsigned int& ergebnis)
{
    bool ok = false;
    unsigned int wert = editKontoNr->text().toUInt(&ok);
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
    if (controller->einzahlen(kontoNr, spinBetrag->value(), fehler))
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
    if (controller->abheben(kontoNr, spinBetrag->value(), fehler))
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
    if (controller->dispokreditAendern(kontoNr, spinNeuerDispo->value(), fehler))
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
    QElapsedTimer timer;
    timer.start();

    std::size_t anzahl = static_cast<std::size_t>(spinTestkontenAnzahl->value());
    controller->erzeugeTestkonten(anzahl);

    qint64 dauerMs = timer.elapsed();

    zeigeStatus(QString("%1 Testkonten erzeugt in %2 ms.").arg(anzahl).arg(dauerMs), false);
    aktualisiereKontenliste();
    aktualisiereAnzahlAnzeige();
}

void Widget::zeigeStatus(const QString& text, bool istFehler)
{
    labelStatus->setText((istFehler ? "Fehler: " : "") + text);
    labelStatus->setStyleSheet(istFehler ? "color: darkred;" : "color: darkgreen;");
}

void Widget::zeigeKontoInfo(const QString& text)
{
    labelKontoInfo->setText(text);
}

void Widget::aktualisiereKontenliste()
{
    // Aus Performance-Gründen wird nur ein begrenzter Ausschnitt angezeigt;
    // intern verwaltet der Controller/das Model beliebig viele Konten.
    listeKonten->setUpdatesEnabled(false);
    listeKonten->clear();

    std::vector<std::string> zeilen = controller->kontenAlsText(MAX_ANGEZEIGTE_KONTEN);
    for (const auto& zeile : zeilen)
    {
        listeKonten->addItem(QString::fromStdString(zeile));
    }

    listeKonten->setUpdatesEnabled(true);
}

void Widget::aktualisiereAnzahlAnzeige()
{
    labelAnzahlKonten->setText(
        QString("Aktuell verwaltete Konten insgesamt: %1").arg(controller->getAnzahlKonten()));
}
