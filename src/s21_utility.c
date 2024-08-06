#include "s21_utility.h"

int check_matrix(matrix_t* A) {
  int res_code = OK;
  if (A == NULL || A->matrix == NULL || A->rows < 1 || A->columns < 1)
    res_code = INCORRECT_MATRIX;
  return res_code;
}

int check_eq_size(matrix_t* A, matrix_t* B) {
  int res_code = OK;
  if (A->columns != B->columns || A->rows != B->rows)
    res_code = INCORRECT_MATRIX;
  return res_code;
}

double** get_memory(int rows, int cols) {
  double** matrix = calloc(rows, sizeof(double*));
  for (int i = 0; i < rows && matrix != NULL; i++) {
    matrix[i] = calloc(cols, sizeof(double));
    if (matrix[i] == NULL) {
      free(matrix);
    }
  }
  return matrix;
}

void cp_helper_matrix(int row, int col, matrix_t* A, matrix_t* helper) {
  int helper_i = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i != row) {
      int helper_j = 0;
      for (int j = 0; j < A->columns; j++) {
        if (j != col) {
          helper->matrix[helper_i][helper_j] = A->matrix[i][j];
          helper_j++;
        }
      }
      helper_i++;
    }
  }
}

int get_determinant(double* result, matrix_t* A) {
  int res_code = 0, sign = 1;
  *result = 0;
  for (int i = 0; i < A->columns && res_code == OK; i++) {
    matrix_t helper = {0};
    res_code = s21_create_matrix(A->rows - 1, A->rows - 1, &helper);
    if (res_code == OK) {
      cp_helper_matrix(0, i, A, &helper);
      double minor_det = 0;
      res_code = s21_determinant(&helper, &minor_det);
      if (res_code == OK) {
        *result += sign * A->matrix[0][i] * minor_det;
        sign = -sign;
      }
      s21_remove_matrix(&helper);
    }
  }
  return res_code;
}