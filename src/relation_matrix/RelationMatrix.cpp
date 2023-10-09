#include "RelationMatrix.hpp"
#include "utils/Utils.hpp"
#include <iostream>

RelationMatrix::RelationMatrix(std::string name, std::string xSetName, std::string ySetName) : name(std::move(name)), xSetName(std::move(xSetName)), ySetName(std::move(ySetName)) {}

void RelationMatrix::initialize(const std::shared_ptr<FuzzySet> &xSet, const std::shared_ptr<FuzzySet> &ySet) {
  if (!xSet || !ySet) {
    throw std::invalid_argument("invalid set");
  }
  for (const auto &[x_name, x_val] : xSet->getData()) {
    for (const auto &[y_name, y_val] : ySet->getData()) {
      data[x_name][y_name] = implication(x_val, y_val);
    }
  }
}

std::string RelationMatrix::getXSetName() const {
  return xSetName;
}

std::string RelationMatrix::getYSetName() const {
  return ySetName;
}

std::string RelationMatrix::getName() const {
  return name;
}

std::ostream& operator<<(std::ostream& os, const RelationMatrix& rel) {
  os << rel.name << " = ( " << rel.xSetName << " => " << rel.ySetName << " )\n";
  return os;
}

std::map<std::string, std::map<std::string, double> > RelationMatrix::getData() const {
  return data;
}
