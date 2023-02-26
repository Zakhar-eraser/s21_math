#include "s21_floor.h"

long double s21_floor(double x) {
  long long int_part = (long long)x;
  long double result;
  if (x != x || x == S21_INF || x == S21_MIN_INF) {
    result = x;
  } else {
    if (x >= 0 || s21_fabs(x - int_part) < 0.0000001) {
      result = int_part;
    } else {
      result = int_part - 1;
    }
  }
  return result;
}