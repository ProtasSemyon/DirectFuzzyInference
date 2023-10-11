//////////////////////////////////////////////////////////////////////////////////////
// Лабораторная работа 4 по дисциплине ЛОИС
// Выполнена студентами группы 021701 БГУИР
// Протас С.А. и Рудьман И.О. - разработали код
// Вариант 22 - Реализовать прямой нечеткий логический вывод, используея импликацию Гогена
// 10.10.2023
// Использованные материалы:
// "Нечеткий логический вывод в системе принятия решений" А. А. Ахрем, М. Р. Ашинянц. С. А. Петров
// https://habr.com/ru/post/111187/ - Прямой нечеткий логический вывод

#include "Tokenizer.hpp"
#include <stdexcept>
#include <set>

std::vector<std::string> Tokenizer::tokenize(const std::string& str) {
  std::vector<std::string> tokens;
  std::string nameToken;
  std::string numberToken;

  const std::set<char> singleTokens{'{', '}', '(', ')', ',', '=', '>'};

  for (auto ch : str) {
    if (ch == ' ') {
      continue;
    }

    if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z') {
      if (!numberToken.empty()) {
        tokens.emplace_back(std::move(numberToken));
      }
      nameToken.push_back(ch);
      continue;
    }

    if (ch >= '0' && ch <= '9') {
      if (!nameToken.empty()) {
        nameToken.push_back(ch);
      } else {
        numberToken.push_back(ch);
      }
      continue;
    }

    if (ch == '.') {
      if (numberToken.empty() || numberToken.back() == '.') {
        throw std::invalid_argument("Invalid number token");
      }
      numberToken.push_back(ch);
      continue;
    }    

    if (singleTokens.count(ch) == 1) {
      if (!numberToken.empty()) {
        tokens.emplace_back(std::move(numberToken));
      }
      if (!nameToken.empty()) {
        tokens.emplace_back(std::move(nameToken));
      }

      tokens.emplace_back(1, ch);
    } else {
      throw std::invalid_argument("Unrecognized token");
    }
  }

  if (!numberToken.empty()) {
    tokens.emplace_back(std::move(numberToken));
  }
  if (!nameToken.empty()) {
    tokens.emplace_back(std::move(nameToken));
  }

  std::vector<std::string> newTokens;

  for (auto & token : tokens) {
    if (token == ">") {
      if (!newTokens.empty() && newTokens.back() == "=") {
        newTokens.pop_back();
        newTokens.emplace_back("=>");
      } else {
        throw std::invalid_argument("Unrecognized token");
      }
    } else {
      newTokens.emplace_back(token);
    }
  }

  return newTokens;
}
