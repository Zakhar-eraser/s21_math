#ifndef _SRC_COMMON_H_
#define _SRC_COMMON_H_

#include "../s21_math.h"

#define ACCURACY 1e-20
#define NEWTON_ACCURACY 1e-16
#define S21_PI 3.141592653589793
#define S21_NAN 0.0 / 0.0
#define S21_INF 1.0 / 0.0
#define S21_MIN_INF -1.0 / 0.0
#define MAX_ITER 100

typedef long double (*taylor_member_func)(long double, unsigned int);
typedef long double (*newton_member_func)(long double, long double);

long double s21_taylor(taylor_member_func func, long double init,
                       long double x);
long double s21_newton(newton_member_func func, long double init,
                       long double x);

#endif  // _SRC_COMMON_H_
