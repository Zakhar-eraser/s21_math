#ifndef _SRC_UNIT_TESTS_UNIT_TESTS_MODULES_H_
#define _SRC_UNIT_TESTS_UNIT_TESTS_MODULES_H_

#include <check.h>
#include <math.h>

#include "../s21_math.h"
#define TOLERANCE 1e-6
#define S21_PI 3.141592653589793
#define S21_NAN 0.0 / 0.0
#define S21_INF 1.0 / 0.0
#define S21_MIN_INF -1.0 / 0.0
#define LENGTH(X) sizeof(X) / sizeof(X[0])

#endif  // _SRC_UNIT_TESTS_UNIT_TESTS_MODULES_H_
