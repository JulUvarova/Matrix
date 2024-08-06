#include <check.h>

#include "s21_test.h"

START_TEST(s21_determinant_NULL_res) {
  double res = -1.1;
  int res_code = s21_determinant(NULL, &res);

  ck_assert(res_code == INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_determinant_matrix_NULL) {
  matrix_t A = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &A);
  int res_code = s21_determinant(&A, NULL);
  s21_remove_matrix(&A);

  ck_assert(res_code == INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_determinant_2x2) {
  matrix_t A = {0};
  double res = -1.1;
  int row = 2, col = 2;
  s21_create_matrix(row, col, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 5;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 1;
  int res_code = s21_determinant(&A, &res);

  ck_assert(res_code == OK);
  ck_assert(res == -10);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_3x3_case_1) {
  matrix_t A = {0};
  double res = -1.1;
  int row = 3, col = 3;
  s21_create_matrix(row, col, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = 2;
  int res_code = s21_determinant(&A, &res);

  ck_assert(res_code == OK);
  ck_assert(res == -18);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_3x3_case_2) {
  matrix_t A = {0};
  double res = -1.1;
  int row = 3, col = 3;
  s21_create_matrix(row, col, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  int res_code = s21_determinant(&A, &res);

  ck_assert(res_code == OK);
  ck_assert(res == -1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_1x1) {
  matrix_t A = {0};
  double res = -1.1;
  int row = 1, col = 1;
  s21_create_matrix(row, col, &A);
  A.matrix[0][0] = 100.1234567;
  int res_code = s21_determinant(&A, &res);

  ck_assert(res_code == OK);
  ck_assert(res == 100.1234567);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_wrong_size) {
  matrix_t A = {0};
  double res = -1.1;
  int row = 2, col = 3;
  s21_create_matrix(row, col, &A);
  int res_code = s21_determinant(&A, &res);

  ck_assert(res_code == CALC_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_4x4) {
  matrix_t A = {0};
  double res = -1.1;
  int row = 4, col = 4;
  s21_create_matrix(row, col, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 3;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 6;
  A.matrix[1][2] = 7;
  A.matrix[1][3] = 8;
  A.matrix[2][0] = 10;
  A.matrix[2][1] = 12;
  A.matrix[2][2] = 13;
  A.matrix[2][3] = 13;
  A.matrix[3][0] = 1;
  A.matrix[3][1] = 4;
  A.matrix[3][2] = 0;
  A.matrix[3][3] = 0;
  int res_code = s21_determinant(&A, &res);

  ck_assert(res_code == OK);
  ck_assert(res == 58);

  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_determinant_suite(void) {
  Suite *s;
  s = suite_create("s21_determinant() tests");
  TCase *tc;
  tc = tcase_create("determinant");
  tcase_add_test(tc, s21_determinant_NULL_res);
  tcase_add_test(tc, s21_determinant_matrix_NULL);
  tcase_add_test(tc, s21_determinant_1x1);
  tcase_add_test(tc, s21_determinant_2x2);
  tcase_add_test(tc, s21_determinant_3x3_case_1);
  tcase_add_test(tc, s21_determinant_3x3_case_2);
  tcase_add_test(tc, s21_determinant_4x4);
  tcase_add_test(tc, s21_determinant_wrong_size);

  suite_add_tcase(s, tc);
  return s;
}

int s21_determinant_test(void) {
  Suite *s = s21_determinant_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}