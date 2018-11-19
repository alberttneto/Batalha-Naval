#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Criando 4 matrizes, duas usuario e duas maquina
struct campo{
  int campos[5][5];
};

//Função para colocar o barcos no campo
void colocaBarcos(int campo[5][5]){

    int tamanho = 5, alei, alej, cont = 0, i, compara;

    //1º barco 3 celulas horizontal
    while(cont != 3){

        alei = rand()%(tamanho-1);
        alej = rand()%(tamanho-1);
        cont = 0;
        compara = alej;

        while(cont < 3){

            if(campo[alei][alej] == 0 && compara < 3){
                campo[alei][alej] = 1;
                alej++;
            } else{
                break;
            }
        cont++;
        }
    }

    //2º barco 2 celulas vertical
    while(cont != 2){

        alei = rand()%(tamanho-1);
        alej = rand()%(tamanho-1);
        cont = 0;

        while(cont < 2){

            if(campo[alei][alej] == 0){
                cont++;
                alei++;
            }else{
                break;
            }
        }
        alei = alei - 2;

        if(cont == 2){
            for(i = 0; i < 2; i++){
                campo[alei][alej] = 2;
                alei++;
            }
        }
    }

    //3º barco 2 celulas vertical
    cont = 0;
    while(cont != 2){

        alei = rand()%(tamanho-1);
        alej = rand()%(tamanho-1);
        cont = 0;

        while(cont < 2){

            if(campo[alei][alej] == 0){
                cont++;
                alei++;
            }else{
                break;
            }
        }
        alei = alei - 2;

        if(cont == 2){
            for(i = 0; i < 2; i++){
                campo[alei][alej] = 3;
                alei++;
            }
        }
    }
}

//Função recebe posições do usuario e verifica se está correta
void atualizaCampo(int campo1[5][5], int campo2[5][5], int user){

    int tamanho = 5, linha, i, j;
    char colunaL, colunaN;


    // Receber linha e coluna do usuario
    if(user == 1){
        printf("Linha: ");
        scanf("%d", &linha);
        printf("Coluna: ");
        setbuf(stdin, NULL);
        scanf("%c", &colunaL);

        switch(colunaL){

        case 'A': colunaN = 0;
        break;

        case 'B': colunaN = 1;
        break;

        case 'C': colunaN = 2;
        break;

        case 'D': colunaN = 3;
        break;

        case 'E': colunaN = 4;

        default:
            printf("\n Opcao incorreta! \n");
        break;
        }
    // Linha e coluna da maquina
    }else{
        linha = rand()%5;
        colunaN = rand()%5;
    }

    campo2[linha][colunaN] = campo1[linha][colunaN];

    //Verifica se errou ou acertou
    if(campo2[linha][colunaN] == 0){
        printf("Errou\n");
    }else{
        printf("Acertou\n");
    }

    //Imprime campo atualizado
    printf("    [A][B][C][D][E]\n");
    for(i = 0; i < tamanho; i++){
        printf("[%d] ", i);
        for(j = 0; j < tamanho; j++){
            printf("[%d]", campo2[i][j]);
        }
        printf("\n");
    }
}

//Função verifica quem ganhou
int verificaVencedor(int campo1[5][5], int campo2[5][5]){

    int iguais = 0, ganhou = 0, i, j, tamanho = 5;

    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++){
            if(campo1[i][j] == campo2[i][j]){
                iguais++;
            }
        }
    }
    if(iguais == 25){
        return ganhou = 1;
    }else{
        return ganhou = 0;
    }
}


int main(){

    struct campo c[4] = {0};
    int tamanho = 5, linha, i, j, ganhou1 = 0, ganhou2 = 0;

    srand(time(NULL));


    // Iniciando o jogo - Regras do jogo
    printf("    ##BATALHA NAVAL - REGRAS##\n");
    printf("1º - Sao tres barcos, cada numero representa um barco diferente. \n"
           "2º - Escolha uma celula, onde A, B, C, D e E representam as colunas e 1, 2, 3, 4 e 5 representam as linhas. \n"
           "3º - Quem encontrar os 3 barcos ganha o jogo.\n\n");

    //Mostrar matriz inicial do jogo com linhas e colunas numeradas
    printf("    ##BATALHA NAVAL##\n");
    printf("    [A][B][C][D][E]\n");
    for(i = 0; i < tamanho; i++){
        printf("[%d] ", i);
        for(j = 0; j < tamanho; j++){
            printf("[%d]", c[1].campos[i][j]);
        }
        printf("\n");
    }

    printf("\n");


    //Colocar barcos no campo
    colocaBarcos(c[0].campos);
    colocaBarcos(c[2].campos);

    while(1){

        //Recebe e verifica jogada do usuario
        printf("\nSua vez: \n");
        atualizaCampo(c[0].campos, c[1].campos, 1);
        ganhou1 = verificaVencedor(c[0].campos, c[1].campos);

        //Recebe e verifica jogada da maquina
        printf("\n Vez da maquina: \n");
        atualizaCampo(c[2].campos, c[3].campos, 2);
        ganhou2 = verificaVencedor(c[2].campos, c[3].campos);

        if(ganhou1 == 1 || ganhou2 == 1){
            break;
        }
    }

    //Resultado final
    if(ganhou1 == 1){
        printf("\nParabens, voce ganhou!!\n");
    }else{
        printf("\nVoce Perdeu!!\n");
    }


    return 0;
}
