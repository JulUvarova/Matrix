#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (check_matrix(A) != OK || check_matrix(B) != OK ||
      check_eq_size(A, B) != OK)
    return FAILURE;

  int res_code = SUCCESS;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-7) {
        res_code = FAILURE;
        i = A->rows;
        j = A->columns;
      }
    }
  }
  return res_code;
}