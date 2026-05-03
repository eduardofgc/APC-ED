#include <iostream>
#include <cmath>
#include <cstring>
#include <string>

//6011000990139424

int main(){

    int algs[20], algs_true[20], cont = 0, soma1 = 0, soma2 = 0;
    std::string credit_num;

    std::cin >> credit_num;

    //zera vetor algs
    for (int i = 0; i < 20; i++){
        algs[i] = 644;
        algs_true[i] = 644;
    }

    //passo 2
    for (int i = 0; i < credit_num.length(); i = i + 2){
        algs[cont] = credit_num[i] - 48;
        cont++;
    }

    for (int i = 0; i < 10; i++){

        if (algs[i] != 644){
            
            algs[i] = algs[i] * 2;
        }
    }
    
    for (int i = 0; i < 20; i++){

        if (algs[i] != 644){

            if (algs[i] > 10){
                algs_true[i] = algs[i];
            }
            else {
                algs_true[i] = algs[i] - (algs[i] % 10);
                algs_true[i + 1] = algs[i] % 10;

                i++;
            }
        }
    }

    for (int i = 0; i < 20; i++){

        if (algs_true[i] != 644){
            soma1 = soma1 + algs_true[i];
        }
    }

    //passo 3
    for (int i = 0; i < credit_num.length(); i++){
        if (algs[i] % 2 != 0){
            if (algs[i] != 644){

                if (algs[i] % 2 != 0){
                    soma2 = soma2 + algs[i];
                }
            }
        }
    }

    if ((soma1 + soma2) % 10 == 0){
        std::cout << "cartao valido\n";
    }
    else {
        std::cout << "cartao invalido\n";
    }

    return 0;
}