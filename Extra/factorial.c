#include <stdio.h>

int fatorial(int n){
    if (n == 1){
        return n;
    }

    return n * fatorial(n-1);
}

int main(){
    int num;
    scanf("%d", &num);

    printf("fatorial: %d\n", fatorial(num));

    return 0;
}