#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

char* binary_representation(uint8_t value);

int main() {
    char *result = binary_representation(179);
    printf("%s", result); 
    free(result);
    
}

char *binary_representation(uint8_t value) 
{

    char *result =  malloc(9);
    int string_index = 0;
    for (int i = 7; i >= 0; i--) 
    {
        char bit = (value >> i) & 1 ? '1' : '0';
        result[string_index] = bit;
        string_index++;
    }   

    result[string_index] = '\0';

    return result; 
}