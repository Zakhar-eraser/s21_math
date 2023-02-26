#include "common.h"

long double s21_newton(newton_member_func func, long double init,
                       long double x) {
  long double member = init;
  long double result = 0.0;
  long long i = 0;
  while ((s21_fabs(member) > NEWTON_ACCURACY) && (i < MAX_ITER)) {
    result += member;
    member = func(x, result);
    i++;
  }
  return result;
}

long double s21_taylor(taylor_member_func func, long double init,
                       long double x) {
  long double member = init;
  long double result = 0.0;
  for (unsigned int i = 1; s21_fabs(member) > ACCURACY; i++) {
    result += member;
    member = member * func(x, i);
  }
  return result;
}