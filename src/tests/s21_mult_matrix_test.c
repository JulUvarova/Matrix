#include <check.h>

#include "s21_test.h"

START_TEST(s21_mult_matrix_NULL_res) {
  matrix_t matrix = {0}, res = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &matrix);
  int res_code = s21_mult_matrix(&matrix, NULL, &res);
  s21_remove_matrix(&matrix);

  ck_assert(res_code == INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_mult_NULL_matrix_res) {
  matrix_t matrix = {0}, res = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &matrix);
  int res_code = s21_mult_matrix(NULL, &matrix, &res);
  s21_remove_matrix(&matrix);

  ck_assert(res_code == INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_mult_matrix_matrix_NULL) {
  matrix_t A = {0}, B = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &A);
  s21_create_matrix(row, col, &B);
  int res_code = s21_mult_matrix(&A, &B, NULL);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert(res_code == INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_mult_2x3) {
  matrix_t A = {0}, B = {0}, res = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &A);
  A.matrix[row - 1][col - 1] = 50.;
  s21_create_matrix(col, row, &B);
  B.matrix[col - 1][row - 1] = 2.;
  int res_code = s21_mult_matrix(&A, &B, &res);

  ck_assert(res_code == OK);
  ck_assert(res.matrix[row - 1][row - 1] == 100);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_mult_wrong_size) {
  matrix_t A = {0}, B = {0}, res = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &A);
  s21_create_matrix(row, col, &B);
  int res_code = s21_mult_matrix(&A, &B, &res);

  ck_assert(res_code == CALC_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_mult_matrix_suite(void) {
  Suite *s;
  s = suite_create("s21_mult_matrix() tests");
  TCase *tc;
  tc = tcase_create("mult_matrix");
  tcase_add_test(tc, s21_mult_matrix_NULL_res);
  tcase_add_test(tc, s21_mult_matrix_matrix_NULL);
  tcase_add_test(tc, s21_mult_NULL_matrix_res);
  tcase_add_test(tc, s21_mult_2x3);
  tcase_add_test(tc, s21_mult_wrong_size);

  suite_add_tcase(s, tc);
  return s;
}

int s21_mult_matrix_test(void) {
  Suite *s = s21_mult_matrix_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}