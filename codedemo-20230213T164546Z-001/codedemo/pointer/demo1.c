#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;

    printf("Address of a: %ld\n", &a);
    printf("Address of b: %ld\n", &b);

    int *p = &a;
    printf("Value of p: %ld\n", p);
    printf("Address of p: %ld\n", &p);

    *p = 100;
    printf("Value of a: %d\n", a);
    printf("Value where p points to: %d\n", *p);
    
    return 0;
}