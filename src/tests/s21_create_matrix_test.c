#include <check.h>

#include "s21_test.h"

START_TEST(s21_create_matrix_OK) {
  matrix_t matrix = {0};
  int row = 2, col = 3;
  int res_code = s21_create_matrix(row, col, &matrix);
  matrix.matrix[row - 1][col - 1] = 100.0;

  ck_assert(res_code == OK);
  ck_assert(matrix.rows == row && matrix.columns == col);
  ck_assert(matrix.matrix[row - 1][col - 1] == 100.0);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_OK_vector_hor) {
  matrix_t matrix = {0};
  int row = 1, col = 10;
  int res_code = s21_create_matrix(row, col, &matrix);
  matrix.matrix[0][col - 1] = 100.0;

  ck_assert(res_code == OK);
  ck_assert(matrix.rows == row && matrix.columns == col);
  ck_assert(matrix.matrix[0][col - 1] == 100.0);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_OK_vector_vert) {
  matrix_t matrix = {0};
  int row = 10, col = 1;
  int res_code = s21_create_matrix(row, col, &matrix);
  matrix.matrix[row - 1][0] = 100.0;

  ck_assert(res_code == OK);
  ck_assert(matrix.rows == row && matrix.columns == col);
  ck_assert(matrix.matrix[row - 1][0] == 100.0);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_NULL_ERR) {
  int res_code = s21_create_matrix(1, 1, NULL);
  ck_assert(res_code == INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_row_ERR) {
  matrix_t matrix = {0};
  int res_code = s21_create_matrix(0, 1, &matrix);
  ck_assert(res_code == INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_col_ERR) {
  matrix_t matrix = {0};
  int res_code = s21_create_matrix(1, 0, &matrix);
  ck_assert(res_code == INCORRECT_MATRIX);
}
END_TEST

Suite *s21_create_matrix_suite(void) {
  Suite *s;
  s = suite_create("s21_create_matrix() tests");
  TCase *tc;
  tc = tcase_create("create_matrix");
  tcase_add_test(tc, s21_create_matrix_OK);
  tcase_add_test(tc, s21_create_matrix_OK_vector_hor);
  tcase_add_test(tc, s21_create_matrix_OK_vector_vert);
  tcase_add_test(tc, s21_create_matrix_NULL_ERR);
  tcase_add_test(tc, s21_create_matrix_row_ERR);
  tcase_add_test(tc, s21_create_matrix_col_ERR);

  suite_add_tcase(s, tc);
  return s;
}

int s21_create_matrix_test(void) {
  Suite *s = s21_create_matrix_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}