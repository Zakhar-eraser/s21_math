#include "s21_acos.h"

long double s21_acos(double x) {
  long double result;
  result = S21_PI / 2 - s21_asin(x);
  return result;
}
