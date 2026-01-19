#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class FileReader {
public:
    FileReader(const std::string& filename = "");
    void setFilename(const std::string& filename);
    bool readData();
    const std::vector<std::string>& getData() const;
    std::string filename;

  private:
    std::vector<std::string> data;
};

#endif // FILEREADER_H
