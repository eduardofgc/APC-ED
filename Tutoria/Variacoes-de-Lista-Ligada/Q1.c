#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* prox;
    struct Node* passado;

    int val;
} Node;

typedef struct ListaDupla{
    Node* inicio;
    int tamanho;
} ListaDupla;

ListaDupla* criaLista(){ //O(1)
    ListaDupla* novaLista = (ListaDupla*) malloc(sizeof(ListaDupla));
    novaLista->inicio = NULL;
    novaLista->tamanho = 0;

    return novaLista;
}

void addNode(ListaDupla* minhaLista, int val){ //O(n)
    Node* novoNode = (Node*) malloc(sizeof(Node));
    novoNode->val = val;
    novoNode->prox = NULL;

    if (minhaLista->inicio == NULL){
        novoNode->passado = NULL;
        minhaLista->inicio = novoNode;
    }
    else{
        Node* atual = minhaLista->inicio;

        while (atual->prox != NULL){
            atual = atual->prox;
        }

        atual->prox = novoNode;

        novoNode->passado = atual;
    }

    minhaLista->tamanho++;
}

void removeNode(ListaDupla* minhaLista, int val){ //O(n)

    if (minhaLista == NULL || minhaLista->inicio == NULL){
        return;
    }

    Node* atual = minhaLista->inicio;

    while (atual != NULL && atual->val != val){
        atual = atual->prox;
    }

    if (atual == NULL){
        return;
    }

    if (atual->passado == NULL){
        minhaLista->inicio = atual->prox;

        if (atual->prox != NULL){
            atual->prox->passado = NULL;
        }
    }
    else{
        atual->passado->prox = atual->prox;

        if (atual->prox != NULL){
            atual->prox->passado = atual->passado;
        }
    }

    free(atual);

    minhaLista->tamanho--;
}

int main(){

    return 0;
}