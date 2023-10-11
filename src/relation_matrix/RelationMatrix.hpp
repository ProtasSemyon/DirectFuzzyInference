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
#include <map>
#include <memory>
#include <string>

#include "fuzzy_set/FuzzySet.hpp"

class RelationMatrix {
public:
  RelationMatrix(std::string name, std::string xSetName, std::string ySetName);

  void initialize(const std::shared_ptr<FuzzySet> &xSet, const std::shared_ptr<FuzzySet> &ySet);

  std::string getXSetName() const;

  std::string getYSetName() const;

  std::string getName() const;

  std::map<std::string, std::map<std::string, double> > getData() const;

  friend std::ostream& operator<<(std::ostream& os, const RelationMatrix& rel);

private:
  std::map<std::string, std::map<std::string, double> > data;

  std::string name;

  std::string xSetName;

  std::string ySetName;
};