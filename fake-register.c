#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void set_pin(uint8_t *reg, uint8_t pin);
void clear_pin(uint8_t *reg, uint8_t pin);
void toggle_pin(uint8_t *reg, uint8_t pin);
uint8_t read_pin(uint8_t reg, uint8_t pin);

int main(void) {
    uint8_t GPIO_ODR = 0x00;
    char binary[9];

    set_pin(&GPIO_ODR, 3);
    convert_binary(GPIO_ODR, binary);
    printf("After setting pin 3:   0x%02X  %s\n", GPIO_ODR, binary);

    set_pin(&GPIO_ODR, 7);
    convert_binary(GPIO_ODR, binary);
    printf("After setting pin 7:   0x%02X  %s\n", GPIO_ODR, binary);

    clear_pin(&GPIO_ODR, 3);
    convert_binary(GPIO_ODR, binary);
    printf("After clearing pin 3:  0x%02X  %s\n", GPIO_ODR, binary);

    clear_pin(&GPIO_ODR, 7);
    convert_binary(GPIO_ODR, binary);
    printf("After clearing pin 7:  0x%02X  %s\n", GPIO_ODR, binary);

    toggle_pin(&GPIO_ODR, 7);
    convert_binary(GPIO_ODR, binary);
    printf("After toggling pin 7:  0x%02X  %s\n", GPIO_ODR, binary);

    printf("Pin 3 is: %d\n", read_pin(GPIO_ODR, 3));
    printf("Pin 7 is: %d\n", read_pin(GPIO_ODR, 7));

    return 0;
}


void set_pin(uint8_t *reg, uint8_t pin)
{
    *reg |= (1 << pin);
}

void clear_pin(uint8_t *reg, uint8_t pin)
{
    *reg &= ~(1 << pin);
}

void toggle_pin(uint8_t *reg, uint8_t pin)
{
    *reg ^= (1 << pin); 
}

uint8_t read_pin(uint8_t reg, uint8_t pin)
{
    uint8_t bit = (reg >> pin) & 1;
    return bit;

}

void convert_binary(uint8_t reg, char *binary)
{
    int binary_index = 0;
    for(int i = 7; i >= 0; i--) 
    {
        char bit = (reg >> i) & 1 ? '1' : '0';
        binary[binary_index] = bit;
        binary_index++;
    }
    binary[binary_index] = '\0';
}