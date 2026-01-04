#include <stdio.h>

void swap_elements(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void max_h(int a[], int n, int i) {
    int big = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[big]) big = l;
    if (r < n && a[r] > a[big]) big = r;

    if (big != i) {
        swap_elements(&a[i], &a[big]);
        max_h(a, n, big);
    }
}

void min_h(int a[], int n, int i) {
    int small = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] < a[small]) small = l;
    if (r < n && a[r] < a[small]) small = r;

    if (small != i) {
        swap_elements(&a[i], &a[small]);
        min_h(a, n, small);
    }
}

int main() {
    int arr1[] = {20, 15, 30, 10, 12, 25};
    int size = 6;

    for (int i = size / 2 - 1; i >= 0; i--) max_h(arr1, size, i);
    
    printf("Max Heap: ");
    for (int i = 0; i < size; i++) printf("%d ", arr1[i]);
    printf("\n");

    int arr2[] = {20, 15, 30, 10, 12, 25};
    for (int i = size / 2 - 1; i >= 0; i--) min_h(arr2, size, i);

    printf("Min Heap: ");
    for (int i = 0; i < size; i++) printf("%d ", arr2[i]);
    printf("\n");

    return 0;
}
