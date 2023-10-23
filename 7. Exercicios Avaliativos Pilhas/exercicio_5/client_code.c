#include "pilha.h"

int main(){
    Pilha minhaPilha, minhaPilha2;
    int menu;
    Tipo_Informacao valor;

    init(&minhaPilha);
    init(&minhaPilha2);

    do{
        printf("\n1 - Empilha pilha 1");
        printf("\n2 - Empilha pilha 2");
        printf("\n3 - Esvaziar pilha 1 e 2");
        printf("\n4 - Comparar pilhas");
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
                printf("\nEmpilha\n\n\tValor: ");
                scanf("%d", &valor);
                if(push(minhaPilha2, valor)){
                    printf("\nEmpilhado com sucesso\n");
                }else{
                    printf("\nEstouro de pilha\n");
                }
                break;
            
            case 3:

                if (!is_empty(minhaPilha) || !is_empty(minhaPilha2))
                {
                    printf("\nPilha 1:");
                    while (!is_empty(minhaPilha))
                    {
                        pop(minhaPilha, &valor);
                        printf("\n%d", valor);
                    }

                    printf("\n\nPilha 2:");
                    while (!is_empty(minhaPilha2))
                    {
                        pop(minhaPilha2, &valor);
                        printf("\n%d", valor);
                    }
                    
                    printf("\n\n");
                }

                break;                
            case 4:
                if (compare(minhaPilha, minhaPilha2)){
                    printf("\nPilhas iguais");
                }else{
                    printf("\nPilhas diferentes");
                }
                break;
        }
    }while(menu != 5);
    return 0;
}