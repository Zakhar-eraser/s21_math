#include "s21_pow_int.h"

long double s21_multiply(long double a, long double b);
long double s21_divide(long double a, long double b);

long double s21_pow_int(long double x, long long pow) {
  long double result = 1.;
  long double (*op)(long double, long double);
  if (pow < 0) {
    op = s21_divide;
    pow = -pow;
  } else {
    op = s21_multiply;
  }
  while (pow) {
    if (pow % 2) {
      result = op(result, x);
      pow--;
    } else {
      x *= x;
      pow /= 2;
    }
  }
  return result;
}

long double s21_multiply(long double a, long double b) { return a * b; }

long double s21_divide(long double a, long double b) { return a / b; }
