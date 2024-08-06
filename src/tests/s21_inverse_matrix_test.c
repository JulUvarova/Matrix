#include <check.h>

#include "s21_test.h"

START_TEST(s21_inverse_matrix_NULL_res) {
  matrix_t A = {0};
  int row = 3, col = 3;
  s21_create_matrix(row, col, &A);
  int res_code = s21_inverse_matrix(NULL, &A);
  s21_remove_matrix(&A);

  ck_assert(res_code == INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_inverse_matrix_matrix_NULL) {
  matrix_t A = {0};
  int row = 3, col = 3;
  s21_create_matrix(row, col, &A);
  int res_code = s21_inverse_matrix(&A, NULL);
  s21_remove_matrix(&A);

  ck_assert(res_code == INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_inverse_matrix_2x2) {
  matrix_t A = {0}, res = {0};
  int row = 2, col = 2;
  s21_create_matrix(row, col, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  int res_code = s21_inverse_matrix(&A, &res);

  ck_assert(res_code == OK);
  ck_assert(res.matrix[0][0] == -2 && res.matrix[0][1] == 1 &&
            res.matrix[1][0] == 1.5 && res.matrix[1][1] == -0.5);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_inverse_matrix_3x3) {
  matrix_t A = {0}, res = {0};
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
  int res_code = s21_inverse_matrix(&A, &res);

  ck_assert(res_code == OK);
  ck_assert(res.matrix[0][0] == 1 && res.matrix[0][1] == -1 &&
            res.matrix[0][2] == 1 && res.matrix[1][0] == -38 &&
            res.matrix[1][1] == 41 && res.matrix[1][2] == -34 &&
            res.matrix[2][0] == 27 && res.matrix[2][1] == -29 &&
            res.matrix[2][2] == 24);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_inverse_det_0) {
  matrix_t A = {0}, res = {0};
  int row = 3, col = 3;
  s21_create_matrix(row, col, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 3;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  int res_code = s21_inverse_matrix(&A, &res);

  ck_assert(res_code == CALC_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_inverse_matrix_1x1) {
  matrix_t A = {0}, res = {0};
  int row = 1, col = 1;
  s21_create_matrix(row, col, &A);
  A.matrix[0][0] = -50;
  int res_code = s21_inverse_matrix(&A, &res);

  ck_assert(res_code == OK);
  ck_assert(res.matrix[0][0] == -0.02);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_inverse_matrix_wrong_size) {
  matrix_t A = {0}, res = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &A);
  int res_code = s21_inverse_matrix(&A, &res);

  ck_assert(res_code == CALC_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_4x4) {
  matrix_t A = {0}, res = {0};
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
  int res_code = s21_inverse_matrix(&A, &res);

  ck_assert(res_code == OK);
  ck_assert(res.matrix[0][0] == -26 / 29.0);
  ck_assert(res.matrix[0][1] == 0);
  ck_assert(res.matrix[0][2] == 6 / 29.0);
  ck_assert(res.matrix[0][3] == -5 / 29.0);
  ck_assert(res.matrix[1][0] == 13 / 58.0);
  ck_assert(res.matrix[1][1] == 0);
  ck_assert(res.matrix[1][2] == -3 / 58.0);
  ck_assert(res.matrix[1][3] == 17 / 58.0);
  ck_assert(res.matrix[2][0] == 21 / 29.0);
  ck_assert(res.matrix[2][1] == -1);
  ck_assert(res.matrix[2][2] == 13 / 29.0);
  ck_assert(res.matrix[2][3] == -6 / 29.0);
  ck_assert(res.matrix[3][1] == 1);
  ck_assert(res.matrix[3][3] == 2 / 29.0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

Suite *s21_inverse_matrix_suite(void) {
  Suite *s;
  s = suite_create("s21_inverse_matrix() tests");
  TCase *tc;
  tc = tcase_create("inverse_matrix");
  tcase_add_test(tc, s21_inverse_matrix_NULL_res);
  tcase_add_test(tc, s21_inverse_matrix_matrix_NULL);
  tcase_add_test(tc, s21_inverse_matrix_1x1);
  tcase_add_test(tc, s21_inverse_matrix_2x2);
  tcase_add_test(tc, s21_inverse_matrix_3x3);
  tcase_add_test(tc, s21_inverse_matrix_4x4);
  tcase_add_test(tc, s21_inverse_matrix_wrong_size);
  tcase_add_test(tc, s21_inverse_det_0);

  suite_add_tcase(s, tc);
  return s;
}

int s21_inverse_matrix_test(void) {
  Suite *s = s21_inverse_matrix_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}