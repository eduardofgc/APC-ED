#include <iostream>
#include <ctime>

const int linha = 3;
const int coluna = 3;

void imprimir_matriz(char matriz[linha][coluna]){
    for (int i = 0; i < 3; i++){

        for (int j = 0; j < 3; j++){

            std::cout << matriz[i][j] << " ";
        }

        std::cout << "\n";
    }
}

bool check_vict(char matriz[linha][coluna]){
    bool vict = false;
    
    //checa horizontalmente
    for (int i = 0; i < 3; i++){

        if (matriz[i][0] != '-'){
            
            if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2]){

                vict = true;
            }
        }   
    }

    //checa verticalmente
    for (int i = 0; i < 3; i++){

        if (matriz[0][i] != '-'){

            if (matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i]){

                vict = true;
            }
        }
    }

    //checa diagonais
    if (matriz[0][0] != '-' && matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]){

        vict = true;
    }
    if (matriz[2][0] != '-' && matriz[2][0] == matriz[1][1] && matriz[1][1] == matriz[0][2]){

        vict = true;
    }


    return vict;
}

char* verif_block(char matriz[linha][coluna]){
    char *p_block = nullptr;
    bool block_action = false;

    //horizontalmente
    for (int i = 0; i < 3; i++){

        if (p_block == nullptr){

            if (matriz[i][0] == 'X' && matriz[i][0] == matriz[i][1] && matriz[i][2] == '-'){
                p_block = &matriz[i][2];
            }
            else if (matriz[i][0] == 'X' && matriz[i][0] == matriz[i][2] && matriz[i][1] == '-'){
                p_block = &matriz[i][1];
            }
            else if (matriz[i][1] == 'X' && matriz[i][1] == matriz[i][2] && matriz[i][0] == '-'){
                p_block = &matriz[i][0];
            }

        }
    }

    //verticalmente
    if (p_block == nullptr){

        for (int j = 0; j < 3; j++){

            if (matriz[0][j] == 'X' && matriz[0][j] == matriz[1][j] && matriz[2][j] == '-'){
                p_block = &matriz[2][j];
            }
            else if (matriz[0][j] == 'X' && matriz[0][j] == matriz[2][j]  && matriz[1][j] == '-'){
                p_block = &matriz[1][j];
            }
            else if (matriz[1][j] == 'X' && matriz[1][j] == matriz[2][j]  && matriz[0][j] == '-'){
                p_block = &matriz[0][j];
            }

        }
    }

    //diagonais
    if (p_block == nullptr){

        if (matriz[0][0] == 'X' && matriz[0][0] == matriz[1][1]  && matriz[2][2] == '-'){
            p_block = &matriz[2][2];
        }
        else if (matriz[0][0] == 'X' && matriz[0][0] == matriz[2][2] && matriz[1][1] == '-'){
            p_block = &matriz[1][1];
        }
        else if (matriz[1][1] == 'X' && matriz[1][1] == matriz[2][2] && matriz[0][0] == '-'){
            p_block = &matriz[0][0];
        }
        else if (matriz[0][2] == 'X' && matriz[0][2] == matriz[1][1] && matriz[2][0] == '-'){
            p_block = &matriz[2][0];
        }
        else if (matriz[0][2] == 'X' && matriz[0][2] == matriz[2][0] && matriz[1][1] == '-'){
            p_block = &matriz[1][1];
        }
        else if (matriz[2][0] == 'X' && matriz[2][0] == matriz[1][1] && matriz[0][2] == '-'){
            p_block = &matriz[0][2];
        }

    }

    return p_block;
}

int main (){
    char matriz[linha][coluna];
    int x, y, xcomp, ycomp, turno = 0;
    bool vitoria;

    srand(time(NULL));

    for (int i = 0; i < 3; i++){

        for (int j = 0; j < 3; j++){

            matriz[i][j] = '-';
        }
    }

    while (1){

        while (1){
            int res2 = 0;

            std::cout << "\n";
            imprimir_matriz(matriz);
            std::cout << "\n\nSua vez! Digite a linha e coluna que quer jogar.\n";
            std::cin >> x >> y;

            if (matriz[x - 1][y - 1] == '-'){
                matriz[x - 1][y - 1] = 'X';
                res2 = 1;
            }
            else {
                std::cout << "\nLocal invalido!\n";
            }

            if (res2 == 1){

                break;
            }
        }
        
        std::cout << "\n\n";
        imprimir_matriz(matriz);

        if (check_vict(matriz) == true){
            std::cout << "\n\nVOCE GANHOU!!!\n";
            break;
        }

        turno++;
        if (turno == 9){
            std::cout << "\n\nEmpate!\n";
            break;
        }

        //computer turn
        std::cout << "\n\nVez do computador!\n\n";

        while (1){

            if (verif_block(matriz) != nullptr){

                char* temp = verif_block(matriz);
                *temp = 'O';

                break;
            }
            else{

                int ver = 0;
                xcomp = rand() % 3;
                ycomp = rand() % 3;

                if (matriz[xcomp][ycomp] == '-'){

                    matriz[xcomp][ycomp] = 'O';
                    ver = 1;
                }

                if (check_vict(matriz) == true){

                    break;
                }

                if (ver == 1){

                    break;
                }

            }
        }

        imprimir_matriz(matriz);

        if (check_vict(matriz) == true){
            std::cout << "\n\nVoce perdeu... mais sorte da proxima!\n";
            break;
        }

        turno++;

        if (turno == 9){
            std::cout << "\n\nEmpate! Obrigado por jogar!\n";
            break;
        }
    }

    return 0;
}