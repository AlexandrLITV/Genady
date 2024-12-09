
// matrix.c
#include "matrix.h"

Matrix create_matrix(int rows, int cols, int fill_value) {
    Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.data = (int**)malloc(rows * sizeof(int*));

    if (matrix.data == NULL) {
        matrix.rows = -1;
        matrix.cols = -1;
        matrix.data = NULL;
        return matrix;
    }

    for (int i = 0; i < rows; i++) {
        matrix.data[i] = (int*)malloc(cols * sizeof(int));
        if (matrix.data[i] == NULL) {
            free_matrix(matrix);
            matrix.rows = -1;
            matrix.cols = -1;
            matrix.data = NULL;
            return matrix;
        }
        for (int j = 0; j < cols; j++) {
            matrix.data[i][j] = fill_value;
        }
    }
    return matrix;
}

void fill_matrix_random(Matrix matrix, int min, int max) {
    if (matrix.data == NULL || matrix.rows < 0 || matrix.cols < 0) {
        printf("Ошибка: недопустимая матрица.\n");
        return;
    }

    srand(time(0));
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            matrix.data[i][j] = rand() % (max - min + 1) + min;
        }
    }
}

Matrix add_matrices(Matrix m1, Matrix m2) {
    if (m1.rows != m2.rows || m1.cols != m2.cols) {
        printf("Ошибка: размеры матриц не совпадают.\n");
        return (Matrix){.rows = -1, .cols = -1, .data = NULL};
    }

    Matrix result = create_matrix(m1.rows, m1.cols, 0);
    if (result.data == NULL) return result;

    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            result.data[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    }
    return result;
}

Matrix subtract_matrices(Matrix m1, Matrix m2) {
    if (m1.rows != m2.rows || m1.cols != m2.cols) {
        printf("Ошибка: размеры матриц не совпадают.\n");
        return (Matrix){.rows = -1, .cols = -1, .data = NULL};
    }

    Matrix result = create_matrix(m1.rows, m1.cols, 0);
    if (result.data == NULL) return result;

    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            result.data[i][j] = m1.data[i][j] - m2.data[i][j];
        }
    }
    return result;
}

Matrix multiply_matrices(Matrix m1, Matrix m2) {
    if (m1.cols != m2.rows) {
        printf("Ошибка: количество столбцов первой матрицы не совпадает с количеством строк второй матрицы.\n");
        return (Matrix){.rows = -1, .cols = -1, .data = NULL};
    }

    Matrix result = create_matrix(m1.rows, m2.cols, 0);
    if (result.data == NULL) return result;

    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m2.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < m1.cols; k++) {
                result.data[i][j] += m1.data[i][k] * m2.data[k][j];
            }
        }
    }
    return result;
}

Matrix transpose_matrix(Matrix matrix) {
    if (matrix.data == NULL || matrix.rows < 0 || matrix.cols < 0) {
        printf("Ошибка: недопустимая матрица.\n");
        return (Matrix){.rows = -1, .cols = -1, .data = NULL};
    }

    Matrix result = create_matrix(matrix.cols, matrix.rows, 0);
    if (result.data == NULL) return result;

    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            result.data[j][i] = matrix.data[i][j];
        }
    }
    return result;
}

void free_matrix(Matrix matrix) {
    if (matrix.data == NULL) return;

    for (int i = 0; i < matrix.rows; i++) {
        free(matrix.data[i]);
    }
    free(matrix.data);
}

Matrix copy_matrix(Matrix matrix) {
    if (matrix.data == NULL || matrix.rows < 0 || matrix.cols < 0) {
        return (Matrix){.rows = -1, .cols = -1, .data = NULL};
    }

    Matrix copy = create_matrix(matrix.rows, matrix.cols, 0);
    if (copy.data == NULL) return copy;

    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            copy.data[i][j] = matrix.data[i][j];
        }
    }
    return copy;
}

void print_matrix(Matrix matrix) {
    if (matrix.data == NULL || matrix.rows < 0 || matrix.cols < 0) {
        printf("Ошибка: недопустимая матрица.\n");
        return;
    }

    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            printf("%4d ", matrix.data[i][j]);
        }
        printf("\n");
    }
}
