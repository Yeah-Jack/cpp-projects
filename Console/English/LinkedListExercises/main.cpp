#include <iostream>

class DoublyLinkedList {
private:
  struct Node {
    int data;
    Node *prev;
    Node *next;
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
  };

  Node *head;
  Node *tail;

public:
  DoublyLinkedList() : head(nullptr), tail(nullptr) {}

  ~DoublyLinkedList() { clear(); }

  // Insert at the beginning
  void insertFront(int value) {
    Node *newNode = new Node(value);
    newNode->next = head;
    newNode->prev = nullptr;

    if (head == nullptr) {
      // List was empty
      head = tail = newNode;
    } else {
      head->prev = newNode;
      head = newNode;
    }
  }

  // Insert at the end
  void insertBack(int value) {
    Node *newNode = new Node(value);
    newNode->next = nullptr;
    newNode->prev = tail;

    if (tail == nullptr) {
      // List was empty
      head = tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  // Delete first occurrence of value
  bool deleteValue(int value) {
    Node *current = head;

    while (current != nullptr && current->data != value) {
      current = current->next;
    }

    if (current == nullptr) {
      // Value not found
      return false;
    }

    // Update previous node
    if (current->prev != nullptr) {
      current->prev->next = current->next;
    } else {
      // Deleting the head
      head = current->next;
    }

    // Update next node
    if (current->next != nullptr) {
      current->next->prev = current->prev;
    } else {
      // Deleting the tail
      tail = current->prev;
    }

    delete current;
    return true;
  }

  // Search for a value
  bool search(int value) const {
    Node *current = head;
    while (current != nullptr) {
      if (current->data == value) {
        return true;
      }
      current = current->next;
    }
    return false;
  }

  // Print all elements from head to tail
  void printForward() const {
    Node *current = head;
    while (current != nullptr) {
      std::cout << current->data;
      if (current->next != nullptr) {
        std::cout << " <-> ";
      }
      current = current->next;
    }
    std::cout << std::endl;
  }

  // Print all elements from tail to head
  void printBackward() const {
    Node *current = tail;
    while (current != nullptr) {
      std::cout << current->data;
      if (current->prev != nullptr) {
        std::cout << " <-> ";
      }
      current = current->prev;
    }
    std::cout << std::endl;
  }

  // Remove all elements
  void clear() {
    Node *current = head;
    while (current != nullptr) {
      Node *nextNode = current->next;
      delete current;
      current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
  }
};

int main() {
  DoublyLinkedList list;

  // Insert elements
  list.insertBack(10);
  list.insertBack(20);
  list.insertFront(5);
  list.insertBack(30);

  std::cout << "List forward:   ";
  list.printForward(); // 5 <-> 10 <-> 20 <-> 30

  std::cout << "List backward:  ";
  list.printBackward(); // 30 <-> 20 <-> 10 <-> 5

  // Search
  int valueToSearch = 20;
  if (list.search(valueToSearch)) {
    std::cout << valueToSearch << " found in the list" << std::endl;
  } else {
    std::cout << valueToSearch << " not found in the list" << std::endl;
  }

  // Delete
  int valueToDelete = 10;
  if (list.deleteValue(valueToDelete)) {
    std::cout << "Deleted " << valueToDelete << " from the list" << std::endl;
  } else {
    std::cout << valueToDelete << " not found, nothing deleted" << std::endl;
  }

  std::cout << "List forward after deletion:   ";
  list.printForward(); // 5 <-> 20 <-> 30

  std::cout << "List backward after deletion:  ";
  list.printBackward(); // 30 <-> 20 <-> 5

  return 0;
}
