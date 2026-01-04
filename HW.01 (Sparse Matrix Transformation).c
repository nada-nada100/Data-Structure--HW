#include <stdio.h>

void makeSparse(int m[4][4]) {
    int s[15][3];
    int n = 1;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (m[i][j] != 0) {
                s[n][0] = i;
                s[n][1] = j;
                s[n][2] = m[i][j];
                n++;
            }
        }
    }

    s[0][0] = 4;
    s[0][1] = 4;
    s[0][2] = n - 1;

    printf("R   C   V\n");
    for (int i = 0; i < n; i++) {
        printf("%d   %d   %d\n", s[i][0], s[i][1], s[i][2]);
    }
}

int main() {
    int data[4][4] = {
        {0, 7, 0, 0},
        {0, 0, 0, 4},
        {6, 0, 0, 0},
        {0, 0, 9, 0}
    };

    makeSparse(data);
    return 0;
}
