#include "utilitario.h"

#define SIZE 100

int main(int argc, char const *argv[]){

    int arquivo[SIZE], auxArquivo[SIZE / 10], position, key;

    load_file_classified(arquivo, SIZE);

    print_file(arquivo, SIZE);

    createAux(arquivo, auxArquivo, SIZE);

    do
    {
        printf("Digite a chave desejada: ");
        scanf("%d", &key);

        position = searchKey(arquivo, auxArquivo, key, SIZE);
        
        if (position > -1)
            printf("Encontrado na posição: %d\n", position);

        else
            printf("Não encontrado!\n");

    } while (key != 0);

    return 0;
}
