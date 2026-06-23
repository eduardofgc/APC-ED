#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* esquerda;
    struct Node* direita;
    
    char c;
} Node;

Node* criaNode(char letra){
    Node* novoNode = (Node*) malloc(sizeof(Node));
    novoNode->c = letra;
    novoNode->esquerda = NULL;
    novoNode->direita = NULL;

    return novoNode;
}

Node* recuperaArvore(char* string, int* array){
    if (string[*array] == '\0'){
        return NULL;
    }

    Node* raiz = criaNode(string[*array]);

    if (string[*array] == '('){
        (*array)++;

        raiz->esquerda = recuperaArvore(string, array);

        if (string[*array] == ','){
            (*array)++;

            raiz->direita = recuperaArvore(string, array);
        }

        if (string[*array] == ')'){
            (*array)++;
        }
    }

    return raiz;
}

int main(){
    int i = 0;
    Node* root = recuperaArvore("A(B(D,E),C(F,G))", &i);
    return 0;
}