//////////////////////////////////////////////////////////////////////////////////////
// Лабораторная работа 4 по дисциплине ЛОИС
// Выполнена студентами группы 021701 БГУИР
// Протас С.А. и Рудьман И.О. - разработали код
// Вариант 22 - Реализовать прямой нечеткий логический вывод, используея импликацию Гогена
// 10.10.2023
// Использованные материалы:
// "Нечеткий логический вывод в системе принятия решений" А. А. Ахрем, М. Р. Ашинянц. С. А. Петров
// https://habr.com/ru/post/111187/ - Прямой нечеткий логический вывод

#include "Conclusion.hpp"
#include "utils/Utils.hpp"
#include <iostream>

Conclusion::Conclusion(std::string setName, std::string relName) : setName(std::move(setName)), relName(std::move(relName)){

}

void Conclusion::initialize(const std::shared_ptr<FuzzySet>& set, const std::shared_ptr<RelationMatrix>& rel) {
  if (!set ||!rel) {
    throw std::invalid_argument("invalid conclusion");
  }

  conclSet = std::make_shared<FuzzySet>();
  conclSet->setName("{ " + setName + ", " + relName + " }");
  
  auto setData = set->getData();
  auto matrix = rel->getData();

  for (const auto & [yName, yRow] : matrix.begin()->second) {
    double value = 0;
    for (const auto & [xName, xRow] : matrix) {
      auto v_set = setData[xName];
      auto v_impl = matrix[xName][yName];
      value = std::max(value, t_normal(v_set, v_impl));
    }
    conclSet->addElement(yName, value);
  }

}

std::string Conclusion::getSetName() const { 
  return setName;
}

std::string Conclusion::getRelName() const {
  return relName;
}

std::ostream& operator<<(std::ostream& os, const Conclusion& rel) {
  os << *rel.conclSet;
  return os;
}
