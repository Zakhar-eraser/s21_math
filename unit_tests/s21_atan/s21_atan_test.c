#include "s21_atan_test.h"

START_TEST(s21_atan_test_pos_0) {
  ck_assert_ldouble_eq_tol(s21_atan(0.6), atan(0.6), TOLERANCE);
}
END_TEST

START_TEST(s21_atan_test_pos_1) {
  ck_assert_ldouble_eq_tol(s21_atan(5), atan(5), TOLERANCE);
}
END_TEST

START_TEST(s21_atan_test_zero) {
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), TOLERANCE);
}
END_TEST

START_TEST(s21_atan_test_neg_0) {
  ck_assert_ldouble_eq_tol(s21_atan(-0.6), atan(-0.6), TOLERANCE);
}
END_TEST

START_TEST(s21_atan_test_neg_1) {
  ck_assert_ldouble_eq_tol(s21_atan(-5), atan(-5), TOLERANCE);
}
END_TEST

START_TEST(s21_atan_test_big_neg) {
  ck_assert_ldouble_eq_tol(s21_atan(-1e6), atan(-1e6), TOLERANCE);
}
END_TEST

START_TEST(s21_atan_test_big_pos) {
  ck_assert_ldouble_eq_tol(s21_atan(1e6), atan(1e6), TOLERANCE);
}
END_TEST

START_TEST(s21_atan_test_inf) {
  ck_assert_ldouble_eq(s21_atan(S21_INF), atan(S21_INF));
}
END_TEST

START_TEST(s21_atan_test_neg_inf) {
  ck_assert_ldouble_eq(s21_atan(S21_MIN_INF), atan(S21_MIN_INF));
}
END_TEST

START_TEST(s21_atan_test_nan) {
  ck_assert_ldouble_nan(atan(NAN));
  ck_assert_ldouble_nan(s21_atan(NAN));
}
END_TEST

Suite *s21_atan_suite() {
  Suite *s = suite_create("s21_atan");

  TCase *tc_default = tcase_create("DEFAULT");
  tcase_add_test(tc_default, s21_atan_test_pos_0);
  tcase_add_test(tc_default, s21_atan_test_pos_1);
  tcase_add_test(tc_default, s21_atan_test_zero);
  tcase_add_test(tc_default, s21_atan_test_neg_0);
  tcase_add_test(tc_default, s21_atan_test_neg_1);
  suite_add_tcase(s, tc_default);

  TCase *tc_small = tcase_create("BIG NEGATIVE");
  tcase_add_test(tc_small, s21_atan_test_big_neg);
  suite_add_tcase(s, tc_small);

  TCase *tc_big = tcase_create("BIG POSITIVE");
  tcase_add_test(tc_big, s21_atan_test_big_pos);
  suite_add_tcase(s, tc_big);

  TCase *tc_infinities = tcase_create("INFINITY");
  tcase_add_test(tc_infinities, s21_atan_test_inf);
  tcase_add_test(tc_infinities, s21_atan_test_neg_inf);
  suite_add_tcase(s, tc_infinities);

  TCase *tc_nan = tcase_create("NAN");
  tcase_add_test(tc_nan, s21_atan_test_nan);
  suite_add_tcase(s, tc_nan);

  return s;
}
