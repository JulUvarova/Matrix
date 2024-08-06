#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (check_matrix(A) != OK || check_matrix(B) != OK || result == NULL)
    return INCORRECT_MATRIX;
  if (A->columns != B->columns || A->rows != B->rows) return CALC_ERROR;

  int res_code = s21_create_matrix(A->rows, A->columns, result);

  if (res_code == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return res_code;
}