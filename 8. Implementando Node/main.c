#include "lse.h"

int main()
{
    List list;
    
    init_list(&list);
    // list = init_list();

    // insert_end_list(list, 10);
    // insert_end_list(list, 20);
    // insert_end_list(list, 30);

    // insert_begin_list(list, 40);
    
    insert_ascendant_list(list, 3);
    insert_ascendant_list(list, 1);
    insert_ascendant_list(list, 2);
    insert_ascendant_list(list, 0);

    printf("Apagado posição 2: %d\n\n", delete_at_list(list, 1));

    while(!is_empty_list(list)){
        printf("%d, ", delete_begin(list));
        // printf("%d, ", delete_end_list(list));
    }

    return 0;
}