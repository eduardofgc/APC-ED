#include <math.h>
#include <stdio.h>

float CalcDist(float aX, float aY, float bX, float bY){
    float dist = sqrt(pow((aX - bX), 2) + pow((aY - bY), 2));

    return dist;
}

void ImprimePonto(float pontoX, float pontoY){
    printf("(%.1f, %.1f)\n", pontoX, pontoY);
}

int GetQuadrantePonto(float pontoX, float pontoY){
    int quadrante;
    
    if (pontoX > 0 && pontoY > 0){
        quadrante = 1;
    }
    else if (pontoX < 0 && pontoY > 0){
        quadrante = 2;
    }
    else if (pontoX < 0 && pontoY < 0){
        quadrante = 3;
    }
    else if (pontoX > 0 && pontoY < 0){
        quadrante = 4;
    }
    else{
        quadrante = 100;
    }

    return quadrante;
}