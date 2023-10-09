#include "FuzzySet.hpp"
#include <iostream>

FuzzySet::FuzzySet(std::string name, const std::map<std::string, double, std::less<>> & data) : data(data), name(std::move(name)) {
}

void FuzzySet::addElement(const std::string& key, double value) {
  data[key] = value;
}

std::ostream& operator<<(std::ostream& os, const FuzzySet& set) {
  os << set.name;
  os << " = { ";

  size_t index = 0;
  const size_t setSize = set.data.size();
  for (const auto &[key, value] : set.data) {
    os << "( " << key << ", " << value << " )";
    if (index < setSize - 1) {
      os << ", ";
    }
    index++;
  }

  os << " }" << std::endl;
  return os; 
}

std::map<std::string, double, std::less<>> FuzzySet::getData() const {
  return data;
}

std::string FuzzySet::getName() const {
  return name;
}

void FuzzySet::setName(std::string newName) {
  name = newName;
}




