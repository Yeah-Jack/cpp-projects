/**
 * @file main.cpp
 * @brief Program entry point for file/CSV utilities.
 */

#include "CSVReader.h"
#include "FileReader.h"
#include <iostream>

int main() {
  // Demonstrating FileReader functionality
  FileReader textFileReader;
  textFileReader.setFilename("sample.txt");
  if (textFileReader.readData()) {
    std::cout << "Text File Data:" << std::endl;
    for (const auto &line : textFileReader.getData()) {
      std::cout << line << std::endl;
    }
  } else {
    std::cerr << "Failed to read text file." << std::endl;
  }

  // Demonstrating CSVReader functionality
  CSVReader csvFileReader;
  csvFileReader.setFilename("sample.csv");
  if (csvFileReader.readData()) {
    std::cout << "\nCSV File Data:" << std::endl;
    for (const auto &record : csvFileReader.getData()) {
      for (const auto &entry : record) {
        std::cout << entry << " ";
      }
      std::cout << std::endl;
    }
  } else {
    std::cerr << "Failed to read CSV file." << std::endl;
  }

  return 0;
}