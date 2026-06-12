#include <stdio.h>

int counter(void);

int main(void) {
    printf("%d\n", counter());
    printf("%d\n", counter());
    printf("%d\n", counter());
    printf("%d\n", counter());
    return 0;
}

int counter(void) {
    static  int counter = 0;
    counter++;
    return counter;
}

