#include "orderlist.h"

OrderList::OrderList()
    : m_head(nullptr), m_tail(nullptr), m_current(nullptr), m_size(0) {}

OrderList::~OrderList() { clear(); }

void OrderList::addOrder(const QString &text) {
  Order newOrder(text);
  Node *node = new Node(newOrder);

  if (!m_head) {
    m_head = m_tail = node;
  } else {
    node->prev = m_tail;
    m_tail->next = node;
    m_tail = node;
  }

  m_current = node;
  m_size++;
}

void OrderList::deleteNode(Node *node) {
  if (!node) {
    return;
  }

  if (node->prev) {
    node->prev->next = node->next;
  } else {
    m_head = node->next;
  }

  if (node->next) {
    node->next->prev = node->prev;
  } else {
    m_tail = node->prev;
  }

  delete node;
  --m_size;
}

void OrderList::removeCurrent() {
  if (!m_current) {
    return;
  }

  Node *toDelete = m_current;

  if (m_current->next) {
    m_current = m_current->next;
  } else {
    m_current = m_current->prev;
  }

  deleteNode(toDelete);

  if (m_size == 0) {
    m_head = m_tail = nullptr;
    m_current = nullptr;
  }
}

void OrderList::clear() {
  Node *node = m_head;
  while (node) {
    Node *next = node->next;
    delete node;
    node = next;
  }

  m_head = m_tail = m_current = nullptr;
  m_size = 0;
}

void OrderList::moveNext() {
  if (m_current && m_current->next) {
    m_current = m_current->next;
  }
}

void OrderList::movePrevious() {
  if (m_current && m_current->prev) {
    m_current = m_current->prev;
  }
}

OrderList::Node *OrderList::nodeAt(int index) const {
  if (index < 0 || index >= m_size) {
    return nullptr;
  }

  Node *node = m_head;
  int currentIndex = 0;
  while (node && currentIndex < index) {
    node = node->next;
    currentIndex++;
  }
  return node;
}

void OrderList::moveToIndex(int index) {
  Node *node = nodeAt(index);
  if (node) {
    m_current = node;
  }
}

const Order *OrderList::currentOrder() const {
  if (!m_current) {
    return nullptr;
  }
  return &m_current->order;
}

Order *OrderList::currentOrder() {
  if (!m_current) {
    return nullptr;
  }
  return &m_current->order;
}

QVector<Order> OrderList::allOrders() const {
  QVector<Order> result;
  result.reserve(m_size);

  Node *node = m_head;
  while (node) {
    result.append(node->order);
    node = node->next;
  }
  return result;
}

bool OrderList::isEmpty() const { return m_size == 0; }

int OrderList::size() const { return m_size; }

int OrderList::currentIndex() const {
  if (!m_current) {
    return -1;
  }

  Node *node = m_head;
  int index = 0;
  while (node) {
    if (node == m_current) {
      return index;
    }
    node = node->next;
    index++;
  }
  return -1;
}
