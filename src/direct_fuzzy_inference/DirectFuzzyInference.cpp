#include "DirectFuzzyInference.hpp"
#include <fstream>
#include <iostream>


DirectFuzzyInference::DirectFuzzyInference(const std::string& inFile) {
  read(inFile);
}


void DirectFuzzyInference::read(const std::string &filename) {
  std::ifstream stream(filename);
  if (!stream.is_open()) {
    throw std::invalid_argument("File " + filename + "does not exist");
  }
  readFuzzySet(stream);
  readRelationMatrix(stream);
  readConclusion(stream);
}


void DirectFuzzyInference::readFuzzySet(std::ifstream& stream) {
  std::string buf;
  std::getline(stream, buf);

  while (!buf.empty()) {
    auto fuzzySet = std::make_shared<FuzzySet>(Parser::parse<FuzzySet>(Tokenizer::tokenize(buf)));
    fuzzySets[fuzzySet->getName()] = fuzzySet;
    std::getline(stream, buf);
  }
}

void DirectFuzzyInference::readRelationMatrix(std::ifstream& stream) {
  std::string buf;
  std::getline(stream, buf);

  while (!buf.empty()) {
    auto rel = std::make_shared<RelationMatrix>(Parser::parse<RelationMatrix>(Tokenizer::tokenize(buf)));
    rel->initialize(fuzzySets[rel->getXSetName()], fuzzySets[rel->getYSetName()]);
    rels[rel->getName()] = rel;
    std::getline(stream, buf);
  }
}

void DirectFuzzyInference::readConclusion(std::ifstream& stream) {
  std::string buf;
  std::getline(stream, buf);

  while (!buf.empty()) {
    auto concl = std::make_shared<Conclusion>(Parser::parse<Conclusion>(Tokenizer::tokenize(buf)));
    concl->initialize(fuzzySets[concl->getSetName()], rels[concl->getRelName()]);
    conclusions.emplace_back(concl);
    std::getline(stream, buf);
  }
}

void DirectFuzzyInference::printResultInFile(const std::string& outFilename) const {
  std::ofstream out(outFilename);
  for (const auto &concl : conclusions) {
    out << *concl;
  } 
}

void DirectFuzzyInference::printResultInConsole() const {
  for (const auto &concl : conclusions) {
    std::cout << *concl;
  }  
}

