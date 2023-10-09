#pragma once
#include "parser/Parser.hpp"
#include "parser/Tokenizer.hpp"



class DirectFuzzyInference {
public:
  DirectFuzzyInference(const std::string& inFile);

  void printResultInFile(const std::string& outFilename) const;

  void printResultInConsole() const;

private:
  std::map<std::string, std::shared_ptr<FuzzySet> > fuzzySets;

  std::map<std::string, std::shared_ptr<RelationMatrix> > rels;

  std::vector<std::shared_ptr<Conclusion>> conclusions;

  void read(const std::string &filename);

  void readFuzzySet(std::ifstream& stream);

  void readRelationMatrix(std::ifstream& stream);

  void readConclusion(std::ifstream& stream);
};