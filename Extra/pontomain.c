#include <stdio.h>
#include "ponto.h"

int main(){
    float pontoA_x, pontoA_y, pontoB_x, pontoB_y;
    float distancia;

    scanf("%f %f %f %f", &pontoA_x, &pontoA_y, &pontoB_x, &pontoB_y);
    
    distancia = CalcDist(pontoA_x, pontoA_y, pontoB_x, pontoB_y);

    printf("Distancia: %f\n", distancia);
    ImprimePonto(pontoA_x, pontoA_y);
    
    if (GetQuadrantePonto(pontoA_x, pontoA_y) != 100){
        printf("Quadrante A: %d", GetQuadrantePonto(pontoA_x, pontoA_y));
    }
    else{
        printf("Quadrante Invalido!\n");
    }

    return 0;
}
