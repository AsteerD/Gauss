# Eliminacja Gaussa z Pivotami w Języku C

## Opis projektu
Projekt implementuje metodę eliminacji Gaussa z częściowym wyborem elementu głównego (pivotowaniem) w języku C. Kod jest podzielony na kilka plików dla lepszej organizacji i czytelności. W implementacji nie wykorzystano żadnych zewnętrznych bibliotek, a wszystkie operacje na macierzach są zaimplementowane ręcznie.

---

## Struktura projektu
```
.
├── gauss.c       # Implementacja eliminacji Gaussa
├── gauss.h       # Deklaracje funkcji eliminacji Gaussa
├── main.c        # Przykładowy program główny
├── matrix.c      # Implementacja operacji macierzowych
├── matrix.h      # Deklaracje funkcji operacji macierzowych
└── test.c        # Testy jednostkowe
```

---

## Funkcjonalności
- Eliminacja Gaussa z częściowym pivotowaniem
- Operacje na macierzach, takie jak:
  - Alokacja i zwalnianie pamięci
  - Wypisywanie macierzy
  - Zamiana wierszy macierzy
- Testy jednostkowe sprawdzające poprawność algorytmu

---

## Instrukcja kompilacji i uruchamiania

### 1. Kompilacja programu głównego
Aby skompilować program główny, użyj poniższego polecenia:
```bash
gcc -o gauss main.c gauss.c matrix.c -lm
```
Uruchomienie programu:
```bash
./gauss
```

### 2. Kompilacja testów jednostkowych
Aby uruchomić testy jednostkowe, skompiluj i uruchom plik `test.c`:
```bash
gcc -o test test.c gauss.c matrix.c -lm
./test
```

Funkcje matematyczne (np. `fabs`) wymagają biblioteki matematycznej, dodaj `-lm` do polecenia kompilacji.

## Przykładowe dane wejściowe i wyjściowe

### Wejście (macierz A i wektor b):
```
Podaj rozmiar macierzy: 3
Podaj elementy macierzy A (wierszami, 3 elementy w wierszu):
2 1 -1
1 3 2
3 -2 4
Podaj elementy wektora b (po 3 elementy):
1 13 2
```

### Wyjście (rozwiązanie układu):
```
Rozwiazanie:
x1 = 3.000000
x2 = 2.000000
x3 = 1.000000
```

---

## Testy jednostkowe
Testy jednostkowe znajdują się w pliku `test.c`. Przykładowy test rozwiązuje układ równań:
```
2x +  y -  z =  1
 x + 3y + 2z = 13
3x - 2y + 4z =  2
```
Oczekiwane rozwiązanie: `x=3, y=2, z=1`.

---

## Struktura kodu

### 1. `matrix.c` i `matrix.h`
- **Funkcje:**
  - `allocate_matrix` - Alokuje macierz o zadanym rozmiarze
  - `free_matrix` - Zwalnia pamięć macierzy
  - `print_matrix` - Wypisuje macierz
  - `swap_rows` - Zamienia dwa wiersze w macierzy

### 2. `gauss.c` i `gauss.h`
- **Funkcje:**
  - `gauss_elimination` - Przeprowadza eliminację Gaussa z pivotowaniem

### 3. `main.c`
- Przykładowy program główny, który:
  - Wczytuje macierz i wektor z wejścia
  - Wykonuje eliminację Gaussa
  - Wypisuje wynik

### 4. `test.c`
- Plik z testami jednostkowymi dla funkcji `gauss_elimination`
- Zawiera funkcje do sprawdzania poprawności wyników (np. z użyciem tolerancji).

---

## Uwagi i ograniczenia
- Algorytm zakłada, że podana macierz ma rozwiązanie.
- Nie obsługuje przypadków macierzy osobliwej (np. brak rozwiązań lub nieskończona liczba rozwiązań).
- W razie wystąpienia problemów z precyzją, można zmienić typ danych na `long double` (%ld).

---

## Autor
AsteerD
