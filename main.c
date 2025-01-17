#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "gauss.h"

int main()
{
    int n;
    printf("Podaj rozmiar macierzy kwadratowej: ");
    scanf("%d", &n);

    // Alokacja pamięci na macierz A (n x n) i wektor b (n-elementowy)
    double** A = allocate_matrix(n, n);
    double* b = (double*)malloc(n * sizeof(double));
    if (!b) {
        fprintf(stderr, "Blad alokacji pamieci dla wektora b!\n");
        return 1;
    }

    printf("Podaj elementy macierzy A (wierszami, %d elementow w wierszu):\n", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Podaj elementy wektora b (rozwiązań układu) (po %d elementow):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    gauss_elimination(A, b, n);

    printf("\nRozwiazanie:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %f\n", i + 1, b[i]);
    }

    free_matrix(A, n);
    free(b);
    
    testGauss1();


    return 0;
}