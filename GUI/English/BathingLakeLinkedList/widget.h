#ifndef WIDGET_H
#define WIDGET_H

#include "ordercontroller.h"
#include "orderlist.h"
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
  void on_btnAddOrder_clicked();
  void on_btnRemoveCurrent_clicked();
  void on_btnNext_clicked();
  void on_btnPrevious_clicked();
  void on_listWidgetOrders_currentRowChanged(int currentRow);

private:
  Ui::Widget *ui;

  OrderList m_model;
  OrderController m_controller;

  void updateView();
  void updateCurrentOrderView();
  void updateOrderListView();
};

#endif // WIDGET_H
