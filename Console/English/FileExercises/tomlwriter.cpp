#include "tomlwriter.h"
#include <iostream>

std::string TomlWriter::outputFilename = "config.toml";

TomlWriter::TomlWriter() {}

TomlWriter::~TomlWriter() {}

void TomlWriter::addValue(const std::string &section, const std::string &key,
                          const std::string &value) {
  data[section][key] = value;
}

bool TomlWriter::writeFile() {
  std::ofstream tomlFile(outputFilename);

  if (!tomlFile.is_open()) {
    std::cout << "Error: File '" << outputFilename
              << "' could not be opened.\n";
    return false;
  }

  for (const auto &sectionPair : data) {
    tomlFile << "[" << sectionPair.first << "]\n";

    for (const auto &keyValuePair : sectionPair.second) {
      tomlFile << keyValuePair.first << " = \"" << keyValuePair.second
               << "\"\n";
    }

    tomlFile << '\n';
  }

  tomlFile.close();
  std::cout << "Data successfully written to '" << outputFilename << "'.\n";
  return true;
}
