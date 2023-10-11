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