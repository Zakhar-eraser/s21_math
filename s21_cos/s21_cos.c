#include "s21_cos.h"

long double s21_cos(double x) {
  double result = 0.0;
  if (x != x || x == S21_INF || x == S21_MIN_INF) {
    result = x;
  } else if (x == S21_PI || x == 0.0) {
    result = 1;
  } else if (x == -S21_PI) {
    result = -1;
  } else {
    if (s21_fabs(x) > 2 * S21_PI) {
      double D = x / 2 / S21_PI;
      int int_part = (int)D;
      double remainder = D - int_part;
      x = remainder * 2 * S21_PI;
    }
    double term = 1;
    result = s21_taylor(s21_cos_rec, term, x);
  }
  return result;
}

long double s21_cos_rec(long double x, unsigned int i) {
  return -1 * x * x / (2 * i - 1) / (2 * i);
}
