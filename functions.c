#include <stdlib.h>
#include <string.h>
#include <stdio.h> 

typedef struct {
    char *sauce;
    char *dough;
    char *cheese; 
} Pizza;    


Pizza *getPizzas(int quantity);
int max(int a, int b);
void greet(void);
int factorial(int n);


int main() {
    greet();
    int max_number = max(2, 3);
    printf("max of 7 and 3 is %d\n", max_number);
    printf("5! is %d\n", factorial(5));
    return 0;
}

int max(int a, int b) {

    if (a > b) 
    {
        return a;
    } else {
        return b;
    }
}

void greet(void) {
    printf("Hello, embedded!\n");
}

int factorial(int n) {
    int result = 1;

    do {
        result *= n;
        n--;

    } while (n != 1);
   return result;
}




 Pizza *getPizzas(int quantity) {
    
    Pizza *pizzas = malloc(quantity * sizeof(Pizza));
     
    for (int i = 0; i < quantity; i++){
            Pizza pizza;
            pizza.cheese = "parmesan";
            pizza.sauce = "banana ketchup";     
            pizza.dough = "nomal dough";

        pizzas[i] = pizza;
    }
    return pizzas;
}

