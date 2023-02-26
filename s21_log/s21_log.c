#include "s21_log.h"

long double s21_log_rec(long double x, long double prev_y);

long double s21_log(double x) {
  long double result;
  if (x == S21_INF) {
    result = x;
  } else if (x < 0. || x != x) {
    result = S21_NAN;
  } else {
    result = s21_newton(s21_log_rec, 1, x);
  }
  return result;
}

long double s21_log_rec(long double x, long double prev_y) {
  long double exp = s21_exp(prev_y);
  return 2 * (x - exp) / (x + exp);
}