#include <stdint.h>

uint32_t extract_field(uint32_t reg, uint8_t start_bit, uint8_t width);
insert_field(uint32_t reg, uint8_t start, uint8_t width, uint32_t value);

int main(){

    return 0;
}

uint32_t extract_field(uint32_t reg, uint8_t start_bit, uint8_t width) 
{
    uint32_t field = (reg >> start_bit)  & (1 << width) - 1;
    return field;
}

insert_field(uint32_t reg, uint8_t start, uint8_t width, uint32_t value) 
{ 
    uint32_t reg_clear = reg & ((1 << width) - 1) << (start + 1);
    reg = reg_clear | value << start;
}
