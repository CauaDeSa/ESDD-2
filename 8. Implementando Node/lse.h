#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Ponteiro para struct node. */
typedef struct node* Node;

/* Ponteiro para a struct lse, que contém o ponteiro (Head) para o primeiro Node da lista. */
typedef struct lse* List;

/* Definindo o tipo de dado que será utilizado. */
typedef int Typeinfo;

/* Alocar endereço de memória para a lista. */
void init_list(List* list);

/* Desalocar o endereço de memória da lista. */
void destroy_list(List* list);

/* Verifica se lista está vazia. */
bool is_empty_list(List list);

/* Inserir elemento na última posição da lista. */
void insert_end_list(List list, Typeinfo new_info);

/* Função recursiva. */
// Node findLastNode(Node current);

/* Função recursiva. */
// Node findLastAndPreviousNode(Node current, Node stalker);

/* Insere elementos no início da fila. */
void insert_begin_list(List list, Typeinfo new_info);

/* Remove nó e o retorna, partindo do começo para o fim. */
Typeinfo delete_begin(List list);

/* Remove o último elemento da lista */
Typeinfo delete_end_list(List list);

/* Insere ordenadamente os elementos na lista. */
void insert_ascendant_list(List list, Typeinfo new_info);

/* Remove elemento na posição indicada. */
Typeinfo delete_at_list(List list, int position);