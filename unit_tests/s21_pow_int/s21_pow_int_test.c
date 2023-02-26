#include "s21_pow_int_test.h"

START_TEST(s21_pow_int_test_pos) {
  ck_assert_double_eq_tol(s21_pow_int(2., 45), pow(2., 45), TOLERANCE);
}
END_TEST

START_TEST(s21_pow_int_test_zero) {
  ck_assert_double_eq_tol(s21_pow_int(2., 0), pow(2., 0), TOLERANCE);
}
END_TEST

START_TEST(s21_pow_int_test_neg) {
  ck_assert_double_eq_tol(s21_pow_int(2., -45), pow(2., -45), TOLERANCE);
}
END_TEST

START_TEST(s21_pow_int_test_small) {
  ck_assert_double_eq_tol(s21_pow_int(1e-8, 0), pow(1e-8, 0), TOLERANCE);
}
END_TEST

Suite *s21_pow_int_suite() {
  Suite *s = suite_create("s21_pow_int");

  TCase *tc_default = tcase_create("DEFAULT");
  tcase_add_test(tc_default, s21_pow_int_test_pos);
  tcase_add_test(tc_default, s21_pow_int_test_zero);
  tcase_add_test(tc_default, s21_pow_int_test_neg);
  suite_add_tcase(s, tc_default);

  TCase *tc_small = tcase_create("SMALL");
  tcase_add_test(tc_small, s21_pow_int_test_small);
  suite_add_tcase(s, tc_small);

  return s;
}
