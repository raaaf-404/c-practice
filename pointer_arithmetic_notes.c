int main(void) 
{

    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr;

    // instead of using an index:
    for (int i = 0; i < 5; i++) 
    {
        printf("%d\n", arr[i]);
    }

    // you can use pointer comparison:
    for (int *p = arr; p < arr + 5; p++)  
    {
         printf("%d\n", *p);
    }
}