#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>
#include <vector>

class StringUtils {
public:
  static std::vector<std::string> split(const std::string &str, char delimiter);
};

#endif // STRINGUTILS_H