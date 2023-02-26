#include "s21_abs_test.h"

START_TEST(s21_abs_test_1) { ck_assert_int_eq(abs(0), s21_abs(0)); }
END_TEST

START_TEST(s21_abs_test_2) { ck_assert_int_eq(abs(-567), s21_abs(-567)); }
END_TEST

START_TEST(s21_abs_test_3) { ck_assert_int_eq(abs(345), s21_abs(345)); }
END_TEST

START_TEST(s21_abs_test_4) {
  ck_assert_int_eq(abs(INT32_MAX), s21_abs(INT32_MAX));
}
END_TEST

START_TEST(s21_abs_test_5) {
  ck_assert_int_eq(abs(INT32_MIN), s21_abs(INT32_MIN));
}
END_TEST

START_TEST(s21_abs_test_6) {
  int inf_max = S21_INF;
  ck_assert_int_eq(s21_abs(inf_max), abs(inf_max));
}
END_TEST

START_TEST(s21_abs_test_7) {
  int inf_min = -S21_INF;
  ck_assert_int_eq(s21_abs(inf_min), abs(inf_min));
}
END_TEST

START_TEST(s21_abs_test_8) {
  int nan = S21_NAN;
  ck_assert_int_eq(s21_abs(nan), abs(nan));
}
END_TEST

Suite *s21_abs_suite() {
  Suite *s = suite_create("s21_abs");
  TCase *tc = tcase_create("DEFAULT");

  tcase_add_test(tc, s21_abs_test_1);
  tcase_add_test(tc, s21_abs_test_2);
  tcase_add_test(tc, s21_abs_test_3);
  tcase_add_test(tc, s21_abs_test_4);
  tcase_add_test(tc, s21_abs_test_5);
  tcase_add_test(tc, s21_abs_test_6);
  tcase_add_test(tc, s21_abs_test_7);
  tcase_add_test(tc, s21_abs_test_8);

  suite_add_tcase(s, tc);

  return s;
}
