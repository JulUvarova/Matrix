#ifndef _S21_MATRIX_H_
#define _S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*Resulting code for matrix comparison*/
#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

/*All operations (except matrix comparison) should return the resulting code:
0 - OK
1 - Error, incorrect matrix
2 - Calculation error (mismatched matrix sizes; matrix for which calculations
cannot be performed, etc.)*/
typedef enum { OK = 0, INCORRECT_MATRIX = 1, CALC_ERROR = 2 } Resulting_code;

#include "s21_utility.h"

/*Creating matrix
if memory is invalis - return INCORRECT_MATRIX, else - OK*/
int s21_create_matrix(int rows, int columns, matrix_t *result);

/*Deleting matrix*/
void s21_remove_matrix(matrix_t *A);

/*The matrices A, B are equal |A = B| if they have the same dimensions and the
corresponding elements are identical, thus for all i and j: A(i,j) = B(i,j) The
comparison must be up to and including 7 decimal places.*/
int s21_eq_matrix(matrix_t *A, matrix_t *B);

/* The sum of two matrices A = m × n and B = m × n of the same size is a matrix
C = m × n = A + B of the same size whose elements are defined by the equations
C(i,j) = A(i,j) + B(i,j).*/
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/* The difference of two matrices A = m × n and B = m × n of the same size is a
matrix C = m × n = A - B of the same size whose elements are defined by the
equations C(i,j) = A(i,j) - B(i,j).*/
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/* The product of the matrix A = m × n by the number λ is the matrix B = m × n =
λ × A whose elements are defined by the equations B = λ × A(i,j).*/
int s21_mult_number(matrix_t *A, double number, matrix_t *result);

/*The product of A = m × k by B = k × n is a matrix C = m × n = A × B of size m
× n whose elements are defined by the equation C(i,j) = A(i,1) × B(1,j) + A(i,2)
× B(2,j) + ... + A(i,k) × B(k,j).*/
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/* The transpose of matrix A is in switching its rows with its columns with
 * their numbers retained*/
int s21_transpose(matrix_t *A, matrix_t *result);

/* Minor M(i,j) is a (n-1)-order determinant obtained by deleting out the i-th
 row and the j-th column from the matrix A. The algebraic complement of a matrix
 element is the value of the minor multiplied by -1^(i+j).*/
int s21_calc_complements(matrix_t *A, matrix_t *result);

/*The determinant is a number that is associated to each square matrix and
calculated from the elements using special formulas. Tip: The determinant can
only be calculated for a square matrix. The determinant of a matrix equals the
sum of the products of elements of the row (column) and the corresponding
algebraic complements.
Made with Rule of Sarrus*/
int s21_determinant(matrix_t *A, double *result);

/*A matrix A to the power of -1 is called the inverse of a square matrix A if
the product of these matrices equals the identity matrix. If the determinant of
the matrix is zero, then it does not have an inverse. The formula to calculate
the inverse of matrix is A−1=1∣A∣×A∗TA^{-1}=\frac{1} {|A|} ×
A_*^TA−1=∣A∣1​×A∗T​*/
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif