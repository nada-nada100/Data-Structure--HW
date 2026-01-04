#include <stdio.h>

void hanoi(int num, char start, char end, char mid) {
    if (num == 1) {
        printf("Disk 1: %c -> %c\n", start, end);
        return;
    }

    hanoi(num - 1, start, mid, end);
    printf("Disk %d: %c -> %c\n", num, start, end);
    hanoi(num - 1, mid, end, start);
}

int main() {
    int disks = 3;

    printf("Hanoi Solution for %d disks:\n", disks);
    hanoi(disks, 'X', 'Z', 'Y');

    return 0;
}
