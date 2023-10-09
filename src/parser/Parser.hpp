#pragma once

#include <vector>

#include "fuzzy_set/FuzzySet.hpp"
#include "relation_matrix/RelationMatrix.hpp"

class Parser {
public:
  template<class T>
  static T parse(const std::vector<std::string> &tokens);

private:
  static bool isSetNameValid(const std::string &name);

  static bool isNameValid(const std::string &name);

  static bool isNumValid(const std::string &num, double &buf);

};