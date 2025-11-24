#ifndef ORDERCONTROLLER_H
#define ORDERCONTROLLER_H

#include "orderlist.h"
#include <QString>
#include <QVector>

/**
 * @class OrderController
 * @brief Acts as an intermediary between the UI and the data model (OrderList).
 *
 * This class provides high-level operations to manage orders, such as adding,
 * removing, and retrieving formatted data for display.
 */
class OrderController {
public:
  OrderController(OrderList &model);

  /**
   * @brief Adds a new order via the OrderList.
   */
  void addOrder(const QString &text);

  /**
   * @brief Removes an order by ID via the OrderList.
   */
  void removeCurrentOrder();

  void nextOrder();
  void previousOrder();
  void selectOrderByIndex(int index);

  const Order *currentOrder() const;
  QVector<Order> allOrders() const;

  bool hasCurrentOrder() const;
  bool isEmpty() const;
  int currentIndex() const;
  int count() const;

private:
  OrderList &m_model;
};

#endif // ORDERCONTROLLER_H