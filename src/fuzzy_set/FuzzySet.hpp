#pragma once

#include <map>
#include <string>

class FuzzySet {
public:
  FuzzySet() = default;

  explicit FuzzySet(std::string name, const std::map<std::string, double, std::less<>> & data);

  void addElement(const std::string& key, double value);

  friend std::ostream& operator<<(std::ostream& os, const FuzzySet& set);
  
private:
  std::map<std::string, double, std::less<>> data;

  std::string setName;
};