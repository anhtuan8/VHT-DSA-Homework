#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p = (int*) malloc(5 * sizeof(int));
    printf("Address of p: %ld\n", &p);
    printf("Value of p: %ld\n", p);

    for (int i = 0; i < 5; i++)
    {
        *p = i + 1;
        p = p + 1;
    }
    p -= 5;

    for (int i = 0; i < 5; i++)
    {
        printf("Value of p[%d]: %d\n", i, p[i]);
    }

    free(p);
    return 0;
}