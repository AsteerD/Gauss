#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

double** allocate_matrix(int rows, int cols)
{
    double** matrix = (double**)malloc(rows * sizeof(double*));
    if (!matrix) {
        fprintf(stderr, "Blad alokacji pamieci dla macierzy!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
        if (!matrix[i]) {
            fprintf(stderr, "Blad alokacji pamieci dla wiersza %d!\n", i);
            exit(EXIT_FAILURE);
        }
    }
    return matrix;
}

void free_matrix(double** matrix, int rows)
{
    if (!matrix) return;
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void print_matrix(double** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%8.3f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void swap_rows(double** matrix, int row1, int row2, int cols)
{
    // Najłatwiej zamienić wskaźniki, dzięki czemu wiersze się "przekręcą".
    double* temp = matrix[row1];
    matrix[row1] = matrix[row2];
    matrix[row2] = temp;
}
