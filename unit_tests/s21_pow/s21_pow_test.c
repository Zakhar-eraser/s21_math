#include "s21_pow_test.h"

const double pow_pos_base[] = {0.2332, 1.234543654, 4, 20.3334, 20};
const double pow_neg_base[] = {-0.2332, -1.236345654, -4, -20.3334, -20};

const double pow_float_pow[] = {1.1,        -1.1,   0.4554545,
                                -0.4554545, 6.0545, -6.0545};
const double pow_int_pow[] = {-1, 1, 3, -3, 6, -6};

// DEFAULT

START_TEST(s21_pow_pos_base_default_pow) {
  for (unsigned char j = 1; j < LENGTH(pow_float_pow); j++)
    ck_assert_double_eq_tol(s21_pow(pow_pos_base[_i], pow_float_pow[j]),
                            pow(pow_pos_base[_i], pow_float_pow[j]), TOLERANCE);
}
END_TEST

START_TEST(s21_pow_neg_base_int_pow) {
  for (unsigned char j = 1; j < LENGTH(pow_int_pow); j++) {
    ck_assert_ldouble_eq_tol(s21_pow(pow_neg_base[_i], pow_int_pow[j]),
                             pow(pow_neg_base[_i], pow_int_pow[j]), TOLERANCE);
  }
}
END_TEST

// NAN

START_TEST(s21_pow_nan_arg) {
  ck_assert_ldouble_nan(pow(NAN, 5.));
  ck_assert_ldouble_nan(pow(5., NAN));
  ck_assert_ldouble_nan(pow(NAN, NAN));
  ck_assert_ldouble_nan(s21_pow(NAN, 5.));
  ck_assert_ldouble_nan(s21_pow(5., NAN));
  ck_assert_ldouble_nan(s21_pow(NAN, NAN));
}
END_TEST

START_TEST(s21_pow_neg_base_float_pow) {
  for (unsigned char j = 0; j < LENGTH(pow_float_pow); j++) {
    ck_assert_ldouble_nan(pow(pow_neg_base[_i], pow_float_pow[j]));
    ck_assert_ldouble_nan(s21_pow(pow_neg_base[_i], pow_float_pow[j]));
  }
}
END_TEST

// ONE

START_TEST(s21_pow_zero_base_and_pow) {
  ck_assert_ldouble_eq_tol(pow(0., 0.), s21_pow(0., 0.), TOLERANCE);
}
END_TEST

START_TEST(s21_pow_mone_base_zero_pow) {
  ck_assert_ldouble_eq_tol(pow(-1., 0.), s21_pow(-1., 0.), TOLERANCE);
}
END_TEST

START_TEST(s21_pow_zero_pow_default) {
  ck_assert_ldouble_eq_tol(s21_pow(pow_float_pow[_i], 0.),
                           pow(pow_float_pow[_i], 0.), TOLERANCE);
}
END_TEST

START_TEST(s21_pow_infinite_base_zero_pow) {
  ck_assert_ldouble_eq_tol(pow(S21_INF, 0.), s21_pow(S21_INF, 0.), TOLERANCE);
  ck_assert_ldouble_eq_tol(pow(S21_MIN_INF, 0.), s21_pow(S21_MIN_INF, 0.),
                           TOLERANCE);
}
END_TEST

START_TEST(s21_pow_one_base_default_pow) {
  ck_assert_ldouble_eq_tol(pow(1., pow_float_pow[_i]),
                           s21_pow(1., pow_float_pow[_i]), TOLERANCE);
}
END_TEST

START_TEST(s21_pow_one_base_inf_pow) {
  ck_assert_ldouble_eq_tol(pow(1., S21_INF), s21_pow(1., S21_INF), TOLERANCE);
  ck_assert_ldouble_eq_tol(pow(1., S21_MIN_INF), s21_pow(1., S21_MIN_INF),
                           TOLERANCE);
  ck_assert_ldouble_eq_tol(pow(-1., S21_INF), s21_pow(-1., S21_INF), TOLERANCE);
  ck_assert_ldouble_eq_tol(pow(-1., S21_MIN_INF), s21_pow(-1., S21_MIN_INF),
                           TOLERANCE);
}
END_TEST

// INFINITE

START_TEST(s21_pow_infinite_base_infinite_pow) {
  ck_assert_ldouble_eq(s21_pow(S21_INF, S21_INF), pow(S21_INF, S21_INF));
  ck_assert_ldouble_eq(s21_pow(S21_MIN_INF, S21_INF),
                       pow(S21_MIN_INF, S21_INF));
}
END_TEST

START_TEST(s21_pow_infinite_base_default_pow) {
  ck_assert_ldouble_eq(s21_pow(S21_INF, 0.23), pow(S21_INF, 0.23));
  ck_assert_ldouble_eq(s21_pow(S21_MIN_INF, 0.23), pow(S21_MIN_INF, 0.23));
}
END_TEST

