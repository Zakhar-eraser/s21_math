#include "s21_acos_test.h"

START_TEST(s21_acos_test_pos_0) {
  ck_assert_ldouble_eq_tol(s21_acos(0.4), acos(0.4), TOLERANCE);
}
END_TEST

START_TEST(s21_acos_test_pos_1) {
  ck_assert_ldouble_eq_tol(s21_acos(0.8), acos(0.8), TOLERANCE);
}
END_TEST

START_TEST(s21_acos_test_zero) {
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), TOLERANCE);
}
END_TEST

START_TEST(s21_acos_test_neg_0) {
  ck_assert_ldouble_eq_tol(s21_acos(-0.4), acos(-0.4), TOLERANCE);
}
END_TEST

START_TEST(s21_acos_test_neg_1) {
  ck_assert_ldouble_eq_tol(s21_acos(-0.8), acos(-0.8), TOLERANCE);
}
END_TEST

START_TEST(s21_acos_test_bound) {
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), TOLERANCE);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), TOLERANCE);
}
END_TEST

START_TEST(s21_acos_test_nan) {
  ck_assert_ldouble_nan(acos(NAN));
  ck_assert_ldouble_nan(s21_acos(NAN));
}
END_TEST

START_TEST(s21_acos_test_out_bound) {
  ck_assert_ldouble_nan(acos(1.1));
  ck_assert_ldouble_nan(acos(-1.1));
  ck_assert_ldouble_nan(s21_acos(1.1));
  ck_assert_ldouble_nan(s21_acos(-1.1));
}
END_TEST

START_TEST(s21_acos_test_infinite) {
  ck_assert_ldouble_nan(acos(S21_INF));
  ck_assert_ldouble_nan(acos(S21_MIN_INF));
  ck_assert_ldouble_nan(s21_acos(S21_INF));
  ck_assert_ldouble_nan(s21_acos(S21_MIN_INF));
}
END_TEST

Suite *s21_acos_suite() {
  Suite *s = suite_create("s21_acos");

  TCase *tc_default = tcase_create("DEFAULT");
  tcase_add_test(tc_default, s21_acos_test_pos_0);
  tcase_add_test(tc_default, s21_acos_test_pos_1);
  tcase_add_test(tc_default, s21_acos_test_zero);
  tcase_add_test(tc_default, s21_acos_test_neg_0);
  tcase_add_test(tc_default, s21_acos_test_neg_1);
  suite_add_tcase(s, tc_default);

  TCase *tc_small = tcase_create("BOUNDS");
  tcase_add_test(tc_small, s21_acos_test_bound);
  suite_add_tcase(s, tc_small);

  TCase *tc_nan = tcase_create("NAN");
  tcase_add_test(tc_nan, s21_acos_test_nan);
  suite_add_tcase(s, tc_nan);

  TCase *tc_out = tcase_create("OUT BOUNDARIES");
  tcase_add_test(tc_out, s21_acos_test_out_bound);
  suite_add_tcase(s, tc_out);

  TCase *tc_infinite = tcase_create("INFINITE");
  tcase_add_test(tc_infinite, s21_acos_test_infinite);
  suite_add_tcase(s, tc_infinite);

  return s;
}
