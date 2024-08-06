#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (check_matrix(A) != OK || result == NULL) return INCORRECT_MATRIX;
  if (A->columns != A->rows) return CALC_ERROR;

  int res_code = s21_create_matrix(A->rows, A->columns, result);
  if (res_code == OK && result->rows > 1) {
    matrix_t helper = {0};
    s21_create_matrix(A->rows - 1, A->columns - 1, &helper);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        double minor = 0.0;
        cp_helper_matrix(i, j, A, &helper);
        s21_determinant(&helper, &minor);
        result->matrix[i][j] = minor * pow(-1, i + j);
      }
    }
    s21_remove_matrix(&helper);
  }
  if (res_code == OK && result->rows == 1) result->matrix[0][0] = 1.0;
  return res_code;
}