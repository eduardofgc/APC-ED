#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* prox;
    int val;
} Node;

typedef struct Deque{
    Node* inicio;
    Node* ultimo;

    int tamanho;
} Deque;

Deque* criaDeque(){
    Deque* novoDeque = (Deque*) malloc(sizeof(Deque));
    novoDeque->inicio = NULL;
    novoDeque->ultimo = NULL;
    novoDeque->tamanho = 0;

    return novoDeque;
}

void insere_inicio(Deque* meuDeque, int val){
    Node* novoNode = (Node*) malloc(sizeof(Node));
    novoNode->val = val;

    if (meuDeque->inicio == NULL){
        meuDeque->inicio = novoNode;
        meuDeque->ultimo = novoNode;
        novoNode->prox = NULL;
    }
    else{
        novoNode->prox = meuDeque->inicio;
        meuDeque->inicio = novoNode;
    }

    meuDeque->tamanho++;
}   

void insere_final(Deque* meuDeque, int val){
    Node* novoNode = (Node*) malloc(sizeof(Node));
    novoNode->prox = NULL;
    novoNode->val = val;

    if (meuDeque->inicio == NULL){
        meuDeque->inicio = novoNode;
        meuDeque->ultimo = novoNode;
    }
    else{
        meuDeque->ultimo->prox = novoNode;
        meuDeque->ultimo = novoNode;
    }

    meuDeque->tamanho++;
}

void remove_inicio(Deque* meuDeque){
    if (meuDeque->inicio == NULL){
        printf("Deque vazio!\n");
        return;
    }

    Node* aSerRemovido = meuDeque->inicio;
    meuDeque->inicio = meuDeque->inicio->prox;

    if (meuDeque->inicio == NULL){
    meuDeque->ultimo = NULL;
    }

    free(aSerRemovido);
    meuDeque->tamanho--;
}

void remove_fim(Deque* meuDeque){ //essa funcao nao funciona corretamente quando o deque tem apenas um elemento
    if (meuDeque->inicio == NULL){
        printf("Deque vazio!\n");
        return;
    }

    Node* aSerRemovido = meuDeque->ultimo;

    Node* atual = meuDeque->inicio;

    while(atual->prox->prox != NULL){
        atual = atual->prox;
    }

    meuDeque->ultimo = atual;
    atual->prox = NULL;
    free(aSerRemovido);

    meuDeque->tamanho--;
}

int main(){

    return 0;
}