#include "s21_log_test.h"

START_TEST(s21_log_test_pos) {
  ck_assert_ldouble_eq_tol(s21_log(5), log(5), TOLERANCE);
}
END_TEST

START_TEST(s21_log_test_zero) {
  ck_assert_ldouble_eq_tol(s21_log(1), log(1), TOLERANCE);
}
END_TEST

START_TEST(s21_log_test_lt_one) {
  ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), TOLERANCE);
}
END_TEST

START_TEST(s21_log_test_small) {
  ck_assert_ldouble_eq_tol(s21_log(1e-6), log(1e-6), TOLERANCE);
}
END_TEST

START_TEST(s21_log_test_big) {
  ck_assert_ldouble_eq_tol(s21_log(1e16), log(1e16), TOLERANCE);
}
END_TEST

START_TEST(s21_log_test_infinite_pos) {
  ck_assert_ldouble_eq(log(S21_INF), s21_log(S21_INF));
}
END_TEST

START_TEST(s21_log_test_infinite_neg) {
  ck_assert_ldouble_nan(log(S21_MIN_INF));
  ck_assert_ldouble_nan(s21_log(S21_MIN_INF));
}
END_TEST

START_TEST(s21_log_test_nan) {
  ck_assert_ldouble_nan(log(NAN));
  ck_assert_ldouble_nan(s21_log(NAN));
}
END_TEST

START_TEST(s21_log_test_neg) {
  ck_assert_ldouble_nan(log(-4.));
  ck_assert_ldouble_nan(s21_log(-4.));
}
END_TEST

Suite *s21_log_suite() {
  Suite *s = suite_create("s21_log");

  TCase *tc_default = tcase_create("DEFAULT");
  tcase_add_test(tc_default, s21_log_test_pos);
  tcase_add_test(tc_default, s21_log_test_zero);
  tcase_add_test(tc_default, s21_log_test_lt_one);
  suite_add_tcase(s, tc_default);

  TCase *tc_small = tcase_create("SMALL");
  tcase_add_test(tc_small, s21_log_test_small);
  suite_add_tcase(s, tc_small);

  TCase *tc_big = tcase_create("BIG");
  tcase_add_test(tc_big, s21_log_test_big);
  suite_add_tcase(s, tc_big);

  TCase *tc_infinite = tcase_create("INFINITE");
  tcase_add_test(tc_big, s21_log_test_infinite_pos);
  tcase_add_test(tc_big, s21_log_test_infinite_neg);
  suite_add_tcase(s, tc_infinite);

  TCase *tc_nan = tcase_create("NAN");
  tcase_add_test(tc_nan, s21_log_test_nan);
  tcase_add_test(tc_nan, s21_log_test_neg);
  suite_add_tcase(s, tc_nan);

  return s;
}
