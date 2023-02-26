#include "s21_fmod.h"

long double s21_fmod(double x, double y) {
  long double res;
  if (x != x || x == S21_INF || x == S21_MIN_INF || y != y || y == 0.) {
    res = S21_NAN;
  } else if (y == S21_INF || y == S21_MIN_INF) {
    res = x;
  } else {
    long long int mod = x / y;
    res = (long double)x - mod * (long double)y;
  }
  return res;
}