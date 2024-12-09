#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Структура
typedef struct {
    int rows;
    int cols;
    int** data;
} Matrix;

Matrix create_matrix(int rows, int cols, int fill_value); // создание матрицы с выделением памяти и заполнением указанным числом
void fill_matrix_random(Matrix matrix, int min, int max); // заполнение матрицы случайными числами
Matrix add_matrices(Matrix m1, Matrix m2); // сложения двух матриц
Matrix subtract_matrices(Matrix m1, Matrix m2); // вычитание двух матриц
Matrix multiply_matrices(Matrix m1, Matrix m2); // умножение матриц
Matrix transpose_matrix(Matrix matrix); // транспонированная матрица
void free_matrix(Matrix matrix); // освобождение памяти матрицы
Matrix copy_matrix(Matrix matrix);
void print_matrix(Matrix matrix);

#endif // MATRIX_H

