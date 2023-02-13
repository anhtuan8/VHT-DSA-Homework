#include <stdio.h>

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    printf("Address of array a: %ld\n", a);
    printf("Address of a[0]: %ld\n", &a[0]);
    printf("Address of a[1]: %ld\n", &a[1]);

    int *p = a;
    printf("Value of p: %ld\n", p);
    printf("Value where p points to: %d\n", *p);

    p = p + 1;
    printf("Value of p: %ld\n", p);
    printf("Value where p points to: %d\n", *p);

    p = p - 2;
    printf("Value of p: %ld\n", p);
    printf("Value where p points to: %d\n", *p);

    *p = 100;
    printf("Value where p points to: %d\n", *p);

    return 0;
}