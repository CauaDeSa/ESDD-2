#include <stdio.h>
#include "functions.h"

int main(){
    int command = 6;

    do
    {
        switch (command)
        {
        case 1:
            setArchive();
            break;
        
        case 2:
            setSecondArchive();
            break;

        case 3:
            getBinarys();
            break;

        case 4:
            getDecimal();
            break;

        case 5:
            getSum();
            break;

        default:
            break;
        }
        
        command = getCommand();

        system("cls"); 

    } while (command != 0);

    return 0;
}