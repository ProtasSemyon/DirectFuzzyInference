#include "Utils.hpp"

double implication(double x, double y) {
  if (x <= y) {
    return 1;
  }
  return y / x;
}

double t_normal(double x, double y) {
  return x * y;
}