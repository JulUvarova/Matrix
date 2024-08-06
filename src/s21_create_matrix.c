#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (result == NULL || rows < 1 || columns < 1) return INCORRECT_MATRIX;

  int res_code = OK;
  double **matrix = get_memory(rows, columns);

  if (matrix == NULL) {
    res_code = INCORRECT_MATRIX;
  } else {
    result->matrix = matrix;
    result->rows = rows;
    result->columns = columns;
  }
  return res_code;
}