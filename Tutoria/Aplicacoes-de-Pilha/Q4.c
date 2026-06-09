#include <stdio.h>
#include <stdlib.h>

typedef struct Registro{
    int n;
    char orig;
    char dest;
    char aux;
    int retorno;
} Registro;

typedef struct Node{
    Registro dados;
    struct Node* prox;
} Node;

typedef struct Pilha{
    Node* head;
} Pilha;

Pilha* criaPilha(){
    Pilha* minhaPilha = (Pilha*) malloc(sizeof(Pilha));
    minhaPilha->head = NULL;

    return minhaPilha;
}

int vazia(Pilha* minhaPilha){
    return minhaPilha->head == NULL;
}

void push(Pilha* minhaPilha, Registro meuRegistro){
    Node* novoNode = (Node*) malloc(sizeof(Node));

    novoNode->dados = meuRegistro;
    novoNode->prox = minhaPilha->head;

    minhaPilha->head = novoNode;
}

Registro popRegistro(Pilha* minhaPilha){
    Node* reference = minhaPilha->head;
    Registro meuRegistro = reference->dados;

    minhaPilha->head = reference->prox;

    free(reference);
    return meuRegistro;
}

void hanoi(int n, char orig, char dest, char aux){
    Pilha* pilha = criaPilha();
    Registro registro;

    registro.n = n;
    registro.orig = orig;
    registro.dest = dest;
    registro.aux = aux;

    push(pilha, registro);

    while (!vazia(pilha)){
        Registro atual = popRegistro(pilha);

        if (atual.n <= 0){
            continue;
        }

        if (atual.retorno != 0){
            Registro voltaRegistro;

            voltaRegistro.n = atual.n;
            voltaRegistro.orig = atual.orig;
            voltaRegistro.dest = atual.dest;
            voltaRegistro.aux = atual.aux;
            voltaRegistro.retorno = 1;

            push(pilha, voltaRegistro);

            Registro segRegistro;

            segRegistro.n = atual.n-1;
            segRegistro.orig = atual.orig;
            segRegistro.dest = atual.dest;
            segRegistro.aux = atual.aux;
            segRegistro.retorno = 0;

            push(pilha, segRegistro);
        }
        else if (atual.retorno == 1){
            printf("move de %c para %c\n", atual.orig, atual.dest);

            Registro ultimaVolta;
            
            ultimaVolta.n = atual.n;
            ultimaVolta.orig = atual.orig;
            ultimaVolta.dest = atual.dest;
            ultimaVolta.aux = atual.aux;
            ultimaVolta.retorno = 2;

            push(pilha, ultimaVolta);

            Registro fallback;

            fallback.n = atual.n-1;
            fallback.orig = atual.orig;
            fallback.dest = atual.dest;
            fallback.aux = atual.orig;
            fallback.retorno = 0;

            push(pilha, fallback);
        }
    }
}

//hanoi(2, 'A', 'C', 'B')