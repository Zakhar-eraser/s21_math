#include "s21_atan.h"

long double s21_atan_rec(long double x, unsigned int i);

long double s21_atan(double x) {
  long double result;
  if (x != x) {
    result = x;
  } else if (x == S21_INF) {
    result = S21_PI / 2;
  } else if (x == S21_MIN_INF) {
    result = -S21_PI / 2;
  } else {
    const long double delim = 0.75;
    long double sign = 1;
    if (x < 0) sign = -sign;
    x = s21_fabs(x);
    unsigned long long sub_times = 0;
    while (x > delim) {
      sub_times++;
      x = (x - delim) / (1 + x * delim);
    }
    result = (s21_taylor(s21_atan_rec, x, x) +
              s21_taylor(s21_atan_rec, delim, delim) * sub_times) *
             sign;
  }
  return result;
}

long double s21_atan_rec(long double x, unsigned int i) {
  return -x * x * (i * 2 - 1) / (i * 2 + 1);
}