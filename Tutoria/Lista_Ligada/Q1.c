#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* prox;
    int val;
} Node;

typedef struct Lista{
    Node* head;
    int tamanho;
} Lista;

Lista* criaLista(){
    Lista* minhaLista = (Lista*)malloc(sizeof(Lista));

    minhaLista->head = NULL;
    minhaLista->tamanho = 0;

    return minhaLista;
}

void addNode(Lista* minhaLista, int val){

    Node* novoNode = (Node*)malloc(sizeof(Node));
    novoNode->val = val;
    novoNode->prox = NULL;

    if (minhaLista->head == NULL || val < minhaLista->head->val){

        novoNode->prox = minhaLista->head;
        minhaLista->head = novoNode;

        minhaLista->tamanho++;
        return;
    }

    Node* atual = minhaLista->head;

    while (atual->prox != NULL && atual->prox->val < val){
        atual = atual->prox;
    }

    if (atual->val == val ||
       (atual->prox != NULL && atual->prox->val == val)){

        free(novoNode);
        return;
    }

    novoNode->prox = atual->prox;
    atual->prox = novoNode;

    minhaLista->tamanho++;
}

int existe(int val, Lista* minhaLista){
    Node* atual = minhaLista->head;

    while (atual != NULL){
        if (atual->val == val){
            return 1;
        }

        atual = atual->prox;
    }

    return 0;
}

Lista* uniaoOrdenada(Lista* lista1, Lista* lista2){

    Lista* novaLista = criaLista();

    Node* atual = lista1->head;

    while(atual != NULL){

        if (!existe(atual->val, novaLista)){
            addNode(novaLista, atual->val);
        }

        atual = atual->prox;
    }

    atual = lista2->head;

    while(atual != NULL){

        if (!existe(atual->val, novaLista)){
            addNode(novaLista, atual->val);
        }

        atual = atual->prox;
    }

    return novaLista;
}

void addNodeDesordenado(Lista* lista, int val){

    Node* novoNode = (Node*)malloc(sizeof(Node));

    novoNode->val = val;
    novoNode->prox = NULL;

    if (lista->head == NULL){

        lista->head = novoNode;
        lista->tamanho++;

        return;
    }

    Node* atual = lista->head;

    while (atual->prox != NULL){
        atual = atual->prox;
    }

    atual->prox = novoNode;

    lista->tamanho++;
}

Lista* uniaoDesordenada(Lista* lista1, Lista* lista2){

    Lista* novaLista = criaLista();

    Node* atual = lista1->head;

    while (atual != NULL){

        if (!existe(atual->val, novaLista)){

            addNodeDesordenado(novaLista, atual->val);
        }

        atual = atual->prox;
    }

    atual = lista2->head;

    while (atual != NULL){

        if (!existe(atual->val, novaLista)){

            addNodeDesordenado(novaLista, atual->val);
        }

        atual = atual->prox;
    }

    return novaLista;
}

Lista* uniaoOrdenada(Lista* lista1, Lista* lista2){

    Lista* novaLista = criaLista();

    Node* atual = lista1->head;
    while(atual != NULL){

        if (!existe(atual->val, novaLista)){
            addNode(novaLista, atual->val);
        }

        atual = atual->prox;
    }

    atual = lista2->head;

    while(atual != NULL){

        if (!existe(atual->val, novaLista)){
            addNode(novaLista, atual->val);
        }

        atual = atual->prox;
    }

    return novaLista;
}


//extra
Lista* intersecao(Lista* lista1, Lista* lista2){
    Lista* novaLista = criaLista();

    Node* atual = lista1->head;

    while(atual != NULL){
        if (existe(atual->val, lista2)){
            addNode(novaLista, atual->val);
        }

        atual = atual->prox;
    }

    return novaLista;
}