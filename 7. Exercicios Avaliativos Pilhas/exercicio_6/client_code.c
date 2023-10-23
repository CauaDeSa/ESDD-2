#include "pilha.h"

bool verify(Pilha minhaPilha);

int main(int argc, char **argv)
{
    Pilha minhaPilha;
    int menu, i;
    Tipo_Informacao string[MAX_STACK_SIZE], caractere;

    init(&minhaPilha);

    do
    {
        printf("\n1 - Ler");
        printf("\n2 - Verificar");
        printf("\n3 - Apagar");
        printf("\n4 - Sair");
        printf("\nOpcao: ");

        scanf("%d", &menu);
        fflush(stdin);

        switch (menu)
        {
        case 1:
            printf("Digite a expressao:");
            fgets(string, MAX_STACK_SIZE, stdin);

            for (i = 0; i < strlen(string); i++)
            {
                if (string[i] != ' ' && string[i] != '\n')
                    push(minhaPilha, string[i]);
            }
            break;
        case 2:
            if (verify(minhaPilha))
            {
                printf("\nExpressão valida");
            }
            else
            {
                printf("\nExpressão invalida");
            }
            break;
        case 3:
            while (!is_empty(minhaPilha))
            {
                pop(minhaPilha, &caractere);
                printf("\ncaractere: %c", caractere);
            }
            break;
        }
    } while (menu != 4);
    return 0;
}

bool verify(Pilha minhaPilha)
{
    char element, archiveAux[MAX_STACK_SIZE];
    int i = -1, j;
    bool parenteses, colchetes, chaves;
    bool isValid = true;

    parenteses = colchetes = chaves = false;

    while (pop(minhaPilha, &element))
    {
        archiveAux[++i] = element;
    }

    j = ++i;

    printf("%c", archiveAux[0]);

    while (i-- > 0)
    {
        printf("\nCaractere: %c", archiveAux[i]);

        if (archiveAux[i] == '{' || archiveAux[i] == '[' || archiveAux[i] == '(')
        {
            switch (archiveAux[i])
            {
            case '{':
                if (chaves)
                    isValid = false;
                
                chaves = true;
                break;

            case '[':
                if (colchetes)
                    isValid = false;

                colchetes = true;
                break;

            case '(':
                if (parenteses)
                    isValid = false;
                    
                parenteses = true;
                break;

            default:
                break;
            }
        }

        else
        {
            if (archiveAux[i] == '}' || archiveAux[i] == ']' || archiveAux[i] == ')')
            {
                if (archiveAux[i] == ')' && parenteses == true)
                {
                    parenteses = false;
                }

                else
                {
                    if (archiveAux[i] == ']' && colchetes == true && parenteses != true)
                    {
                        colchetes = false;
                    }

                    else
                    {
                        if (archiveAux[i] == '}' && chaves == true && colchetes != true && parenteses != true)
                        {    
                            chaves = false;
                        }
                    }
                }
            }
        }
    }

    while (j-- > 0)
    {
        push(minhaPilha, archiveAux[j]);
    }

    return isValid == true && parenteses == false && colchetes == false && chaves == false;
}