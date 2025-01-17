#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"
#include "gauss.h"


//Funkcja zwraca 1 (true), jeśli a i b są równe z dokładnością tolerancji (3-5%).

int approx_equal(double a, double b, double tol)
{
    return fabs(a - b) < tol;
}

/**
 * Przykładowy test #1.
 * Rozwiązywany układ:
 *   2x +  1y - 1z =  1
 *   1x +  3y + 2z = 13
 *   3x + -2y + 4z =  2
 * Oczekiwane rozwiązanie: x=3, y=2, z=1
 */
void test_gauss1()
{
    int n = 3;
    double** A = allocate_matrix(n, n);
    double* b = (double*)malloc(n * sizeof(double));

    // Wypełniamy macierz A i wektor b
    A[0][0] = 2; A[0][1] = 1;  A[0][2] = -1;  b[0] = 1;
    A[1][0] = 1; A[1][1] = 3;  A[1][2] = 2;   b[1] = 13;
    A[2][0] = 3; A[2][1] = -2; A[2][2] = 4;   b[2] = 2;

    gauss_elimination(A, b, n);

    // Sprawdzanie poprawności wyniku z pewną tolerancją
    if (approx_equal(b[0], 3.0, 1e-6) &&
        approx_equal(b[1], 2.0, 1e-6) &&
        approx_equal(b[2], 1.0, 1e-6))
    {
        printf("test_gauss1 zakonczony sukcesem\n");
    }
    else {
        printf("test_gauss1 zakonczony porazka. Otrzymane: [%lf, %lf, %lf]\n", b[0], b[1], b[2]);
    }

    free_matrix(A, n);
    free(b);
}