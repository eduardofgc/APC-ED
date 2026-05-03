#include <iostream>

void bubble_sort(int array[], int tamanho){
    int temp;

    for (int i = 0; i < tamanho - 1; i++){
        for (int j = 0; j < tamanho - 1 - i; j++){
            if (array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main(){
    int t, n;
    std::cin >> t;

    while (t--) {
        std::cin >> n;
        int *array = new int[n];

        for (int i = 0; i < n; i++){
            std::cin >> array[i];
        }

        bubble_sort(array, n);

        int meio = n / 2;

        int temp = array[meio];
        array[meio] = array[n - 1];
        array[n - 1] = temp;

        int esquerda = meio + 1;
        int direita = n - 2;

        while (esquerda < direita) {
            int aux = array[esquerda];
            array[esquerda] = array[direita];
            array[direita] = aux;
            esquerda++;
            direita--;
        }

        for (int i = 0; i < n; i++){
            std::cout << array[i];
            if (i != n - 1) std::cout << " ";
        }
        std::cout << "\n";

        delete[] array;
    }

    return 0;
}