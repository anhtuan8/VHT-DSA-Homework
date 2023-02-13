#include <stdio.h>
#include <stdlib.h>


void print_array(int a[], const int n)
{
    printf("Value of array: %ld\n", a);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void double_array(int *a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] *= 2;
    }
}

int create_int(const int n)
{
    int a = n * 2;
    return a;
}

int* create_array(const int n)
{
    int a[n];
    printf("Value of array (create_array): %ld\n", a);
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    printf("Inside create_array: \n");
    print_array(a, n);
    return a;
}

int main()
{
    // int a[5] = {1, 2, 3, 4, 5};
    // print_array(a, 5);

    // int *p = (int*) malloc(5 * sizeof(int));
    // for (int i = 0; i < 5; i++)
    // {
    //     p[i] = i + 1;
    // }

    // print_array(p, 5);
    // double_array(p, 5);
    // print_array(p, 5);

    // free(p);
    int n = 5;
    int a = create_int(n);
    printf("Value of a: %d\n", a);

    int *p = create_array(n);
    printf("Value of array (main): %ld\n", p);
    printf("Inside main: \n");
    print_array(p, n);

    return 0;
}