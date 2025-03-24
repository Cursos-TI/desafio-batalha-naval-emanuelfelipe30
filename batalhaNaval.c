#include <stdio.h>
#include <math.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3
#define HABILIDADE 5

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void posicionarNavioHorizontal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO <= TAMANHO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = 3;
        }
    }
}

void posicionarNavioVertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO <= TAMANHO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = 3;
        }
    }
}

void posicionarNavioDiagonalPrincipal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO <= TAMANHO && coluna + TAMANHO_NAVIO <= TAMANHO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna + i] = 3;
        }
    }
}

void posicionarNavioDiagonalSecundaria(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO <= TAMANHO && coluna - TAMANHO_NAVIO + 1 >= 0) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna - i] = 3;
        }
    }
}

void aplicarHabilidadeCone(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        for (int j = -i; j <= i; j++) {
            if (linha + i < TAMANHO && coluna + j >= 0 && coluna + j < TAMANHO) {
                tabuleiro[linha + i][coluna + j] = HABILIDADE;
            }
        }
    }
}

void aplicarHabilidadeCruz(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    for (int i = -2; i <= 2; i++) {
        if (linha + i >= 0 && linha + i < TAMANHO) {
            tabuleiro[linha + i][coluna] = HABILIDADE;
        }
        if (coluna + i >= 0 && coluna + i < TAMANHO) {
            tabuleiro[linha][coluna + i] = HABILIDADE;
        }
    }
}

void aplicarHabilidadeOctaedro(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    for (int i = -2; i <= 2; i++) {
        for (int j = -2 + abs(i); j <= 2 - abs(i); j++) {
            if (linha + i >= 0 && linha + i < TAMANHO && coluna + j >= 0 && coluna + j < TAMANHO) {
                tabuleiro[linha + i][coluna + j] = HABILIDADE;
            }
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Definição das coordenadas iniciais (exemplo)
    int linhaHorizontal = 2, colunaHorizontal = 4;
    int linhaVertical = 5, colunaVertical = 1;
    int linhaDiagonal1 = 0, colunaDiagonal1 = 0;
    int linhaDiagonal2 = 0, colunaDiagonal2 = 9;
    
    // Posicionando os navios
    posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal);
    posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical);
    posicionarNavioDiagonalPrincipal(tabuleiro, linhaDiagonal1, colunaDiagonal1);
    posicionarNavioDiagonalSecundaria(tabuleiro, linhaDiagonal2, colunaDiagonal2);

    // Aplicando habilidades
    aplicarHabilidadeCone(tabuleiro, 6, 5);
    aplicarHabilidadeCruz(tabuleiro, 4, 4);
    aplicarHabilidadeOctaedro(tabuleiro, 7, 7);

    // Exibir tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}