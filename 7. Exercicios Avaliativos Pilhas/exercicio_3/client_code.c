#include "pilha.h"

void to_binary(Pilha, int);

int main(int argc, char** argv)
{
    int value;
    Pilha binario;

    init(&binario);

    printf("Digite um valor: ");
    scanf("%d", &value);

    to_binary(binario, value);

    while (!is_empty(binario)) {
        pop(binario, &value);
        printf("%d ", value);
    }

    return 0;
}

void to_binary(Pilha pilha, int num)
{
    while (num != 0) {
        push(pilha, num % 2);
        num = num / 2;
    }
}

