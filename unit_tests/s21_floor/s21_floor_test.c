#include "s21_floor_test.h"

START_TEST(s21_floor_test_1) {
  double num = INFINITY;
  long double orig_res = floor(num), our_res = s21_floor(num);
  int suc = 0;
  if (isinf(orig_res) && isinf(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_floor_test_2) {
  double num = -INFINITY;
  long double orig_res = floor(num), our_res = s21_floor(num);
  int suc = 0;
  if (isinf(-orig_res) && isinf(-our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_floor_test_3) {
  double num = NAN;
  long double orig_res = floor(num), our_res = s21_floor(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_floor_test_4) { ck_assert_int_eq(s21_floor(0), floor(0)); }
END_TEST

START_TEST(s21_floor_test_5) { ck_assert_int_eq(s21_floor(-0), floor(-0)); }
END_TEST

START_TEST(s21_floor_test_6) { ck_assert_int_eq(s21_floor(1), floor(1)); }
END_TEST

START_TEST(s21_floor_test_7) { ck_assert_int_eq(s21_floor(100), floor(100)); }
END_TEST

START_TEST(s21_floor_test_8) { ck_assert_int_eq(s21_floor(-1), floor(-1)); }
END_TEST

START_TEST(s21_floor_test_9) { ck_assert_int_eq(s21_floor(-100), floor(-100)); }
END_TEST

START_TEST(s21_floor_test_10) {
  ck_assert_int_eq(s21_floor(666666), floor(666666));
}
END_TEST

START_TEST(s21_floor_test_11) {
  ck_assert_int_eq(s21_floor(-666666), floor(-666666));
}
END_TEST

START_TEST(s21_floor_test_12) { ck_assert_int_eq(s21_floor(0.5), floor(0.5)); }
END_TEST

START_TEST(s21_floor_test_13) {
  ck_assert_int_eq(s21_floor(-0.5), floor(-0.5));
}
END_TEST

START_TEST(s21_floor_test_14) { ck_assert_int_eq(s21_floor(2.5), floor(2.5)); }
END_TEST

START_TEST(s21_floor_test_15) {
  ck_assert_int_eq(s21_floor(-2.5), floor(-2.5));
}
END_TEST

START_TEST(s21_floor_test_16) {
  ck_assert_int_eq(s21_floor(1234.456789), floor(1234.456789));
}
END_TEST

START_TEST(s21_floor_test_17) {
  ck_assert_int_eq(s21_floor(-1234.456789), floor(-1234.456789));
}
END_TEST

START_TEST(s21_floor_test_18) {
  ck_assert_int_eq(s21_floor(0.000001), floor(0.000001));
}
END_TEST

START_TEST(s21_floor_test_19) {
  ck_assert_int_eq(s21_floor(-0.000001), floor(-0.000001));
}
END_TEST

START_TEST(s21_floor_test_20) {
  ck_assert_int_eq(s21_floor(0.3425443513423432432432),
                   floor(0.3425443513423432432432));
}
END_TEST

START_TEST(s21_floor_test_21) {
  ck_assert_int_eq(s21_floor(-0.3425443513423432432432),
                   floor(-0.3425443513423432432432));
}
END_TEST

Suite *s21_floor_suite() {
  Suite *s = suite_create("s21_floor");
  TCase *tc = tcase_create("TEST FLOOR");

  tcase_add_test(tc, s21_floor_test_1);
  tcase_add_test(tc, s21_floor_test_2);
  tcase_add_test(tc, s21_floor_test_3);
  tcase_add_test(tc, s21_floor_test_4);
  tcase_add_test(tc, s21_floor_test_5);
  tcase_add_test(tc, s21_floor_test_6);
  tcase_add_test(tc, s21_floor_test_7);
  tcase_add_test(tc, s21_floor_test_8);
  tcase_add_test(tc, s21_floor_test_9);
  tcase_add_test(tc, s21_floor_test_10);
  tcase_add_test(tc, s21_floor_test_11);
  tcase_add_test(tc, s21_floor_test_12);
  tcase_add_test(tc, s21_floor_test_13);
  tcase_add_test(tc, s21_floor_test_14);
  tcase_add_test(tc, s21_floor_test_15);
  tcase_add_test(tc, s21_floor_test_16);
  tcase_add_test(tc, s21_floor_test_17);
  tcase_add_test(tc, s21_floor_test_18);
  tcase_add_test(tc, s21_floor_test_19);
  tcase_add_test(tc, s21_floor_test_20);
  tcase_add_test(tc, s21_floor_test_21);

  suite_add_tcase(s, tc);
  return s;
}
