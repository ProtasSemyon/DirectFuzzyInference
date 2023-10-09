#pragma once
#include <memory>
#include <string>

#include "fuzzy_set/FuzzySet.hpp"
#include "relation_matrix/RelationMatrix.hpp"

class Conclusion {
public:
  Conclusion(std::string setName, std::string relName);

  void initialize(const std::shared_ptr<FuzzySet>& set, const std::shared_ptr<RelationMatrix>& rel);

  std::string getSetName() const;

  std::string getRelName() const;

  friend std::ostream& operator<<(std::ostream& os, const Conclusion& rel);

private:
  std::shared_ptr<FuzzySet> conclSet;

  std::string setName;

  std::string relName;
};