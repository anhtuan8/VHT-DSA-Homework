#include <stdio.h>
#include <stdlib.h>

void print_array(int *p, const int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
}

int* create_array(const int n)
{
    int *p = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
    }
    print_array(p, n);
    return p;
}

int main()
{
    int n = 5;
    int *p = create_array(n);
    print_array(p, n);
    free(p);
    return 0;
}