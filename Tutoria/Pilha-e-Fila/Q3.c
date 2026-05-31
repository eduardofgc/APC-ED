#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* prox;
    int val;
} Node;

typedef struct Pilha{
    Node* inicio;

    int tamanho;
} Pilha;

Pilha* inicializaPilha(){
    Pilha* minhaPilha = (Pilha*) malloc(sizeof(Pilha));
    minhaPilha->inicio = NULL;
    minhaPilha->tamanho = 0;

    return minhaPilha;
}

void empilharInteiro(Pilha* minhaPilha, int val){
    Node* novoNode = (Node*) malloc(sizeof(Node));
    novoNode->val = val;

    if (minhaPilha->inicio == NULL){
        minhaPilha->inicio = novoNode;
        novoNode->prox = NULL;
    }
    else{
        novoNode->prox = minhaPilha->inicio;
        minhaPilha->inicio = novoNode;
    }

    minhaPilha->tamanho++;
}

void desempilharInteiro(Pilha* minhaPilha){
    if (minhaPilha->inicio == NULL){
        printf("pilha vazia!\n");
        return;
    }

    Node* referencia = minhaPilha->inicio;
    minhaPilha->inicio = minhaPilha->inicio->prox;

    free(referencia);
    minhaPilha->tamanho--;
}

int acharMaior(Pilha* minhaPilha){
    if (minhaPilha->inicio == NULL){
        printf("pilha vazia!\n");
        return -1;
    }

    Node* atual = minhaPilha->inicio;
    int maior = minhaPilha->inicio->val;


    while (atual != NULL){
        if (atual->val > maior) maior = atual->val;

        atual = atual->prox;
    }

    return maior;
}

int main(){

    return 0;
}