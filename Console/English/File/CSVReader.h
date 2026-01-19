#ifndef CSVREADER_H
#define CSVREADER_H

#include "FileReader.h"
#include <vector>
#include <string>

class CSVReader : public FileReader {
public:
    CSVReader(const std::string& filename = "");
    void readCSV();
    const std::vector<std::vector<std::string>>& getRecords() const;

private:
    std::vector<std::vector<std::string>> records;
    void parseLine(const std::string& line);
};

#endif // CSVREADER_H