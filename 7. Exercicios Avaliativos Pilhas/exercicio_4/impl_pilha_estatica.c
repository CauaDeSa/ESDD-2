#include "pilha.h"

struct stack
{
	Tipo_Informacao itens[MAX_STACK_SIZE];
	int topo;
	int base;
	int size;
	char operator;
};

void init(Pilha *pilha)
{
	*pilha = malloc(sizeof(struct stack));

	if (*pilha != NULL)
	{
		(*pilha)->topo = -1;
		(*pilha)->size = 0;
		(*pilha)->base = 0;
		(*pilha)->operator= '+';
	}
}

bool is_full(Pilha pilha)
{

	if (pilha->size == MAX_STACK_SIZE - 1){
		return true;
	}
	else{
		return false;
	}
}

bool is_empty(Pilha pilha)
{

	return pilha->size == 0 ? true : false;
}

bool push(Pilha pilha, Tipo_Informacao elemento)
{
	bool deuCerto = false;

	if (pilha != NULL)
	{
		if (!is_full(pilha))
		{
			if (pilha->operator == '+')
			{
				if (pilha->topo == MAX_STACK_SIZE - 1){
					pilha->topo = 0;
				}
				else{
					pilha->topo++;
				}

				pilha->itens[pilha->topo] = elemento;
				deuCerto = true;
				pilha->size++;
			}

			else{
				if (pilha->topo == 0){
					pilha->topo = MAX_STACK_SIZE - 1;
				}
				else{
					pilha->topo--;
				}

				pilha->itens[pilha->topo] = elemento;
				deuCerto = true;
				pilha->size++;
			}
			
		}
	}

	return deuCerto;
}

bool pop(Pilha pilha, Tipo_Informacao *elemento)
{
	bool deuCerto = false;

	if (pilha != NULL)
	{
		if (!is_empty(pilha))
		{
			if (pilha->operator == '+')
			{
				*elemento = pilha->itens[pilha->topo];
				deuCerto = true;
				pilha->size--;
				
				if (pilha->topo == 0){
					pilha->topo = MAX_STACK_SIZE - 1;
				}
				else{
					pilha->topo--;
				}
			}

			else{
				*elemento = pilha->itens[pilha->topo];
				deuCerto = true;
				pilha->size--;
				
				if (pilha->topo == MAX_STACK_SIZE - 1){
					pilha->topo = 0;
				}
				else{
					pilha->topo++;
				}
			}
		}
	}

	return deuCerto;
}

bool invert(Pilha pilha){
	int aux;

	if (pilha->operator == '+'){
		pilha->operator = '-';
	}
	else{
		pilha->operator = '+';
	}

	aux = pilha->base;
	pilha->base = pilha->topo;
	pilha->topo = aux;
}