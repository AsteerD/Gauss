#ifndef MATRIX_H
#define MATRIX_H


 //Alokacja pamięci dla macierzy o rozmiarze rows x cols, tworzy tablice tablic.
double** allocate_matrix(int rows, int cols);

 // Funkcja zwalnia pamięć alokowaną dla macierzy o rozmiarze rows x cols.
 
void free_matrix(double** matrix, int rows);

 //Funkcja wypisuje macierz o rozmiarze rows x cols na standardowe wyjście.

void print_matrix(double** matrix, int rows, int cols);

 //Funkcja zamienia wiersze row1 oraz row2 w macierzy matrix.

void swap_rows(double** matrix, int row1, int row2, int cols);

#endif
