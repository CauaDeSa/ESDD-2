#include "uteis.h"
#include <stdlib.h>
#include <stdio.h> 

#define TRUE 1
#define FALSE 0
#define MIN 1000
#define AVRG 100000
#define MAX 1000000

int getCase(){
	int option;

	printf("Qual caso? ");
	scanf("%d", &option);

	return option;
}

int defineLength(int choose){
	int qtty;

	if (choose == 1 || choose == 4 || choose == 7)
		qtty = MIN;

	else{
		if (choose == 2 || choose == 5 || choose == 8)
			qtty = AVRG;

		else{
			if (choose == 3 || choose == 6 || choose == 9)
				qtty = MAX;
		}
	}

	return qtty;
}

void defineArray(int choose, int array[], int length){
	if (choose == 1 || choose == 2 || choose == 3)
		carrega_vetor_ordenado(array, 1, length);

	else{
		if (choose == 4 || choose == 5 || choose == 6)
			carrega_vetor_aleatorio(array, length);

		else{
			if (choose == 7 || choose == 8 || choose == 9)
				carrega_vetor_nao_ordenado(array, length);
		}
	}
}

void carrega_vetor_aleatorio(int array[], int length){
	int i;
	
	srand( (unsigned) time(NULL) );

	for(i = 0; i < length; i++)
		array[i] = rand() % MAX;
}

void carrega_vetor_ordenado(int array[], int initialValue, int length){
	int i;

	srand( (unsigned) time(NULL) );

	for(array[0] = initialValue, i = 1; i < length; i++)
		array[i] = array[i-1] + (rand() % 10);
}

void carrega_vetor_nao_ordenado(int array[], int finalValue){
	int i, aux = 1;

	srand( (unsigned) time(NULL) );

	for(i = finalValue; i >= 0; i--)
		array[i] = aux++;
}

void copyArray(int array[], int arrayAux[], int length){
	int i;
	
	for (i = 0; i < length; i++)
		arrayAux[i] = array[i];
}

void updateData(int array[], int arrayAux[], int length, int comparationsChanges[]){
	
	comparationsChanges[0] = comparationsChanges[1] = 0;

	copyArray(array, arrayAux, length);
}

int getSortResult(int type, int array[], int arrayAux[], int length, int comparationsChanges[]){

	updateData(array, arrayAux, length, comparationsChanges);

	if (type == 1)
	{
		clock_t begin = clock();
		bubble_sort(arrayAux, length, comparationsChanges);
		clock_t end = clock();

		showResult(type, (double)(end - begin) / CLOCKS_PER_SEC, comparationsChanges);
	}

	else
	{
		if (type == 2)
		{
			clock_t begin = clock();
			selection_sort(arrayAux, length, comparationsChanges);
			clock_t end = clock();

			showResult(type, (double)(end - begin) / CLOCKS_PER_SEC, comparationsChanges);
		}

		else
		{
			if (type == 3)
			{
				clock_t begin = clock();
				insert_sort(arrayAux, length, comparationsChanges);
				clock_t end = clock();

				showResult(type, (double)(end - begin) / CLOCKS_PER_SEC, comparationsChanges);
			}

			else
			{
				if (type == 4)
				{
					clock_t begin = clock();
					merge(arrayAux, 0, length-1, length, comparationsChanges);
					clock_t end = clock();

					showResult(type, (double)(end - begin) / CLOCKS_PER_SEC, comparationsChanges);
				}

				else
				{
						clock_t begin = clock();
						quicksort(arrayAux, 0, length-1, comparationsChanges);
						clock_t end = clock();

						showResult(type, (double)(end - begin) / CLOCKS_PER_SEC, comparationsChanges);
				}
			}
		}
	}
}

void bubble_sort(int array[], int length, int comparationsChanges[]){
	int i, j, auxElement;
	int changed = TRUE;
	
	for(i = 0; i < length && changed; i++){
		changed = FALSE;

		for(j = 0; j < length - (1 + i); j++)
		{
			if(array[j] > array[j+1])
			{
				comparationsChanges[1]++;
				auxElement = array[j];
				array[j] = array[j+1];
				array[j+1] = auxElement;
				changed = TRUE;
			}
			comparationsChanges[0]++;
		}
	}
}

