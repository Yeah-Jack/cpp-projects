#ifndef UI_H
#define UI_H

#include <QMainWindow>
#include <QString>

#include "controller.h"

class QLabel;
class QComboBox;

QT_BEGIN_NAMESPACE
namespace Ui { class UI; }
QT_END_NAMESPACE

class UI : public QMainWindow {
  Q_OBJECT

public:
  UI(QWidget *parent = nullptr);
  ~UI();

  void listeAnzeigen();
  void liegeBuchen();
  void buchungStornieren();

private:
  LiegeTyp ausgewaehlterTyp() const;
  void zeigeStatus(const QString &text);

  Ui::UI *ui;
  Controller controller;
  QLabel *listeLabel;
  QLabel *statusLabel;
  QComboBox *typAuswahl;
};
#endif // UI_H
