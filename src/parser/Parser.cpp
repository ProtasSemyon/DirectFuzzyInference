#include "Parser.hpp"

#include <stdexcept>

template <>
FuzzySet Parser::parse(const std::vector<std::string> &tokens) {
  const std::string name = isSetNameValid(tokens.at(0)) ? tokens.at(0) : "";
  if (name.empty()) {
    throw std::invalid_argument("Incorrect set name: " + tokens.at(0));
  }

  std::map<std::string, double, std::less<>> data;

  if (tokens.size() < 4 || tokens.at(1) != "=" || tokens.at(2) != "{" || tokens.back() != "}") {
    throw std::invalid_argument("Invalid set declaration");
  }

  bool expectedBrackets = true;
  bool expectedComma = false;
  for (size_t i = 3; i < tokens.size() - 1; i++) {
    if (expectedBrackets) {
      if (tokens.at(i) != "(") {
        throw std::invalid_argument("Invalid brackets");
      }
      i++;
      const std::string& setElementName = tokens.at(i);
      if (!isNameValid(setElementName)) {
        throw std::invalid_argument("Invalid set element name");
      }
      i++;
      if (tokens.at(i) != ",") {
        throw std::invalid_argument("Expected comma");
      }
      i++;
      
      double value = 0;
      if (!isNumValid(tokens.at(i), value)) {
        throw std::invalid_argument("Invalid number");
      }
      i++;
      if (tokens.at(i) != ")") {
        throw std::invalid_argument("Invalid brackets");
      }

      data[setElementName] = value;
      expectedBrackets = !expectedBrackets;
      expectedComma = !expectedComma;
      continue;
    }
    if (expectedComma) {
      if (tokens.at(i) == ",") {
        expectedBrackets = !expectedBrackets;
        expectedComma = !expectedComma;
        continue;
      } 
      throw std::invalid_argument("Expected comma");
    }
  }

  return FuzzySet(name, data);
}

template <>
RelationMatrix Parser::parse(const std::vector<std::string> &tokens) {
  const std::string name = isNameValid(tokens.at(0)) ? tokens.at(0) : "";
  if (name.empty()) {
    throw std::invalid_argument("Incorrect relation name: " + tokens.at(0));
  }

  if (tokens.size() != 7 || 
      tokens.at(1) != "=" || 
      tokens.at(2) != "(" || 
      tokens.back() != ")" ||
      tokens.at(4) != "=>" ||
      !isSetNameValid(tokens.at(3)) ||
      !isSetNameValid(tokens.at(5))) {
    throw std::invalid_argument("Invalid relation declaration");
  }

  return RelationMatrix(name, tokens.at(3), tokens.at(5));
}

template <>
Conclusion Parser::parse(const std::vector<std::string> &tokens) {
  if (tokens.size() != 5 ||
      tokens.at(0) != "{" ||
      tokens.back() != "}" ||
      tokens.at(2) != "," ||
      !isSetNameValid(tokens.at(1)) ||
      !isNameValid(tokens.at(3))) {
        throw std::invalid_argument("Invalid conclusion declaration");
      }
  return Conclusion(tokens.at(1), tokens.at(3));
}

bool Parser::isSetNameValid(const std::string &name) {
  return name[0] >= 'A' && name[0] <= 'Z';
}
bool Parser::isNameValid(const std::string &name) {
  return name[0] >= 'a' && name[0] <= 'z';
}

bool Parser::isNumValid(const std::string &num, double &buf) {
  double number = 0;
  try {
    number = std::stod(num);
  }
  catch(const std::invalid_argument&) {
    throw std::invalid_argument("Expected number");
  }

  buf = number;

  return number >= 0 && number <=1;
}


