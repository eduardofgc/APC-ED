//letra b já está implementada, uma implementação que criaria cópias seria uma que destruisse a imagem original
//e criasse uma nova com tamanho estendido ou cortado.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* direita;
    struct Node* abaixo;

    int val;
} Node;

typedef struct Imagem{
    int linhas;
    int colunas;

    Node* start;
} Imagem;

Imagem* criarImagem(int linhas, int colunas){

    if (linhas <= 0 || colunas <= 0){
        printf("invalido\n");
        return;
    }
    
    Imagem* minhaImagem = (Imagem*) malloc(sizeof(Imagem));

    minhaImagem->colunas = colunas;
    minhaImagem->linhas = linhas;

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

    while (linha != NULL){

        Node* atual = linha;

        while (atual->direita != NULL){
            atual = atual->direita;
        }

        for (int i = 0; i < pixelsExtendidos; i++){

            Node* novoNode = malloc(sizeof(Node));

            novoNode->val = 0;
            novoNode->direita = NULL;
            novoNode->abaixo = NULL;

            atual->direita = novoNode;
            atual = novoNode;
        }

        linha = linha->abaixo;
    }

    minhaImagem->colunas += pixelsExtendidos;
}

void cortarDireita(Imagem* minhaImagem, int pixelsCortados){
    if (pixelsCortados <= 0){
        printf("tamanho invalido!\n");
        return;
    }

    int novasColunas = minhaImagem->colunas - pixelsCortados;
    Node* linha = minhaImagem->start;

    while (linha != NULL){
        Node* atual = linha;

        for (int i = 0; i < novasColunas; i++){
            atual = atual->direita;
        }

        Node* aSerApagado = atual->direita;
        atual->direita = NULL;

        while(aSerApagado != NULL){
            Node* prox = aSerApagado->direita;
            free(aSerApagado);

            aSerApagado = prox;
        }

        linha = linha->abaixo;
    }

    minhaImagem->colunas = novasColunas;
}