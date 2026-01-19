/**
 * @file FileReader.cpp
 * @brief Defines file reading utilities.
 */

#include "FileReader.h"
#include <fstream>
#include <iostream>
#include <sstream>

FileReader::FileReader(const std::string &filename) : filename(filename) {}

void FileReader::setFilename(const std::string &filename) {
  this->filename = filename;
}

bool FileReader::readData() {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    return false;
  }

  std::string line;
  data.clear();
  while (std::getline(file, line)) {
    data.push_back(line);
  }

  file.close();
  return true;
}

const std::vector<std::string> &FileReader::getData() const { return data; }