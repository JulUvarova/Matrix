#include <check.h>

#include "s21_test.h"

START_TEST(s21_transpose_NULL_res) {
  matrix_t res = {0};
  int res_code = s21_transpose(NULL, &res);

  ck_assert(res_code == INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_transpose_matrix_NULL) {
  matrix_t mat = {0};
  int res_code = s21_transpose(&mat, NULL);

  ck_assert(res_code == INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_transpose_1x1) {
  matrix_t A = {0}, res = {0};
  int row = 1, col = 1;
  s21_create_matrix(row, col, &A);
  A.matrix[0][0] = 100;
  int res_code = s21_transpose(&A, &res);

  ck_assert(res_code == OK);
  ck_assert(res.matrix[0][0] == 100);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_transpose_2x3) {
  matrix_t A = {0}, res = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &A);
  A.matrix[row - 1][col - 1] = 100;
  int res_code = s21_transpose(&A, &res);

  ck_assert(res_code == OK);
  ck_assert(res.matrix[col - 1][row - 1] == 100);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_transpose_3x3) {
  matrix_t A = {0}, res = {0};
  int row = 3, col = 3;
  s21_create_matrix(row, col, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  int res_code = s21_transpose(&A, &res);

  ck_assert(res_code == OK);
  ck_assert(
      res.matrix[0][0] == 1 && res.matrix[0][1] == 4 && res.matrix[0][2] == 7 &&
      res.matrix[1][0] == 2 && res.matrix[1][1] == 5 && res.matrix[1][2] == 8 &&
      res.matrix[2][0] == 3 && res.matrix[2][1] == 6 && res.matrix[2][2] == 9);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

Suite *s21_transpose_suite(void) {
  Suite *s;
  s = suite_create("s21_transpose() tests");
  TCase *tc;
  tc = tcase_create("transpose");
  tcase_add_test(tc, s21_transpose_NULL_res);
  tcase_add_test(tc, s21_transpose_matrix_NULL);
  tcase_add_test(tc, s21_transpose_1x1);
  tcase_add_test(tc, s21_transpose_2x3);
  tcase_add_test(tc, s21_transpose_3x3);

  suite_add_tcase(s, tc);
  return s;
}

int s21_transpose_test(void) {
  Suite *s = s21_transpose_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}