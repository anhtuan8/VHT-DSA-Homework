#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i, j, temp;
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (i = 0, j = 9; i < j; i++, j--) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    for (i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
}