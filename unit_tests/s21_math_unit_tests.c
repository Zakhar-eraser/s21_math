#include "s21_math_unit_tests.h"

int main() {
  int result = 0;
  SRunner *runner = srunner_create(suite_create("s21_math"));
  srunner_add_suite(runner, s21_acos_suite());
  srunner_add_suite(runner, s21_asin_suite());
  srunner_add_suite(runner, s21_atan_suite());
  srunner_add_suite(runner, s21_log_suite());
  srunner_add_suite(runner, s21_exp_suite());
  srunner_add_suite(runner, s21_pow_int_suite());
  srunner_add_suite(runner, s21_sin_suite());
  srunner_add_suite(runner, s21_cos_suite());
  srunner_add_suite(runner, s21_tan_suite());
  srunner_add_suite(runner, s21_ceil_suite());
  srunner_add_suite(runner, s21_floor_suite());
  srunner_add_suite(runner, s21_sqrt_suite());
  srunner_add_suite(runner, s21_abs_suite());
  srunner_add_suite(runner, s21_fabs_suite());
  srunner_add_suite(runner, s21_pow_suite());
  srunner_add_suite(runner, s21_fmod_suite());

  srunner_run_all(runner, CK_NORMAL);

  if (srunner_ntests_failed(runner)) result = EXIT_FAILURE;
  srunner_free(runner);
  return result;
}
