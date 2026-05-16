#include <stdio.h>
#include <stdlib.h>

//letra a
typedef struct Node{
    struct Node* direita;
    struct Node* abaixo;

    int index;
    int linha;
    int coluna;
} Node;

typedef struct Matriz{
    Node* inicio;
    int linhasMax;
    int colunasMax;
} Matriz;

Matriz* criarMatriz (int minhasLinhas, int minhasColunas){
    Matriz* novaMatriz = (Matriz*) malloc(sizeof(Matriz));
    novaMatriz->linhasMax = minhasLinhas;
    novaMatriz->colunasMax = minhasColunas;
    novaMatriz->inicio = NULL;

    return novaMatriz;
}

void adicionarElemento(Matriz* minhaMatriz, int meuValor){
    Node* novo = (Node*) malloc(sizeof(Node));
    novo->index = meuValor;
    Node* atual = minhaMatriz->inicio;

    while (atual != NULL){
        
        for (int i = 0; i < minhaMatriz->linhasMax; i++){

            for (int j = 0; j < minhaMatriz->colunasMax; j++){ //TODO
                

            }
        }
    }
}

//letra b
Node* acessarElemento(Matriz* minhaMatriz, int minha_linha, int minha_coluna) {

    Node* dummy_linha = minhaMatriz->inicio;

    for (int i = 0; i < minha_linha; i++) {
        dummy_linha = dummy_linha->abaixo;
    }

    Node* atual = dummy_linha->direita;

    while (atual != dummy_linha) {

        if (atual->coluna == minha_coluna) {
            return atual;
        }

        if (atual->coluna > minha_coluna) {
            return NULL; 
        }

        atual = atual->direita;
    }

    return NULL;
}