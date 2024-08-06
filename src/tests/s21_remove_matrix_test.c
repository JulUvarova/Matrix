#include <check.h>

#include "s21_test.h"

START_TEST(s21_remove_matrix_OK) {
  matrix_t matrix = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &matrix);
  matrix.matrix[row - 1][col - 1] = 100.0;
  s21_remove_matrix(&matrix);

  ck_assert(matrix.matrix == NULL && matrix.rows == 0 && matrix.columns == 0);
}
END_TEST

START_TEST(s21_remove_matrix_double_remove) {
  matrix_t matrix = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &matrix);
  matrix.matrix[row - 1][col - 1] = 100.0;
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&matrix);

  ck_assert(matrix.matrix == NULL && matrix.rows == 0 && matrix.columns == 0);
}
END_TEST

Suite *s21_remove_matrix_suite(void) {
  Suite *s;
  s = suite_create("s21_remove_matrix() tests");
  TCase *tc;
  tc = tcase_create("remove_matrix");
  tcase_add_test(tc, s21_remove_matrix_OK);
  tcase_add_test(tc, s21_remove_matrix_double_remove);

  suite_add_tcase(s, tc);
  return s;
}

int s21_remove_matrix_test(void) {
  Suite *s = s21_remove_matrix_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}