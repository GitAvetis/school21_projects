#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = OK;

  if (rows <= 0 || columns <= 0 || result == NULL) {
    status = INCORRECT_MATRIX;
  } else {
    double **init_matrix = (double **)malloc(rows * sizeof(double *) +
                                             rows * columns * sizeof(double));
    if (init_matrix == NULL) {
      status = INCORRECT_MATRIX;
    } else {
      double *p = (double *)((char *)init_matrix + rows * sizeof(double *));
      for (int i = 0; i < rows; i++) {
        init_matrix[i] = p + i * columns;
      }

      for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
          init_matrix[row][col] = 0;
        }
      }
      result->matrix = init_matrix;
      result->columns = columns;
      result->rows = rows;
    }
  }
  return status;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = SUCCESS;  // 0 - fail
  if (is_matix_correct(A) && is_matix_correct(B) && s21_eq_size_matrix(A, B)) {
    int rows = A->rows;
    int columns = A->columns;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-7) {
          result = FAILURE;
        }
      }
    }
  } else
    result = FAILURE;  // incorrect matix
  return result;
}

int s21_eq_size_matrix(matrix_t *A, matrix_t *B) {
  int result = FAILURE;
  if (is_matix_correct(A) && is_matix_correct(B)) {
    if (A->columns == B->columns && A->rows == B->rows) result = SUCCESS;
  }
  return result;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res_code = OK;
  if (s21_eq_size_matrix(A, B)) {
    int rows = A->rows;
    int columns = A->columns;
    s21_create_matrix(rows, columns, result);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        result->matrix[i][j] = (A->matrix[i][j] + B->matrix[i][j]);
      }
    }
  } else
    res_code = CALC_ERR;  // incorrect matix
  return res_code;
}
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res_code = OK;
  if (s21_eq_size_matrix(A, B)) {
    int rows = A->rows;
    int columns = A->columns;
    s21_create_matrix(rows, columns, result);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        result->matrix[i][j] = (A->matrix[i][j] - B->matrix[i][j]);
      }
    }
  } else
    res_code = CALC_ERR;
  return res_code;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res_code = OK;
  if (A != NULL) {
    int rows = A->rows;
    int columns = A->columns;
    s21_create_matrix(rows, columns, result);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        result->matrix[i][j] = (A->matrix[i][j] * number);
      }
    }
  } else
    res_code = INCORRECT_MATRIX;  // incorrect matix
  return res_code;
}
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;
  if (A == NULL || B == NULL || result == NULL) {
    status = INCORRECT_MATRIX;
  } else if (A->columns != B->rows) {
    status = CALC_ERR;
  } else {
    s21_create_matrix(A->rows, B->columns, result);

    for (int row = 0; row < result->rows; row++) {
      for (int col = 0; col < result->columns; col++) {
        result->matrix[row][col] = 0;
        for (int k = 0; k < A->columns; k++) {
          result->matrix[row][col] += A->matrix[row][k] * B->matrix[k][col];
        }
      }
    }
  }

  return status;
}

void s21_remove_matrix(matrix_t *A) {
  if (A) {
    if (A->matrix) {
      free(A->matrix);
    }
    A->matrix = NULL;
    A->columns = 0;
    A->rows = 0;
  }
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int res_code = OK;
  if (is_matix_correct(A)) {
    int rows = A->rows;
    int columns = A->columns;
    s21_create_matrix(columns, rows, result);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  } else
    res_code = INCORRECT_MATRIX;  // incorrect matix
  return res_code;
}
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res_code = OK;
  if (is_matix_correct(A)) {
    int rows = A->rows;
    int columns = A->columns;
    if (rows == columns) {
      s21_create_matrix(rows, columns, result);
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
          matrix_t minor;
          s21_create_minor_matrix(i, j, A, &minor);
          double determinant = 0;
          s21_determinant(&minor, &determinant);
          result->matrix[i][j] = (pow(-1, i + j)) * determinant;
          s21_remove_matrix(&minor);
        }
      }
    } else
      res_code = CALC_ERR;
  } else
    res_code = INCORRECT_MATRIX;  // incorrect matix
  return res_code;
}

int s21_determinant(matrix_t *A, double *result) {
  int res_code = OK;
  double tmp = 0;
  if (is_matix_correct(A)) {
    int columns = A->columns;
    int rows = A->rows;

    if (rows == columns) {
      if (columns == 1) {
        tmp = A->matrix[0][0];
      } else {
        for (int i = 0; i < columns; i++) {
          matrix_t minor;
          s21_create_minor_matrix(0, i, A, &minor);
          double tmp_det = 0;
          s21_determinant(&minor, &tmp_det);
          tmp += A->matrix[0][i] * pow(-1, i) * tmp_det;
          s21_remove_matrix(&minor);
        }
      }
    } else
      res_code = CALC_ERR;
  } else
    res_code = INCORRECT_MATRIX;  // incorrect matix
  *result = tmp;
  return res_code;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res_code = OK;  // 0 - fail
  int rows = A->rows;
  int columns = A->columns;

  if (is_matix_correct(A) && (rows == columns)) {
    double determinant = 0;
    s21_determinant(A, &determinant);
    if (determinant) {
      matrix_t minor;
      matrix_t minor_trans;
      s21_calc_complements(A, &minor);
      s21_transpose(&minor, &minor_trans);
      s21_mult_number(&minor_trans, 1 / determinant, result);
      s21_remove_matrix(&minor);
      s21_remove_matrix(&minor_trans);
    } else
      res_code = CALC_ERR;
  } else
    res_code = CALC_ERR;  // incorrect matix
  return res_code;
}
