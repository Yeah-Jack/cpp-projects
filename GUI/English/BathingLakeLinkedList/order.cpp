#include "order.h"

int Order::s_nextNumber = 1;

Order::Order(const QString &text, int number) : m_text(text) {
  if (number < 0) {
    m_number = s_nextNumber++;
  } else {
    m_number = number;
    if (number >= s_nextNumber) {
      s_nextNumber = number + 1;
    }
  }
}

int Order::number() const { return m_number; }

QString Order::text() const { return m_text; }

void Order::setText(const QString &text) { m_text = text; }
