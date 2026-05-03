#include <iostream>
#include <cmath>

void bubble_sort(int array[], int tamanho){
    int temp;

    for (int i = 0; i < tamanho-1; i++){

        for (int j = 0; j < tamanho-1; j++){

            if (array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main(){
    int n;

    std::cin >> n;

    int *pArray = new int[n];

    for (int i = 0; i < n; i++){

        std::cin >> pArray[i];
    }

    bubble_sort(pArray, n);

    for (int i = 0; i < n; i++){

        std::cout << pow(pArray[i], 2) << "\n";
    }

    delete[] pArray;

    return 0;
}