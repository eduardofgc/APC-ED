#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *prox;
    struct Node *passado;
} Node;

typedef struct Lista{
    int size;
    Node *head;
    Node *ultimo;
} Lista;

Lista *createList(){
    Lista *novaLista = (Lista *)malloc(sizeof(Lista));
    novaLista->head = NULL;
    novaLista->ultimo = NULL;
    novaLista->size = 0;

    return novaLista;
}

// letra a
void addElem(int num, Lista *minhaLista)
{
    Node *novo = malloc(sizeof(Node));
    novo->val = num;
    novo->prox = NULL;
    novo->passado = NULL;

    if (minhaLista->head == NULL)
    {
        minhaLista->head = novo;
        minhaLista->ultimo = novo;
        minhaLista->size++;
        return;
    }

    Node *cur = minhaLista->head;
    while (cur != NULL && cur->val < num)
        cur = cur->prox;

    if (cur == NULL)
    {
        novo->passado = minhaLista->ultimo;
        minhaLista->ultimo->prox = novo;
        minhaLista->ultimo = novo;
    }
    else if (cur == minhaLista->head)
    {
        novo->prox = minhaLista->head;
        minhaLista->head->passado = novo;
        minhaLista->head = novo;
    }
    else
    {
        novo->prox = cur;
        novo->passado = cur->passado;
        cur->passado->prox = novo;
        cur->passado = novo;
    }

    minhaLista->size++;
}

// letra c (e b, uma vez que os elementos que adicionamos ja sao ordenados)
Lista *uniao(Lista *a, Lista *b)
{
    Lista *resultado = createList();

    Node *curA = a->head;
    Node *curB = b->head;

    while (curA != NULL && curB != NULL)
    {
        if (curA->val < curB->val)
        {
            addElem(curA->val, resultado);
            curA = curA->prox;
        }
        else if (curB->val < curA->val)
        {
            addElem(curB->val, resultado);
            curB = curB->prox;
        }
        else
        {
            addElem(curA->val, resultado);
            curA = curA->prox;
            curB = curB->prox;
        }
    }

    while (curA != NULL)
    {
        addElem(curA->val, resultado);
        curA = curA->prox;
    }

    while (curB != NULL)
    {
        addElem(curB->val, resultado);
        curB = curB->prox;
    }

    return resultado;
}

void printLista(Lista *minhaLista)
{
    Node *referenceNode = minhaLista->head;

    while (referenceNode != NULL)
    {
        printf("%d ", referenceNode->val);
        referenceNode = referenceNode->prox;
    }

    printf("\n");
}