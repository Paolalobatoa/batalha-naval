#include <stdio.h>

#define TAB_SIZE 10
#define SHIP_SIZE 3

void inicializaTabuleiro(int tabuleiro[TAB_SIZE][TAB_SIZE]) {
    for (int i = 0; i < TAB_SIZE; i++) {
        for (int j = 0; j < TAB_SIZE; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

int validaPosicionamento(int tabuleiro[TAB_SIZE][TAB_SIZE], int linha, int coluna, int tamanho, char orientacao) {
    if (orientacao == 'H') {
        if (coluna + tamanho > TAB_SIZE) return 0;
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return 0;
        }
    } else if (orientacao == 'V') {
        if (linha + tamanho > TAB_SIZE) return 0;
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return 0;
        }
    } else {
        return 0;
    }
    return 1;
}

void posicionaNavio(int tabuleiro[TAB_SIZE][TAB_SIZE], int linha, int coluna, int tamanho, char orientacao) {
    if (orientacao == 'H') {
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha][coluna + i] = 3;
        }
    } else if (orientacao == 'V') {
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha + i][coluna] = 3;
        }
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
    int navio1Linha = 2, navio1Coluna = 3;
    int navio2Linha = 5, navio2Coluna = 7;

    inicializaTabuleiro(tabuleiro);

    if (validaPosicionamento(tabuleiro, navio1Linha, navio1Coluna, SHIP_SIZE, 'H')) {
        posicionaNavio(tabuleiro, navio1Linha, navio1Coluna, SHIP_SIZE, 'H');
    } else {
        printf("Posicionamento inválido para o navio horizontal.\n");
        return 1;
    }

    if (validaPosicionamento(tabuleiro, navio2Linha, navio2Coluna, SHIP_SIZE, 'V')) {
        posicionaNavio(tabuleiro, navio2Linha, navio2Coluna, SHIP_SIZE, 'V');
    } else {
        printf("Posicionamento inválido para o navio vertical.\n");
        return 1;
    }

    exibeTabuleiro(tabuleiro);

    return 0;
}
