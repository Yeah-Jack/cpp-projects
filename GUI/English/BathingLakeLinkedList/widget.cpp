#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget), m_model(), m_controller(m_model) {
  ui->setupUi(this);
  updateView();
}

Widget::~Widget() { delete ui; }

void Widget::updateView() {
  updateCurrentOrderView();
  updateOrderListView();
}

void Widget::updateCurrentOrderView() {
  const Order *current = m_controller.currentOrder();

  if (!current) {
    ui->labelCurrentNumber->setText(tr("No current order"));
    ui->lineEditCurrentText->clear();
    ui->btnNext->setEnabled(false);
    ui->btnPrevious->setEnabled(false);
    ui->btnRemoveCurrent->setEnabled(false);
    return;
  }

  ui->labelCurrentNumber->setText(
      tr("Current order number: %1").arg(current->number()));
  ui->lineEditCurrentText->setText(current->text());
  ui->btnNext->setEnabled(true);
  ui->btnPrevious->setEnabled(true);
  ui->btnRemoveCurrent->setEnabled(true);
}

void Widget::updateOrderListView() {
  ui->listWidgetOrders->clear();

  const QVector<Order> orders = m_controller.allOrders();
  for (const Order &o : orders) {
    ui->listWidgetOrders->addItem(tr("%1: %2").arg(o.number()).arg(o.text()));
  }

  int index = m_controller.currentIndex();
  if (index >= 0 && index < ui->listWidgetOrders->count()) {
    ui->listWidgetOrders->setCurrentRow(index);
  }
}

void Widget::on_btnAddOrder_clicked() {
  const QString text = ui->lineEditNewOrderText->text();
  m_controller.addOrder(text);
  ui->lineEditNewOrderText->clear();
  updateView();
}

void Widget::on_btnRemoveCurrent_clicked() {
  m_controller.removeCurrentOrder();
  updateView();
}

void Widget::on_btnNext_clicked() {
  m_controller.nextOrder();
  updateView();
}

void Widget::on_btnPrevious_clicked() {
  m_controller.previousOrder();
  updateView();
}

void Widget::on_listWidgetOrders_currentRowChanged(int currentRow) {
  if (currentRow < 0) {
    return;
  }
  m_controller.selectOrderByIndex(currentRow);
  updateCurrentOrderView();
}
