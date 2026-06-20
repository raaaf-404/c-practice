#include <stdio.h>

void add_one_bad(int n);
void add_one_good(int *n);
void swap(int *a, int *b);

int main(void) 
{
    int v = 10;
    int n1 = 3;
    int n2 = 12;

    add_one_bad(v);
    printf("%d\n", v);
    add_one_good(&v);
    printf("%d\n", v);
    
    printf("before swap n1 = %d and n2 = %d\n", n1, n2);
    swap(&n1, &n2);
    printf("after swap n1 = %d and n2 = %d\n", n1, n2);
}

void add_one_bad(int n) 
{
    n = n + 1;
    return 0;
}

void add_one_good(int *n) 
{
    *n = *n + 1;
    return 0;
}

void swap(int *a, int *b) 
{
    int holder = *a;
    *a = *b;
    *b = holder; 
}