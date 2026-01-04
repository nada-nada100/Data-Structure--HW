#include <stdio.h>

int matrix[5][5] = {
    {0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 1, 0, 1},
    {0, 0, 0, 1, 0}
};
int seen[5];

void do_dfs(int s, int n) {
    seen[s] = 1;
    printf("%d ", s);
    int i;
    for (i = 0; i < n; i++) {
        if (matrix[s][i] == 1 && seen[i] == 0) {
            do_dfs(i, n);
        }
    }
}

void do_bfs(int s, int n) {
    int q[10], f = 0, r = 0;
    int v_bfs[5] = {0};

    v_bfs[s] = 1;
    q[r++] = s;

    while (f < r) {
        int curr = q[f++];
        printf("%d ", curr);

        int i;
        for (i = 0; i < n; i++) {
            if (matrix[curr][i] == 1 && v_bfs[i] == 0) {
                v_bfs[i] = 1;
                q[r++] = i;
            }
        }
    }
}

int main() {
    int i;
    for(i = 0; i < 5; i++) seen[i] = 0;
    
    printf("DFS Result: ");
    do_dfs(0, 5);

    printf("\nBFS Result: ");
    do_bfs(0, 5);

    return 0;
}
