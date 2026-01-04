#include <stdio.h>

int done[10] = {0};
int graph[10][10] = {
    {0, 1, 0, 0, 0}, 
    {1, 0, 1, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1}, 
    {0, 0, 0, 1, 0}
};

void search(int node, int total) {
    done[node] = 1;
    printf("%d ", node);
    for (int j = 0; j < total; j++) {
        if (graph[node][j] == 1 && done[j] == 0) {
            search(j, total);
        }
    }
}

int main() {
    int i;
    printf("Nodes in each cluster:\n");
    for (i = 0; i < 5; i++) {
        if (done[i] == 0) {
            printf("Group: ");
            search(i, 5);
            printf("\n");
        }
    }
    return 0;
}
