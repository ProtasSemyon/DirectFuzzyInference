//////////////////////////////////////////////////////////////////////////////////////
// Лабораторная работа 4 по дисциплине ЛОИС
// Выполнена студентами группы 021701 БГУИР
// Протас С.А. и Рудьман И.О. - разработали код
// Вариант 22 - Реализовать прямой нечеткий логический вывод, используея импликацию Гогена
// 10.10.2023
// Использованные материалы:
// "Нечеткий логический вывод в системе принятия решений" А. А. Ахрем, М. Р. Ашинянц. С. А. Петров
// https://habr.com/ru/post/111187/ - Прямой нечеткий логический вывод

#pragma once
#include "parser/Parser.hpp"
#include "parser/Tokenizer.hpp"

class DirectFuzzyInference {
public:
  DirectFuzzyInference() = default;

  void printResultInFile(const std::string& outFilename) const;

  void printResultInConsole() const;

  void read(const std::string &filename);

  void process();

private:
  std::map<std::string, std::shared_ptr<FuzzySet> > fuzzySets;

  std::map<std::string, std::shared_ptr<RelationMatrix> > rels;

  std::vector<std::shared_ptr<Conclusion>> conclusions;

  void readFuzzySet(std::ifstream& stream);

  void readRelationMatrix(std::ifstream& stream);

  void readConclusion(std::ifstream& stream);
};