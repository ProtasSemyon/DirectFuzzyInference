//////////////////////////////////////////////////////////////////////////////////////
// Лабораторная работа 4 по дисциплине ЛОИС
// Выполнена студентами группы 021701 БГУИР
// Протас С.А. и Рудьман И.О. - разработали код
// Вариант 22 - Реализовать прямой нечеткий логический вывод, используея импликацию Гогена
// 10.10.2023
// Использованные материалы:
// "Нечеткий логический вывод в системе принятия решений" А. А. Ахрем, М. Р. Ашинянц. С. А. Петров
// https://habr.com/ru/post/111187/ - Прямой нечеткий логический вывод

#include "RelationMatrix.hpp"
#include "utils/Utils.hpp"
#include <iostream>

RelationMatrix::RelationMatrix(std::string name, std::string xSetName, std::string ySetName) : name(std::move(name)), xSetName(std::move(xSetName)), ySetName(std::move(ySetName)) {}

void RelationMatrix::initialize(const std::shared_ptr<FuzzySet> &xSet, const std::shared_ptr<FuzzySet> &ySet) {
  if (!xSet || !ySet) {
    throw std::invalid_argument("invalid set");
  }
  for (const auto &[x_name, x_val] : xSet->getData()) {
    for (const auto &[y_name, y_val] : ySet->getData()) {
      data[x_name][y_name] = implication(x_val, y_val);
    }
  }
}

std::string RelationMatrix::getXSetName() const {
  return xSetName;
}

std::string RelationMatrix::getYSetName() const {
  return ySetName;
}

std::string RelationMatrix::getName() const {
  return name;
}

std::ostream& operator<<(std::ostream& os, const RelationMatrix& rel) {
  os << rel.name << " = ( " << rel.xSetName << " => " << rel.ySetName << " )\n";
  return os;
}

std::map<std::string, std::map<std::string, double> > RelationMatrix::getData() const {
  return data;
}
