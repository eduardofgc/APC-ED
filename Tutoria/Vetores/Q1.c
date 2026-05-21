#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* direita;
    struct Node* abaixo;

    int val;
} Node;

typedef struct Imagem{
    Node* start;

    int linhas;
    int colunas;
} Imagem;

Imagem* criarMatriz(int linhas, int colunas){

    if (linhas <= 0 || colunas <= 0){
        printf("tamanho invalido!\n");
        return NULL;
    }

    Imagem* minhaImagem = (Imagem*)malloc(sizeof(Imagem));

    minhaImagem->linhas = linhas;
    minhaImagem->colunas = colunas;

    Node* primeiraLinha = NULL;
    Node* linhaAnterior = NULL;

    for (int i = 0; i < linhas; i++){
        Node* inicioLinha = NULL;
        Node* atual = NULL;

        Node* acima = linhaAnterior;

        for (int j = 0; j < colunas; j++){
            Node* novoNode = (Node*) malloc(sizeof(Node));
            novoNode->val = 1;

            novoNode->direita = NULL;
            novoNode->abaixo = NULL;

            if (inicioLinha == NULL){
                inicioLinha = novoNode;
                atual = novoNode;
            }
            else{
                atual->direita = novoNode;
                atual = novoNode;
            }

            if (acima != NULL){
                acima->abaixo = novoNode;
                acima = acima->direita;
            }

        }

        if (i == 0){
            primeiraLinha = inicioLinha;
        }

        linhaAnterior = inicioLinha;
    }

    minhaImagem->start = primeiraLinha;

    return minhaImagem;
}

void estenderImagemDireita(Imagem* minhaImagem, int pixelsExtendidos){

    if (pixelsExtendidos <= 0){
        printf("tamanho invalido!\n");
        return;
    }

    Node* linha = minhaImagem->start;

    while(linha != NULL){
        Node* atual = linha;

        while (atual->direita != NULL){
            atual = atual->direita;
        }

        for (int i = 0; i < pixelsExtendidos; i++){
            Node* novoNode = (Node*)malloc(sizeof(Node));
            novoNode->val = 0;
            novoNode->direita = NULL;
            novoNode->abaixo = NULL;

            atual->direita = novoNode;
            atual = novoNode;
        }

        linha = linha->abaixo;
    }

    minhaImagem->colunas = minhaImagem->colunas + pixelsExtendidos;
}

void cortarImagemDireita(int pixelsCortados, Imagem* minhaImagem){
    if (pixelsCortados <= 0 || pixelsCortados >= minhaImagem->colunas){
        printf("tamanho invalido!\n");
        return;
    }

    int novasColunas = minhaImagem->colunas - pixelsCortados;
    Node* linha = minhaImagem->start;

    while (linha != NULL){
        Node* atual = linha;

        for (int i = 0; i < novasColunas - 1; i++){
            atual = atual->direita;
        }

        Node* aSerApagado = atual->direita;
        atual->direita = NULL;

        while (aSerApagado != NULL){
            Node* prox = aSerApagado->direita;
            free(aSerApagado);

            aSerApagado = prox;
        }

        linha = linha->abaixo;
    }

    minhaImagem->colunas = novasColunas;
}

void printImage(Imagem* minhaImagem){
    if (minhaImagem == NULL){
        printf("nao tem imagem!\n");
        return;
    }

    Node* linha = minhaImagem->start;

    while (linha != NULL){
        Node* atual = linha;

        while (atual != NULL){
            printf("%d ", atual->val);
            atual = atual->direita;
        }

        printf("\n");
        linha = linha->abaixo;
    }
}

int main(){
    Imagem* matriz = criarMatriz(8, 8);

    printImage(matriz);

    estenderImagemDireita(matriz, 5);

    printImage(matriz);

    cortarImagemDireita(6, matriz);

    printImage(matriz);

    return 0;
}