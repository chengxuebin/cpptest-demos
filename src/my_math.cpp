#include "my_math.h"

int MyMath::add_numbers(const int f1, const int f2) { return f1 + f2; }

int MyMath::subtract_numbers(const int f1, const int f2) { return f1 - f2; }

int MyMath::multiply_numbers(const int f1, const int f2) { return f1 * f2; }

int MyMath::my_calculate(const int f1, const int f2) {
  // equal f2*f2
  return multiply_numbers(subtract_numbers(add_numbers(f1, f2), f1), f2);
}