#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* esquerda;
    struct Node* direita;
    
    int val;
} Node;

int contagemL(Node* root, int l){
    if (root == NULL){
        return 0;
    }
    else if (l == 0){
        return 1;
    }

    return contagemL(root->esquerda, l - 1) + contagemL(root->direita, l-1);
}


int main(){

    return 0;
}