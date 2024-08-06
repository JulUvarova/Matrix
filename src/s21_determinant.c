#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (check_matrix(A) != OK || result == NULL) return INCORRECT_MATRIX;
  if (A->columns != A->rows) return CALC_ERROR;

  int res_code = OK;
  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    res_code = get_determinant(result, A);
  }
  return res_code;
}