#include "utilitario.h"

void load_file_classified(int array[], int size){
    srand( (unsigned) time(NULL) );

    array[0] = rand() % 1000;
    for(int i = 1; i != size; i++){
        array[i] = array[i-1] + ( rand() % 100 );
    }
}

void print_file(int array[], int size){
    for(int i = 0; i != size; i += 1){
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

void createAux(int array[], int auxArray[], int size){

    for (int i = 0; i <= size / 10; i++)
    {
        auxArray[i] = array[i * 9];
        printf("auxiliar[%d] = %d\n", i, auxArray[i]);
    }
}

int searchKey(int array[], int auxArray[], int key, int size){

    int initialPos, finalPos, position = 0, pos;
    int flag = 0;

    if (key < array[0]) 
        return -1;

    if (key > array[size - 1])
        return -1;

    for (int i = 0; i < 10 && flag == 0; i++)
    {
        if (auxArray[i] == key){
            position = i * 9; 
            flag = 1;
        }

        else{
            if (auxArray[i] > key){
                if (i == 0) 
                    initialPos = array[0];
                else
                    initialPos = auxArray[i - 1];

                finalPos = auxArray[i];
                flag = 1;

                printf("Esta entre: %d e %d\n", initialPos, finalPos);
            }
            else{
                if (i == 9){
                    initialPos = auxArray[i + 1];
                    finalPos = array[size - 1];

                    printf("Esta entre: %d e %d\n", initialPos, finalPos);
                }
            }     
        }
    }

    while(initialPos <= finalPos && position == 0)
    {
        printf("pos[%d] = %d\n", initialPos, array[initialPos]);
        if (key == array[initialPos])
            position = initialPos;

        initialPos++;
    }

    return position;
}