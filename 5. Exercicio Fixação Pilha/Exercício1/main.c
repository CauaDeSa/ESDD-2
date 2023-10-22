#include "pilha.h"

int main(int argc, char** argv) {
    Pilha minhaPilha, suaPilha;
    int menu;
    Tipo_Informacao valor;

    init(&minhaPilha);
    init(&suaPilha);

    do{
        printf("\n1 - Empilha");
        printf("\n2 - Desempilha");
        printf("\n3 - Esvaziar");
        printf("\n4 - Copiar");
        printf("\n5 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("\nEmpilha\n\n\tValor: ");
                scanf("%d", &valor);
                if(push(minhaPilha, valor)){
                    printf("\nEmpilhado com sucesso\n");
                }else{
                    printf("\nEstouro de pilha\n");
                }
                break;
            case 2:
                if(pop(minhaPilha, &valor)){
                    printf("\nDesempilha\n\n\tValor: %d", valor);
                }else{
                    printf("\nPilha vazia\n");
                }
                break;
            case 3:
                while(!is_empty(minhaPilha)){
                    pop(minhaPilha, &valor);
                    printf("\nValor: %d", valor);
                }
                while(!is_empty(suaPilha)){
                    pop(suaPilha, &valor);
                    printf("\nValor copiado: %d", valor);
                }
                break;
            
            case 4:
                while(!is_empty(minhaPilha)){
                    duplicar_pilha(minhaPilha, suaPilha);
                }
                break;
        }
    }while(menu != 5);
    return 0;
}