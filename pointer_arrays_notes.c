

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

        //both valid
        p--;
        p++;
    }

}