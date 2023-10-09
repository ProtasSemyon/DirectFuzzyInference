#include "Conclusion.hpp"
#include "utils/Utils.hpp"
#include <iostream>

Conclusion::Conclusion(std::string setName, std::string relName) : setName(std::move(setName)), relName(std::move(relName)){

}

void Conclusion::initialize(const std::shared_ptr<FuzzySet>& set, const std::shared_ptr<RelationMatrix>& rel) {
  if (!set ||!rel) {
    throw std::invalid_argument("invalid conclusion");
  }

  conclSet = std::make_shared<FuzzySet>();
  conclSet->setName("{ " + setName + ", " + relName + " }");
  
  size_t i = 0;

  auto setData = set->getData();
  auto matrix = rel->getData();

  for (const auto & [yName, yRow] : matrix.begin()->second) {
    double value = 0;
    for (const auto & [xName, xRow] : matrix) {
      auto v_set = setData[xName];
      auto v_impl = matrix[xName][yName];
      value = std::max(value, t_normal(v_set, v_impl));
    }
    conclSet->addElement(yName, value);
  }

}

std::string Conclusion::getSetName() const { 
  return setName;
}

std::string Conclusion::getRelName() const {
  return relName;
}

std::ostream& operator<<(std::ostream& os, const Conclusion& rel) {
  os << *rel.conclSet;
  //os << "{ " << rel.setName << ", " << rel.relName << " }\n";
  return os;
}
