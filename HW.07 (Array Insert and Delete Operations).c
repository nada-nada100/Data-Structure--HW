#include <stdio.h>

int add_element(int a[], int n, int pos, int val) {
    int i;
    for (i = n; i > pos; i--) {
        a[i] = a[i - 1];
    }
    a[pos] = val;
    return n + 1;
}

int del_element(int a[], int n, int pos) {
    int item = a[pos];
    int i;
    for (i = pos; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    printf("Item %d removed\n", item);
    return n - 1;
}

int find_element(int a[], int n, int target) {
    int i;
    for (i = 0; i < n; i++) {
        if (a[i] == target) return i;
    }
    return -1;
}

int main() {
    int my_array[100] = {5, 15, 25, 35, 45};
    int count = 5;

    count = add_element(my_array, count, 2, 77);
    
    int index = find_element(my_array, count, 77);
    if (index != -1) printf("77 found at index %d\n", index);

    count = del_element(my_array, count, 2);

    printf("Final Array: ");
    int i;
    for (i = 0; i < count; i++) printf("%d ", my_array[i]);
    printf("\n");

    return 0;
}
