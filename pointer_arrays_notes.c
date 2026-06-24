#include <stdint.h>

int main(void) 
{

    int arr[3] = {1,2,3};
    // array name is like a pointer for a first element
    arr; 
    //assigning it to pointer is valid
    int *p = arr;

    for (int i; i < 3; i++)
    {
        //indexing is with pointer
        arr[i]; // == *(arr + i) also returns value of i element
        
        // both pointer an array are same holding memory and then pointing to an element
        arr[i] = *(arr + i);
        p[i] = *(p + i);

        //both valid increments the pointer 
        //to new memory address
        p--;
        p++;
    }

    //EMBEDDED USAGE:

    //1. UART message
    uint8_t buffer[] = {0x01, 0x03,  0x48, 0x6c};
    uint8_t *p = buffer;

    uint8_t device_id = *p++;
    uint8_t command   = *p++;   // read 0x03, move to next
    uint8_t data1     = *p++;   // read 0x48, move to next
    uint8_t data2     = *p++;   // read 0x65, move to next
    uint8_t data3     = *p++;   // read 0x6C, move to next

    //SAME RESULT with using indexing with array:
    uint8_t device_id = buffer[0];
    uint8_t command   = buffer[1];
    uint8_t data1     = buffer[2];
    uint8_t data2     = buffer[3];
    uint8_t data3     = buffer[4];

    //2 Stepping through hardware-filled regions
    // say DMA fills a region of memory with 16-bit sensor readings:
    // Memory filled by hardware:
    // Address:  0x1000  0x1002  0x1004  0x1006
    // Data:     [00 2A] [01 F4] [00 8C] [03 E8]
    //        reading1 reading2 reading3 reading4
    //        (42)     (500)    (140)    (1000)

    uint16_t *p = (uint16_t *)0x1000;

    *p++;   // reads 0x002A (42)   from 0x1000, jumps to 0x1002
    *p++;   // reads 0x01F4 (500)  from 0x1002, jumps to 0x1004
    *p++;   // reads 0x008C (140)  from 0x1004, jumps to 0x1006

    // indexing — same result
    p[0];
    p[1];
    p[2];
}