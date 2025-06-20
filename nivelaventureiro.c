#include <stdio.h>

#define TAB_SIZE 10
#define SHIP_SIZE 3

void inicializaTabuleiro(int tabuleiro[TAB_SIZE][TAB_SIZE]) {
    for (int i = 0; i < TAB_SIZE; i++)
        for (int j = 0; j < TAB_SIZE; j++)
            tabuleiro[i][j] = 0;
}

int validaPosicionamentoHV(int tabuleiro[TAB_SIZE][TAB_SIZE], int linha, int coluna, int tamanho, char orientacao) {
    if (orientacao == 'H') {
        if (coluna + tamanho > TAB_SIZE) return 0;
        for (int i = 0; i < tamanho; i++)
            if (tabuleiro[linha][coluna + i] != 0)
                return 0;
    } else if (orientacao == 'V') {
        if (linha + tamanho > TAB_SIZE) return 0;
        for (int i = 0; i < tamanho; i++)
            if (tabuleiro[linha + i][coluna] != 0)
                return 0;
    } else {
        return 0;
    }
    return 1;
}

int validaPosicionamentoDiagonal(int tabuleiro[TAB_SIZE][TAB_SIZE], int linha, int coluna, int tamanho, char orientacaoDiagonal) {
    if (orientacaoDiagonal == 'D') {
        if (linha + tamanho > TAB_SIZE || coluna + tamanho > TAB_SIZE)
            return 0;
        for (int i = 0; i < tamanho; i++)
            if (tabuleiro[linha + i][coluna + i] != 0)
                return 0;
    } else if (orientacaoDiagonal == 'I') {
        if (linha + tamanho > TAB_SIZE || coluna - (tamanho - 1) < 0)
            return 0;
        for (int i = 0; i < tamanho; i++)
            if (tabuleiro[linha + i][coluna - i] != 0)
                return 0;
    } else {
        return 0;
    }
    return 1;
}

void posicionaNavioHV(int tabuleiro[TAB_SIZE][TAB_SIZE], int linha, int coluna, int tamanho, char orientacao) {
    if (orientacao == 'H') {
        for (int i = 0; i < tamanho; i++)
            tabuleiro[linha][coluna + i] = 3;
    } else if (orientacao == 'V') {
        for (int i = 0; i < tamanho; i++)
            tabuleiro[linha + i][coluna] = 3;
    }
}

void posicionaNavioDiagonal(int tabuleiro[TAB_SIZE][TAB_SIZE], int linha, int coluna, int tamanho, char orientacaoDiagonal) {
    if (orientacaoDiagonal == 'D') {
        for (int i = 0; i < tamanho; i++)
            tabuleiro[linha + i][coluna + i] = 3;
    } else if (orientacaoDiagonal == 'I') {
        for (int i = 0; i < tamanho; i++)
            tabuleiro[linha + i][coluna - i] = 3;
    }
}

void exibeTabuleiro(int tabuleiro[TAB_SIZE][TAB_SIZE]) {
    printf("Tabuleiro (0 = agua, 3 = navio):\n");
    for (int i = 0; i < TAB_SIZE; i++) {
        for (int j = 0; j < TAB_SIZE; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAB_SIZE][TAB_SIZE];

    int navio1Linha = 1, navio1Coluna = 1;
    int navio2Linha = 4, navio2Coluna = 5;
    int navio3Linha = 0, navio3Coluna = 7;
    int navio4Linha = 6, navio4Coluna = 2;

    inicializaTabuleiro(tabuleiro);

    if (!validaPosicionamentoHV(tabuleiro, navio1Linha, navio1Coluna, SHIP_SIZE, 'H')) {
        printf("Posicionamento inválido para navio horizontal 1.\n");
        return 1;
    }
    posicionaNavioHV(tabuleiro, navio1Linha, navio1Coluna, SHIP_SIZE, 'H');

    if (!validaPosicionamentoHV(tabuleiro, navio2Linha, navio2Coluna, SHIP_SIZE, 'V')) {
        printf("Posicionamento inválido para navio vertical 2.\n");
        return 1;
    }
    posicionaNavioHV(tabuleiro, navio2Linha, navio2Coluna, SHIP_SIZE, 'V');

    if (!validaPosicionamentoDiagonal(tabuleiro, navio3Linha, navio3Coluna, SHIP_SIZE, 'I')) {
        printf("Posicionamento inválido para navio diagonal 3.\n");
        return 1;
    }
    posicionaNavioDiagonal(tabuleiro, navio3Linha, navio3Coluna, SHIP_SIZE, 'I');

    if (!validaPosicionamentoDiagonal(tabuleiro, navio4Linha, navio4Coluna, SHIP_SIZE, 'D')) {
        printf("Posicionamento inválido para navio diagonal 4.\n");
        return 1;
    }
    posicionaNavioDiagonal(tabuleiro, navio4Linha, navio4Coluna, SHIP_SIZE, 'D');

    exibeTabuleiro(tabuleiro);

    return 0;
}
