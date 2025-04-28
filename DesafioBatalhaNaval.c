#include <stdio.h>

int main(){
    
    

    int tabuleiro[10][10] = {0};        // criação e inicialização do tabuleiro
    int i, j;                           // definição das variaveis correspondentes a posição dos navios.
    int linha, coluna;                  // definição das variaveis que vão imprimir a posição dos navios no tabuleiro.
    char letra;                         // varivavel char para imprimir as letras correspondentes as colunas do tabuleiro.


    for (i = 1; i <= 3; i++)
    {
        tabuleiro[i][2] = 1;        // posicionamento do navio vertical.
    }

   
    
    for (j = 3; j <= 5; j++)
    {
        tabuleiro[5][j] = 1;        // posicionamento do navio orizontal.
    }

    printf ("  ");

    for (letra = 'A'; letra <= 'J'; letra++)        // comando for para impressão das letras das colunas to tabuleiro.
    {
        printf (" %c", letra);
    }
    printf ("\n");

    for (linha = 0; linha <= 9; linha++){
        printf ("%d ", linha);
        for (coluna = 0; coluna <= 9; coluna++){
            if (tabuleiro[linha][coluna] == 1)          // comando for aninhado para impressão dos numeros das linha e de todo o tabuleiro
            {                                           // mostrando a posição dos navios e da agua.
                printf (" 3");  // representação do navio
            }else {
                printf (" 0"); // representação da agua
            }
            
        }
        printf ("\n");
    }

    return 0;
}