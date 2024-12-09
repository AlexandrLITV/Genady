#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {
    // Создание и заполнение матриц
    Matrix m1 = create_matrix(2, 2, 1);
    Matrix m2 = create_matrix(2, 2, 2);

    // Заполнение матриц случайными числами от 1 до 10
    fill_matrix_random(m1, 1, 10);
    fill_matrix_random(m2, 1, 10);

    // Печать матриц
    printf("Matrix 1:\n");
    print_matrix(m1);

    printf("Matrix 2:\n");
    print_matrix(m2);

    // Сложение матриц
    Matrix sum = add_matrices(m1, m2);
    if (sum.data != NULL) {
        printf("Sum of matrices:\n");
        print_matrix(sum);
    } else {
        printf("Error in matrix addition.\n");
    }

    // Вычитание матриц
    Matrix difference = subtract_matrices(m1, m2);
    if (difference.data != NULL) {
        printf("Difference of matrices:\n");
        print_matrix(difference);
    } else {
        printf("Error in matrix subtraction.\n");
    }

    // Умножение матриц
    Matrix product = multiply_matrices(m1, m2);
    if (product.data != NULL) {
        printf("Product of matrices:\n");
        print_matrix(product);
    } else {
        printf("Error in matrix multiplication.\n");
    }

    // Транспонирование матрицы
    Matrix transpose = transpose_matrix(m1);
    if (transpose.data != NULL) {
        printf("Transpose of Matrix 1:\n");
        print_matrix(transpose);
    } else {
        printf("Error in matrix transposition.\n");
    }

    // Копирование матрицы
    Matrix copy = copy_matrix(m1);
    if (copy.data != NULL) {
        printf("Copy of Matrix 1:\n");
        print_matrix(copy);
    } else {
        printf("Error in matrix copy.\n");
    }

    // Освобождение памяти
    free_matrix(m1);
    free_matrix(m2);
    free_matrix(sum);
    free_matrix(difference);
    free_matrix(product);
    free_matrix(transpose);
    free_matrix(copy);

    return 0;
}