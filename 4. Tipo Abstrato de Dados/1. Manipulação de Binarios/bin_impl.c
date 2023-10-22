#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include "functions.h"

int archive[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int secondArchive[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int auxArchive[17] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void screenMessage(){
    printf("\n-------------- Binary Machine ---------------\n\n");
}

int getCommand(){
    int command;

    screenMessage();

    printf("Digite (0) para sair\n");
    printf("Digite (1) para ler o primeiro número binário\n");
    printf("Digite (2) para ler o segundo número binário\n");
    printf("Digite (3) para visualizar os números binários\n");
    printf("Digite (4) para visualizar os números binários em valores decimais\n");
    printf("Digite (5) para somar os números binários\n\n");
    printf("--------------------------------------------\n\n");

    do
    {
        printf("Digite uma escolha de 0 a 5: ");
        scanf("%d", &command);

    } while (command < 0 || command > 5);

    return command;
}

int conversionToDecimal(int archive[], int size){
    int i, contr = 0, sum = 0;

    for (i = size; i > -1; i--, contr++){
        if (archive[i] == true)
            sum += pow(2, contr);
    }
    
    return sum;
}

void conversionToBinary(int archive[], int value, int size){
    int i, j;

    for (i = size, j = 0; i >= 0; i--)
    {
        if (value - pow(2, i) >= 0){
            value -= pow(2, i);

            archive[j] = 1;
        }

        else
            archive[j] = 0;

        j++;
    }
}

bool sumBinarys(int archive[], int secondArchive[], int auxArchive[]){
    int result;
    bool overflow = false;

    result = conversionToDecimal(archive, 15);

    result += conversionToDecimal(secondArchive, 15);

    conversionToBinary(auxArchive, result, 16);

    return overflow;
}

int existResult(){
    if (conversionToDecimal(auxArchive, 16) != 0)    
    return true;

    else
        return false;
}

void setArchive(){
    int i, digit;

    for (i = 0; i < 16; i++)
    {
        printf("Digito[%d]: ", i + 1);
        scanf("%d", &digit);
        archive[i] = digit;
    }
}

void setSecondArchive(){
    int i, digit;

    for (i = 0; i < 16; i++)
    {
        printf("Digito[%d]: ", i + 1);
        scanf("%d", &digit);
        secondArchive[i] = digit;
    }
}

void getBinarys(){
    int i;

    printf("--------------------------------------------\n\n");

    printf("Binário 1: ");

    for (i = 0; i < 15; i++)
        printf("%d ", archive[i]);

    printf("%d\n", archive[15]);
    
    printf("Binário 2: ");

    for (i = 0; i < 15; i++)
        printf("%d ", secondArchive[i]);
        
    printf("%d\n", secondArchive[15]);

    if (existResult()){

        printf("Binário R: ");

        for (i = 0; i < 15; i++)
            printf("%d ", auxArchive[i]);
        printf("%d\n", auxArchive[15]);
    }
}

void getDecimal(){
    printf("--------------------------------------------\n\n");

    printf("Binário 1: %d\n", conversionToDecimal(archive, 15));
    printf("Binário 2: %d\n", conversionToDecimal(secondArchive, 15));

    if(existResult())
        printf("Binário resultante: %d\n", conversionToDecimal(auxArchive, 16));
}

void getSum(){
    int i;

    printf("--------------------------------------------\n\n");

    printf("Binário resultante:\n");
    
    if(sumBinarys(archive, secondArchive, auxArchive))
        printf("1 ");

    for (i = 0; i < 15; i++)
        printf("%d ", auxArchive[i]);
    printf("%d\n", auxArchive[15]);
}