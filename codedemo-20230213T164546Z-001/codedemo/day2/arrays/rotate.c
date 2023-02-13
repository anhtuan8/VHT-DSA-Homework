#include <stdio.h>
#include <stdlib.h>

void rotate_right_once(int a[], int n) {
    int i, temp;
    temp = a[n - 1];
    for (i = n - 1; i > 0; i--) {
        a[i] = a[i - 1];
    }
    a[0] = temp;
}
void print_array(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}
void rotate_right(int a[], int n, int k) {
    k = k % n;
    int i;
    for (i = 0; i < k; i++) {
        rotate_right_once(a, n);
    }
}

void rotate_right_temp(int a[], int n, int k) {
    int temp[n];
    // copy the 1st n - k elements to temp
    int i;
    for (i = 0; i < n - k; i++) {
        temp[i+k] = a[i];
    }
    // copy the last k elements to temp
    for (i = n - k; i < n; i++) {
        temp[i - n + k] = a[i];
    }
    // copy temp to a
    for (i = 0; i < n; i++) {
        a[i] = temp[i];
    }
}

int main(int argc, char *argv[]) {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    rotate_right_temp(a, 10, 3);
    print_array(a, 10);
}