START_TEST(s21_pow_lt_one_base_minf_pow) {
  ck_assert_ldouble_eq(s21_pow(0.23, S21_MIN_INF), pow(0.23, S21_MIN_INF));
  ck_assert_ldouble_eq(s21_pow(-0.23, S21_MIN_INF), pow(-0.23, S21_MIN_INF));
}
END_TEST

START_TEST(s21_pow_gt_one_base_inf_pow) {
  ck_assert_ldouble_eq(s21_pow(1.23, S21_INF), pow(1.23, S21_INF));
  ck_assert_ldouble_eq(s21_pow(-1.23, S21_INF), pow(-1.23, S21_INF));
}
END_TEST

START_TEST(s21_pow_zero_base_neg_pow) {
  ck_assert_ldouble_eq(s21_pow(0., -0.003), pow(0., -0.003));
  ck_assert_ldouble_eq(s21_pow(0., -1), pow(0., -1));
  ck_assert_ldouble_eq(s21_pow(0., -5435), pow(0., -5435));
}
END_TEST

// ZERO

START_TEST(s21_pow_zero_base_infinite_pow) {
  ck_assert_ldouble_eq_tol(s21_pow(0., S21_INF), pow(0., S21_INF), TOLERANCE);
  ck_assert_ldouble_eq(s21_pow(0., S21_MIN_INF), pow(0., S21_MIN_INF));
}
END_TEST

START_TEST(s21_pow_infinite_base_minfinite_pow) {
  ck_assert_ldouble_eq_tol(pow(S21_INF, S21_MIN_INF),
                           s21_pow(S21_INF, S21_MIN_INF), TOLERANCE);
  ck_assert_ldouble_eq_tol(pow(S21_MIN_INF, S21_MIN_INF),
                           s21_pow(S21_MIN_INF, S21_MIN_INF), TOLERANCE);
}
END_TEST

START_TEST(s21_pow_lt_one_base_inf_pow) {
  ck_assert_ldouble_eq_tol(pow(0.98, S21_INF), s21_pow(0.98, S21_INF),
                           TOLERANCE);
  ck_assert_ldouble_eq_tol(pow(-0.98, S21_INF), s21_pow(-0.98, S21_INF),
                           TOLERANCE);
}
END_TEST

START_TEST(s21_pow_gt_one_base_minf_pow) {
  ck_assert_ldouble_eq_tol(pow(56457.343, S21_MIN_INF),
                           s21_pow(56457.343, S21_MIN_INF), TOLERANCE);
  ck_assert_ldouble_eq_tol(pow(-56457.343, S21_MIN_INF),
                           s21_pow(-56457.343, S21_MIN_INF), TOLERANCE);
}
END_TEST

Suite *s21_pow_suite() {
  Suite *s = suite_create("s21_pow");

  TCase *tc_default = tcase_create("DEFAULT");
  tcase_add_loop_test(tc_default, s21_pow_pos_base_default_pow, 0,
                      LENGTH(pow_pos_base));
  tcase_add_loop_test(tc_default, s21_pow_neg_base_int_pow, 0,
                      LENGTH(pow_neg_base));
  suite_add_tcase(s, tc_default);

  TCase *tc_nan = tcase_create("NAN");
  tcase_add_test(tc_nan, s21_pow_nan_arg);
  tcase_add_loop_test(tc_nan, s21_pow_neg_base_float_pow, 0,
                      LENGTH(pow_neg_base));
  suite_add_tcase(s, tc_nan);

  TCase *tc_one = tcase_create("ONE");
  tcase_add_test(tc_one, s21_pow_infinite_base_zero_pow);
  tcase_add_loop_test(tc_one, s21_pow_zero_pow_default, 0,
                      LENGTH(pow_float_pow));
  tcase_add_test(tc_one, s21_pow_zero_base_and_pow);
  tcase_add_loop_test(tc_one, s21_pow_one_base_default_pow, 0,
                      LENGTH(pow_float_pow));
  tcase_add_test(tc_one, s21_pow_one_base_inf_pow);
  tcase_add_test(tc_one, s21_pow_mone_base_zero_pow);
  suite_add_tcase(s, tc_one);

  TCase *tc_infinite = tcase_create("INFINITE");
  tcase_add_test(tc_infinite, s21_pow_infinite_base_infinite_pow);
  tcase_add_test(tc_infinite, s21_pow_infinite_base_default_pow);
  tcase_add_test(tc_infinite, s21_pow_lt_one_base_minf_pow);
  tcase_add_test(tc_infinite, s21_pow_gt_one_base_inf_pow);
  tcase_add_test(tc_infinite, s21_pow_zero_base_neg_pow);
  suite_add_tcase(s, tc_infinite);

  TCase *tc_zero = tcase_create("ZERO");
  tcase_add_test(tc_zero, s21_pow_zero_base_infinite_pow);
  tcase_add_test(tc_zero, s21_pow_infinite_base_minfinite_pow);
  tcase_add_test(tc_zero, s21_pow_lt_one_base_inf_pow);
  tcase_add_test(tc_zero, s21_pow_gt_one_base_minf_pow);
  suite_add_tcase(s, tc_zero);

  return s;
}
