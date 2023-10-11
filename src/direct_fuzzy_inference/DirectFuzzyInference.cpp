//////////////////////////////////////////////////////////////////////////////////////
// Лабораторная работа 4 по дисциплине ЛОИС
// Выполнена студентами группы 021701 БГУИР
// Протас С.А. и Рудьман И.О. - разработали код
// Вариант 22 - Реализовать прямой нечеткий логический вывод, используея импликацию Гогена
// 10.10.2023
// Использованные материалы:
// "Нечеткий логический вывод в системе принятия решений" А. А. Ахрем, М. Р. Ашинянц. С. А. Петров
// https://habr.com/ru/post/111187/ - Прямой нечеткий логический вывод

#include "DirectFuzzyInference.hpp"
#include <fstream>
#include <iostream>

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
    rels[rel->getName()] = rel;
    std::getline(stream, buf);
  }
}

void DirectFuzzyInference::readConclusion(std::ifstream& stream) {
  std::string buf;
  std::getline(stream, buf);

  while (!buf.empty()) {
    auto concl = std::make_shared<Conclusion>(Parser::parse<Conclusion>(Tokenizer::tokenize(buf)));
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

void DirectFuzzyInference::process() {
  for (const auto &[relName, rel] : rels) {
    rel->initialize(fuzzySets[rel->getXSetName()], fuzzySets[rel->getYSetName()]);
  }

  for (const auto &concl : conclusions) {
    concl->initialize(fuzzySets[concl->getSetName()], rels[concl->getRelName()]);
  }
}
