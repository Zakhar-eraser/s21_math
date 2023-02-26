#include "s21_pow.h"

long double s21_pow(double base, double exp) {
  long double result;
  double rem = (double)s21_fmod(exp, 1.);
  if (base != base || exp != exp ||
      (base < 0. && base != S21_MIN_INF && rem && rem != S21_INF &&
       rem != S21_MIN_INF && rem == rem)) {
    result = S21_NAN;
  } else if (exp == 0. || s21_fabs(base) == 1.) {
    result = 1.;
  } else if ((base == 0. && exp > 0.) ||
             ((s21_fabs(base) < 1.) && (exp == S21_INF)) ||
             ((s21_fabs(base) > 1.) && exp == S21_MIN_INF) ||
             ((base == S21_INF || base == S21_MIN_INF) && exp < 0.)) {
    result = 0.;
  } else if ((base == S21_INF) || (base == S21_MIN_INF) ||
             (base == 0. && exp < 0.) ||
             (s21_fabs(base) > 1 && exp == S21_INF) ||
             (s21_fabs(base) < 1. && exp == S21_MIN_INF)) {
    result = S21_INF;
  } else {
    char sign = 1;
    if (base < 0.) sign = -sign;
    result = s21_exp(exp * s21_log(base * sign));
    if (s21_fmod(exp, 2.)) result *= sign;
  }
  return result;
}
