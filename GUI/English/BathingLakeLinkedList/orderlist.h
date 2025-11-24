#ifndef ORDERLIST_H
#define ORDERLIST_H

#include "order.h"
#include <QString>
#include <QVector>

/**
 * @class OrderList
 * @brief Manages a singly linked list of Order objects.
 *
 * This class handles the creation, deletion, and traversal of Order nodes.
 * It is responsible for memory management of the nodes in the list.
 */
class OrderList {
public:
  /**
   * @brief Constructs an empty OrderList.
   */
  OrderList();

  /**
   * @brief Destroys the OrderList and frees all associated memory.
   */
  ~OrderList();

  OrderList(const OrderList &) = delete;
  OrderList &operator=(const OrderList &) = delete;

  /**
   * @brief Adds a new order to the list.
   *
   * Creates a new Order node and appends it to the list.
   *
   * @param text The text of the new order.
   */
  void addOrder(const QString &text);

  /**
   * @brief Removes an order from the list by its ID.
   *
   * Searches for the order with the specified ID and removes it from the linked
   * list.
   */
  void removeCurrent();

  Order *getHead() const;

  void clear();

  void moveNext();
  void movePrevious();
  void moveToIndex(int index); // set current by index (0-based)

  const Order *currentOrder() const;
  Order *currentOrder();

  QVector<Order> allOrders() const;

  bool isEmpty() const;
  int size() const;
  int currentIndex() const; // -1 if there is no current element

private:
  struct Node {
    Order order;
    Node *prev;
    Node *next;

    Node(const Order &o) : order(o), prev(nullptr), next(nullptr) {}
  };

  Node *m_head;
  Node *m_tail;
  Node *m_current;
  int m_size;

  Node *nodeAt(int index) const;
  void deleteNode(Node *node);
};

#endif // ORDERLIST_H
