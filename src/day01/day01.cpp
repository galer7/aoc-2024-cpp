#include "day01.h"
#include "../utils/file_reader.h"

#include <numeric>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iostream>

struct NumberPairs
{
  std::vector<int> left;
  std::vector<int> right;
};

NumberPairs parseInput(const std::string &filename)
{
  auto lines = FileReader::readLines(filename);
  NumberPairs result;
  result.left.reserve(lines.size());
  result.right.reserve(lines.size());

  for (const auto &line : lines)
  {
    int left, right;
    std::istringstream iss(line);
    if (!(iss >> left >> right))
    {
      throw std::runtime_error("Invalid input format");
    }
    result.left.push_back(left);
    result.right.push_back(right);
  }

  return result;
}

int Day01::solvePart1(const std::string &filename)
{
  auto [leftList, rightList] = parseInput(filename);

  std::vector<int> sortedLeft = leftList;
  std::vector<int> sortedRight = rightList;
  std::sort(sortedLeft.begin(), sortedLeft.end());
  std::sort(sortedRight.begin(), sortedRight.end());

  int totalDistance = 0;
  for (size_t i = 0; i < sortedLeft.size(); i++)
  {
    totalDistance += std::abs(sortedLeft[i] - sortedRight[i]);
  }

  return totalDistance;
}

int Day01::solvePart2(const std::string &filename)
{
  auto [leftList, rightList] = parseInput(filename);

  int similarityScore = 0;
  for (int leftNum : leftList)
  {
    int count = std::count(rightList.begin(), rightList.end(), leftNum);
    similarityScore += leftNum * count;
  }

  return similarityScore;
}

int main()
{
#ifndef PROJECT_ROOT
#define PROJECT_ROOT "." // fallback for IDE
#endif
  std::string inputPath = std::string(PROJECT_ROOT) + "/src/day01/input.txt";
  std::cout << Day01::solvePart1(inputPath) << std::endl;
  std::cout << Day01::solvePart2(inputPath) << std::endl;
  return 0;
}