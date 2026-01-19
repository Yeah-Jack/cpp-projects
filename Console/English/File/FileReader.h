#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class FileReader {
public:
  FileReader(const std::string &filename = "");
  void setFilename(const std::string &filename);
  bool readData();
  const std::vector<std::string> &getData() const;
  std::string filename;

private:
  std::vector<std::string> data;
};

#endif // FILEREADER_H
