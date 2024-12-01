#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>
#include <vector>

class FileReader
{
public:
  static std::vector<std::string> readLines(const std::string &filename);
};

#endif