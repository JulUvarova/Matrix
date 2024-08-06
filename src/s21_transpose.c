#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (check_matrix(A) != OK || result == NULL) return INCORRECT_MATRIX;

  int res_code = s21_create_matrix(A->columns, A->rows, result);

  if (res_code == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return res_code;
}