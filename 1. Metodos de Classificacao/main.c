#include <stdio.h>
#include "uteis.h"
#include <time.h>       
#include <unistd.h> 
#include <stdlib.h>
#define MAX 1000000

int arquivo[MAX], arquivoAux[MAX];

int main(){
    int choose, length;
    int comparationsChanges[2];

    choose = getCase();
    
    while ((choose >= 1) && (choose <= 9))
    {        
        length = defineLength(choose);

        defineArray(choose, arquivo, length);

        getSortResult(1, arquivo, arquivoAux, length, comparationsChanges);

        getSortResult(2, arquivo, arquivoAux, length, comparationsChanges);

        getSortResult(3, arquivo, arquivoAux, length, comparationsChanges);

        getSortResult(4, arquivo, arquivoAux, length, comparationsChanges);

        getSortResult(5, arquivo, arquivoAux, length, comparationsChanges);
    
        choose = getCase();
    }
}