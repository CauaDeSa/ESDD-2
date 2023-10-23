#include "pilha.h"

struct stack{
    Tipo_Informacao itens[MAX_STACK_SIZE];
    int topo;
};


void init(Pilha* pilha){

	*pilha = malloc(sizeof(struct stack));

	if(*pilha != NULL){
		(*pilha)->topo = -1;
	}
}

bool is_full(Pilha pilha){
	
	if(pilha->topo == MAX_STACK_SIZE - 1){
		return true;
    }else{
	    return false;
    }
}

bool is_empty(Pilha pilha){
	
    return pilha->topo == -1 ? true : false;

}

bool push(Pilha pilha, Tipo_Informacao elemento){
	bool deuCerto = false;

	if( pilha != NULL ){
		if( ! is_full(pilha) ){
            pilha->topo += 1;
            pilha->itens[pilha->topo] = elemento;
			deuCerto = true;
		}
	}

	return deuCerto;
}

bool pop(Pilha pilha, Tipo_Informacao* elemento){
	bool deuCerto = false;

	if( pilha != NULL ){
		if( ! is_empty(pilha) ){
			*elemento = pilha->itens[pilha->topo];
			pilha->topo -= 1;
			deuCerto = true;
		}
	}

	return deuCerto;
}

bool compare(Pilha pilha1, Pilha pilha2){
	int  valueAux, archiveAux[MAX_STACK_SIZE], i = 0, size;
	bool isEqual = true;
	
	size = (pilha1->topo == pilha2->topo) ? pilha1->topo : 0;

	if (size != 0)
	{
		while (i <= size && isEqual)
		{
			pop(pilha1, &archiveAux[i]);
			pop(pilha2, &valueAux);

			if (archiveAux[i] != valueAux){
				push(pilha1, archiveAux[i]);
				push(pilha2, valueAux);
				isEqual = false;
			}
			else{
				i++;
			}
		}	

		while (i-- > 0)
		{
			push(pilha1, archiveAux[i]);
			push(pilha2, archiveAux[i]);
		}
	}
	else{
		isEqual = false;
	}
	
	return isEqual;
}