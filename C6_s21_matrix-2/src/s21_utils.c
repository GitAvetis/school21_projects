#include "s21_matrix.h"

int is_matix_correct(matrix_t *A) {
  int result = 0;  // 0 - fail
  if ((A)) {
    if (A->columns > 0 && A->rows > 0) result = SUCCESS;
  }
  return result;
}

void s21_create_minor_matrix(int ignored_row, int ignored_column, matrix_t *A,
                             matrix_t *result) {
  if (A && ignored_row >= 0 && ignored_column >= 0) {
    int columns = 0;
    int rows = 0;
    s21_create_matrix(A->rows - 1, A->columns - 1, result);
    for (int i = 0; i < A->rows; i++) {
      if (i != ignored_row) {
        for (int j = 0; j < A->columns; j++) {
          if (j != ignored_column) {
            result->matrix[rows][columns] = A->matrix[i][j];

            columns++;
          }
        }
        columns = 0;
        rows++;
      }
    }
  } else
    result->matrix = NULL;
}

void fill_matrix(matrix_t *matr,
                 double initial_values[matr->rows][matr->columns]) {
  for (int row = 0; row < matr->rows; row++) {
    for (int col = 0; col < matr->columns; col++) {
      matr->matrix[row][col] = initial_values[row][col];
    }
  }
}
