#include <stdio.h>
#include <stdlib.h>

#define TABLE_MAX 200000

typedef struct Node{
    int val;
    int id;
    struct Node* next; 
} Node;

int hash(int value){
    if (value < 0) value = -value;
    return value % TABLE_MAX;
}

int main(){
    int n, x, a, found = 0;
    scanf("%d %d", &n, &x);

    Node* myTable[TABLE_MAX] = {NULL};

    for (int i = 0; i < n; i++){
        scanf("%d", &a);

        int complemento = x - a;
        int h = hash(complemento);

        Node* referenceNode = myTable[h];

        while (referenceNode != NULL){
            if (referenceNode->val == complemento) {
                printf("%d %d\n", referenceNode->id + 1, i + 1);

                found = 1;
            }

            referenceNode = referenceNode->next;
        }

        int ha = hash(a);
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->val = a;
        newNode->id = i;
        newNode->next = myTable[ha];
        myTable[ha] = newNode;

        if (found == 1) break;
    }

    if (found == 0) printf("IMPOSSIBLE\n");
    return 0;
}
