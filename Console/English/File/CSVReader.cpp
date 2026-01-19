/**
 * @file CSVReader.cpp
 * @brief Defines CSV reader utilities.
 */

#include "CSVReader.h"
#include "StringUtils.h"
#include <fstream>
#include <iostream>
#include <sstream>

CSVReader::CSVReader(const std::string &filename) : FileReader(filename) {}

void CSVReader::readCSV() {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Could not open the file: " << filename << std::endl;
    return;
  }

  std::string line;
  while (std::getline(file, line)) {
    std::vector<std::string> parsedLine = StringUtils::split(line, ';');
    records.push_back(parsedLine);
  }
  file.close();
}

const std::vector<std::vector<std::string>> &CSVReader::getRecords() const {
  return records;
}