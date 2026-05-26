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

void adicionarElemento(Matriz* minhaMatriz, int meuValor, int minhaLinha, int minhaColuna){
    int achou = 0;

    if (meuValor == 0) return;

    Node* novoNode = (Node*)malloc(sizeof(Node));
    novoNode->index = meuValor;
    novoNode->linha = minhaLinha;
    novoNode->coluna = minhaColuna;

    if (minhaMatriz->inicio == NULL){
        novoNode->direita = NULL;
        novoNode->abaixo = NULL;

        minhaMatriz->inicio = novoNode;
    }
    else{
        Node* atual = minhaMatriz->inicio;

        for (int i = 0; i < minhaMatriz->colunasMax; i++){
            if (atual->direita == NULL){//todo

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