#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* addNode(int val){
    Node* node = (Node*)malloc(sizeof(Node));

    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* insertNode(Node* root, int val){
    if (root == NULL) return addNode(val);

    if (val < root->val){
        root->left = insertNode(root->left, val);
    }
    else{
        root->right = insertNode(root->right, val);
    }
    
    return root;
}

void posOrdem(Node* root) {
    if (root == NULL) return;

    posOrdem(root->left);
    posOrdem(root->right);
    printf("%d ", root->val);
}

int main() {
    int n;
    scanf("%d", &n);

    Node* root = NULL;

    for (int i = 0; i < n; i++){
        int val;
        scanf("%d", &val);
        root = insertNode(root, val);
    }

    posOrdem(root);
    printf("\n");

    return 0;
}