#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b)
{
    printf("Value of a: %ld\n", a);
    printf("Value of b: %ld\n", b);
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("In swap: a = %d, b = %d\n", *a, *b);
}

int main()
{
    int a = 10;
    int b = 20;
    printf("Address of a: %ld\n", &a);
    printf("Address of b: %ld\n", &b);

    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);
}