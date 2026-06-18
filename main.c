#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* esquerda;
    struct Node* direita;
    
    int val;
} Node;

Node* addNode(int val){
    Node* novoNode = (Node*) malloc(sizeof(Node));
    
    novoNode->val = val;
    novoNode->esquerda = NULL;
    novoNode->direita = NULL;

    return novoNode;
}

Node* reconstruct(char* str, int* i){
    
}




int main(){

    return 0;
}