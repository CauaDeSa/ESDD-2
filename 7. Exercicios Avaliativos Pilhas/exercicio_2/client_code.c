#include "pilha.h"

bool insert_element(Pilha pilha, Tipo_Informacao valor);

int main(int argc, char** argv)
{
    Pilha minhaPilha;
    int menu;
    Tipo_Informacao valor;

    init(&minhaPilha);

    do {
        printf("\n1 - Empilha");
        printf("\n2 - Desempilha");
        printf("\n3 - Esvaziar");
        printf("\n4 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\nEmpilha\n\n\tValor: ");
                scanf("%d", &valor);
                if (insert_element(minhaPilha, valor)) {
                    printf("\nEmpilhado com sucesso\n");
                } else {
                    printf("\nEstouro de pilha ou numero ja existe na pilha\n");
                }
                break;
            case 2:
                if (pop(minhaPilha, &valor)) {
                    printf("\nDesempilha\n\n\tValor: %d", valor);
                } else {
                    printf("\nPilha vazia\n");
                }
                break;
            case 3:
                while (!is_empty(minhaPilha)) {
                    pop(minhaPilha, &valor);
                    printf("\nValor: %d", valor);
                }
                break;
        }
    } while (menu != 4);
    return 0;
}

bool insert_element(Pilha pilha, Tipo_Informacao new_value)
{
    bool is_there = false;
    bool is_inserted = false;
    int value;

    Pilha aux;

    init(&aux);

    if (is_empty(pilha)) {
        push(pilha, new_value);
    } else {
        if (!is_full(pilha)) {
            while (!is_empty(pilha) && !is_inserted) {
                pop(pilha, &value);

                if (new_value == value) {
                    is_there = true;
                    is_inserted = true;
                    push(aux, value);
                } else {
                    if (value > new_value) {
                        push(aux, value);
                    } else {
                        push(aux, new_value);
                        push(aux, value);
                        is_inserted = true;
                    }
                }
            }

            if (!is_inserted) {
                push(aux, new_value);
            }

            while (!is_empty(aux)) {
                pop(aux, &value);
                push(pilha, value);
            }
        } else {
            is_there = true;
        }
    }

    free(aux);

    return !is_there;
}