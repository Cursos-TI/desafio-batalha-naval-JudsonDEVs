#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para gerar matriz em forma de cone (apontando para baixo)
void gerarCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= (TAM_HABILIDADE / 2 - i) && j <= (TAM_HABILIDADE / 2 + i))
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Função para gerar matriz em forma de cruz
void gerarCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == centro || j == centro)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Função para gerar matriz em forma de octaedro (losango)
void gerarOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        int dist = (i > centro) ? (i - centro) : (centro - i); // substitui abs()
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= dist && j < TAM_HABILIDADE - dist)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Função para aplicar uma matriz de habilidade ao tabuleiro, centrando em (origem_i, origem_j)
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origem_i, int origem_j, int valor_area) {
    int offset = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int ti = origem_i - offset + i;
            int tj = origem_j - offset + j;

            if (ti >= 0 && ti < TAM_TABULEIRO && tj >= 0 && tj < TAM_TABULEIRO) {
                if (habilidade[i][j] == 1) {
                    tabuleiro[ti][tj] = valor_area;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Adiciona navios manualmente (valor 9 para destacar)
    tabuleiro[2][2] = 9;
    tabuleiro[2][3] = 9;
    tabuleiro[3][2] = 9;
    tabuleiro[5][5] = 9;

    // Matrizes de habilidade
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    // Gerar as habilidades
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Aplicar habilidades no tabuleiro com valores específicos
    aplicarHabilidade(tabuleiro, cone, 2, 2, 1);       // Cone → valor 1
    aplicarHabilidade(tabuleiro, cruz, 5, 5, 3);       // Cruz → valor 3
    aplicarHabilidade(tabuleiro, octaedro, 7, 7, 5);   // Octaedro → valor 5

    // Mostrar resultado
    printf("Tabuleiro com habilidades aplicadas:\n\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
