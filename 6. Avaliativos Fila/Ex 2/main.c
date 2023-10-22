/*
    2. Faça um programa para controlar uma fila de banco com atendimento prioritário. Existem 10 caixas
    (representados pelos números de 1 a 10). Os atendimentos prioritários são atendidos exclusivamente pelos
    caixas de I a 3, porém estes caixas podem atender também a fila normal, caso não tenha nenhum cliente na
    fila de atendimento prioritário. Faça um programa que mostre um menu com as seguintes opções: I — Pegar
    ficha normal, 2 — Pegar ficha prioritária, 3 — Caixa chama próximo cliente (informando o número do caixa) e
    sistema exibe o número do cliente a ser atendido e se é da fila normal ou da prioritária. Controle o número de
    chamada dos clientes, iniciando ambas as filas em I.
*/

#include "queue.h"

int main() {
    Queue filaNormal, filaPrioritaria;
    int caixa, command = 1;
    int i = 0, countFilaNormal = 1, countFilaPrioritaria = 1;

    init(&filaNormal);
    init(&filaPrioritaria);

    while (command != 0) {
        printf("\n---------- LISTA DE COMANDOS ----------\n");
        printf("Digite (1) para pegar ficha normal.\n");
        printf("Digite (2) para pegar ficha prioritária.\n");
        printf("Digite (3) para chamar próximo cliente.\n");
        printf("Digite (0) para sair.\n\n");

        printf("Comando: ");

        scanf("%d", &command);

        if (command != 0) {
            switch (command) {
            case 1:
                printf("\n%s\n", enqueue(filaNormal, countFilaNormal) ? "OK" : "ERRO");
                countFilaNormal++;
                break;
            case 2:
                printf("\n%s\n", enqueue(filaPrioritaria, countFilaPrioritaria) ? "OK" : "ERRO");
                countFilaPrioritaria++;
                break;

            case 3:

                printf("\nCaixa: ");
                scanf("%d", &caixa);

                if (caixa > 0 && caixa <= 3 && !is_empty(filaPrioritaria))
                    printf("\nCaixa: %d | Cliente prioritario: %d\n", caixa, dequeue(filaPrioritaria));
                else if (!is_empty(filaNormal))
                    printf("\nCaixa: %d | Cliente: %d\n", caixa, dequeue(filaNormal));
                else
                    printf("\nNao tem ninguem na fila!!");
                break;
            default:
                printf("Comando inválido!\n");
                break;
            }
            i++;
        }
    }

    free(filaNormal);
    free(filaPrioritaria);

    return 0;
}