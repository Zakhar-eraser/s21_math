#include "s21_ceil_test.h"

START_TEST(s21_ceil_test_1) {
  double num = INFINITY;
  long double orig_res = ceil(num), our_res = s21_ceil(num);
  int suc = 0;
  if (isinf(orig_res) && isinf(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_ceil_test_2) {
  double num = -INFINITY;
  long double orig_res = ceil(num), our_res = s21_ceil(num);
  int suc = 0;
  if (isinf(-orig_res) && isinf(-our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_ceil_test_3) {
  double num = NAN;
  long double orig_res = ceil(num), our_res = s21_ceil(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_ceil_test_4) { ck_assert_int_eq(s21_ceil(0), ceil(0)); }
END_TEST

START_TEST(s21_ceil_test_5) { ck_assert_int_eq(s21_ceil(-0), ceil(-0)); }
END_TEST

START_TEST(s21_ceil_test_6) { ck_assert_int_eq(s21_ceil(1), ceil(1)); }
END_TEST

START_TEST(s21_ceil_test_7) { ck_assert_int_eq(s21_ceil(100), ceil(100)); }
END_TEST

START_TEST(s21_ceil_test_8) { ck_assert_int_eq(s21_ceil(-1), ceil(-1)); }
END_TEST

START_TEST(s21_ceil_test_9) { ck_assert_int_eq(s21_ceil(-100), ceil(-100)); }
END_TEST

START_TEST(s21_ceil_test_10) {
  ck_assert_int_eq(s21_ceil(666666), ceil(666666));
}
END_TEST

START_TEST(s21_ceil_test_11) {
  ck_assert_int_eq(s21_ceil(-666666), ceil(-666666));
}
END_TEST

START_TEST(s21_ceil_test_12) { ck_assert_int_eq(s21_ceil(0.5), ceil(0.5)); }
END_TEST

START_TEST(s21_ceil_test_13) { ck_assert_int_eq(s21_ceil(-0.5), ceil(-0.5)); }
END_TEST

START_TEST(s21_ceil_test_14) { ck_assert_int_eq(s21_ceil(2.5), ceil(2.5)); }
END_TEST

START_TEST(s21_ceil_test_15) { ck_assert_int_eq(s21_ceil(-2.5), ceil(-2.5)); }
END_TEST

START_TEST(s21_ceil_test_16) {
  ck_assert_int_eq(s21_ceil(1234.456789), ceil(1234.456789));
}
END_TEST

START_TEST(s21_ceil_test_17) {
  ck_assert_int_eq(s21_ceil(-1234.456789), ceil(-1234.456789));
}
END_TEST

START_TEST(s21_ceil_test_18) {
  ck_assert_int_eq(s21_ceil(0.000001), ceil(0.000001));
}
END_TEST

START_TEST(s21_ceil_test_19) {
  ck_assert_int_eq(s21_ceil(-0.000001), ceil(-0.000001));
}
END_TEST

START_TEST(s21_ceil_test_20) {
  ck_assert_int_eq(s21_ceil(0.3425443513423432432432),
                   ceil(0.3425443513423432432432));
}
END_TEST

START_TEST(s21_ceil_test_21) {
  ck_assert_int_eq(s21_ceil(-0.3425443513423432432432),
                   ceil(-0.3425443513423432432432));
}
END_TEST

Suite *s21_ceil_suite() {
  Suite *s = suite_create("s21_ceil");
  TCase *tc = tcase_create("TEST CEIL");

  tcase_add_test(tc, s21_ceil_test_1);
  tcase_add_test(tc, s21_ceil_test_2);
  tcase_add_test(tc, s21_ceil_test_3);
  tcase_add_test(tc, s21_ceil_test_4);
  tcase_add_test(tc, s21_ceil_test_5);
  tcase_add_test(tc, s21_ceil_test_6);
  tcase_add_test(tc, s21_ceil_test_7);
  tcase_add_test(tc, s21_ceil_test_8);
  tcase_add_test(tc, s21_ceil_test_9);
  tcase_add_test(tc, s21_ceil_test_10);
  tcase_add_test(tc, s21_ceil_test_11);
  tcase_add_test(tc, s21_ceil_test_12);
  tcase_add_test(tc, s21_ceil_test_13);
  tcase_add_test(tc, s21_ceil_test_14);
  tcase_add_test(tc, s21_ceil_test_15);
  tcase_add_test(tc, s21_ceil_test_16);
  tcase_add_test(tc, s21_ceil_test_17);
  tcase_add_test(tc, s21_ceil_test_18);
  tcase_add_test(tc, s21_ceil_test_19);
  tcase_add_test(tc, s21_ceil_test_20);
  tcase_add_test(tc, s21_ceil_test_21);

  suite_add_tcase(s, tc);
  return s;
}
