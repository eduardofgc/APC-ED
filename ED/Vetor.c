#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* prox;
    int val;
} Node;

typedef struct Vetor{
    Node* head;
    int tamanho;
} Vetor;

Vetor* criaVetor(){
    Vetor* meuVetor = (Vetor*) malloc(sizeof(Vetor)); //o tamanho do espaço do meu vetor será do tamanho que um vetor precisa
    meuVetor->head = NULL; //garante que nao vai acessar lixo de memoria
    meuVetor->tamanho = 0;

    return meuVetor;
} //nosso vetor criado aqui ainda nao tem NADA. tamanho = 0 e head = NULL

void addNode(Vetor* meuVetor, int valor){
    Node* novoNode = (Node*) malloc(sizeof(Node));
    novoNode->val = valor;
    novoNode->prox = NULL;

    if (meuVetor->head == NULL){ //se vetor for vazio
        meuVetor->head = novoNode;
    }
    else{
        Node* atual = meuVetor->head;

        while (atual->prox != NULL){
            atual = atual->prox; //vai passando pra frente ate chegar no ultimo Node
        }

        atual->prox = novoNode; //antes era NULL. atribuimos o no criado agora
    }

    meuVetor->tamanho++;
}

void removeNode(Vetor* meuVetor, int valor){

    if (meuVetor->head == NULL){ //se o vetor estiver vazio
        printf("Vetor vazio!\n");
        return;
    }
    
    Node* atual = meuVetor->head;

    while (atual->prox != NULL){
        if (atual->prox->val == valor) break;
        atual = atual->prox;
    }

    if (atual == NULL){
        printf("nao tem esse elemento!\n");
        return;
    }
    
    Node* aSerDeletado = atual->prox;
    atual->prox = aSerDeletado->prox; //ou atual->prox->prox
    free(aSerDeletado);

    meuVetor->tamanho--;
}

void printVetor(Vetor* meuVetor){
    Node* atual = meuVetor->head;

    while (atual != NULL){
        printf("%d ", atual->val); //vai imprimindo e passando pra frente
        atual = atual->prox;
    }

    printf("\n");
}



int main(){
    Vetor* meuVetor = criaVetor();
    printVetor(meuVetor);

    addNode(meuVetor, 1);
    addNode(meuVetor, 2);
    addNode(meuVetor, 3);

    printVetor(meuVetor);

    addNode(meuVetor, 4);

    removeNode(meuVetor, 4);

    addNode(meuVetor, 5);

    printVetor(meuVetor);

    return 0;
}