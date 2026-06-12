#include <stdio.h>

int main(void) {
    int memory[16];

    memory[4] = 65;
    memory[5] = 3;

    for (int i = 0; i < 16; i++) {
        printf("Value at memory[%d]: %d\n", i, memory[i]);
    }

    return 0;
}