#ifndef ORDER_H
#define ORDER_H

#include <QString>

/**
 * @class Order
 * @brief Represents a single order in the linked list.
 *
 * This class acts as a node in a singly linked list. It stores the details
 * of a specific order (ID, description, cost) and a pointer to the next
 * order in the sequence.
 */
class Order {
public:
  Order(const QString &text = QString(), int number = -1);

  int number() const;
  QString text() const;
  void setText(const QString &text);

private:
  int m_number;
  QString m_text;

  static int s_nextNumber;
};

#endif // ORDER_H