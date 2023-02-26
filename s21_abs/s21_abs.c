#include "s21_abs.h"

int s21_abs(int number) {
  if (number < 0) {
    number = -number;
  }
  return number;
}