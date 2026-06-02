#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    struct Node* prox;

    int numero;
    int idoso;
} Node;

typedef struct Fila{
    Node* inicio;
    Node* ultimo;

    int tamanho;
} Fila;

Fila* inicializaFila(){
    Fila* minhaFila = (Fila*) malloc(sizeof(Fila));

    minhaFila->inicio = NULL;
    minhaFila->ultimo = NULL;
    minhaFila->tamanho = 0;

    return minhaFila;
}

void insere_geral(Fila* fila, int numero){
    Node* novoNode = (Node*) malloc(sizeof(Node));

    novoNode->numero = numero;
    novoNode->idoso = 0;
    novoNode->prox = NULL;

    if(fila->inicio == NULL){
        fila->inicio = novoNode;
        fila->ultimo = novoNode;
    }
    else{
        fila->ultimo->prox = novoNode;
        fila->ultimo = novoNode;
    }

    fila->tamanho++;
}

void insere_idoso(Fila* fila, int numero){
    Node* novoNode = (Node*) malloc(sizeof(Node));

    novoNode->numero = numero;
    novoNode->idoso = 1;
    novoNode->prox = NULL;

    if(fila->inicio == NULL){
        fila->inicio = novoNode;
        fila->ultimo = novoNode;
        fila->tamanho++;
        return;
    }

    Node* atual = fila->inicio;
    Node* anterior = NULL;

    int idososNaFrente = 0;

    while(atual != NULL && atual->idoso == 1 && idososNaFrente < 2){

        idososNaFrente++;
        anterior = atual;
        atual = atual->prox;
    }

    if(anterior == NULL){
        novoNode->prox = fila->inicio;
        fila->inicio = novoNode;
    }
    else{
        anterior->prox = novoNode;
        novoNode->prox = atual;
    }

    if(novoNode->prox == NULL)
        fila->ultimo = novoNode;

    fila->tamanho++;
}

void printFila(Fila* fila){
    Node* atual = fila->inicio;

    while(atual != NULL){
        printf("%d ", atual->numero);
        atual = atual->prox;
    }

    printf("\n");
}

void liberaFila(Fila* fila){
    Node* atual = fila->inicio;

    while(atual != NULL){
        Node* prox = atual->prox;
        free(atual);
        atual = prox;
    }

    free(fila);
}

int main(){
    int n;

    scanf("%d", &n);

    Fila* fila = inicializaFila();

    for(int i = 0; i < n; i++){
        int numero;
        char tipo[20];

        scanf("%d %s", &numero, tipo);

        if(strcmp(tipo, "idoso") == 0){
            insere_idoso(fila, numero);
        }
        else{
            insere_geral(fila, numero);
        }
    }

    printFila(fila);

    liberaFila(fila);

    return 0;
}