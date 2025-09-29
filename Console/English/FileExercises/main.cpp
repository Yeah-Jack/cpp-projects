#include "tomlwriter.h"
#include <iostream>

int main() {
  TomlWriter writer;

  // Section [owner]
  writer.addValue("owner", "name", "John Doe");
  writer.addValue("owner", "phone", "+1-800-555-0199");
  writer.addValue("owner", "email", "john.doe@example.com");
  writer.addValue("owner", "address",
                  "415 Oaklands, South Ariane, South Dakota");
  writer.addValue("owner", "title", "Engineer");
  writer.addValue("owner", "company", "Acme Widgets Inc.");

  // Section [database]
  writer.addValue("database", "server", "192.168.1.1");
  writer.addValue("database", "ports", "8001, 8002, 8003");
  writer.addValue("database", "username", "admin");

  if (writer.writeFile()) {
    std::cout << "Operation completed.\n";
  } else {
    std::cout << "Operation ended with errors.\n";
  }

  return 0;
}
