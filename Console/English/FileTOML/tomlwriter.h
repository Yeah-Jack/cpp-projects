#ifndef TOML_WRITER_H
#define TOML_WRITER_H

#include <fstream>
#include <map>
#include <string>
#include <vector>

/**
 * @class TomlWriter
 * @brief A class for writing data in TOML format to a file.
 *
 * This class allows adding key-value pairs to different sections and writes
 * the entire structure to a .toml file.
 */
class TomlWriter {
public:
  TomlWriter();
  ~TomlWriter();

  /**
   * @brief Adds a key-value pair to a specific section.
   *
   * If the section does not exist yet, it will be created.
   * All values are treated as strings.
   *
   * @param section The name of the section.
   * @param key The key for the value.
   * @param value The value to store.
   */
  void addValue(const std::string &section, const std::string &key,
                const std::string &value);

  /**
   * @brief Writes the collected data to the TOML file.
   *
   * The method iterates through all sections and their key-value pairs and
   * writes them formatted to the file.
   *
   * @return true if writing was successful, otherwise false.
   */
  bool writeFile();

private:
  /** @brief nested map for storing the data.
   *
   * The outer key is the section name.
   * The inner map contains the key-value pairs of the section.
   */
  std::map<std::string, std::map<std::string, std::string>> data;
};

#endif // TOML_WRITER_H
