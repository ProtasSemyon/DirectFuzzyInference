#include <iostream>
#include <fstream>
#include "src/parser/Tokenizer.hpp"
#include "src/parser/Parser.hpp"
#include "src/direct_fuzzy_inference/DirectFuzzyInference.hpp"

int main() {
  auto inference = DirectFuzzyInference(INPUT_FILE_PATH);

  inference.printResultInFile(OUTPUT_FILE_PATH);
  return 0;
}