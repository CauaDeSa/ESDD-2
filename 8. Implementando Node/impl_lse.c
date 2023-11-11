#include "lse.h"

struct node{
    /* Informação que é armazenada no node.*/
    Typeinfo info;
    Node next;
    /* Outra forma de representar */
    // struct node* next;
};

struct lse{
    /* Ponteiro para o primeiro Node da lista*/
    Node head;
};

/* Inicializa lista, a passando como argumento. */
void init_list(List *list){
    *list = malloc(sizeof(struct lse)); 
    (*list)->head = NULL;
}

/* Outra forma de inicializar, retornando o endereço alocado para a lista. */
// List init_list(){

//     List ptr = malloc(sizeof(struct lse));
//     ptr->head = NULL;

//     return ptr;
// }

bool is_empty_list(List list){
    return list->head == NULL;
}

void insert_end_list(List list, Typeinfo new_info){
    if (list != NULL)
    {
        /* Cria novo nó. */
        Node new_node = malloc(sizeof(struct node));

        /* Inicializa os valores do novo nó. */
        new_node->next = NULL;
        new_node->info = new_info;

        /* Se lista é vazia, head aponta para o novo nó.*/
        if (list->head == NULL){
            list->head = new_node;
        }
        /* Se não for vazia, encontra o último elemento da lista, que receberá o endereço do novo nó. */
        else{
            Node jhonny_walker = list->head;

            /* Caminha até o último nó.*/
            while (jhonny_walker->next != NULL)
            {
                jhonny_walker = jhonny_walker->next;
            }

            jhonny_walker->next = new_node;

            /* Com recursividade. */ 
            // Node last_node = findLastNode(list->head);
            // last_node->next = new_node;

            // last_node = list->head;

            // while(last_node->next != NULL){
            //     printf("%d ", last_node->info);
            //     last_node = last_node->next;
            // }
            
            // if (last_node->next == NULL)
            // {
            //     printf("%d ", last_node->info);
            // }
        }
    }
}

/* Função recursiva */
// Node findLastNode(Node current){
//     if (current->next == NULL){
//         return current;
//     }
//     else{
//         return findLastNode(current->next);
//     }
// }

/* Função recursiva */
// Node findLastAndPreviousNode(Node current, Node stalker){
//     if (current->next == NULL){
//         return current;
//     }
//     else{
//         stalker = current;
//         return findLastNode(current->next);
//     }
// }

void insert_begin_list(List list, Typeinfo new_info){
    
    if (list != NULL)
    {
        Node new_node = malloc(sizeof(struct node));

        new_node->next = list->head;
        new_node->info = new_info;
        list->head = new_node;
    }
}

void destroy_list(List* list){
    if ( *list != NULL)
    {
        /* Se lista possuir elementos, destrói um a um. */
        if ((*list)->head != NULL)
        {
            Node rip;
            Node jhonny_walker;

            rip = (*list)->head;

            while (rip->next != NULL)
            {
                jhonny_walker = rip->next;
                free(rip);
                rip = jhonny_walker;
            }
            free(rip);
        }
        
        /* Lista sem nodes, apenas libera a lista. */
        free(*list);
        *list = NULL;
    }
}

Typeinfo delete_begin(List list){
    Typeinfo nodeInfo;

    if (list != NULL)
    {
        if (list->head != NULL)
        {
            Node rip = list->head;
            nodeInfo = list->head->info;

            /* De outra maneira. */
            //nodeInfo = rip->info;
               
            list->head = rip->next;
            free(rip);
        }
    }

    return nodeInfo;
}

Typeinfo delete_end_list(List list){
    Typeinfo nodeInfo;

    if (list != NULL)
    {
        if (list->head != NULL)
        {
            Node rip = list->head;
            Node stalker = NULL;

            while (rip->next != NULL)
            {
                stalker = rip;
                rip = rip->next;
            }
            
            nodeInfo = rip->info;
            free(rip);

            if (stalker == NULL){
                list->head = NULL;
            }
            else{
                stalker->next = NULL;
            }
        }
    }

    /* Função recursiva */
    // Node stalker = list->head;
    // Node rip = findLastAndPreviousNode(Node current, Node stalker)
    // 
    // nodeInfo = rip->info;
    // free(rip);
    // stalker->next = NULL;

    return nodeInfo;
}

void insert_ascendant_list(List list, Typeinfo new_info){
    if (list != NULL)
    {
        Node new_node = malloc(sizeof(struct node));
        new_node->info = new_info;
        
        /* Se lista está vazia, head recebe novo nó. */
        if (list->head == NULL)
        {
            list->head = new_node;
            new_node->next = NULL;
        }
        else{
            Node jhonny_walker = list->head;
            Node stalker = NULL;

            while (jhonny_walker->info < new_node->info && jhonny_walker->next != NULL)
            {
                stalker = jhonny_walker;
                jhonny_walker = jhonny_walker->next;
            }

            /* Novo nó é menor que walker. */
            if (jhonny_walker->info > new_info)
            {
                /* Insere no início da lista. */
                if (stalker == NULL){
                    list->head = new_node;
                }
                /* Insere no meio da lista. */
                else{
                    stalker->next = new_node;
                }
                
                new_node->next = jhonny_walker;
            }       
            /* Novo nó é maior que walker */
            else{
                /* Insere no fim da lista. */
                jhonny_walker->next = new_node;
                new_node->next = NULL;
            }
        }
    }   
}

Typeinfo delete_at_list(List list, int position){
    Typeinfo info;

    if (list != NULL)
    {
        if (list->head != NULL){
            Node walker = list->head;
            Node stalker = NULL;
            int count = 0;

            while (walker->next != NULL && count < position)
            {
                stalker = walker;
                walker = walker->next;
                count++;
            }

            /* Achou a posição. */
            if (count == position)
            {
                info = walker->info;

                if (stalker == NULL)
                {
                    list->head = walker->next;
                }
                else{
                    stalker->next = walker->next;
                }
                
                free(walker);
            }
            
        }
    }

    return info;
}