#include "s21_fabs.h"

long double s21_fabs(double number) {
  if (number < 0) {
    number = -number;
  }
  return number;
}