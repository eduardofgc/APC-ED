#include <stdio.h>

void Rotate(int* array, int lenght){
    int temp = array[lenght-1];
    array[lenght-1] = array[0];
    
    for (int i = 0; i < lenght-1; i++){
        if (i != lenght-2){
            array[i] = array[i+1];
        }
        else{
            array[i] = temp;
        }
    }
}

int main(){
    int n, d;
    scanf("%d %d", &n, &d);

    int arr[n];

    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < d; i++){
        Rotate(arr, n);
    }

    //output
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}