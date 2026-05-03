#include <iostream>

class Node{
    public:
        int valor;
        Node* p_prox;

        Node(int valor){
            this->valor = valor;
            p_prox = nullptr;
        }
};

int main (){
    int n;

    Node* novo = nullptr;
    Node* head = nullptr;
    Node* temp = nullptr;

    std::cin >> n;

    //main loop
    for (int i = 0; i < n; i++){

        novo = new Node(i);

        if (i == 0){
            head = novo;
            temp = novo;

            std::cout << novo->valor << "\n";
        }
        else {
            temp->p_prox = novo;
            temp = novo;

            std::cout << novo->valor << "\n";
        }

    }

    //liberando memoria
    temp = head;

    while (temp != nullptr){

        Node* temp2 = temp->p_prox;
        
        delete temp;
        temp = temp2;
    }

    return 0;
}