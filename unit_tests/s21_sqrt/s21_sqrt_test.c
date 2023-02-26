#include "s21_sqrt_test.h"

START_TEST(s21_sqrt_test_1) {
  ck_assert_int_eq(s21_sqrt(INFINITY), sqrt(INFINITY));
}
END_TEST

START_TEST(s21_sqrt_test_2) {
  ck_assert_int_eq(s21_sqrt(-INFINITY), sqrt(-INFINITY));
}
END_TEST

START_TEST(s21_sqrt_test_3) {
  double num = NAN;
  long double orig_res = sqrt(num), our_res = s21_sqrt(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_sqrt_test_4) {
  ck_assert(fabs((double)s21_sqrt(0) - sqrt(0)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sqrt_test_5) {
  ck_assert(fabs((double)s21_sqrt(-0) - sqrt(-0)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sqrt_test_6) {
  ck_assert(fabs((double)s21_sqrt(1) - sqrt(1)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sqrt_test_7) {
  ck_assert(fabs((double)s21_sqrt(100) - sqrt(100)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sqrt_test_8) {
  double num = -1;
  long double orig_res = sqrt(num), our_res = s21_sqrt(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_sqrt_test_9) {
  double num = -100;
  long double orig_res = sqrt(num), our_res = s21_sqrt(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_sqrt_test_10) {
  ck_assert(fabs((double)s21_sqrt(666666) - sqrt(666666)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sqrt_test_11) {
  double num = -666666;
  long double orig_res = sqrt(num), our_res = s21_sqrt(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_sqrt_test_12) {
  ck_assert(fabs((double)s21_sqrt(0.5) - sqrt(0.5)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sqrt_test_13) {
  double num = -0.5;
  long double orig_res = sqrt(num), our_res = s21_sqrt(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_sqrt_test_14) {
  ck_assert(fabs((double)s21_sqrt(2.5) - sqrt(2.5)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sqrt_test_15) {
  double num = -2.5;
  long double orig_res = sqrt(num), our_res = s21_sqrt(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_sqrt_test_16) {
  ck_assert(fabs((double)s21_sqrt(1234.456789) - sqrt(1234.456789)) <
            TOLERANCE);
}
END_TEST

START_TEST(s21_sqrt_test_17) {
  double num = -1234.456789;
  long double orig_res = sqrt(num), our_res = s21_sqrt(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_sqrt_test_18) {
  ck_assert(fabs((double)s21_sqrt(0.000001) - sqrt(0.000001)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sqrt_test_19) {
  double num = -0.000001;
  long double orig_res = sqrt(num), our_res = s21_sqrt(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_sqrt_test_20) {
  ck_assert(fabs((double)s21_sqrt(0.3425443513423432432432) -
                 sqrt(0.3425443513423432432432)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sqrt_test_21) {
  double num = -0.3425443513423432432432;
  long double orig_res = sqrt(num), our_res = s21_sqrt(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

Suite *s21_sqrt_suite() {
  Suite *s = suite_create("s21_sqrt");
  TCase *tc = tcase_create("TEST sqrt");

  tcase_add_test(tc, s21_sqrt_test_1);
  tcase_add_test(tc, s21_sqrt_test_2);
  tcase_add_test(tc, s21_sqrt_test_3);
  tcase_add_test(tc, s21_sqrt_test_4);
  tcase_add_test(tc, s21_sqrt_test_5);
  tcase_add_test(tc, s21_sqrt_test_6);
  tcase_add_test(tc, s21_sqrt_test_7);
  tcase_add_test(tc, s21_sqrt_test_8);
  tcase_add_test(tc, s21_sqrt_test_9);
  tcase_add_test(tc, s21_sqrt_test_10);
  tcase_add_test(tc, s21_sqrt_test_11);
  tcase_add_test(tc, s21_sqrt_test_12);
  tcase_add_test(tc, s21_sqrt_test_13);
  tcase_add_test(tc, s21_sqrt_test_14);
  tcase_add_test(tc, s21_sqrt_test_15);
  tcase_add_test(tc, s21_sqrt_test_16);
  tcase_add_test(tc, s21_sqrt_test_17);
  tcase_add_test(tc, s21_sqrt_test_18);
  tcase_add_test(tc, s21_sqrt_test_19);
  tcase_add_test(tc, s21_sqrt_test_20);
  tcase_add_test(tc, s21_sqrt_test_21);

  suite_add_tcase(s, tc);
  return s;
}
