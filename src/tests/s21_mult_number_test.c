#include <check.h>

#include "s21_test.h"

START_TEST(s21_mult_number_NULL_res) {
  matrix_t res = {0};
  int res_code = s21_mult_number(NULL, 1, &res);

  ck_assert(res_code == INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_mult_number_matrix_NULL) {
  matrix_t mat = {0};
  int res_code = s21_mult_number(&mat, 1, NULL);

  ck_assert(res_code == INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_mult_number_2x3) {
  matrix_t A = {0}, res = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &A);
  A.matrix[0][0] = 50.;
  int res_code = s21_mult_number(&A, 2, &res);

  ck_assert(res_code == OK);
  ck_assert(res.matrix[0][0] == 100);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_mult_number_3x3) {
  matrix_t A = {0}, res = {0};
  int row = 3, col = 3;
  s21_create_matrix(row, col, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = -2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = -4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = -6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = -8;
  A.matrix[2][2] = 9;
  int res_code = s21_mult_number(&A, -1, &res);

  ck_assert(res_code == OK);
  ck_assert(res.matrix[0][0] == -1 && res.matrix[1][0] == 4 &&
            res.matrix[2][0] == -7 && res.matrix[0][1] == 2 &&
            res.matrix[1][1] == -5 && res.matrix[2][1] == 8 &&
            res.matrix[0][2] == -3 && res.matrix[1][2] == 6 &&
            res.matrix[2][2] == -9);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

Suite *s21_mult_number_suite(void) {
  Suite *s;
  s = suite_create("s21_mult_number() tests");
  TCase *tc;
  tc = tcase_create("mult_number");
  tcase_add_test(tc, s21_mult_number_NULL_res);
  tcase_add_test(tc, s21_mult_number_matrix_NULL);
  tcase_add_test(tc, s21_mult_number_2x3);
  tcase_add_test(tc, s21_mult_number_3x3);

  suite_add_tcase(s, tc);
  return s;
}

int s21_mult_number_test(void) {
  Suite *s = s21_mult_number_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}