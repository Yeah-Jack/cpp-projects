#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include "controllerlake.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class ViewWidget;
}
QT_END_NAMESPACE

class ViewWidget : public QWidget {
  Q_OBJECT

public:
  ViewWidget(QWidget *parent = nullptr);
  ~ViewWidget();

private:
  Ui::ViewWidget *ui;
  ControllerLake *myLake;

private slots:
  void createLoungerTypeStandard();
  void showListLoungers();
  void clearLog();
};
#endif // VIEWWIDGET_H
