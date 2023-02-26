#include "s21_ceil.h"

long double s21_ceil(double x) {
  long long int_part = (long long)x;
  long double result;
  long double frac_part = x - int_part;
  if (x != x || x == S21_INF || x == S21_MIN_INF) {
    result = x;
  } else {
    if (frac_part > 0.0) {
      result = (long double)(int_part + 1);
    } else {
      result = (long double)int_part;
    }
  }
  return result;
}