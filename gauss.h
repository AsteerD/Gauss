#ifndef GAUSS_H
#define GAUSS_H

/**
 * Funkcja wykonuje eliminację Gaussa z częściowym pivotowaniem na macierzy A (nxn)
 * i wektorze b(n). Wektor b będzie zawierał rozwiązanie układu po wykonaniu funkcji.
 */
void gauss_elimination(double** A, double* b, int n);

#endif
