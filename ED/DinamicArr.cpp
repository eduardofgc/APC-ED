#include <iostream>

class DinamicArray{
    public:
        int* lista = new int[capacidade];
        int capacidade, index;

        void Resize(int nova_cap){
            int* nova_lista = new int[nova_cap];

            for (int i = 0; i < capacidade; i++){
                nova_lista[i] = lista[i];
            }

            delete[] lista;
            lista = nova_lista;
            capacidade = nova_cap;
        }

        void Add(int val){

            if (index == capacidade){
                Resize(capacidade*2);
            }

            lista[index] = val;
            index++;
        }

        void PrintElements(){
            for (int i = 0; i < index; i++){
                std::cout << lista[i] << " ";
            }
        }

        DinamicArray(int cap = 2){
            capacidade = cap;
            index = 0;
        }

        ~DinamicArray(){
            delete[] lista;
        }

};

int main(){
    DinamicArray dinamico;
    int n;
    
    std::cin >> n;

    for (int i = 1; i <= n; i++){
        dinamico.Add(i);
        std::cout << "\ntamanho atual: " << dinamico.capacidade << "\n";
        std::cout << "elementos: ";
        dinamico.PrintElements();

        std::cout << "\n********************************************************";
    }

    return 0;
}