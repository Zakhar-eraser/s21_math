#include "s21_sin_test.h"

START_TEST(s21_sin_test_1) {
  ck_assert_int_eq(s21_sin(INFINITY), sin(INFINITY));
}
END_TEST

START_TEST(s21_sin_test_2) {
  ck_assert_int_eq(s21_sin(-INFINITY), sin(-INFINITY));
}
END_TEST

START_TEST(s21_sin_test_3) {
  double num = NAN;
  long double orig_res = sin(num), our_res = s21_sin(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_sin_test_4) {
  ck_assert(fabs((double)s21_sin(0) - sin(0)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sin_test_5) {
  ck_assert(fabs((double)s21_sin(-0) - sin(-0)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sin_test_6) {
  ck_assert(fabs((double)s21_sin(1) - sin(1)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sin_test_7) {
  ck_assert(fabs((double)s21_sin(100) - sin(100)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sin_test_8) {
  ck_assert(fabs((double)s21_sin(-1) - sin(-1)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sin_test_9) {
  ck_assert(fabs((double)s21_sin(-100) - sin(-100)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sin_test_10) {
  ck_assert(fabs((double)s21_sin(666666) - sin(666666)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sin_test_11) {
  ck_assert(fabs((double)s21_sin(-666666) - sin(-666666)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sin_test_12) {
  ck_assert(fabs((double)s21_sin(0.5) - sin(0.5)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sin_test_13) {
  ck_assert(fabs((double)s21_sin(-0.5) - sin(-0.5)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sin_test_14) {
  ck_assert(fabs((double)s21_sin(2.5) - sin(2.5)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sin_test_15) {
  ck_assert(fabs((double)s21_sin(-2.5) - sin(-2.5)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sin_test_16) {
  ck_assert(fabs((double)s21_sin(1234.456789) - sin(1234.456789)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sin_test_17) {
  ck_assert(fabs((double)s21_sin(-1234.456789) - sin(-1234.456789)) <
            TOLERANCE);
}
END_TEST

START_TEST(s21_sin_test_18) {
  ck_assert(fabs((double)s21_sin(0.000001) - sin(0.000001)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sin_test_19) {
  ck_assert(fabs((double)s21_sin(-0.000001) - sin(-0.000001)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sin_test_20) {
  ck_assert(fabs((double)s21_sin(0.3425443513423432432432) -
                 sin(0.3425443513423432432432)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sin_test_21) {
  ck_assert(fabs((double)s21_sin(-0.3425443513423432432432) -
                 sin(-0.3425443513423432432432)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sin_test_22) {
  ck_assert(fabs((double)s21_sin(S21_PI) - sin(S21_PI)) < TOLERANCE);
}
END_TEST

START_TEST(s21_sin_test_23) {
  ck_assert(fabs((double)s21_sin(-S21_PI) - sin(-S21_PI)) < TOLERANCE);
}
END_TEST

Suite *s21_sin_suite() {
  Suite *s = suite_create("s21_sin");
  TCase *tc = tcase_create("TEST sin");

  tcase_add_test(tc, s21_sin_test_1);
  tcase_add_test(tc, s21_sin_test_2);
  tcase_add_test(tc, s21_sin_test_3);
  tcase_add_test(tc, s21_sin_test_4);
  tcase_add_test(tc, s21_sin_test_5);
  tcase_add_test(tc, s21_sin_test_6);
  tcase_add_test(tc, s21_sin_test_7);
  tcase_add_test(tc, s21_sin_test_8);
  tcase_add_test(tc, s21_sin_test_9);
  tcase_add_test(tc, s21_sin_test_10);
  tcase_add_test(tc, s21_sin_test_11);
  tcase_add_test(tc, s21_sin_test_12);
  tcase_add_test(tc, s21_sin_test_13);
  tcase_add_test(tc, s21_sin_test_14);
  tcase_add_test(tc, s21_sin_test_15);
  tcase_add_test(tc, s21_sin_test_16);
  tcase_add_test(tc, s21_sin_test_17);
  tcase_add_test(tc, s21_sin_test_18);
  tcase_add_test(tc, s21_sin_test_19);
  tcase_add_test(tc, s21_sin_test_20);
  tcase_add_test(tc, s21_sin_test_21);
  tcase_add_test(tc, s21_sin_test_22);
  tcase_add_test(tc, s21_sin_test_23);

  suite_add_tcase(s, tc);
  return s;
}
