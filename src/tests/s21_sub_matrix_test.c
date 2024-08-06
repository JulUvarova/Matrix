#include <check.h>

#include "s21_test.h"

START_TEST(s21_sub_matrix_NULL_res) {
  matrix_t matrix = {0}, res = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &matrix);
  int res_code = s21_sub_matrix(&matrix, NULL, &res);
  s21_remove_matrix(&matrix);

  ck_assert(res_code == INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_sub_NULL_matrix_res) {
  matrix_t matrix = {0}, res = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &matrix);
  int res_code = s21_sub_matrix(NULL, &matrix, &res);
  s21_remove_matrix(&matrix);

  ck_assert(res_code == INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_sub_matrix_matrix_NULL) {
  matrix_t A = {0}, B = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &A);
  s21_create_matrix(row, col, &B);
  int res_code = s21_sub_matrix(&A, &B, NULL);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert(res_code == INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_sub_2x3) {
  matrix_t A = {0}, B = {0}, res = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &A);
  A.matrix[0][0] = 50.;
  s21_create_matrix(row, col, &B);
  B.matrix[0][0] = 50.;
  int res_code = s21_sub_matrix(&A, &B, &res);

  ck_assert(res_code == OK);
  ck_assert(res.matrix[0][0] == 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_sub_wrong_size) {
  matrix_t A = {0}, B = {0}, res = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &A);
  s21_create_matrix(col, row, &B);
  int res_code = s21_sub_matrix(&A, &B, &res);

  ck_assert(res_code == CALC_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_sub_matrix_suite(void) {
  Suite *s;
  s = suite_create("s21_sub_matrix() tests");
  TCase *tc;
  tc = tcase_create("sub_matrix");
  tcase_add_test(tc, s21_sub_matrix_NULL_res);
  tcase_add_test(tc, s21_sub_matrix_matrix_NULL);
  tcase_add_test(tc, s21_sub_NULL_matrix_res);
  tcase_add_test(tc, s21_sub_2x3);
  tcase_add_test(tc, s21_sub_wrong_size);

  suite_add_tcase(s, tc);
  return s;
}

int s21_sub_matrix_test(void) {
  Suite *s = s21_sub_matrix_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}