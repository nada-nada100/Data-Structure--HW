#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *nxt, *prv;
};

struct Node* add_node(int d) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = d;
    n->nxt = n->prv = NULL;
    return n;
}

void insert(struct Node** h, int d, int p) {
    struct Node* n = add_node(d);
    if (p == 0) {
        n->nxt = *h;
        if (*h != NULL) (*h)->prv = n;
        *h = n;
        return;
    }
    struct Node* t = *h;
    for (int i = 0; i < p - 1 && t != NULL; i++) t = t->nxt;
    if (!t) return;
    n->nxt = t->nxt;
    n->prv = t;
    if (t->nxt) t->nxt->prv = n;
    t->nxt = n;
}

void remove_node(struct Node** h, int p) {
    if (!*h) return;
    struct Node* t = *h;
    if (p == 0) {
        *h = t->nxt;
        if (*h) (*h)->prv = NULL;
        free(t);
        return;
    }
    for (int i = 0; i < p && t != NULL; i++) t = t->nxt;
    if (!t) return;
    if (t->nxt) t->nxt->prv = t->prv;
    if (t->prv) t->prv->nxt = t->nxt;
    free(t);
}

void show(struct Node* h) {
    while (h) {
        printf("%d ", h->val);
        h = h->nxt;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insert(&head, 5, 0);
    insert(&head, 15, 1);
    insert(&head, 25, 2);
    show(head);
    remove_node(&head, 1);
    show(head);
    return 0;
}
