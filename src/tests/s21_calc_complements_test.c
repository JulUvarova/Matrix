#include <check.h>

#include "s21_test.h"

START_TEST(s21_calc_complements_NULL_res) {
  matrix_t A = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &A);
  int res_code = s21_calc_complements(NULL, &A);
  s21_remove_matrix(&A);

  ck_assert(res_code == INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_calc_complements_matrix_NULL) {
  matrix_t A = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &A);
  int res_code = s21_calc_complements(&A, NULL);
  s21_remove_matrix(&A);

  ck_assert(res_code == INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_calc_complements_2x2) {
  matrix_t A = {0}, res = {0};
  int row = 2, col = 2;
  s21_create_matrix(row, col, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  int res_code = s21_calc_complements(&A, &res);

  ck_assert(res_code == OK);
  ck_assert(res.matrix[0][0] = 4);
  ck_assert(res.matrix[0][1] = -3);
  ck_assert(res.matrix[1][0] = -2);
  ck_assert(res.matrix[1][1] = 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_calc_complements_3x3) {
  matrix_t A = {0}, res = {0};
  int row = 3, col = 3;
  s21_create_matrix(row, col, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  int res_code = s21_calc_complements(&A, &res);

  ck_assert(res_code == OK);
  ck_assert(res.matrix[0][0] == 0 && res.matrix[0][1] == 10 &&
            res.matrix[0][2] == -20 && res.matrix[1][0] == 4 &&
            res.matrix[1][1] == -14 && res.matrix[1][2] == 8 &&
            res.matrix[2][0] == -8 && res.matrix[2][1] == -2 &&
            res.matrix[2][2] == 4);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_calc_complements_1x1_case_1) {
  matrix_t A = {0}, res = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 5.0;
  int res_code = s21_calc_complements(&A, &res);

  ck_assert(res_code == OK);
  ck_assert(res.matrix[0][0] == 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_calc_complements_1x1_case_2) {
  matrix_t A = {0}, res = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1.0;
  int res_code = s21_calc_complements(&A, &res);

  ck_assert(res_code == OK);
  ck_assert(res.matrix[0][0] == 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_calc_complements_wrong_size) {
  matrix_t A = {0}, res = {0};
  int row = 2, col = 3;
  s21_create_matrix(row, col, &A);
  int res_code = s21_calc_complements(&A, &res);

  ck_assert(res_code == CALC_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_calc_complements_suite(void) {
  Suite *s;
  s = suite_create("s21_calc_complements() tests");
  TCase *tc;
  tc = tcase_create("calc_complements");
  tcase_add_test(tc, s21_calc_complements_NULL_res);
  tcase_add_test(tc, s21_calc_complements_matrix_NULL);
  tcase_add_test(tc, s21_calc_complements_1x1_case_1);
  tcase_add_test(tc, s21_calc_complements_1x1_case_2);
  tcase_add_test(tc, s21_calc_complements_2x2);
  tcase_add_test(tc, s21_calc_complements_3x3);
  tcase_add_test(tc, s21_calc_complements_wrong_size);

  suite_add_tcase(s, tc);
  return s;
}

int s21_calc_complements_test(void) {
  Suite *s = s21_calc_complements_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}