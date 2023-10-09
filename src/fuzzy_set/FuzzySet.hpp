#pragma once

#include <map>
#include <string>

class FuzzySet {
public:
  FuzzySet() = default;

  explicit FuzzySet(std::string name, const std::map<std::string, double, std::less<>> & data);

  void addElement(const std::string& key, double value);

  friend std::ostream& operator<<(std::ostream& os, const FuzzySet& set);

  std::map<std::string, double, std::less<>> getData() const;

  std::string getName() const;

  void setName(std::string newName);

private:
  std::map<std::string, double, std::less<>> data;

  std::string name;
};