#include <iostream>
#include <string>


void bubble_sort(int array[], int tamanho){
    int temp;

    for (int i = 0; i < tamanho - 1; i++){

        for (int j = 0; j < tamanho - 1; j++){

            if (array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main(){
    std::string somaDada;
    std::cin >> somaDada;

    int n = ((somaDada.length() + 1)/2);
    int *numArr = new int[n-1];
    int cont = 0;

    for (int i = 0; i < somaDada.length(); i++){
        if (i % 2 == 0 || i == 0){
            numArr[cont] = somaDada[i] - '0';
            cont++;
        }
    }

    bubble_sort(numArr, n);

    for (int i = 0; i < n; i++){
        if (i != n-1){
            std::cout << numArr[i] << "+";
        }
        else {
            std::cout << numArr[i];
        }
    }

    delete numArr;

    return 0;
}