#include <stdio.h>
#include <math.h>
#include "gauss.h"
#include "matrix.h"

void gauss_elimination(double** A, double* b, int n)
{
    // i, j, k - iteratory
    int i, j, k;

    for (k = 0; k < n - 1; k++) { //zaczyna od 0 kolumny, więc n-1
        // Wybór elementu głównego (pivot) w kolumnie k
        double maxVal = fabs(A[k][k]); // fabs - wartość bezwględna elementu
        int maxIndex = k;
        for (i = k + 1; i < n; i++) {
            if (fabs(A[i][k]) > maxVal) {
                maxVal = fabs(A[i][k]);
                maxIndex = i;
            }
        }
        // Zamiana wiersza k z wierszem maxIndex, jeśli pivot nie jest w wierszu k
        if (maxIndex != k) {
            swap_rows(A, k, maxIndex, n);
            double temp = b[k]; //temp - temporary
            b[k] = b[maxIndex];
            b[maxIndex] = temp;
        }

        // Eliminacja elementów poniżej pivota w kolumnie k
        for (i = k + 1; i < n; i++) {
            // Czynnik przez który mnożymy wiersz k, aby odjąć od wiersza i
            double factor = A[i][k] / A[k][k];
            for (j = k; j < n; j++) {
                A[i][j] -= factor * A[k][j];
            }
            b[i] -= factor * b[k];
        }
    }

    // Podstawianie wsteczne (back substitution)
    for (i = n - 1; i >= 0; i--) {
        double sum = b[i];
        for (j = i + 1; j < n; j++) {
            sum -= A[i][j] * b[j];
        }
        b[i] = sum / A[i][i];
    }
}
