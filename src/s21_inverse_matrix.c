#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (check_matrix(A) != OK || result == NULL) return INCORRECT_MATRIX;
  if (A->columns != A->rows) return CALC_ERROR;

  double det = 0.0;
  int res_code = s21_determinant(A, &det);

  if (det == 0 || res_code != OK) {
    res_code = CALC_ERROR;
  } else {
    matrix_t complement = {0}, transpose = {0};
    res_code = s21_calc_complements(A, &complement);
    if (res_code == OK) res_code = s21_transpose(&complement, &transpose);
    if (res_code == OK)
      res_code = s21_mult_number(&transpose, (1 / det), result);

    s21_remove_matrix(&transpose);
    s21_remove_matrix(&complement);
  }
  return res_code;
}
