#include <stdio.h>
#include <stdlib.h>

/*
    Binary Tree Structure:
          10         
        /    \
       20     30       
      / \    / \
     40  50 60  70     
*/

struct node {
    int val;
    struct node *L;
    struct node *R;
};

// function to create a new node
struct node* build(int d) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->val = d;
    n->L = NULL;
    n->R = NULL;
    return n;
}

// Pre-order traversal: Root -> Left -> Right
void pre_order(struct node* root) {
    if (root == NULL) return;
    
    printf("%d ", root->val);
    pre_order(root->L);
    pre_order(root->R);
}

int main() {
    // Creating the root and branches
    struct node* root = build(10);

    root->L = build(20);
    root->L->L = build(40);
    root->L->R = build(50);

    root->R = build(30);
    root->R->L = build(60);
    root->R->R = build(70);

    printf("Pre-order: ");
    pre_order(root);

    return 0;
}
