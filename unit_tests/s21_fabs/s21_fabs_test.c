#include "s21_fabs_test.h"

START_TEST(s21_fabs_test_pos) {
  ck_assert_ldouble_eq_tol(s21_fabs(5.0), fabs(5.0), TOLERANCE);
}
END_TEST

START_TEST(s21_fabs_test_zero) {
  ck_assert_ldouble_eq_tol(s21_fabs(0.), fabs(0.), TOLERANCE);
}
END_TEST

START_TEST(s21_fabs_test_neg) {
  ck_assert_ldouble_eq_tol(s21_fabs(-5.), fabs(-5.), TOLERANCE);
}
END_TEST

START_TEST(s21_fabs_test_big_neg) {
  ck_assert_ldouble_eq_tol(s21_fabs(-1e16), fabs(-1e16), TOLERANCE);
}
END_TEST

START_TEST(s21_fabs_test_max) {
  ck_assert_ldouble_eq_tol(s21_fabs(DBL_MAX), fabs(DBL_MAX), TOLERANCE);
}
END_TEST

START_TEST(s21_fabs_test_min) {
  ck_assert_ldouble_eq_tol(s21_fabs(DBL_MIN), fabs(DBL_MIN), TOLERANCE);
}
END_TEST

START_TEST(s21_fabs_test_nan) {
  ck_assert_ldouble_nan(fabs(NAN));
  ck_assert_ldouble_nan(s21_fabs(NAN));
}
END_TEST

START_TEST(s21_fabs_test_infinite) {
  ck_assert_ldouble_eq(fabs(S21_INF), s21_fabs(S21_INF));
  ck_assert_ldouble_eq(fabs(S21_MIN_INF), s21_fabs(S21_MIN_INF));
}
END_TEST

Suite *s21_fabs_suite() {
  Suite *s = suite_create("s21_fabs");

  TCase *tc_default = tcase_create("DEFAULT");
  tcase_add_test(tc_default, s21_fabs_test_pos);
  tcase_add_test(tc_default, s21_fabs_test_zero);
  tcase_add_test(tc_default, s21_fabs_test_neg);
  suite_add_tcase(s, tc_default);

  TCase *tc_small = tcase_create("BIG NEGATIVE");
  tcase_add_test(tc_small, s21_fabs_test_big_neg);
  suite_add_tcase(s, tc_small);

  TCase *tc_max = tcase_create("MAX");
  tcase_add_test(tc_max, s21_fabs_test_max);
  tcase_add_test(tc_max, s21_fabs_test_min);
  suite_add_tcase(s, tc_max);

  TCase *tc_nan = tcase_create("NAN");
  tcase_add_test(tc_nan, s21_fabs_test_nan);
  suite_add_tcase(s, tc_nan);

  TCase *tc_inf = tcase_create("INF");
  tcase_add_test(tc_inf, s21_fabs_test_infinite);
  suite_add_tcase(s, tc_inf);

  return s;
}
