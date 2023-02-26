#include "s21_exp_test.h"

START_TEST(s21_exp_test_pos) {
  ck_assert_ldouble_eq_tol(s21_exp(5), exp(5), TOLERANCE);
  ck_assert_ldouble_eq_tol(s21_exp(20.5554), exp(20.5554), TOLERANCE);
}
END_TEST

START_TEST(s21_exp_test_zero) {
  ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), TOLERANCE);
}
END_TEST

START_TEST(s21_exp_test_neg) {
  ck_assert_ldouble_eq_tol(s21_exp(-5), exp(-5), TOLERANCE);
}
END_TEST

START_TEST(s21_exp_test_big_neg) {
  ck_assert_ldouble_eq_tol(s21_exp(-1e6), exp(-1e6), TOLERANCE);
}
END_TEST

START_TEST(s21_exp_test_big_pos) {
  ck_assert_double_eq(s21_exp(1004), exp(1004));
}
END_TEST

START_TEST(s21_exp_test_inf) {
  ck_assert_ldouble_eq(s21_exp(S21_INF), exp(S21_INF));
  ck_assert_ldouble_eq(s21_exp(S21_MIN_INF), exp(S21_MIN_INF));
}
END_TEST

START_TEST(s21_exp_test_nan) {
  ck_assert_ldouble_nan(exp(NAN));
  ck_assert_ldouble_nan(s21_exp(NAN));
}
END_TEST

Suite *s21_exp_suite() {
  Suite *s = suite_create("s21_exp");

  TCase *tc_default = tcase_create("DEFAULT");
  tcase_add_test(tc_default, s21_exp_test_pos);
  tcase_add_test(tc_default, s21_exp_test_zero);
  tcase_add_test(tc_default, s21_exp_test_neg);
  suite_add_tcase(s, tc_default);

  TCase *tc_small = tcase_create("BIG NEGATIVE");
  tcase_add_test(tc_small, s21_exp_test_big_neg);
  suite_add_tcase(s, tc_small);

  TCase *tc_big = tcase_create("BIG POSITIVE");
  tcase_add_test(tc_big, s21_exp_test_big_pos);
  suite_add_tcase(s, tc_big);

  TCase *tc_infinities = tcase_create("INFINITY");
  tcase_add_test(tc_infinities, s21_exp_test_inf);
  suite_add_tcase(s, tc_infinities);

  TCase *tc_nan = tcase_create("NAN");
  tcase_add_test(tc_nan, s21_exp_test_nan);
  suite_add_tcase(s, tc_nan);

  return s;
}
