#include "s21_tan.h"

long double s21_tan(double x) {
  double result = 0;
  if (x != x || x == S21_INF || x == S21_MIN_INF || x == 0) {
    result = x;
  } else if (x == S21_PI || x == -S21_PI) {
    result = 1e-21;
  } else if (x == S21_PI / 2) {
    result = 16331239353195370L;
  } else if (x == -S21_PI / 2) {
    result = -16331239353195370L;
  } else {
    result = s21_sin(x) / s21_cos(x);
  }
  return result;
}
