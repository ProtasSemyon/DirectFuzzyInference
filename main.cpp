//////////////////////////////////////////////////////////////////////////////////////
// Лабораторная работа 4 по дисциплине ЛОИС
// Выполнена студентами группы 021701 БГУИР
// Протас С.А. и Рудьман И.О. - разработали код
// Вариант 22 - Реализовать прямой нечеткий логический вывод, используея импликацию Гогена
// 10.10.2023
// Использованные материалы:
// "Нечеткий логический вывод в системе принятия решений" А. А. Ахрем, М. Р. Ашинянц. С. А. Петров
// https://habr.com/ru/post/111187/ - Прямой нечеткий логический вывод

#include <iostream>
#include <fstream>
#include "src/parser/Tokenizer.hpp"
#include "src/parser/Parser.hpp"
#include "src/direct_fuzzy_inference/DirectFuzzyInference.hpp"

int main() {
  DirectFuzzyInference inference;
  inference.read(INPUT_FILE_PATH);
  inference.process();
  inference.printResultInFile(OUTPUT_FILE_PATH);
  return 0;
}