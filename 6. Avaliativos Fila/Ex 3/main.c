/*
    3. O problema de Josephus é assim conhecido por causa da lenda de Flavius Josephus, um historiador judeu
    que viveu no século I. Segundo o relato de Josephus do cerco de Yodfat, ele e seus companheiros (40
    soldados) foram presos em uma caverna, cuja saída foi bloqueada pelos romanos. Eles preferiram suicidar-se
    a serem capturados, e decidiram que iriam formar um círculo e começar a matar-se pulando de três em três.
    Josephus afirma que, por sorte ou talvez pela mão de Deus, ele permaneceu por último e preferiu entregar-se
    aos romanos a suicidar-se.

    Utilizando um TAD Fila, leia o nome de 40 pessoas e indique o nome do sobrevivente. Siga a mesma
    estratégia da lenda indicada acima.
*/

#include "queue.h"
#define NAME_MAXSIZE 40

int main() {
    Queue soldados, auxSoldados;
    char* nome;
    int count = 1, vivos = QUEUE_MAX_SIZE, i;

    init(&soldados);
    init(&auxSoldados);

    for (int i = 0; i < QUEUE_MAX_SIZE; i++) {
        nome = malloc(sizeof(char) * NAME_MAXSIZE);
        printf("Digite nome[%d]: ", i + 1);
        fgets(nome, NAME_MAXSIZE, stdin);
        enqueue(soldados, nome);
    }

    while (vivos > 1) {

        while (!is_empty(soldados)) {
            if (count == 3) {
                dequeue(soldados);
                count = 1;
                vivos--;
            } else {
                enqueue(auxSoldados, dequeue(soldados));
                count++;
            }
            
            i++;
        }

        while (!is_empty(auxSoldados)) {
            if (count == 3) {
                dequeue(auxSoldados);
                count = 1;
                vivos--;
            } else {
                enqueue(soldados, dequeue(auxSoldados));
                count++;
            }

            i++;
        }
    }

    printf("Ultimo vivo: %s", dequeue(soldados));

    free(soldados);
    free(auxSoldados);
    free(nome);

    return 0;
}