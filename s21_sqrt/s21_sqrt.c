#include "s21_sqrt.h"

long double s21_sqrt(double x) {
  double result = x / 2;
  double term = 0;
  if (x < 0) {
    result = S21_NAN;
  } else if (x < 1e-21 || s21_fabs(x - 1) <= 1e-21) {
    result = x;
  } else {
    while (s21_fabs(result - term) > 1e-16) {
      term = result;
      result = (result + x / result) / 2;
    }
  }
  return result;
}