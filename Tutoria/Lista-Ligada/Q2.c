#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* direita;
    struct Node* abaixo;

    int val;
    int x;
    int y;
} Node;

typedef struct Matriz{
    Node* inicio;

    int linhas;
    int colunas;
} Matriz;

Matriz* criaMatriz(int linhas, int colunas){
    Matriz* novaMatriz = (Matriz*) malloc(sizeof(Matriz));
    novaMatriz->inicio = NULL;
    novaMatriz->linhas = linhas;
    novaMatriz->colunas = colunas;

    return novaMatriz;
}

Node* acessarNode(int x, int y, Matriz* minhaMatriz){

    if (minhaMatriz->inicio == NULL){
        printf("sem matriz!\n");
        return NULL;
    }

    Node* linha = minhaMatriz->inicio;

    for (int i = 0; i < y; i++){
        linha = linha->abaixo;
    }

    Node* atual = linha->direita;

    while (atual != linha){

        if (atual->x == x){
            return atual;
        }

        if (atual->y > y){
            return NULL;
        }

        atual = atual->direita;
    }

    return NULL;
}