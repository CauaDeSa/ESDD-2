#include <time.h>

int getCase();

int defineLength(int);

void defineArray(int, int[], int);

void carrega_vetor_aleatorio(int[], int);

void carrega_vetor_ordenado(int[], int, int);

void carrega_vetor_nao_ordenado(int[], int);

void copyArray(int[], int[], int);

void updateData(int[], int[], int, int[]);

int getSortResult(int, int[], int[], int, int[]);

void bubble_sort(int[], int, int[]);

void selection_sort(int[], int, int[]);

void insert_sort(int[], int, int[]);

void merge(int[], int, int, int, int[]);

void intercala(int[], int, int, int, int, int[]);

void quicksort(int[], int, int, int[]);

void partition(int[], int, int, int *j, int[]);

void showResult(int, double, int[]);