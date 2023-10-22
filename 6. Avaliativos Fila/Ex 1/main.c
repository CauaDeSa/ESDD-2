/*
    1. Faça um programa que leia em um TAD Fila, 20 números inteiros fornecidos pelo usuários. Após a leitura
    o programa deve remover da Fila todos os números PARES, contudo os valores NULOS e IMPARES devem
    permanecer na mesma ordem de leitura na Fila. Apresente a Fila resultante.
*/

#include "queue.h"

void printFila(Queue fila);

int main() {
    Queue fila1, fila2;
    int num, i;

    init(&fila1);
    init(&fila2);

    for (i = 0; i < QUEUE_MAX_SIZE; i++) {
        printf("Digite numero[%d]: ", i + 1);
        scanf("%d", &num);

        printf("%s\n", enqueue(fila1, num) ? "OK" : "ERRO");
    }

    for (i = 0; i < QUEUE_MAX_SIZE; i++) {
        num = dequeue(fila1);

        if (num % 2 != 0 || num == 0)
            enqueue(fila2, num);
    }

    while (!is_empty(fila2)) {
        num = dequeue(fila2);
        printf("%s", enqueue(fila1, num) ? "" : "");
    }

    printFila(fila1);

    free(fila1);
    free(fila2);

    return 0;
}

void printFila(Queue fila) {
    Queue aux;
    int num, i = 1;

    init(&aux);

    while (!is_empty(fila)) {
        num = dequeue(fila);
        printf("[%d]: %d\n", i, num);
        printf("%s", enqueue(aux, num) ? "" : "");
        i++;
    }

    while (!is_empty(aux)) {
        num = dequeue(aux);
        printf("%s", enqueue(fila, num) ? "" : "");
        i++;
    }

    free(aux);
}