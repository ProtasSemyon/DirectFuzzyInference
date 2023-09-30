#pragma once

#include <map>
#include <string>

class FuzzySet {
public:
  void addElement(const std::string& key, double value);
  
private:
  std::map<std::string, double> data;
};