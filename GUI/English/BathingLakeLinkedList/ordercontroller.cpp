#include "ordercontroller.h"

OrderController::OrderController(OrderList &model) : m_model(model) {}

void OrderController::addOrder(const QString &text) {
  if (text.trimmed().isEmpty()) {
    return;
  }
  m_model.addOrder(text.trimmed());
}

void OrderController::removeCurrentOrder() { m_model.removeCurrent(); }

void OrderController::nextOrder() { m_model.moveNext(); }

void OrderController::previousOrder() { m_model.movePrevious(); }

void OrderController::selectOrderByIndex(int index) {
  m_model.moveToIndex(index);
}

const Order *OrderController::currentOrder() const {
  return m_model.currentOrder();
}

QVector<Order> OrderController::allOrders() const {
  return m_model.allOrders();
}

bool OrderController::hasCurrentOrder() const {
  return m_model.currentOrder() != nullptr;
}

bool OrderController::isEmpty() const { return m_model.isEmpty(); }

int OrderController::currentIndex() const { return m_model.currentIndex(); }

int OrderController::count() const { return m_model.size(); }
