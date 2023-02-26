#include "s21_cos_test.h"

START_TEST(s21_cos_test_1) {
  ck_assert_int_eq(s21_cos(INFINITY), cos(INFINITY));
}
END_TEST

START_TEST(s21_cos_test_2) {
  ck_assert_int_eq(s21_cos(-INFINITY), cos(-INFINITY));
}
END_TEST

START_TEST(s21_cos_test_3) {
  double num = NAN;
  long double orig_res = cos(num), our_res = s21_cos(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_cos_test_4) {
  ck_assert(fabs((double)s21_cos(0) - cos(0)) < TOLERANCE);
}
END_TEST

START_TEST(s21_cos_test_5) {
  ck_assert(fabs((double)s21_cos(-0) - cos(-0)) < TOLERANCE);
}
END_TEST

START_TEST(s21_cos_test_6) {
  ck_assert(fabs((double)s21_cos(1) - cos(1)) < TOLERANCE);
}
END_TEST

START_TEST(s21_cos_test_7) {
  ck_assert(fabs((double)s21_cos(100) - cos(100)) < TOLERANCE);
}
END_TEST

START_TEST(s21_cos_test_8) {
  ck_assert(fabs((double)s21_cos(-1) - cos(-1)) < TOLERANCE);
}
END_TEST

START_TEST(s21_cos_test_9) {
  ck_assert(fabs((double)s21_cos(-100) - cos(-100)) < TOLERANCE);
}
END_TEST

START_TEST(s21_cos_test_10) {
  ck_assert(fabs((double)s21_cos(666666) - cos(666666)) < TOLERANCE);
}
END_TEST

START_TEST(s21_cos_test_11) {
  ck_assert(fabs((double)s21_cos(-666666) - cos(-666666)) < TOLERANCE);
}
END_TEST

START_TEST(s21_cos_test_12) {
  ck_assert(fabs((double)s21_cos(0.5) - cos(0.5)) < TOLERANCE);
}
END_TEST

START_TEST(s21_cos_test_13) {
  ck_assert(fabs((double)s21_cos(-0.5) - cos(-0.5)) < TOLERANCE);
}
END_TEST

START_TEST(s21_cos_test_14) {
  ck_assert(fabs((double)s21_cos(2.5) - cos(2.5)) < TOLERANCE);
}
END_TEST

START_TEST(s21_cos_test_15) {
  ck_assert(fabs((double)s21_cos(-2.5) - cos(-2.5)) < TOLERANCE);
}
END_TEST

START_TEST(s21_cos_test_16) {
  ck_assert(fabs((double)s21_cos(1234.456789) - cos(1234.456789)) < TOLERANCE);
}
END_TEST

START_TEST(s21_cos_test_17) {
  ck_assert(fabs((double)s21_cos(-1234.456789) - cos(-1234.456789)) <
            TOLERANCE);
}
END_TEST

START_TEST(s21_cos_test_18) {
  ck_assert(fabs((double)s21_cos(0.000001) - cos(0.000001)) < TOLERANCE);
}
END_TEST

START_TEST(s21_cos_test_19) {
  ck_assert(fabs((double)s21_cos(-0.000001) - cos(-0.000001)) < TOLERANCE);
}
END_TEST

START_TEST(s21_cos_test_20) {
  ck_assert(fabs((double)s21_cos(0.3425443513423432432432) -
                 cos(0.3425443513423432432432)) < TOLERANCE);
}
END_TEST

START_TEST(s21_cos_test_21) {
  ck_assert(fabs((double)s21_cos(-0.3425443513423432432432) -
                 cos(-0.3425443513423432432432)) < TOLERANCE);
}
END_TEST

START_TEST(s21_cos_test_22) {
  ck_assert(fabs((double)s21_cos(-S21_PI) - cos(-S21_PI)) < TOLERANCE);
}
END_TEST

Suite *s21_cos_suite() {
  Suite *s = suite_create("s21_cos");
  TCase *tc = tcase_create("TEST cos");

  tcase_add_test(tc, s21_cos_test_1);
  tcase_add_test(tc, s21_cos_test_2);
  tcase_add_test(tc, s21_cos_test_3);
  tcase_add_test(tc, s21_cos_test_4);
  tcase_add_test(tc, s21_cos_test_5);
  tcase_add_test(tc, s21_cos_test_6);
  tcase_add_test(tc, s21_cos_test_7);
  tcase_add_test(tc, s21_cos_test_8);
  tcase_add_test(tc, s21_cos_test_9);
  tcase_add_test(tc, s21_cos_test_10);
  tcase_add_test(tc, s21_cos_test_11);
  tcase_add_test(tc, s21_cos_test_12);
  tcase_add_test(tc, s21_cos_test_13);
  tcase_add_test(tc, s21_cos_test_14);
  tcase_add_test(tc, s21_cos_test_15);
  tcase_add_test(tc, s21_cos_test_16);
  tcase_add_test(tc, s21_cos_test_17);
  tcase_add_test(tc, s21_cos_test_18);
  tcase_add_test(tc, s21_cos_test_19);
  tcase_add_test(tc, s21_cos_test_20);
  tcase_add_test(tc, s21_cos_test_21);
  tcase_add_test(tc, s21_cos_test_22);

  suite_add_tcase(s, tc);
  return s;
}
