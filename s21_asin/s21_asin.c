#include "s21_asin.h"

long double s21_asin(double x) {
  long double result;
  result = s21_atan(x / s21_sqrt(1 - x * x));
  return result;
}
