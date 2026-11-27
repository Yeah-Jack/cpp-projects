#ifndef VIEW_H
#define VIEW_H

#include "controller.h"
#include <QFrame>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QWidget {
  Q_OBJECT

public:
  View(QWidget *parent = nullptr);
  ~View();

private slots:
  void on_lightOn_clicked();
  void on_lightOff_clicked();

private:
  Ui::View *ui;
  Controller myController;

  void updateDisplay();
  void colorFrame(QFrame *frame, bool lightOn);
};
#endif // VIEW_H