void selection_sort(int array[], int length, int comparationsChanges[]){
	int i, j, minorPosition, auxElement;
	
	for(i = 0; i < length; i++){
		minorPosition = i;

		for(j = i + 1; j < length; j++){
			if(array[j] < array[minorPosition])
				minorPosition = j;
			comparationsChanges[0]++;
		}

		auxElement = array[i];
		array[i] = array[minorPosition];
		array[minorPosition] = auxElement;
		comparationsChanges[1]++;
	}
}

void insert_sort(int array[], int length, int comparationsChanges[]){
	int i, j, auxElement;

	for(i = 1; i < length; i++){
		auxElement = array[i];

		for(j = i - 1; j >= 0 && array[j] > auxElement; j--)
		{
			array[j+1] = array[j];
			comparationsChanges[0]++;
			comparationsChanges[1]++;
		}

		array[j+1] = auxElement;
		comparationsChanges[0]++;
		comparationsChanges[1]++;
	}
}

void merge(int array[], int start, int end, int length, int comparationsChanges[]){
	int middle;

	if(start < end){
		middle = (start + end) / 2;
		merge(array, start, middle, length, comparationsChanges);
		merge(array, middle + 1, end, length, comparationsChanges);
		intercala(array, start, end, middle, length, comparationsChanges);
	}
}

void intercala(int array[], int start, int end, int middle, int length, int comparationsChanges[]){
	int freePosition, start_array1, start_array2, i;
	int array_aux[length];
	start_array1 = start;
	start_array2 = middle + 1;
	freePosition = start;

	while(start_array1 <= middle && start_array2 <= end){

		if(array[start_array1] <= array[start_array2]){
			array_aux[freePosition] = array[start_array1];
			start_array1++;
		} 
		else{
			array_aux[freePosition] = array[start_array2];
			start_array2++;
		}

		freePosition++;
		comparationsChanges[0]++;
		comparationsChanges[1]++;
	}

	for(i = start_array1; i <= middle; i++, freePosition++){
		array_aux[freePosition] = array[i];
		comparationsChanges[0]++;
		comparationsChanges[1]++;
	}
	comparationsChanges[0]++;

	for(i = start_array2; i <= end; i++, freePosition++){
		array_aux[freePosition] = array[i];
		comparationsChanges[0]++;
		comparationsChanges[1]++;
	}
	comparationsChanges[0]++;

	for(i = start; i <= end; i++){
		array[i] = array_aux[i];
		comparationsChanges[0]++;
		comparationsChanges[1]++;
	}
	comparationsChanges[0]++;
}

void quicksort(int array[], int left, int right, int comparationsChanges[]){
    int i = left, j = right;

    int tmp;

    int pivot = array[(left + right) / 2];

    while (i <= j)
    {

        while (array[i] < pivot)
        {
            i++;
        }
        while (array[j] > pivot)
        {
            j--;
        }

        comparationsChanges[0]++;

        if (i <= j)
        {
            comparationsChanges[1]++;

            tmp = array[i];

            array[i] = array[j];

            array[j] = tmp;

            i++;

            j--;
        }
    };

    if (left < j)

        quicksort(array, left, j, comparationsChanges);

    if (i < right)

        quicksort(array, i, right, comparationsChanges);
}

void showResult(int type, double time_spent, int comparationsChanges[]){
	
	if (type == 1){
	    printf("\n--------------------------------------------------------------------------\n\n");
		printf("bubble sort:    %f seconds \t %10d \t %10d \n", time_spent, comparationsChanges[0], comparationsChanges[1]);
	}

	else
	{	
		if (type == 2)
			printf("selection sort: %f seconds \t %10d \t %10d \n", time_spent, comparationsChanges[0], comparationsChanges[1]);
		
		else
		{
			if (type == 3)
				printf("insert sort:    %f seconds \t %10d \t %10d \n", time_spent, comparationsChanges[0], comparationsChanges[1]);

			else
			{
				if (type == 4)
					printf("merge sort:     %f seconds \t %10d \t %10d \n", time_spent, comparationsChanges[0], comparationsChanges[1]);
				
				else
				{
					printf("quick sort:     %f seconds \t %10d \t %10d \n", time_spent, comparationsChanges[0], comparationsChanges[1]);
					printf("\n--------------------------------------------------------------------------\n");
				}
			}
		}
	}
}