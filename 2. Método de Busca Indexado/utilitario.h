#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void load_file_classified(int array[], int size);

void print_file(int array[], int size);

void createAux(int array[], int auxArray[], int size);

int searchKey(int array[], int auxArray[], int key, int size);