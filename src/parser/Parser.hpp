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

#include <vector>
#include <string>

#include "fuzzy_set/FuzzySet.hpp"
#include "relation_matrix/RelationMatrix.hpp"
#include "conclusion/Conclusion.hpp"

class Parser {
public:
  template<class T>
  static T parse(const std::vector<std::string> &tokens);

private:
  static bool isSetNameValid(const std::string &name);

  static bool isNameValid(const std::string &name);

  static bool isNumValid(const std::string &num, double &buf);

};