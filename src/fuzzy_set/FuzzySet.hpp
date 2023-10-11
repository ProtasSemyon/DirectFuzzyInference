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
#include <string>

class FuzzySet {
public:
  FuzzySet() = default;

  explicit FuzzySet(std::string name, const std::map<std::string, double, std::less<>> & data);

  void addElement(const std::string& key, double value);

  friend std::ostream& operator<<(std::ostream& os, const FuzzySet& set);

  std::map<std::string, double, std::less<>> getData() const;

  std::string getName() const;

  void setName(std::string newName);

private:
  std::map<std::string, double, std::less<>> data;

  std::string name;
};