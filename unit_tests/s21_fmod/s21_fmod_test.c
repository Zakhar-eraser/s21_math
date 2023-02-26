#include "s21_fmod_test.h"

const double fmod_args[9] = {0.,
                             1.,
                             345346.63454634634636346,
                             0.523266262235324,
                             0.000000000023,
                             -1.,
                             -345346.63454634634636346,
                             -0.523266262235324,
                             -0.000000000023};

const double default_modulo[10] = {1.,
                                   345346.63454634634636346,
                                   0.523266262235324,
                                   0.000000000023,
                                   -1.,
                                   -345346.63454634634636346,
                                   -0.523266262235324,
                                   -0.000000000023,
                                   S21_INF,
                                   S21_MIN_INF};

START_TEST(s21_fmod_base_default) {
  for (unsigned char j = 0; j < 10; j++)
    ck_assert_ldouble_eq_tol(s21_fmod(fmod_args[_i], default_modulo[j]),
                             fmod(fmod_args[_i], default_modulo[j]), TOLERANCE);
}
END_TEST

START_TEST(s21_fmod_modulo_default) {
  for (unsigned char j = 0; j < 9; j++)
    ck_assert_ldouble_eq_tol(s21_fmod(fmod_args[j], default_modulo[_i]),
                             fmod(fmod_args[j], default_modulo[_i]), TOLERANCE);
}
END_TEST

START_TEST(s21_fmod_zero_modulo) {
  ck_assert_ldouble_nan(fmod(fmod_args[_i], 0.));
  ck_assert_ldouble_nan(s21_fmod(fmod_args[_i], 0.));
}
END_TEST

START_TEST(s21_fmod_nan) {
  ck_assert_ldouble_nan(fmod(NAN, 5.));
  ck_assert_ldouble_nan(fmod(5., NAN));
  ck_assert_ldouble_nan(fmod(NAN, NAN));
  ck_assert_ldouble_nan(s21_fmod(NAN, 5.));
  ck_assert_ldouble_nan(s21_fmod(5., NAN));
  ck_assert_ldouble_nan(s21_fmod(NAN, NAN));
}
END_TEST

Suite *s21_fmod_suite() {
  Suite *s = suite_create("s21_fmod");

  TCase *tc_default = tcase_create("DEFAULT");
  tcase_add_loop_test(tc_default, s21_fmod_base_default, 0, 9);
  tcase_add_loop_test(tc_default, s21_fmod_modulo_default, 0, 10);
  suite_add_tcase(s, tc_default);

  TCase *tc_nan = tcase_create("NAN");
  tcase_add_loop_test(tc_nan, s21_fmod_zero_modulo, 0, 9);
  tcase_add_test(tc_nan, s21_fmod_nan);
  suite_add_tcase(s, tc_nan);

  return s;
}
