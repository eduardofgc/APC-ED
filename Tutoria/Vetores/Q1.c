//letra b já está implementada, uma implementação que criaria cópias seria uma que destruisse a imagem original
//e criasse uma nova com tamanho estendido ou cortado.


#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;

    struct Node* direita;
    struct Node* abaixo;
} Node;

typedef struct Imagem{
    Node* start;

    int linhas;
    int colunas;
} Imagem;


Imagem* criarImagem(int linhas, int colunas){

    if (linhas <= 0 || colunas <= 0){
        printf("tamanho inválido.\n");

        return NULL;
    }
    
    Imagem* minhaImagem = (Imagem*) malloc(sizeof(Imagem));
    
    minhaImagem->linhas = linhas;
    minhaImagem->colunas = colunas;

    Node* primeiraLinha = NULL;
    Node* linhaAnterior = NULL;

    //criacao de linhas e colunas
     for (int i = 0; i < linhas; i++){

        Node* inicioLinhaAtual = NULL;
        Node* atual = NULL;

        Node* acima = linhaAnterior;

        for (int j = 0; j < colunas; j++){

            Node* novo = (Node*) malloc(sizeof(Node));

            novo->val = 1;

            novo->direita = NULL;
            novo->abaixo = NULL;


            if (inicioLinhaAtual == NULL){ //caso seja o primeiro no da linha

                inicioLinhaAtual = novo;
                atual = novo;
            }
            else{

                atual->direita = novo;
                atual = novo;
            }

            if (acima != NULL){

                acima->abaixo = novo;
                acima = acima->direita;
            }
        }

        if (i == 0){ //pra salvar o start

            primeiraLinha = inicioLinhaAtual;
        }

        linhaAnterior = inicioLinhaAtual;
    }

    minhaImagem->start = primeiraLinha;

    return minhaImagem;
}

//letra a
void estenderDireita(Imagem* minhaImagem, int pixelsExtendidos){

    if (pixelsExtendidos <= 0) return;

    Node* linha = minhaImagem->start;

    while (linha != NULL){

        Node* atual = linha;

        while (atual->direita != NULL){//escolhe o node mais a direita de cada linha

            atual = atual->direita;
        }

        for (int i = 0; i < pixelsExtendidos; i++){
            Node* novo = (Node*) malloc(sizeof(Node));

            novo->val = 0;
            novo->direita = NULL;
            novo->abaixo = NULL;

            atual->direita = novo;
            atual = novo;
        }

        linha = linha->abaixo;
    }

    minhaImagem->colunas = minhaImagem->colunas + pixelsExtendidos;
}

void cortarDireita(Imagem* minhaImagem, int pixelsCortados){

    if (pixelsCortados <= 0 || pixelsCortados >= minhaImagem->colunas) return;

    int novasColunas = minhaImagem->colunas - pixelsCortados;
    Node* linha = minhaImagem->start;

    while (linha != NULL){
        Node* atual = linha;

        for (int i = 0; i < novasColunas; i++){//ate o final da nova linha, vamos apagar todas depois dela

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