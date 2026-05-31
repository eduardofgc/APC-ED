#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* prox;
    int val;
} Node;

typedef struct Pilha{
    Node* inicio;
    Node* ultimo;

    int tamanho;
} Pilha;

typedef struct Fila{
    Node* inicio;

    int tamanho;
} Fila;

Pilha* inicializaPilha(){
    Pilha* minhaPilha = (Pilha*) malloc(sizeof(Pilha));
    minhaPilha->inicio = NULL;
    minhaPilha->ultimo = NULL;
    minhaPilha->tamanho = 0;

    return minhaPilha;
}

Fila* inicializaFila(){
    Fila* minhaFila = (Fila*) malloc(sizeof(Fila));
    minhaFila->inicio = NULL;
    minhaFila->tamanho = 0;

    return minhaFila;
}

int ehVaziaPilha(Pilha* minhaPilha){
    if (minhaPilha->inicio == NULL) return 1;

    return 0;
}

int ehVaziaFila(Fila* minhaFila){
    if (minhaFila->inicio == NULL) return 1;

    return 0;
}

//eh_cheia me parece redundante, se minha interpretacao estiver correta basta usar ehVazia para verificar

int main(){

    return 0;
}