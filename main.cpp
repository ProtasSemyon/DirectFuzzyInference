#include <iostream>
#include "src/parser/Tokenizer.hpp"

int main() {
  auto tokens = Tokenizer::tokenize("A={(x1,0.0,(x2,0.1),(x3,0.3),(x4,1.0)}");
  for (const auto &token : tokens) {
    std::cout << "\"" << token << "\"" << " ";
  }
  return 0;
}