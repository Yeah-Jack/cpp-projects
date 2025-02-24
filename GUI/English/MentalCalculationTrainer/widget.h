#ifndef WIDGET_H
#define WIDGET_H

#include <QComboBox>
#include <QInputDialog>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
  Q_OBJECT

public:
  Widget(QWidget *parent = nullptr);
  ~Widget();

private slots:
  void on_input_clicked();

private:
  Ui::Widget *ui;
  int tasksCounter = 0;
  int tasksCorrect = 0;
  int tasksIncorrect = 0;
};
#endif // WIDGET_H
