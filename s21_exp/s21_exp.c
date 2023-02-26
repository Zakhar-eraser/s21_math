#include "s21_exp.h"

#define E 2.71828182845904523536028747135266249L

long double s21_exp(double x) {
  long double result;
  if (x != x || x == S21_INF) {
    result = x;
  } else if (x == S21_MIN_INF) {
    result = 0;
  } else {
    long long sub = (long long)x;
    long double rem = x - sub;
    result = s21_taylor(s21_exp_rec, 1, rem);
    if (sub) result *= s21_pow_int(E, sub);
  }
  return result;
}

long double s21_exp_rec(long double x, unsigned int i) { return x / i; }
