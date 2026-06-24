#include <stdio.h>

int main(void) 
{
    int num[5] = {10, 20, 30, 40, 50};
    int *p = num;
    for(int i = 0; i < 5; i++)
    {
        printf("value of nums[i] is %d  and value of *(num + i) is %d\n",num[i], *(num + i));
        printf("*p is %d\n", *p);
        p++;
        printf("memory address is: %p\n",num + i);
    }

}