#include "s21_test.h"

int main(void) {
  int number_failed = 0;

  number_failed += s21_create_matrix_test();
  number_failed += s21_remove_matrix_test();
  number_failed += s21_eq_matrix_test();
  number_failed += s21_sum_matrix_test();
  number_failed += s21_sub_matrix_test();
  number_failed += s21_mult_matrix_test();
  number_failed += s21_mult_number_test();
  number_failed += s21_transpose_test();
  number_failed += s21_determinant_test();
  number_failed += s21_calc_complements_test();
  number_failed += s21_inverse_matrix_test();

  printf("====================\n\n");
  printf("Total errors: %d\n\n", number_failed);
  printf("====================\n\n");

  return 0;
}