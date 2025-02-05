
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
}

Widget::~Widget() { delete ui; }

void Widget::on_berechnen_clicked() {
  double zuZahlenderBetrag;
  double gegebenerBetrag;
  double rueckgeld;
  int rueckgeldInCents;

  int anzahlEinCent = 0;
  int anzahlZweiCent = 0;
  int anzahlFuenfCent = 0;
  int anzahlZehnCent = 0;
  int anzahlZwanzigCent = 0;
  int anzahlFuenfzigCent = 0;
  int anzahlEinEuro = 0;
  int anzahlZweiEuro = 0;
  int anzahlFuenfEuro = 0;
  int anzahlZehnEuro = 0;
  int anzahlZwanzigEuro = 0;
  int anzahlFuenfzigEuro = 0;
  int anzahlEinhundertEuro = 0;
  int anzahlZweihundertEuro = 0;

  zuZahlenderBetrag = ui->gegebenerBetrag->value();
  gegebenerBetrag = ui->zuZahlenderBetrag->value();

  rueckgeld = zuZahlenderBetrag - gegebenerBetrag;
  ui->rueckgeld->display(rueckgeld);
  rueckgeldInCents = static_cast<int>(rueckgeld * 100);

  while (rueckgeldInCents >= 20000) {
    rueckgeldInCents -= 20000;
    anzahlZweihundertEuro++;
  }

  while (rueckgeldInCents >= 10000) {
    rueckgeldInCents -= 10000;
    anzahlEinhundertEuro++;
  }

  while (rueckgeldInCents >= 5000) {
    rueckgeldInCents -= 5000;
    anzahlFuenfzigEuro++;
  }

  while (rueckgeldInCents >= 2000) {
    rueckgeldInCents -= 2000;
    anzahlZwanzigEuro++;
  }

  while (rueckgeldInCents >= 1000) {
    rueckgeldInCents -= 1000;
    anzahlZehnEuro++;
  }

  while (rueckgeldInCents >= 500) {
    rueckgeldInCents -= 500;
    anzahlFuenfEuro++;
  }

  while (rueckgeldInCents >= 200) {
    rueckgeldInCents -= 200;
    anzahlZweiEuro++;
  }

  while (rueckgeldInCents >= 100) {
    rueckgeldInCents -= 100;
    anzahlEinEuro++;
  }

  while (rueckgeldInCents >= 50) {
    rueckgeldInCents -= 50;
    anzahlFuenfzigCent++;
  }

  while (rueckgeldInCents >= 20) {
    rueckgeldInCents -= 20;
    anzahlZwanzigCent++;
  }

  while (rueckgeldInCents >= 10) {
    rueckgeldInCents -= 10;
    anzahlZehnCent++;
  }

  while (rueckgeldInCents >= 5) {
    rueckgeldInCents -= 5;
    anzahlFuenfCent++;
  }

  while (rueckgeldInCents >= 2) {
    rueckgeldInCents -= 2;
    anzahlZweiCent++;
  }

  while (rueckgeldInCents >= 1) {
    rueckgeldInCents -= 1;
    anzahlEinCent++;
  }

  ui->anzahlEinCent->display(anzahlEinCent);
  ui->anzahlZweiCent->display(anzahlZweiCent);
  ui->anzahlFuenfCent->display(anzahlFuenfCent);
  ui->anzahlZehnCent->display(anzahlZehnCent);
  ui->anzahlZwanzigCent->display(anzahlZwanzigCent);
  ui->anzahlFuenfzigCent->display(anzahlFuenfzigCent);
  ui->anzahlEinEuro->display(anzahlEinEuro);
  ui->anzahlZweiEuro->display(anzahlZweiEuro);
  ui->anzahlFuenfEuro->display(anzahlFuenfEuro);
  ui->anzahlZehnEuro->display(anzahlZehnEuro);
  ui->anzahlZwanzigEuro->display(anzahlZwanzigEuro);
  ui->anzahlFuenfzigEuro->display(anzahlFuenfzigEuro);
  ui->anzahlEinhundertEuro->display(anzahlEinhundertEuro);
  ui->anzahlZweihundertEuro->display(anzahlZweihundertEuro);
}
