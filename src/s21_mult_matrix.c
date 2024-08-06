#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (check_matrix(A) != OK || check_matrix(B) != OK || result == NULL)
    return INCORRECT_MATRIX;
  if (A->columns != B->rows) return CALC_ERROR;

  int res_code = s21_create_matrix(A->rows, B->columns, result);
  for (int i = 0; i < result->rows && res_code == OK; i++) {
    for (int j = 0; j < result->columns && res_code == OK; j++) {
      for (int p = 0; p < A->columns && res_code == OK; p++) {
        result->matrix[i][j] += A->matrix[i][p] * B->matrix[p][j];
      }
    }
  }
  return res_code;
}