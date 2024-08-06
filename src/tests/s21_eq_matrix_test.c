#include <check.h>

#include "s21_test.h"

START_TEST(s21_eq_matrix_NULL) {
  matrix_t matrix = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &matrix);
  int res_code = s21_eq_matrix(&matrix, NULL);
  s21_remove_matrix(&matrix);

  ck_assert(res_code == FAILURE);
}
END_TEST

START_TEST(s21_eq_NULL_matrix) {
  matrix_t matrix = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &matrix);
  int res_code = s21_eq_matrix(NULL, &matrix);
  s21_remove_matrix(&matrix);

  ck_assert(res_code == FAILURE);
}
END_TEST

START_TEST(s21_eq_dif_size) {
  matrix_t A = {0}, B = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &A);
  s21_create_matrix(col, col, &B);
  int res_code = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert(res_code == FAILURE);
}
END_TEST

START_TEST(s21_eq_case_1) {
  matrix_t A = {0}, B = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &A);
  s21_create_matrix(row, col, &B);
  int res_code = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert(res_code == SUCCESS);
}
END_TEST

START_TEST(s21_eq_case_2) {
  matrix_t A = {0}, B = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &A);
  s21_create_matrix(row, col, &B);
  A.matrix[row - 1][col - 1] = -0.0000001;
  B.matrix[row - 1][col - 1] = -0.0000001;
  int res_code = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert(res_code == SUCCESS);
}
END_TEST

START_TEST(s21_eq_case_3) {
  matrix_t A = {0}, B = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &A);
  s21_create_matrix(row, col, &B);
  A.matrix[row - 1][col - 1] = -0.0000001;
  B.matrix[row - 1][col - 1] = -0.0000001;
  int res_code = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert(res_code == SUCCESS);
}
END_TEST

START_TEST(s21_not_eq_case_1) {
  matrix_t A = {0}, B = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &A);
  s21_create_matrix(row, col, &B);
  A.matrix[row - 1][col - 1] = 0.0000001;
  B.matrix[row - 1][col - 1] = 0.0000002;
  int res_code = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert(res_code == FAILURE);
}
END_TEST

START_TEST(s21_not_eq_case_2) {
  matrix_t A = {0}, B = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &A);
  s21_create_matrix(row, col, &B);
  A.matrix[row - 1][col - 1] = 0.0000001;
  B.matrix[row - 1][col - 1] = 0.000000111;
  int res_code = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert(res_code == SUCCESS);
}
END_TEST

START_TEST(s21_not_eq_case_3) {
  matrix_t A = {0}, B = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &A);
  s21_create_matrix(row, col, &B);
  A.matrix[row - 1][col - 1] = -0.0000001;
  B.matrix[row - 1][col - 1] = 0.0000001;
  int res_code = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert(res_code == FAILURE);
}
END_TEST

START_TEST(s21_not_eq_case_4) {
  matrix_t A = {0}, B = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &A);
  s21_create_matrix(row, col, &B);
  A.matrix[row - 1][col - 1] = 1.0;
  B.matrix[0][0] = 1.0;
  int res_code = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert(res_code == FAILURE);
}
END_TEST

START_TEST(s21_eq_round) {
  matrix_t A = {0}, B = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &A);
  s21_create_matrix(row, col, &B);
  A.matrix[0][0] = 0.12345670;
  B.matrix[0][0] = 0.12345678;
  int res_code = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert(res_code == SUCCESS);
}
END_TEST

Suite *s21_eq_matrix_suite(void) {
  Suite *s;
  s = suite_create("s21_eq_matrix() tests");
  TCase *tc;
  tc = tcase_create("eq_matrix");
  tcase_add_test(tc, s21_eq_matrix_NULL);
  tcase_add_test(tc, s21_eq_NULL_matrix);
  tcase_add_test(tc, s21_eq_dif_size);
  tcase_add_test(tc, s21_eq_case_1);
  tcase_add_test(tc, s21_eq_case_2);
  tcase_add_test(tc, s21_eq_case_3);
  tcase_add_test(tc, s21_not_eq_case_1);
  tcase_add_test(tc, s21_not_eq_case_2);
  tcase_add_test(tc, s21_not_eq_case_3);
  tcase_add_test(tc, s21_not_eq_case_4);
  tcase_add_test(tc, s21_eq_round);

  suite_add_tcase(s, tc);
  return s;
}

int s21_eq_matrix_test(void) {
  Suite *s = s21_eq_matrix_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}