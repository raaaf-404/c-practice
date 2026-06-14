#include <stdio.h>

int main() 
{
    int x = 7;
    int *p = NULL;


    if (p != NULL) 
        printf("%d\n", *p);
    else
        printf("empty\n");

    return 0;
}