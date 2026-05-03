#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    Node *prox;
} Node;

int main(){
    Node* novo;
    Node* head;
    Node* next;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        novo = malloc(sizeof(Node));
        novo->val = i;

        if (i == 0){
            head = novo;
            next = novo;

            printf("%d", novo->val);
        }
        else{
            next->prox = novo;
            next = novo;

            printf("%d", novo->val);
        }
    }

    next = head;

    while (next != NULL){
        Node* temp = next->prox;
        free(next);

        next = temp;
    }



    return 0;
}