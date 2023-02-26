#include "s21_tan_test.h"

START_TEST(s21_tan_test_1) {
  ck_assert_int_eq(s21_tan(INFINITY), tan(INFINITY));
}
END_TEST

START_TEST(s21_tan_test_2) {
  ck_assert_int_eq(s21_tan(-INFINITY), tan(-INFINITY));
}
END_TEST

START_TEST(s21_tan_test_3) {
  double num = NAN;
  long double orig_res = tan(num), our_res = s21_tan(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_tan_test_4) {
  ck_assert(fabs((double)s21_tan(0) - tan(0)) < TOLERANCE);
}
END_TEST

START_TEST(s21_tan_test_5) {
  ck_assert(fabs((double)s21_tan(-0) - tan(-0)) < TOLERANCE);
}
END_TEST

START_TEST(s21_tan_test_6) {
  ck_assert(fabs((double)s21_tan(1) - tan(1)) < TOLERANCE);
}
END_TEST

START_TEST(s21_tan_test_7) {
  ck_assert(fabs((double)s21_tan(100) - tan(100)) < TOLERANCE);
}
END_TEST

START_TEST(s21_tan_test_8) {
  ck_assert(fabs((double)s21_tan(-1) - tan(-1)) < TOLERANCE);
}
END_TEST

START_TEST(s21_tan_test_9) {
  ck_assert(fabs((double)s21_tan(-100) - tan(-100)) < TOLERANCE);
}
END_TEST

START_TEST(s21_tan_test_10) {
  ck_assert(fabs((double)s21_tan(666666) - tan(666666)) < TOLERANCE);
}
END_TEST

START_TEST(s21_tan_test_11) {
  ck_assert(fabs((double)s21_tan(-666666) - tan(-666666)) < TOLERANCE);
}
END_TEST

START_TEST(s21_tan_test_12) {
  ck_assert(fabs((double)s21_tan(0.5) - tan(0.5)) < TOLERANCE);
}
END_TEST

START_TEST(s21_tan_test_13) {
  ck_assert(fabs((double)s21_tan(-0.5) - tan(-0.5)) < TOLERANCE);
}
END_TEST

START_TEST(s21_tan_test_14) {
  ck_assert(fabs((double)s21_tan(2.5) - tan(2.5)) < TOLERANCE);
}
END_TEST

START_TEST(s21_tan_test_15) {
  ck_assert(fabs((double)s21_tan(-2.5) - tan(-2.5)) < TOLERANCE);
}
END_TEST

START_TEST(s21_tan_test_16) {
  ck_assert(fabs((double)s21_tan(1234.456789) - tan(1234.456789)) < TOLERANCE);
}
END_TEST

START_TEST(s21_tan_test_17) {
  ck_assert(fabs((double)s21_tan(-1234.456789) - tan(-1234.456789)) <
            TOLERANCE);
}
END_TEST

START_TEST(s21_tan_test_18) {
  ck_assert(fabs((double)s21_tan(0.000001) - tan(0.000001)) < TOLERANCE);
}
END_TEST

START_TEST(s21_tan_test_19) {
  ck_assert(fabs((double)s21_tan(-0.000001) - tan(-0.000001)) < TOLERANCE);
}
END_TEST

START_TEST(s21_tan_test_20) {
  ck_assert(fabs((double)s21_tan(0.3425443513423432432432) -
                 tan(0.3425443513423432432432)) < TOLERANCE);
}
END_TEST

START_TEST(s21_tan_test_21) {
  ck_assert(fabs((double)s21_tan(-0.3425443513423432432432) -
                 tan(-0.3425443513423432432432)) < TOLERANCE);
}
END_TEST

START_TEST(s21_tan_test_22) {
  ck_assert(fabs((double)s21_tan(S21_PI) - tan(S21_PI)) < TOLERANCE);
}
END_TEST


START_TEST(s21_tan_test_23) {
  ck_assert(fabs((double)s21_tan(S21_PI/2) - tan(S21_PI/2)) < TOLERANCE);
}
END_TEST

START_TEST(s21_tan_test_24) {
  ck_assert(fabs((double)s21_tan(-S21_PI/2) - tan(-S21_PI/2)) < TOLERANCE);
}
END_TEST

START_TEST(s21_tan_test_25) {
  ck_assert(fabs((double)s21_tan(-S21_PI) - tan(-S21_PI)) < TOLERANCE);
}
END_TEST

Suite *s21_tan_suite() {
  Suite *s = suite_create("s21_tan");
  TCase *tc = tcase_create("TEST tan");

  tcase_add_test(tc, s21_tan_test_1);
  tcase_add_test(tc, s21_tan_test_2);
  tcase_add_test(tc, s21_tan_test_3);
  tcase_add_test(tc, s21_tan_test_4);
  tcase_add_test(tc, s21_tan_test_5);
  tcase_add_test(tc, s21_tan_test_6);
  tcase_add_test(tc, s21_tan_test_7);
  tcase_add_test(tc, s21_tan_test_8);
  tcase_add_test(tc, s21_tan_test_9);
  tcase_add_test(tc, s21_tan_test_10);
  tcase_add_test(tc, s21_tan_test_11);
  tcase_add_test(tc, s21_tan_test_12);
  tcase_add_test(tc, s21_tan_test_13);
  tcase_add_test(tc, s21_tan_test_14);
  tcase_add_test(tc, s21_tan_test_15);
  tcase_add_test(tc, s21_tan_test_16);
  tcase_add_test(tc, s21_tan_test_17);
  tcase_add_test(tc, s21_tan_test_18);
  tcase_add_test(tc, s21_tan_test_19);
  tcase_add_test(tc, s21_tan_test_20);
  tcase_add_test(tc, s21_tan_test_21);
  tcase_add_test(tc, s21_tan_test_22);
  tcase_add_test(tc, s21_tan_test_23);
  tcase_add_test(tc, s21_tan_test_24);
  tcase_add_test(tc, s21_tan_test_25);

  suite_add_tcase(s, tc);
  return s;
}
