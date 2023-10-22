#include <stdio.h>
#include <stdlib.h>
#include "declarations.h"

int main()
{
    int *a, *b, *c;

    createAdress(&a, &b, &c);

    getData(&a, &b, &c);

    getResult(&a, &b, &c);

    showResult(&a, &b, &c);

    return 0;
}
