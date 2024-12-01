#include "file_reader.h"
#include <fstream>
#include <stdexcept>

std::vector<std::string> FileReader::readLines(const std::string &filename)
{
  std::vector<std::string> lines;
  std::ifstream file(filename);

  if (!file.is_open())
  {
    throw std::runtime_error("Could not open file: " + filename);
  }

  std::string line;
  while (std::getline(file, line))
  {
    lines.push_back(line);
  }

  return lines;
}