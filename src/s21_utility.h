#ifndef _UTILITY_H_
#define _UTILITY_H_

#include "s21_matrix.h"

/* check size and memory of matrix
 if all is normal - return OK, else - INCORRECT_MATRIX */
int check_matrix(matrix_t* A);

/* check size equation of A and B
 if they equal - return OK, else - INCORRECT_MATRIX */
int check_eq_size(matrix_t* A, matrix_t* B);

/* allocate memory for matrix with calloc
if smth wrong - return NULL */
double** get_memory(int rows, int cols);

/* Copy the matrix A with deleting out the row-th row and the col-th column  */
void cp_helper_matrix(int row, int col, matrix_t* A, matrix_t* helper);

/* Count determinant of the matrix A with size more than 2x2 */
int get_determinant(double* result, matrix_t* A);

#endif